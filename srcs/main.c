/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:05:47 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/28 11:39:11 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"

void windo_start(void)
{
	int row;
	int col;

	initscr();
	getmaxyx(stdscr, row, col);
	mvhline(0, 0, '-', col);
	mvvline(0, 0, '+', row);
	mvvline(0, col / 4, '+', row);
	mvvline(0, (2 * col) / 4, '+', row);
	mvvline(0, (3 * col) / 4, '+', row);
	mvvline(0, col - 1, '+', row);
	mvhline(row / 4, 0, '-', col);
	mvhline((2 * row) / 4, 0, '-', col);
	mvhline((3 * row) / 4, 0, '-', col);
	mvhline(row - 1, 0, '-', col);
	mvprintw((row / 4) / 2, (col / 4) / 2, "1");
	raw();
	keypad(stdscr, TRUE);
	noecho();
}

void handle_winch(int sig)
{
    endwin();
    // Needs to be called after an endwin() so ncurses will initialize
    // itself with the new terminal dimensions.
    int row;
	int col;
	(void)sig;
    refresh();
    clear();
    getmaxyx(stdscr, row, col);
	mvhline(0, 0, '-', col);
	mvvline(0, 0, '+', row);
	mvvline(0, col / 4, '+', row);
	mvvline(0, (2 * col) / 4, '+', row);
	mvvline(0, (3 * col) / 4, '+', row);
	mvvline(0, col - 1, '+', row);
	mvhline(row / 4, 0, '-', col);
	mvhline((2 * row) / 4, 0, '-', col);
	mvhline((3 * row) / 4, 0, '-', col);
	mvhline(row - 1, 0, '-', col);
	mvprintw((row / 4) / 2, (col / 4) / 2, "1");
    refresh();
}

int main(int argc, char **argv)
{
	
	int key;

	(void)argc;
	(void)argv;
	windo_start();
//	printw("%d\n",key = getch() );
	while ((key = getch()) != 27)
		handle_winch(key);
	endwin();
	return (0);
}
