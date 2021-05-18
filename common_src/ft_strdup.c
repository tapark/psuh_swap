/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapark <tapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:39:30 by tapark            #+#    #+#             */
/*   Updated: 2021/05/16 15:42:24 by tapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = ft_strlen(s);
	if (!(dest = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
