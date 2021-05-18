/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:40:29 by tapark            #+#    #+#             */
/*   Updated: 2021/05/18 13:16:00 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		return_case_b(t_stack **a, t_stack **b, t_op **op, int len)
{
	int i;

	i = 0;
	if (sorted_check_b(b, len))
	{
		while (len--)
			get_operation_list(op, "pa", a, b);
		return (1);
	}
	if (len <= 3)
	{
		if (len == get_num_of_stack_node(b))
			sort_just_three_b(a, b, op);
		else
			sort_less_than_three_b(a, b, op, len);
		while (i++ < len)
			get_operation_list(op, "pa", a, b);
		return (1);
	}
	return (0);
}

void	sort_main_b(t_stack **a, t_stack **b, t_op **op, int len)
{
	int mid;
	int push;
	int rotate;
	int i;

	mid = get_mid_value(b, len);
	push = 0;
	rotate = 0;
	i = 0;
	if (return_case_b(a, b, op, len))
		return ;
	while (i++ < len)
	{
		if ((*b)->n >= mid && ++push)
			get_operation_list(op, "pa", a, b);
		else if ((*b)->n < mid && ++rotate)
			get_operation_list(op, "rb", a, b);
	}
	while (rotate--)
		get_operation_list(op, "rrb", a, b);
	sort_main_a(a, b, op, push);
	sort_main_b(a, b, op, len - push);
}
