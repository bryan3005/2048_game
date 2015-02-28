/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:05:47 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/28 13:55:32 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		refresh_window(int **map)
{
	int lines;
	int columns;

	getmaxyx(stdscr, lines, columns);
	if (lines < 20 || columns < 40)
		return (0);
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

int		key_handle(int key, int **map)
{
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

#include <fcntl.h>

int		main(void)
{
	int 	key;
	int		**map;
	int		fd;

	fd = open("key_log", O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd == -1)
	{
		ft_putendl_fd("open failed", 2);
		return (0);
	}
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
		ft_putnbr_nl_fd(key, fd);
		if (key == 27)
		{
			endwin();
			return (0);
		}
		if (key_handle(key, map) == 0)
		{
			endwin();
			ft_putendl_fd("Window too small", 2);
			return (0);
		}
	}
	endwin();
	return (0);
}
