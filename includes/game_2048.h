/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 13:59:47 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/28 20:15:30 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <unistd.h>
# include <stdlib.h>
# include <ncurses.h>
# include <time.h>

enum	e_const
{
	WIN_VALUE = 2048
};

enum	e_fus
{
	YES, NO
};

typedef struct	s_case
{
	int			val;
	enum e_fus	fusion;
}				t_case;

t_case			**move_right(t_case **map);
t_case			**move_left(t_case **map);
t_case			**move_down(t_case **map);
t_case			**move_up(t_case **map);

int				refresh_map(t_case **map);

t_case			**check_win_loss(t_case **map);

#endif
