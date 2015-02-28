/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:54:28 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/28 16:54:59 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		compute(int lines, int i)
{
	int		ret;

	ret = ((i * lines) / 4) + (lines / 8);
	return (ret);
}

void	print_map(int lines, int columns, t_case **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j != 4)
		{
			if (map[i][j].val != 0)
				mvprintw(compute(lines, i), compute(columns, j), "%d", map[i][j].val);
			j++;
		}
		i++;
	}
}

int		rand_a_b(int a, int b)
{
	int		ret;

	ret = rand();
	ret = ret % (b - a);
	ret += a;
	return (ret);
}

t_case	**init_map(void)
{
	t_case	**map;
	int		i;
	int		j;
	int		pos;

	map = (t_case **)malloc(5 * sizeof(t_case *));
	map[4] = NULL;
	i = 0;
	while (i != 4)
	{
		map[i] = (t_case *)malloc(4 * sizeof(t_case));
		j = 0;
		while (j != 4)
		{
			map[i][j].val = 0;
			map[i][j].fusion = NO;
			j++;
		}
		i++;
	}
	srand(time(NULL));
	pos = rand_a_b(0, 16);
	map[pos / 4][pos % 4].val = 2;
	map = add_random_num(map);
	return (map);
}
