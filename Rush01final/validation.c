/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaasch <agaasch@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:05:16 by agaasch           #+#    #+#             */
/*   Updated: 2025/05/11 18:05:17 by agaasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int *line);
int	check_column_up(int board[4][4], int *views, int col);
int	check_column_down(int board[4][4], int *views, int col);
int	check_row_left(int board[4][4], int *views, int row);
int	check_row_right(int board[4][4], int *views, int row);

/* Checks if you can actually put the number in the cell. Returns 0 if the digit is already present in the row or col */
int	is_valid_placement(int board[4][4], int row, int col, int height)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (board[row][i] == height || board[i][col] == height)
			return (0);
		i++;
	}
	return (1);
}
/* Checks the views in all different directions */
int	check_views(int board[4][4], int *views)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!check_column_up(board, views, i)
			|| !check_column_down(board, views, i)
			|| !check_row_left(board, views, i)
			|| !check_row_right(board, views, i))
			return (0);
	}
	return (1);
}
