/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   miscleanous.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 14:33:04 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 15:56:30 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void			error_ps(int error, t_stacks *stacks, t_stack *head_stack,
						t_option *option)
{
	if (error == 1)
	{
		ft_printf("Error\n");
		free_stacks(stacks);
		if (option->f)
			ft_strdel(&option->path);
		exit(EXIT_FAILURE);
	}
	if (error == 2)
	{
		ft_printf("Error\n");
		free_stack(head_stack);
		if (option->f && option->path != NULL)
			ft_strdel(&option->path);
		exit(EXIT_FAILURE);
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

int				is_ordered(t_stack *head, t_stack *stop)
{
	t_stack		*tmp;

	tmp = head;
	if (stop == NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->n > tmp->next->n)
				return (0);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp->next != stop)
		{
			if (tmp->n > tmp->next->n)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
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
		{
			ret = 0;
			break ;
		}
		tmp = tmp->next;
	}
	free_stack(stacks->a);
	free_stack(stacks->b);
	return (ret);
}
