/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_cmd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 17:32:37 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 14:57:53 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	t_fptr		get_action(char *cmd)
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

t_cmd				*save_cmd(t_cmd *cmd_head, char *line)
{
	t_cmd			*new;
	t_cmd			*tmp;

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

static int			check_input(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (1);
	if (ft_strcmp(line, "sb") == 0)
		return (1);
	if (ft_strcmp(line, "ss") == 0)
		return (1);
	if (ft_strcmp(line, "ra") == 0)
		return (1);
	if (ft_strcmp(line, "rb") == 0)
		return (1);
	if (ft_strcmp(line, "rr") == 0)
		return (1);
	if (ft_strcmp(line, "pa") == 0)
		return (1);
	if (ft_strcmp(line, "pb") == 0)
		return (1);
	if (ft_strcmp(line, "rra") == 0)
		return (1);
	if (ft_strcmp(line, "rrb") == 0)
		return (1);
	if (ft_strcmp(line, "rrr") == 0)
		return (1);
	return (0);
}

static void			error_cmd(t_cmd *cmd, t_stacks *stacks, t_option *option)
{
	ft_printf("Error\n");
	if (option->f)
		ft_strdel(&option->path);
	free_stacks(stacks);
	free_cmd(cmd);
	exit(EXIT_FAILURE);
}

t_cmd				*get_commands(t_cmd *cmd, t_option *option,
									t_stacks *stacks)
{
	char			*line;
	int				fd;

	cmd = NULL;
	line = NULL;
	if (option->f != 0)
		fd = open(option->path, O_RDONLY);
	else
		fd = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strcmp("", line) == 0)
			break ;
		if (check_input(line) == 0)
			error_cmd(cmd, stacks, option);
		cmd = save_cmd(cmd, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (option->f != 0)
	{
		ft_strdel(&option->path);
		close(fd);
	}
	return (cmd);
}
