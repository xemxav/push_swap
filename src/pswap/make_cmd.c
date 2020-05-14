/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_cmd.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/06 16:21:52 by xem          #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 11:21:27 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack			*swap(t_stack *head_stack)
{
	t_stack		*tmp;

	tmp = head_stack;
	if (head_stack == NULL || head_stack->next == NULL)
		return (tmp);
	tmp = head_stack->next;
	head_stack->next = tmp->next;
	tmp->next = head_stack;
	return (tmp);
}

t_stacks		*push(t_stacks *stacks, char c)
{
	t_stack		*tmp;

	if (c == 'a')
	{
		if (stacks->b == NULL)
			return (stacks);
		tmp = stacks->b;
		tmp = tmp->next;
		stacks->b->next = stacks->a;
		stacks->a = stacks->b;
		stacks->b = tmp;
	}
	else
	{
		if (stacks->a == NULL)
			return (stacks);
		tmp = stacks->a;
		tmp = tmp->next;
		stacks->a->next = stacks->b;
		stacks->b = stacks->a;
		stacks->a = tmp;
	}
	return (stacks);
}

t_stack			*rotate(t_stack *head_stack)
{
	t_stack		*tmp;
	t_stack		*last;

	if (head_stack == NULL || head_stack->next == NULL)
		return (head_stack);
	tmp = head_stack;
	last = head_stack;
	while (last->next != NULL)
		last = last->next;
	head_stack = head_stack->next;
	last->next = tmp;
	tmp->next = NULL;
	return (head_stack);
}

t_stack			*reverse_rotate(t_stack *head_stack)
{
	t_stack		*tmp;
	t_stack		*last;

	if (head_stack == NULL || head_stack->next == NULL)
		return (head_stack);
	last = head_stack;
	tmp = head_stack;
	while (last->next != NULL)
		last = last->next;
	while (tmp->next != last)
		tmp = tmp->next;
	last->next = head_stack;
	tmp->next = NULL;
	return (last);
}

t_stacks		make_cmd(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	if (option->v)
		make_v(stacks, "Initial State");
	while (cmd != NULL)
	{
		stacks = (*cmd->action)(stacks, cmd->cmd);
		if (option->v)
			make_v(stacks, cmd->cmd);
		cmd = cmd->next;
	}
	return (*stacks);
}
