/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:40:04 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 15:42:24 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		get_partition(int *sort, int start, int end)
{
	int pivot;
	int i;
	int index;
	int temp;

	pivot = sort[end];
	index = start;
	i = start;
	while (i < end)
	{
		if (sort[i] <= pivot)
		{
			temp = sort[i];
			sort[i] = sort[index];
			sort[index] = temp;
			index++;
		}
		i++;
	}
	temp = sort[index];
	sort[index] = sort[end];
	sort[end] = temp;
	return (index);
}

void	quick_sort(int *sort, int start, int end)
{
	int index;

	if (start < end)
	{
		index = get_partition(sort, start, end);
		quick_sort(sort, start, index - 1);
		quick_sort(sort, index + 1, end);
	}
}
