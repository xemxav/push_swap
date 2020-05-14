/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   medium.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/09 17:37:53 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 16:17:59 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char			*is_swap(t_stacks *stacks)
{
	int				i;

	i = 0;
	if (stacks->a != NULL && stacks->a->next != NULL)
		if (stacks->a->n > stacks->a->next->n)
			i += 1;
	if (stacks->b != NULL && stacks->b->next != NULL)
		if (stacks->b->n < stacks->b->next->n)
			i += 2;
	if (i == 1)
		return (ft_strdup("sa"));
	if (i == 2)
		return (ft_strdup("sb"));
	if (i == 3)
		return (ft_strdup("ss"));
	return (NULL);
}

static char			*is_rotate(t_stacks *stacks)
{
	int				i;

	i = 0;
	if (stacks->a_pivot != NULL && stacks->a != NULL && stacks->a->next != NULL)
		if (stacks->a->n > stacks->a_pivot->n)
			i += 1;
	if (stacks->b_pivot != NULL && stacks->b != NULL && stacks->b->next != NULL)
		if (stacks->b_pivot->n > stacks->b->n)
			i += 2;
	if (i == 1)
		return (ft_strdup("ra"));
	if (i == 2)
		return (ft_strdup("rb"));
	if (i == 3)
		return (ft_strdup("rr"));
	return (NULL);
}

static char			*is_reverse_rotate(t_stacks *stacks)
{
	int				i;

	i = 0;
	if (stacks->a_pivot != NULL && stacks->a != NULL && stacks->a->next != NULL)
		if (stacks->a_last->n < stacks->a_pivot->n
		&& stacks->a_last->n < stacks->a->n)
			i += 1;
	if (stacks->b_pivot != NULL && stacks->b != NULL && stacks->b->next != NULL)
		if (stacks->b_last->n < stacks->b_pivot->n
		&& stacks->a_last->n > stacks->a->n)
			i += 2;
	if (i == 1)
		return (ft_strdup("rra"));
	if (i == 2)
		return (ft_strdup("rrb"));
	if (i == 3)
		return (ft_strdup("rrr"));
	return (NULL);
}

static char			*is_push(t_stacks *stacks)
{
	if (stacks->a_pivot != NULL)
		return (ft_strdup("pb"));
	return (ft_strdup("pa"));
}

t_cmd				*medium(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	char			*s;
	t_cmd			*tmp;

	s = NULL;
	if (check_stacks(stacks) == 1)
		return (cmd);
	stacks = find_important(stacks);
	if ((s = is_swap(stacks)) == NULL)
		if ((s = is_reverse_rotate(stacks)) == NULL)
			if ((s = is_rotate(stacks)) == NULL)
				s = is_push(stacks);
	cmd = save_cmd(cmd, s);
	tmp = cmd;
	while (tmp->next != NULL)
		tmp = tmp->next;
	stacks = (*tmp->action)(stacks, s);
	if (option->v)
		make_v(stacks, s);
	ft_strdel(&s);
	return (medium(stacks, cmd, option));
}
