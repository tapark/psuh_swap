/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_just_three_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:40:08 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 15:42:24 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_two_a(t_stack **a, t_op **op)
{
	if ((*a)->n > (*a)->next->n)
		get_operation_list(op, "sa", a, NULL);
}

void	case_three_a(t_stack **a, t_op **op, int len)
{
	int max;

	max = get_max_value(a, len);
	max = get_value_index(a, max);
	if (max == 1)
	{
		get_operation_list(op, "ra", a, NULL);
		case_two_a(a, op);
	}
	else if (max == 2)
	{
		get_operation_list(op, "rra", a, NULL);
		case_two_a(a, op);
	}
	else if (max == 3)
		case_two_a(a, op);
}

int		sort_just_three_a(t_stack **a, t_op **op)
{
	int len;

	len = get_num_of_stack_node(a);
	if (len == 2)
		case_two_a(a, op);
	else if (len == 3)
		case_three_a(a, op, len);
	return (0);
}
