/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:51:44 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/28 20:15:59 by ncolliau         ###   ########.fr       */
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

	getmaxyx(stdscr, lines, columns);
	if (lines < 20 || columns < 40)
	{
		endwin();
		write(2, "Window too small\n", 17);
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
