/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:51:44 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/01 16:54:11 by ncolliau         ###   ########.fr       */
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
	border('|', '|', '-', '-', '+', '+', '+', '+');
	mvvline(1, columns / 4, '|', lines - 2);
	mvvline(1, (2 * columns) / 4, '|', lines - 2);
	mvvline(1, (3 * columns) / 4, '|', lines - 2);
	mvhline(lines / 4, 1, '-', columns - 2);
	mvhline((2 * lines) / 4, 1, '-', columns - 2);
	mvhline((3 * lines) / 4, 1, '-', columns - 2);
	print_map(lines, columns, map);
	refresh();
	return (1);
}
