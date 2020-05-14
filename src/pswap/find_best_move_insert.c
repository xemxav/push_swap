/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_best_move_insert.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/23 19:07:48 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 11:33:50 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		get_to_top(t_stack *a, int n)
{
	int			i;
	int			len;
	t_stack		*ac;

	i = 0;
	len = count_stack(a);
	ac = a;
	while (ac != NULL && ac->n != n)
	{
		i++;
		ac = ac->next;
	}
	if (i > len / 2)
		return (i - len);
	return (i);
}

static int		real_value(int a, int b)
{
	int			min;
	int			max;

	if (a * b >= 0)
	{
		if (abs_value(a) >= abs_value(b))
		{
			min = b;
			max = a;
		}
		else
		{
			min = a;
			max = b;
		}
		return (abs_value(max));
	}
	else
		return (abs_value(a) + abs_value(b));
}

void			choose_move(t_stacks *stacks, int a, int b, int first)
{
	int			sumab;
	int			sumove;

	sumab = real_value(a, b);
	sumove = real_value(stacks->move_a, stacks->move_b);
	if (sumab < sumove || first == 1)
	{
		stacks->move_a = a;
		stacks->move_b = b;
	}
}

void			find_best_move_insert(t_stacks *stacks)
{
	int			a;
	int			b;
	t_stack		*sa;
	int			first;

	sa = stacks->a;
	first = 1;
	while (sa != NULL)
	{
		a = get_to_top(stacks->a, sa->n);
		b = get_proper_interval(stacks->b, sa->n);
		choose_move(stacks, a, b, first);
		first = 0;
		sa = sa->next;
	}
}
