/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_management.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 15:40:45 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 10:34:01 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack			*free_stack(t_stack *stack_head)
{
	t_stack		*tmp;

	if (stack_head == NULL)
		return (NULL);
	tmp = stack_head->next;
	ft_memdel((void**)&stack_head);
	return (free_stack(tmp));
}

t_cmd			*free_cmd(t_cmd *cmd_head)
{
	t_cmd		*tmp;

	if (cmd_head == NULL)
		return (NULL);
	tmp = cmd_head->next;
	ft_memdel((void**)&cmd_head->cmd);
	ft_memdel((void**)&cmd_head);
	return (free_cmd(tmp));
}

void			free_stacks(t_stacks *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
}
