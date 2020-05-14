/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/18 14:35:24 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 18:48:30 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char			*inverse_move(t_stacks *stacks)
{
	if (stacks->move_a > 0)
	{
		stacks->move_a--;
		return (ft_strdup("ra"));
	}
	if (stacks->move_a < 0)
	{
		stacks->move_a++;
		return (ft_strdup("rra"));
	}
	if (stacks->move_b > 0)
	{
		stacks->move_b--;
		return (ft_strdup("rb"));
	}
	if (stacks->move_b < 0)
	{
		stacks->move_b++;
		return (ft_strdup("rrb"));
	}
	return (NULL);
}

char			*translate_move(t_stacks *stacks)
{
	if (stacks->move_a == 0 && stacks->move_b == 0)
		return (NULL);
	if (stacks->move_a * stacks->move_b > 0)
	{
		if (stacks->move_a > 0)
		{
			stacks->move_a--;
			stacks->move_b--;
			return (ft_strdup("rr"));
		}
		else
		{
			stacks->move_a++;
			stacks->move_b++;
			return (ft_strdup("rrr"));
		}
	}
	else
		return (inverse_move(stacks));
}

static t_cmd	*apply_moves(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	char		*s;

	while (stacks->move_a != 0 || stacks->move_b != 0)
	{
		s = translate_move(stacks);
		cmd = save_make_action(cmd, s, option, stacks);
		if (s != NULL)
			ft_strdel(&s);
	}
	cmd = save_make_action(cmd, "pb", option, stacks);
	return (cmd);
}

static t_cmd	*create_wheel(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	int			i;

	i = 2;
	while (i)
	{
		cmd = save_make_action(cmd, "pb", option, stacks);
		i--;
	}
	if (stacks->b->n < stacks->b->next->n)
		cmd = save_make_action(cmd, "sb", option, stacks);
	return (cmd);
}

t_cmd			*insertion(t_stacks *stacks, t_cmd *cmd, t_option *option)
{
	cmd = create_wheel(stacks, cmd, option);
	while (stacks->a)
	{
		stacks->move_a = 0;
		stacks->move_b = 0;
		find_best_move_insert(stacks);
		cmd = apply_moves(stacks, cmd, option);
	}
	back_to_base(stacks);
	cmd = apply_return(stacks, cmd, option);
	return (cmd);
}
