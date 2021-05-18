/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:54 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 16:28:14 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		get_num_of_op_list_node(t_op **head)
{
	t_op	*index;
	int		num;

	index = (*head);
	num = 0;
	if (index == NULL)
		return (0);
	while (index != NULL)
	{
		index = index->next;
		num++;
	}
	return (num);
}

void	print_operation_list(t_op **head)
{
	t_op *index;

	index = (*head);
	while (index != NULL)
	{
		if (index->s != NULL)
		{
			write(1, index->s, ft_strlen(index->s));
			write(1, "\n", 1);
		}
		index = index->next;
	}
}
