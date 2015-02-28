/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:05:47 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/28 16:54:30 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		refresh_window(t_case **map)
{
	int lines;
	int columns;

	getmaxyx(stdscr, lines, columns);
	if (lines < 20 || columns < 40)
	{
		endwin();
		ft_putendl_fd("Window too small", 2);
		return (0);
	}
	mvhline(0, 0, '-', columns);
	mvvline(0, 0, '+', lines);
	mvvline(0, columns / 4, '+', lines);
	mvvline(0, (2 * columns) / 4, '+', lines);
	mvvline(0, (3 * columns) / 4, '+', lines);
	mvvline(0, columns - 1, '+', lines);
	mvhline(lines / 4, 0, '-', columns);
	mvhline((2 * lines) / 4, 0, '-', columns);
	mvhline((3 * lines) / 4, 0, '-', columns);
	mvhline(lines - 1, 0, '-', columns);
	print_map(lines, columns, map);
    refresh();
	curs_set(0);
	return (1);
}

t_case	**add_random_num(t_case **map)
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

t_case	**reset_fusion(t_case **map)
{
	int		i;
	int		j;
	int		verif;
	int		lines;
	int		columns;

	verif = 0;
	i = 0;
	getmaxyx(stdscr, lines, columns);
	while (map[i])
	{
		j = 0;
		while (j != 4)
		{
			if (map[i][j].val == 0)
				verif = 1;
			if (map[i][j].val >= WIN_VALUE)				
				mvprintw(lines / 2 + 1, columns / 2 + 1, "You win !");
			map[i][j].fusion = NO;
			j++;
		}
		i++;
	}
	if (verif == 0)
	{
		endwin();
		ft_putendl("You loose !");
		return (NULL);
	}
	return (map);
}

int		key_handle(int key, t_case **map)
{
	if (key == 260 || key == 261 || key == 258 || key == 259)
	{
		endwin();
		refresh();
		clear();
		if (key == 260)
			map = move_left(map);
		if (key == 261)
			map = move_right(map);
		if (key == 258)
			map = move_down(map);
		if (key == 259)
			map = move_up(map);
		map = reset_fusion(map);
		if (map == NULL)
			return (0);
		map = add_random_num(map);
		if (refresh_window(map) == 0)
			return (0);
	}
	if (key == 410 || key == -1)
	{
		endwin();
		refresh();
		clear();
		if (refresh_window(map) == 0)
			return (0);
	}
	return (1);
}

int		main(void)
{
	int 	key;
	t_case	**map;

	map = init_map();
	initscr();
	if (refresh_window(map) == 0)
	{
		endwin();
		ft_putendl_fd("Window too small", 2);
		return (0);
	}
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
