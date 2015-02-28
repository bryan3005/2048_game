/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:54:28 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/28 13:55:49 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		compute(int lines, int i)
{
	int		ret;

	ret = lines - ((i * lines) / 4) - (lines / 8);
	return (ret);
}

void	print_map(int lines, int columns, int **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (j != 4)
		{
			if (map[i][j] != 0)
				mvprintw(compute(lines, i), compute(columns, j), "%d", map[i][j]);
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

int		**init_map(void)
{
	int		**map;
	int		i;
	int		pos;

	map = (int **)malloc(5 * sizeof(int *));
	map[4] = NULL;
	i = 0;
	while (i != 4)
	{
		map[i] = (int *)malloc(4 * sizeof(int));
		map[i][0] = 0;
		map[i][1] = 0;
		map[i][2] = 0;
		map[i][3] = 0;
		i++;
	}
	srand(time(NULL));
	pos = rand_a_b(0, 16);
	map[pos / 4][pos % 4] = 2;
	while (map[pos / 4][pos % 4] == 2)
		pos = rand_a_b(0, 16);
	map[pos / 4][pos % 4] = 2;
	return (map);
}
