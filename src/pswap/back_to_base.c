/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   back_to_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/25 17:40:09 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:09:34 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_cmd			*apply_return(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	char		*s;

	s = NULL;
	while (stacks->move_b != 0)
	{
		s = translate_move(stacks);
		cmd = save_make_action(cmd, s, option, stacks);
		if (s != NULL)
			ft_strdel(&s);
	}
	while (stacks->b)
		cmd = save_make_action(cmd, "pa", option, stacks);
	return (cmd);
}

void			back_to_base(t_stacks *stacks)
{
	t_stack		*min;
	int			len;
	t_stack		*bc;

	stacks->move_a = 0;
	stacks->move_b = 0;
	len = count_stack(stacks->b);
	bc = stacks->b;
	min = bc;
	while (bc != NULL)
	{
		if (bc->n < min->n)
		{
			stacks->move_b++;
			min = bc;
		}
		bc = bc->next;
	}
	stacks->move_b++;
	if (stacks->move_b > len / 2)
		stacks->move_b = (stacks->move_b - len);
}
