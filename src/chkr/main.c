/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 13:57:38 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 17:58:46 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

static int		checker(int argc, char **argv)
{
	t_stacks	stacks;
	t_option	option;
	t_cmd		*cmd;

	cmd = NULL;
	option.v = 0;
	option.f = 0;
	option.path = NULL;
	stacks.b = NULL;
	if ((stacks.a = fill_stack_a(argc, argv, &option)) == NULL)
		error(1, NULL, NULL, &option);
	if (!(valid_stack(stacks.a)))
		error(1, &stacks, NULL, &option);
	if ((cmd = get_commands(cmd, &option, &stacks)) == NULL)
		error(2, &stacks, NULL, &option);
	stacks = make_cmd(&stacks, cmd, &option);
	free_cmd(cmd);
	if (check_stack_free(&stacks) == 1)
		return (1);
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc == 1)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		if (checker(argc, argv) == 0)
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
	}
	return (0);
}
