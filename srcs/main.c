/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:05:47 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/28 20:11:34 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		rand_a_b(int a, int b)
{
	int		ret;

	ret = rand();
	ret = ret % (b - a);
	ret += a;
	return (ret);
}

static t_case	**add_random_num(t_case **map)
{
	int		pos;
	int		new_num;

	while (map[pos / 4][pos % 4].val != 0)
		pos = rand_a_b(0, 16);
	new_num = rand_a_b(1, 5);
	new_num = (new_num != 4) ? 2 : 4;
	map[pos / 4][pos % 4].val = new_num;
	return (map);
}

static t_case	**init_map(void)
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

static int		key_handle(int key, t_case **map)
{
	if (key == 260 || key == 261 || key == 258 || key == 259)
	{
		if (key == 260)
			map = move_left(map);
		if (key == 261)
			map = move_right(map);
		if (key == 258)
			map = move_down(map);
		if (key == 259)
			map = move_up(map);
		map = check_win_loss(map);
		if (map == NULL)
			return (0);
		map = add_random_num(map);
	}
	if (key == 260 || key == 261 || key == 258 || key == 259
		|| key == 410 || key == -1)
	{
		endwin();
		refresh();
		clear();
		if (refresh_map(map) == 0)
			return (0);
	}
	return (1);
}

int				main(void)
{
	int		key;
	t_case	**map;

	map = init_map();
	initscr();
	if (refresh_map(map) == 0)
		return (0);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	while (1)
	{
		key = getch();
		if (key == 27)
		{
			endwin();
			return (0);
		}
		if (key_handle(key, map) == 0)
			return (0);
	}
	endwin();
	return (0);
}
