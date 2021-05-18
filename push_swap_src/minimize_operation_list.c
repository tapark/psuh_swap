/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_operation_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:49 by tapark            #+#    #+#             */
/*   Updated: 2021/05/18 13:03:38 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		get_merge_case(t_op *i)
{
	if (ft_strcmp(i->s, "ra") && ft_strcmp(i->next->s, "rb"))
		return (1);
	if (ft_strcmp(i->s, "rb") && ft_strcmp(i->next->s, "ra"))
		return (1);
	if (ft_strcmp(i->s, "rra") && ft_strcmp(i->next->s, "rrb"))
		return (2);
	if (ft_strcmp(i->s, "rrb") && ft_strcmp(i->next->s, "rra"))
		return (2);
	return (0);
}

int		get_delete_case(t_op *i)
{
	if (ft_strcmp(i->s, "pa") && ft_strcmp(i->next->s, "pb"))
		return (1);
	if (ft_strcmp(i->s, "pb") && ft_strcmp(i->next->s, "pa"))
		return (1);
	if (ft_strcmp(i->s, "ra") && ft_strcmp(i->next->s, "rra"))
		return (1);
	if (ft_strcmp(i->s, "rra") && ft_strcmp(i->next->s, "ra"))
		return (1);
	if (ft_strcmp(i->s, "rb") && ft_strcmp(i->next->s, "rrb"))
		return (1);
	if (ft_strcmp(i->s, "rrb") && ft_strcmp(i->next->s, "rb"))
		return (1);
	if (ft_strcmp(i->s, "sa") && ft_strcmp(i->next->s, "sa"))
		return (1);
	if (ft_strcmp(i->s, "sb") && ft_strcmp(i->next->s, "sb"))
		return (1);
	return (0);
}

int		get_merge_operation(t_op **op)
{
	t_op	*i;
	t_op	*new;
	int		index;
	int		merge;

	i = (*op);
	index = 1;
	while (i->next != NULL)
	{
		if ((merge = get_merge_case(i)))
		{
			del_op_list(op, index);
			del_op_list(op, index);
			if (merge == 1)
				new = create_op_list_node("rr");
			if (merge == 2)
				new = create_op_list_node("rrr");
			add_op_list_middle(op, new, index);
			return (1);
		}
		else
			i = i->next;
		index++;
	}
	return (0);
}

int		get_delete_operation(t_op **op)
{
	t_op	*i;
	int		index;

	i = (*op);
	index = 1;
	while (i->next != NULL)
	{
		if (get_delete_case(i))
		{
			i = i->next->next;
			del_op_list(op, index);
			del_op_list(op, index);
			return (1);
		}
		else
		{
			i = i->next;
			index++;
		}
	}
	return (0);
}

void	minimize_operation_list(t_op **op)
{
	while (get_merge_operation(op))
		;
	while (get_delete_operation(op))
		;
}
