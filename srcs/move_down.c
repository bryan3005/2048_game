/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:29:13 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/28 15:59:54 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	it_is_ok(t_case **map, int i, int j)
{
	if (i == 3)
		return (0);
	if (map[i + 1][j].val == 0)
		return (1);
	if (map[i + 1][j].val == map[i][j].val)
		if (map[i][j].fusion == NO && map[i + 1][j].fusion == NO)
			return (1);
	return (0);
}

t_case		**move_down(t_case **map)
{
	int		i;
	int		j;
	int		mem_i;

	j = 0;
	while (map[j])
	{
		i = 2;
		while (i != -1)
		{
			mem_i = i;
			while (it_is_ok(map, i, j))
			{
				if (map[i + 1][j].val == 0)
				{
					map[i + 1][j].val = map[i][j].val;
					map[i][j].val = 0;
				}
				else
				{
					map[i + 1][j].val *= 2;
					map[i][j].val = 0;
					map[i + 1][j].fusion = YES;
				}
				i++;
			}
			i = mem_i - 1;
		}
		j++;
	}
	return (map);
}
