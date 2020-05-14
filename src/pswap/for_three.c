/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   for_three.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 16:13:08 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:09:57 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_cmd		*two_rra(t_cmd *cmd)
{
	cmd = save_cmd(cmd, "rra");
	cmd = save_cmd(cmd, "rra");
	return (cmd);
}

static	int			is_first_max(t_stack *a)
{
	t_stack			*second;
	t_stack			*last;

	second = a->next;
	last = second->next;
	if (a->n > second->n && a->n > last->n)
		return (1);
	return (0);
}

static	int			is_second_min(t_stack *a)
{
	t_stack			*second;
	t_stack			*last;

	second = a->next;
	last = second->next;
	if (a->n > second->n && second->n < last->n)
		return (1);
	return (0);
}

t_cmd				*for_three(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	char			*s;

	s = NULL;
	if (check_stacks(stacks) == 1)
		return (cmd);
	if (is_first_max(stacks->a) && is_second_min(stacks->a))
		return (two_rra(cmd));
	else
		return (medium(stacks, cmd, option));
}
