/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:44 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 15:42:24 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_operation_list(t_op **op, char *s, t_stack **a, t_stack **b)
{
	t_op *new;

	new = create_op_list_node(s);
	add_op_list_back(op, new);
	if (s[0] == 'p' && s[1] == 'a')
		move_stack_node(a, b);
	if (s[0] == 'p' && s[1] == 'b')
		move_stack_node(b, a);
	if (s[0] == 's' && s[1] == 'a')
		swap_stack_node(a);
	if (s[0] == 's' && s[1] == 'b')
		swap_stack_node(b);
	if (s[0] == 'r' && s[1] == 'a')
		top_stack_node_to_bot(a);
	if (s[0] == 'r' && s[1] == 'b')
		top_stack_node_to_bot(b);
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		bot_stack_node_to_top(a);
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		bot_stack_node_to_top(b);
}
