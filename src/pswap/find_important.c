/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_important.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/11 17:20:34 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 11:20:43 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int				is_reverse_order(t_stack *head_stack)
{
	t_stack		*tmp;

	tmp = head_stack;
	while (tmp->next != NULL)
	{
		if (tmp->next->n > tmp->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack			*find_last(t_stack *stack_head)
{
	t_stack		*tmp;

	if (stack_head == NULL)
		return (NULL);
	tmp = stack_head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_stack			*find_pivot(t_stack *head_stack, char stack)
{
	t_stack			*pivot;
	t_stack			*tmp;

	if (head_stack == NULL || head_stack->next == NULL)
		return (NULL);
	tmp = head_stack;
	pivot = NULL;
	if (stack == 'a')
	{
		while (tmp != NULL && tmp->next != NULL && tmp->n < tmp->next->n)
			tmp = tmp->next;
	}
	if (stack == 'b')
	{
		while (tmp != NULL && tmp->next != NULL && tmp->n > tmp->next->n)
			tmp = tmp->next;
	}
	if (tmp->next != NULL)
		pivot = tmp;
	return (pivot);
}

int				abs_value(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

t_stacks		*find_important(t_stacks *stacks)
{
	stacks->a_last = find_last(stacks->a);
	stacks->b_last = find_last(stacks->b);
	stacks->a_pivot = find_pivot(stacks->a, 'a');
	stacks->b_pivot = find_pivot(stacks->b, 'b');
	return (stacks);
}
