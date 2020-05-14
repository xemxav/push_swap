/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_proper_interval.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 11:32:05 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 11:41:41 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		before_pivot(t_stack *bc, t_stack *pivot, int n)
{
	int			i;

	i = 0;
	while (bc != pivot)
	{
		i++;
		if (bc->n > n && bc->next->n < n)
			break ;
		bc = bc->next;
	}
	return (i);
}

static	int		pivot_interval(t_stack *bc, t_stack *pivot, int n)
{
	int			i;
	t_stack		*start;
	t_stack		*last;

	start = bc;
	i = 0;
	last = find_last(bc);
	while (start != pivot)
	{
		i++;
		start = start->next;
	}
	while (start->next != NULL)
	{
		i++;
		if (start->n > n && start->next->n < n)
			return (i);
		start = start->next;
	}
	if ((bc->n < n && last->n > n))
		return (0);
	i = before_pivot(bc, pivot, n);
	return (i);
}

int				get_proper_interval(t_stack *b, int n)
{
	int			i;
	int			len;
	t_stack		*bc;
	t_stack		*pivot;

	i = 0;
	len = count_stack(b);
	pivot = find_pivot(b, 'b');
	bc = b;
	if (is_reverse_order(b))
	{
		while (bc != NULL && bc->n > n)
		{
			i++;
			bc = bc->next;
		}
	}
	else
	{
		pivot = pivot->next;
		i = pivot_interval(bc, pivot, n);
	}
	if (i > len / 2)
		return (i - len);
	return (i);
}
