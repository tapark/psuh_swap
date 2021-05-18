/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:40:11 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 17:02:59 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_two_b(t_stack **b, t_op **op)
{
	if ((*b)->n < (*b)->next->n)
		get_operation_list(op, "sb", NULL, b);
}

void	case_three_b(t_stack **b, t_op **op, int len)
{
	int min;

	min = get_min_value(b, len);
	min = get_value_index(b, min);
	if (min == 1)
	{
		get_operation_list(op, "rb", NULL, b);
		case_two_b(b, op);
	}
	else if (min == 2)
	{
		get_operation_list(op, "rrb", NULL, b);
		case_two_b(b, op);
	}
	else if (min == 3)
		case_two_b(b, op);
}

int		sort_just_three_b(t_stack **a, t_stack **b, t_op **op)
{
	int len;

	len = get_num_of_stack_node(b);
	if (len == 1)
		get_operation_list(op, "pa", a, b);
	else if (len == 2)
		case_two_b(b, op);
	else if (len == 3)
		case_three_b(b, op, len);
	return (0);
}
