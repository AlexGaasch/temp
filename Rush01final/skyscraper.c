/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaasch <agaasch@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:48:15 by agaasch           #+#    #+#             */
/*   Updated: 2025/05/11 17:48:16 by agaasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		is_valid_placement(int board[4][4], int row, int col, int height);
int		count_visible(int *line);
int		check_views(int board[4][4], int *views);

/* Prints the whole board */
void	print_board(int board[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = board[i][j] + '0';
			write(1, &c, 1);
			if (j != 3) //to add a space after each digit except for the last digit of a line
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	solve_puzzle(int board[4][4], int *views, int pos)
{
	int	row;
	int	col;
	int	height;
	/* checks if the board is valid after putting 16 numbers */
	if (pos == 16)
		return (check_views(board, views));
	/*  */
	row = pos / 4;
	col = pos % 4;
	if (board[row][col] != 0)
	/*  */
		return (solve_puzzle(board, views, pos + 1));
	height = 0;
	/* height represents the input it will put in the board next (or first)*/
	while (++height <= 4) // loops from 1 to 4 (increments before checking the condition)
	{
		/* if it is possible to put height(the input) in that cell, places it there abnd increases the pos (amount placed) by one */
		if (is_valid_placement(board, row, col, height))
		{
			board[row][col] = height;
			/* You place the next input (recursivly), and if its valid in the end, returns 1*/
			if (solve_puzzle(board, views, pos + 1))
				return (1);
			/* If it was not valid, reset the grid to 0*/
			board[row][col] = 0;
		}
	}
	return (0);
}
/* Checks all conditions for the input */
int	parse_input(char *str, int *views)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	/* Only accepts 16 digits, so stops after 16 */
	while (str[i] && count < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
			views[count++] = str[i] - '0';
		i++;
	}
	/* If the string is longer than it should be, prints Error */
	if (str[i])
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

/* Sets the puzzle to 0 in every cell */
void	reset_puzzle(int grid[4][4])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
/* Where the magic happens */
int	main(int argc, char **argv)
{
	int	board[4][4];
	int	views[16];

	/* sets the board to 0 */
	reset_puzzle(board);
	/* If you input more than 1 string, prints an Error */
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	/* If the input wasn't parsed correctly (wrong input) */
	if (!parse_input(argv[1], views))
		return (0);
	/* Starts the backtracking, and stops once it found a valid solution, and prints it */
	if (solve_puzzle(board, views, 0))
		print_board(board);
	/* Else prints Error */
	else
		write(1, "Error\n", 6);
	return (0);
}
