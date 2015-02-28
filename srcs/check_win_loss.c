/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_loss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:54:28 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/28 20:16:24 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	win_value(void)
{
	int		nb;

	if (WIN_VALUE < 2)
		return (2048);
	nb = 2;
	while (nb < WIN_VALUE)
		nb *= 2;
	if (nb != WIN_VALUE)
		return (2048);
	return (WIN_VALUE);
}

static void	print_win(void)
{
	int		lines;
	int		columns;

	getmaxyx(stdscr, lines, columns);
	mvprintw(lines / 2 + 1, columns / 2 + 1, "You win !");
}

t_case		**check_win_loss(t_case **map)
{
	int		i;
	int		j;
	int		verif;

	verif = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j != 4)
		{
			if (map[i][j].val == 0)
				verif = 1;
			if (map[i][j].val >= win_value())
				print_win();
			map[i][j].fusion = NO;
		}
	}
	if (verif == 0)
	{
		endwin();
		write(1, "You loose !\n", 12);
		return (NULL);
	}
	return (map);
}
