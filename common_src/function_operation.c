/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:37 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 15:42:24 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_op	*create_op_list_node(char *s)
{
	t_op *node;

	node = (t_op *)malloc(sizeof(t_op));
	node->s = ft_strdup(s);
	node->next = NULL;
	return (node);
}

void	add_op_list_front(t_op **head, t_op *node)
{
	node->next = (*head);
	(*head) = node;
}

void	add_op_list_back(t_op **head, t_op *node)
{
	t_op *index;

	index = (*head);
	if (index == NULL)
		(*head) = node;
	else
	{
		while (index->next != NULL)
			index = index->next;
		index->next = node;
	}
}

void	add_op_list_middle(t_op **head, t_op *node, int n)
{
	t_op *index;
	t_op *temp;

	index = (*head);
	if (n == 1)
	{
		add_op_list_front(head, node);
		return ;
	}
	n = n - 2;
	while (n--)
		index = index->next;
	temp = index->next;
	index->next = node;
	node->next = temp;
}

void	del_op_list(t_op **head, int n)
{
	t_op *index;
	t_op *temp;

	index = (*head);
	if (n == 1)
	{
		(*head) = (*head)->next;
		free(index->s);
		free(index);
		return ;
	}
	n = n - 2;
	while (n--)
		index = index->next;
	temp = index->next;
	index->next = temp->next;
	free(temp->s);
	free(temp);
}
