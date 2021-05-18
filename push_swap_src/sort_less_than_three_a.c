/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_three_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:40:13 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 17:24:44 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_less_than_two_a(t_stack **a, t_op **op)
{
	if ((*a)->n > (*a)->next->n)
		get_operation_list(op, "sa", a, NULL);
}

void	max_is_two_a(t_stack **a, t_stack **b, t_op **op)
{
	get_operation_list(op, "ra", a, b);
	get_operation_list(op, "sa", a, b);
	get_operation_list(op, "rra", a, b);
	sort_less_than_two_a(a, op);
}

int		sort_less_than_three_a(t_stack **a, t_stack **b, t_op **op, int len)
{
	int max;

	if (len == 2)
		sort_less_than_two_a(a, op);
	else if (len == 3)
	{
		max = get_max_value(a, len);
		max = get_value_index(a, max);
		if (max == 3)
			sort_less_than_two_a(a, op);
		else if (max == 2)
			max_is_two_a(a, b, op);
		else
		{
			get_operation_list(op, "sa", a, b);
			max_is_two_a(a, b, op);
		}
	}
	return (1);
}
