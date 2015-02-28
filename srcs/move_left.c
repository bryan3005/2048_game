/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:20:03 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/28 16:00:16 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		it_is_ok(t_case **map, int i, int j)
{
	if (j == 0)
		return (0);
	if (map[i][j - 1].val == 0)
		return (1);
	if (map[i][j - 1].val == map[i][j].val)
		if (map[i][j].fusion == NO && map[i][j - 1].fusion == NO)
			return (1);
	return (0);
}

t_case	**move_left(t_case **map)
{
	int		i;
	int		j;
	int		mem_j;

	i = 0;
	while (map[i])
	{
		j = 1;
		while (j != 4)
		{
			mem_j = j;
			while (it_is_ok(map, i, j))
			{
				if (map[i][j - 1].val == 0)
				{
					map[i][j - 1].val = map[i][j].val;
					map[i][j].val = 0;
				}
				else
				{
					map[i][j - 1].val *= 2;
					map[i][j].val = 0;
					map[i][j - 1].fusion = YES;
				}
				j--;
			}
			j = mem_j + 1;
		}
		i++;
	}
	return (map);
}
