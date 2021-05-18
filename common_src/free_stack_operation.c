/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:19 by tapark            #+#    #+#             */
/*   Updated: 2021/05/18 13:25:29 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack *index;
	t_stack *temp;

	index = (*a);
	while (index != NULL)
	{
		temp = index;
		index = index->next;
		free(temp);
	}
	(*a) = NULL;
}

void	free_operation(t_op **op)
{
	t_op *index;
	t_op *temp;

	index = (*op);
	while (index != NULL)
	{
		temp = index;
		index = index->next;
		free(temp->s);
		free(temp);
	}
	(*op) = NULL;
}
