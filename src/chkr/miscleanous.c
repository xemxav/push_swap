/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   miscleanous.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:33:04 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 13:29:54 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		error2(t_stacks *stacks)
{
	if (check_stack_free(stacks) == 1)
	{
		ft_printf("OK\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("KO\n");
		exit(EXIT_FAILURE);
	}
}

void			error(int error, t_stacks *stacks, t_stack *head_stack,
				t_option *option)
{
	if (error == 1)
	{
		ft_printf("Error\n");
		free_stacks(stacks);
		exit(EXIT_FAILURE);
	}
	if (error == 3)
	{
		ft_printf("Error\n");
		if (option->f)
			ft_strdel(&option->path);
		free_stack(head_stack);
		exit(EXIT_FAILURE);
	}
	if (error == 2)
	{
		error2(stacks);
	}
}

void			make_v(t_stacks *stacks, char *cmd)
{
	t_stack		*a;
	t_stack		*b;

	a = stacks->a;
	b = stacks->b;
	ft_printf("\ncommand  is: %s\n\n_____A_____ _____B_____\n", cmd);
	while (a != NULL || b != NULL)
	{
		if (a != NULL && b != NULL)
		{
			ft_printf("%11d %11d\n", a->n, b->n);
			a = a->next;
			b = b->next;
		}
		if (a != NULL && b == NULL)
		{
			ft_printf("%11d\n", a->n);
			a = a->next;
		}
		if (a == NULL && b != NULL)
		{
			ft_printf("%23d\n", b->n);
			b = b->next;
		}
	}
}

int				check_stack_free(t_stacks *stacks)
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
	free_stack(stacks->a);
	free_stack(stacks->b);
	return (ret);
}
