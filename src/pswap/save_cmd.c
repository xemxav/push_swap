/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   save_cmd.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/11 18:45:56 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 11:27:31 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	t_fptr	get_action(char *cmd)
{
	if (cmd[0] == 's')
		return (swap_action);
	if (cmd[0] == 'p')
		return (push_action);
	if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] != '\0')
		return (reverse_rotate_action);
	else
		return (rotate_action);
}

t_cmd			*save_cmd(t_cmd *cmd_head, char *line)
{
	t_cmd		*new;
	t_cmd		*tmp;

	if ((new = malloc(sizeof(t_cmd))) == NULL)
		return (NULL);
	new->cmd = ft_strdup(line);
	new->action = get_action(new->cmd);
	new->next = NULL;
	if (cmd_head == NULL)
		return (new);
	else
	{
		tmp = cmd_head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		return (cmd_head);
	}
}

void			make_action(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	t_cmd		*tmp;

	tmp = cmd;
	while (tmp->next != NULL)
		tmp = tmp->next;
	stacks = (*tmp->action)(stacks, tmp->cmd);
	if (option->v)
		make_v(stacks, tmp->cmd);
}

t_cmd			*save_make_action(t_cmd *cmd, char *s,
								t_option *option, t_stacks *stacks)
{
	cmd = save_cmd(cmd, s);
	make_action(stacks, cmd, option);
	return (cmd);
}
