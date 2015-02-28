/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:47:20 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/28 20:07:18 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		it_is_ok(t_case **map, int i, int j)
{
	if (i == 0)
		return (0);
	if (map[i - 1][j].val == 0)
		return (1);
	if (map[i - 1][j].val == map[i][j].val)
		if (map[i][j].fusion == NO && map[i - 1][j].fusion == NO)
			return (1);
	return (0);
}

static t_case	**do_move(t_case **map, int i, int j)
{
	while (it_is_ok(map, i, j))
	{
		if (map[i - 1][j].val == 0)
		{
			map[i - 1][j].val = map[i][j].val;
			map[i][j].val = 0;
		}
		else
		{
			map[i - 1][j].val *= 2;
			map[i][j].val = 0;
			map[i - 1][j].fusion = YES;
		}
		i--;
	}
	return (map);
}

t_case			**move_up(t_case **map)
{
	int		i;
	int		j;

	j = 0;
	while (map[j])
	{
		i = 1;
		while (i != 4)
		{
			map = do_move(map, i, j);
			i++;
		}
		j++;
	}
	return (map);
}
