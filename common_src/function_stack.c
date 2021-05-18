/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:39 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 15:42:24 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack_node(int n)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->n = n;
	node->next = NULL;
	return (node);
}

int		get_num_of_stack_node(t_stack **head)
{
	t_stack	*index;
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

void	add_stack_node_front(t_stack **head, t_stack *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_stack_node_back(t_stack **head, t_stack *node)
{
	t_stack *index;

	index = (*head);
	if ((*head) == NULL)
		(*head) = node;
	else
	{
		while (index->next != NULL)
			index = index->next;
		index->next = node;
	}
}
