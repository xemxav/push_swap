/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 13:57:38 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:15:10 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void			good_exit(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	free_stacks(stacks);
	if (option->f)
		ft_strdel(&option->path);
	free_cmd(cmd);
	exit(EXIT_SUCCESS);
}

int				check_stacks(t_stacks *stacks)
{
	t_stack		*tmp;
	int			ret;

	ret = 1;
	tmp = stacks->a;
	if (stacks->b != NULL)
		ret = 0;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			break ;
		if (tmp->n > tmp->next->n)
			ret = 0;
		tmp = tmp->next;
	}
	return (ret);
}

int				valid_stack(t_stack *stack_head)
{
	t_stack		*tmp;
	t_stack		*tested;

	tested = stack_head;
	tmp = stack_head->next;
	while (tested->next != NULL)
	{
		tmp = tested->next;
		while (tmp != NULL)
		{
			if (tmp->n == tested->n)
				return (0);
			tmp = tmp->next;
		}
		tested = tested->next;
	}
	return (1);
}

static void		push_swap(int argc, char **argv)
{
	t_stacks	stacks;
	t_option	option;
	t_cmd		*cmd;

	option.v = 0;
	option.f = 0;
	option.path = NULL;
	cmd = NULL;
	stacks.b = NULL;
	if ((stacks.a = fill_stack_a(argc, argv, &option)) == NULL)
		error_ps(1, NULL, NULL, &option);
	if (!(valid_stack(stacks.a)))
		error_ps(2, NULL, stacks.a, &option);
	if (option.v)
		make_v(&stacks, "initial state");
	if (check_stacks(&stacks))
		good_exit(&stacks, cmd, &option);
	if ((cmd = find_algo(&stacks, cmd, &option)) == NULL)
		error_ps(1, &stacks, NULL, &option);
	if (!(option.v) && !(option.f))
		print_cmd(cmd, &option);
	if ((option.f))
		write_cmd(cmd, &option);
	good_exit(&stacks, cmd, &option);
}

int				main(int argc, char **argv)
{
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else
		push_swap(argc, argv);
	return (0);
}
