/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:59 by tapark            #+#    #+#             */
/*   Updated: 2021/05/18 13:37:54 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_op	*op;
	int		len;

	a = NULL;
	b = NULL;
	op = NULL;
	if (check_argv_to_stack(&a, argc, argv))
		return (write_error());
	len = get_num_of_stack_node(&a);
	if (sorted_check_a(&a, len))
		return (0);
	if (len <= 3)
		sort_just_three_a(&a, &op);
	else if (len <= 6)
		sort_just_six(&a, &b, &op, len);
	else
		sort_main_a(&a, &b, &op, len);
	minimize_operation_list(&op);
	print_operation_list(&op);
	free_stack(&a);
	free_operation(&op);
	return (0);
}
