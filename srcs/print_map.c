/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:51:44 by ncolliau          #+#    #+#             */
/*   Updated: 2015/05/25 13:39:23 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	pos(int lines, int i)
{
	int		ret;

	ret = ((i * lines) / 4) + (lines / 8);
	return (ret);
}

static void	print_map(int line, int column, t_case **map)
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
				mvprintw(pos(line, i), pos(column, j), "%d", map[i][j].val);
			j++;
		}
		i++;
	}
}

int			refresh_map(t_case **map)
{
	int lines;
	int columns;

	clear();
	getmaxyx(stdscr, lines, columns);
	if (lines < 20 || columns < 40)
	{
		endwin();
		write(2, "Window too small\n", 17);
		return (0);
	}
	if (has_colors() == FALSE)
	{
		endwin();
		write(1, "Your terminal does not support color\n", 37);
		return (0);
	}
	start_color();
	init_color(COLOR_WHITE, 933, 894, 855);
	init_color(COLOR_GREEN, 467, 431, 396);
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	wbkgd(stdscr, COLOR_PAIR(1));
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	attron(COLOR_PAIR(2));
	border(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	mvvline(1, columns / 4, ' ', lines - 2);
	mvvline(1, (2 * columns) / 4, ' ', lines - 2);
	mvvline(1, (3 * columns) / 4, ' ', lines - 2);
	mvhline(lines / 4, 1, ' ', columns - 2);
	mvhline((2 * lines) / 4, 1, ' ', columns - 2);
	mvhline((3 * lines) / 4, 1, ' ', columns - 2);
	attroff(COLOR_PAIR(2));
	print_map(lines, columns, map);
	refresh();
	return (1);
}
