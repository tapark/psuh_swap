/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:52 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 15:42:24 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack_node(t_stack **head)
{
	int temp;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		temp = (*head)->n;
		(*head)->n = (*head)->next->n;
		(*head)->next->n = temp;
	}
}

void	move_stack_node(t_stack **dest, t_stack **src)
{
	t_stack *temp;

	if ((*src) != NULL)
	{
		temp = (*src)->next;
		add_stack_node_front(dest, *src);
		(*src) = temp;
	}
}

void	top_stack_node_to_bot(t_stack **head)
{
	t_stack *temp;

	if ((*head) != NULL && (*head)->next != NULL)
	{
		temp = (*head);
		(*head) = (*head)->next;
		temp->next = NULL;
		add_stack_node_back(head, temp);
	}
}

void	bot_stack_node_to_top(t_stack **head)
{
	t_stack *temp;
	t_stack *last;

	temp = (*head);
	if ((*head) != NULL && (*head)->next != NULL)
	{
		while (temp->next->next != NULL)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		add_stack_node_front(head, last);
	}
}
