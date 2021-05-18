/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:40:32 by tapark            #+#    #+#             */
/*   Updated: 2021/05/18 12:27:12 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		sorted_check_a(t_stack **a, int len)
{
	t_stack	*index;
	int		low;
	int		i;

	index = (*a)->next;
	low = (*a)->n;
	i = 0;
	if (index == NULL)
		return (1);
	while (index != NULL && i < len)
	{
		if (low < index->n)
			low = index->n;
		else
			return (0);
		index = index->next;
		i++;
	}
	return (1);
}

int		sorted_check_b(t_stack **b, int len)
{
	t_stack *index;
	int		high;
	int		i;

	index = (*b)->next;
	high = (*b)->n;
	i = 0;
	if (index == NULL)
		return (1);
	while (index != NULL && i < len)
	{
		if (high > index->n)
			high = index->n;
		else
			return (0);
		index = index->next;
		i++;
	}
	return (1);
}
