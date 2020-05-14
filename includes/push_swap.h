/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 15:40:51 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 15:08:24 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*a_last;
	t_stack			*b_last;
	t_stack			*a_pivot;
	t_stack			*b_pivot;
	t_stack			*a_med;
	t_stack			*b_med;
	int				move_a;
	int				move_b;
}					t_stacks;

typedef t_stacks *(*t_fptr)(t_stacks *stacks, char *cmd);

typedef struct		s_option
{
	int				v;
	int				f;
	char			*path;
}					t_option;

typedef struct		s_cmd
{
	char			*cmd;
	t_fptr			action;
	struct s_cmd	*next;
}					t_cmd;

/*
**shared functions
*/

t_stack				*fill_stack_a(int argc, char **argv, t_option *option);
t_stack				*new_link_end_of_stack(t_stack *stack_head, int n);
t_stacks			*swap_action(t_stacks *stacks, char *cmd);
t_stacks			*push_action(t_stacks *stacks, char *cmd);
t_stacks			*reverse_rotate_action(t_stacks *stacks, char *cmd);
t_stacks			*rotate_action(t_stacks *stacks, char *cmd);
t_stack				*swap(t_stack *head_stack);
t_stacks			*push(t_stacks *stacks, char c);
t_stack				*rotate(t_stack *head_stack);
t_stack				*reverse_rotate(t_stack *head_stack);
t_stack				*free_stack(t_stack *stack_head);
void				make_v(t_stacks *stacks, char *cmd);
void				free_stacks(t_stacks *stacks);
t_cmd				*free_cmd(t_cmd *cmd_head);
int					valid_stack(t_stack *stack_head);

/*
**push_swap functions
*/

t_cmd				*find_algo(t_stacks *stacks, t_cmd *cmd, t_option *option);
t_cmd				*medium(t_stacks *stacks, t_cmd *cmd, t_option *option);
t_cmd				*for_three(t_stacks *stacks, t_cmd *cmd, t_option *option);
t_cmd				*insertion(t_stacks *stacks, t_cmd *cmd, t_option *option);
void				find_best_move_insert(t_stacks *stacks);
t_stacks			*find_important(t_stacks *stacks);
t_cmd				*save_cmd(t_cmd *cmd_head, char *line);
void				make_action(t_stacks *stacks, t_cmd *cmd, t_option *option);
t_cmd				*save_make_action(t_cmd *cmd, char *s,
								t_option *option, t_stacks *stacks);
void				print_cmd(t_cmd *cmd_head, t_option *option);
int					check_stacks(t_stacks *stacks);
int					count_stack(t_stack *head_stack);
int					is_reverse_order(t_stack *head_stack);
void				good_exit(t_stacks *stacks, t_cmd *cmd, t_option *options);
void				error_ps(int error, t_stacks *stacks, t_stack *head_stack,
					t_option *option);
t_stack				*find_mediane(t_stack *stack_head);
void				choose_move(t_stacks *stacks, int a, int b, int first);
int					abs_value(int n);
t_stack				*find_last(t_stack *stack_head);
t_stack				*find_pivot(t_stack *head_stack, char stack);
void				back_to_base(t_stacks *stacks);
t_cmd				*apply_return(t_stacks *stacks, t_cmd *cmd,
								t_option *option);
char				*translate_move(t_stacks *stacks);
char				*inverse_move(t_stacks *stacks);
int					is_ordered(t_stack *head, t_stack *stop);
void				write_cmd(t_cmd *cmd_head, t_option *option);
int					get_proper_interval(t_stack *b, int n);

/*
**checker only functions
*/

t_cmd				*get_commands(t_cmd *cmd, t_option *option,
								t_stacks *stacks);
t_stacks			make_cmd(t_stacks *stacks, t_cmd *cmd, t_option *option);
int					check_stack_free(t_stacks *stacks);
void				error(int error, t_stacks *stacks, t_stack *head_stack,
					t_option *option);
#endif
