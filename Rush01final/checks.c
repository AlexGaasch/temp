/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaasch <agaasch@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:45:06 by agaasch           #+#    #+#             */
/*   Updated: 2025/05/11 17:45:41 by agaasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int *line)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_column_up(int board[4][4], int *views, int col)
{
	int	j;
	int	line[4];

	j = -1;
	while (++j < 4)
		line[j] = board[j][col];
	if (views[col] != 0 && count_visible(line) != views[col])
		return (0);
	return (1);
}

int	check_column_down(int board[4][4], int *views, int col)
{
	int	j;
	int	line[4];

	j = -1;
	while (++j < 4)
		line[4 - 1 - j] = board[j][col];
	if (views[4 + col] != 0 && count_visible(line) != views[4 + col])
		return (0);
	return (1);
}

int	check_row_left(int board[4][4], int *views, int row)
{
	int	j;
	int	line[4];

	j = -1;
	while (++j < 4)
		line[j] = board[row][j];
	if (views[8 + row] != 0 && count_visible(line) != views[8 + row])
		return (0);
	return (1);
}

int	check_row_right(int board[4][4], int *views, int row)
{
	int	j;
	int	line[4];

	j = -1;
	while (++j < 4)
		line[4 - 1 - j] = board[row][j];
	if (views[12 + row] != 0 && count_visible(line) != views[12 + row])
		return (0);
	return (1);
}
