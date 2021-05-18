/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:37:19 by tapark            #+#    #+#             */
/*   Updated: 2021/05/18 13:40:10 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_op
{
	char			*s;
	struct s_op		*next;
}					t_op;

int					ft_strlen(char *s);
char				*ft_strdup(char *s);
int					ft_strcmp(char *s1, char *s2);
long long			ft_atoi(const char *str);
int					get_next_line(char **line);

int					check_argv_to_stack(t_stack **a, int argc, char **argv);
int					write_error(void);

void				quick_sort(int *sort, int start, int end);

int					get_mid_value(t_stack **head, int len);
int					get_min_value(t_stack **head, int len);
int					get_max_value(t_stack **head, int len);
int					get_value_index(t_stack **head, int value);

t_stack				*create_stack_node(int n);
int					get_num_of_stack_node(t_stack **head);
void				get_operation_list
					(t_op **op, char *s, t_stack **a, t_stack **b);

t_op				*create_op_list_node(char *s);
void				add_op_list_front(t_op **head, t_op *node);
void				add_op_list_back(t_op **head, t_op *node);
void				add_op_list_middle(t_op **head, t_op *node, int n);
void				del_op_list(t_op **head, int n);
void				minimize_operation_list(t_op **op);

void				add_stack_node_front(t_stack **head, t_stack *node);
void				add_stack_node_back(t_stack **head, t_stack *node);
void				swap_stack_node(t_stack **head);
void				move_stack_node(t_stack **dest, t_stack **src);
void				top_stack_node_to_bot(t_stack **head);
void				bot_stack_node_to_top(t_stack **head);

int					sort_just_three_a(t_stack **a, t_op **op);
int					sort_just_three_b(t_stack **a, t_stack **b, t_op **op);
int					sort_just_six
					(t_stack **a, t_stack **b, t_op **op, int len);
int					sort_less_than_three_a
					(t_stack **a, t_stack **b, t_op **op, int len);
int					sort_less_than_three_b
					(t_stack **a, t_stack **b, t_op **op, int len);

int					sorted_check_a(t_stack **a, int len);
int					sorted_check_b(t_stack **b, int len);

void				sort_main_a(t_stack **a, t_stack **b, t_op **op, int len);
void				sort_main_b(t_stack **a, t_stack **b, t_op **op, int len);

void				print_stack_ab(t_stack **a, t_stack **b);
void				print_operation_list(t_op **head);

void				free_stack(t_stack **a);
void				free_operation(t_op **op);

#endif
