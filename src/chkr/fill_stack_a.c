/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_stack_a.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 15:47:54 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 15:45:04 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_option		*look_for_option(int argc, char **argv, t_option *option)
{
	int				y;

	y = 1;
	while (y < argc)
	{
		if (argv[y][0] != '-' && !ft_isdigit(argv[y][0]))
			error(3, NULL, NULL, option);
		if (argv[y][0] == '-' && argv[y][1] != 'v' && argv[y][1] != 'f'
		&& !(ft_isdigit(argv[y][1])))
			error(3, NULL, NULL, option);
		if (ft_strcmp(argv[y], "-v") == 0)
			option->v = y;
		if (ft_strcmp(argv[y], "-f") == 0)
		{
			option->f = y;
			if (argc > y + 1 && !(ft_isdigit(argv[y + 1][0])))
				option->path = ft_strdup(argv[y + 1]);
			else
				error(1, NULL, NULL, option);
		}
		y++;
	}
	return (option);
}

t_stack				*new_link_end_of_stack(t_stack *stack_head, int n)
{
	t_stack			*new;
	t_stack			*tmp;

	if ((new = malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (stack_head == NULL)
		return (new);
	else
	{
		tmp = stack_head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		return (stack_head);
	}
}

static t_stack		*get_nbr(char *s, t_stack *a, t_option *option)
{
	int				y;
	int				n;
	char			**tab;

	tab = NULL;
	tab = ft_strsplit(s, ' ');
	y = 0;
	while (tab[y] != NULL)
	{
		n = ft_atoi(tab[y]);
		if ((n < 0 && tab[y][0] != '-') || (n > 0 && tab[y][0] == '-'))
			error(3, NULL, a, option);
		a = new_link_end_of_stack(a, n);
		ft_strdel(&tab[y]);
		y++;
	}
	free(tab);
	return (a);
}

t_stack				*fill_stack_a(int argc, char **argv, t_option *option)
{
	int				y;
	int				i;
	t_stack			*a;

	option = look_for_option(argc, argv, option);
	y = 0;
	a = NULL;
	while (y++ < argc)
	{
		i = -1;
		if (option->v != 0 && y == option->v)
			y++;
		if (option->f != 0 && y == option->f)
			y += 2;
		if (y >= argc)
			break ;
		while (argv[y][i++] != '\0')
		{
			if (!ft_isdigit(argv[y][i]) && (argv[y][i] != ' '
			&& argv[y][i] != '-'))
				error(3, NULL, a, option);
		}
		a = get_nbr(argv[y], a, option);
	}
	return (a);
}
