/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:22:22 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/28 17:34:55 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		it_is_ok(t_case **map, int i, int j)
{
	if (j == 3)
		return (0);
	if (map[i][j + 1].val == 0)
		return (1);
	if (map[i][j + 1].val == map[i][j].val)
		if (map[i][j].fusion == NO && map[i][j + 1].fusion == NO)
			return (1);
	return (0);
}

static t_case	**do_move(t_case **map, int i, int j)
{
	while (it_is_ok(map, i, j))
	{
		if (map[i][j + 1].val == 0)
		{
			map[i][j + 1].val = map[i][j].val;
			map[i][j].val = 0;
		}
		else
		{
			map[i][j + 1].val *= 2;
			map[i][j].val = 0;
			map[i][j + 1].fusion = YES;
		}
		j++;
	}
	return (map);
}

t_case			**move_right(t_case **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 2;
		while (j != -1)
		{
			map = do_move(map, i, j);
			j--;
		}
		i++;
	}
	return (map);
}
