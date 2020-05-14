/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_algo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/16 12:03:58 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 11:19:33 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_cmd	*find_simple(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	t_stack		*last;
	t_stack		*a;

	a = stacks->a;
	if (a->n > a->next->n && a->n < a->next->next->n
	&& is_ordered(a->next->next, NULL))
		return (save_make_action(cmd, "sa", option, stacks));
	last = find_last(a);
	if (a->n > last->n && is_ordered(a->next, NULL))
		return (save_make_action(cmd, "ra", option, stacks));
	if (last->n < a->n && is_ordered(a, last))
		return (save_make_action(cmd, "rra", option, stacks));
	return (NULL);
}

int				count_stack(t_stack *head_stack)
{
	int		i;

	i = 0;
	while (head_stack != NULL)
	{
		i++;
		head_stack = head_stack->next;
	}
	return (i);
}

t_cmd			*find_algo(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	int			stack_len;

	stack_len = count_stack(stacks->a);
	if ((cmd = find_simple(stacks, cmd, option)) != NULL)
		return (cmd);
	if (stack_len == 3)
		return (for_three(stacks, cmd, option));
	if (stack_len <= 50)
		return (medium(stacks, cmd, option));
	cmd = insertion(stacks, cmd, option);
	return (cmd);
}
