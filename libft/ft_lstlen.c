/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:51:34 by ncolliau          #+#    #+#             */
/*   Updated: 2015/01/04 15:55:15 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *p_list)
{
	size_t	i;

	i = 0;
	while (p_list)
	{
		i++;
		p_list = p_list->next;
	}
	return (i);
}