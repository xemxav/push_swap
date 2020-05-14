/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   actions.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/07 10:45:29 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 10:34:01 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacks			*swap_action(t_stacks *stacks, char *cmd)
{
	if (cmd[1] == 'a')
		stacks->a = swap(stacks->a);
	else if (cmd[1] == 'b')
		stacks->b = swap(stacks->b);
	else
	{
		stacks->a = swap(stacks->a);
		stacks->b = swap(stacks->b);
	}
	return (stacks);
}

t_stacks			*push_action(t_stacks *stacks, char *cmd)
{
	return (stacks = push(stacks, cmd[1]));
}

t_stacks			*reverse_rotate_action(t_stacks *stacks, char *cmd)
{
	if (cmd[2] == 'a')
		stacks->a = reverse_rotate(stacks->a);
	else if (cmd[2] == 'b')
		stacks->b = reverse_rotate(stacks->b);
	else
	{
		stacks->a = reverse_rotate(stacks->a);
		stacks->b = reverse_rotate(stacks->b);
	}
	return (stacks);
}

t_stacks			*rotate_action(t_stacks *stacks, char *cmd)
{
	if (cmd[1] == 'a')
		stacks->a = rotate(stacks->a);
	else if (cmd[1] == 'b')
		stacks->b = rotate(stacks->b);
	else
	{
		stacks->a = rotate(stacks->a);
		stacks->b = rotate(stacks->b);
	}
	return (stacks);
}
