/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_prt_cmd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 11:24:41 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 11:25:19 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void			write_cmd(t_cmd *cmd_head, t_option *option)
{
	int			fd;

	if ((fd = open(option->path, O_RDWR | O_CREAT | O_APPEND, S_IRWXU)) == -1)
		printf("erreur ouverture");
	while (cmd_head != NULL)
	{
		fd_printf(fd, "%s\n", cmd_head->cmd);
		cmd_head = cmd_head->next;
	}
	close(fd);
}

void			print_cmd(t_cmd *cmd_head, t_option *option)
{
	t_cmd		*tmp;

	tmp = cmd_head;
	if (option->f)
		return (write_cmd(cmd_head, option));
	while (tmp != NULL)
	{
		ft_printf("%s\n", tmp->cmd);
		tmp = tmp->next;
	}
}
