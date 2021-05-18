/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_in_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:46 by tapark            #+#    #+#             */
/*   Updated: 2021/05/18 12:57:53 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		*get_stack_array(t_stack **head, int num)
{
	int		i;
	int		*sort;
	t_stack *count;

	if (!(sort = (int *)malloc(sizeof(int) * num)))
		return (NULL);
	i = 0;
	count = (*head);
	while (i < num)
	{
		sort[i] = count->n;
		count = count->next;
		i++;
	}
	return (sort);
}

int		get_mid_value(t_stack **head, int len)
{
	int *sort;
	int mid_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	mid_value = sort[len / 2];
	free(sort);
	return (mid_value);
}

int		get_min_value(t_stack **head, int len)
{
	int *sort;
	int min_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	min_value = sort[0];
	free(sort);
	return (min_value);
}

int		get_max_value(t_stack **head, int len)
{
	int *sort;
	int max_value;

	sort = get_stack_array(head, len);
	quick_sort(sort, 0, len - 1);
	max_value = sort[len - 1];
	free(sort);
	return (max_value);
}

int		get_value_index(t_stack **head, int value)
{
	int		index;
	t_stack *count;

	index = 1;
	count = (*head);
	while (count != NULL)
	{
		if (count->n == value)
			return (index);
		count = count->next;
		index++;
	}
	return (0);
}
