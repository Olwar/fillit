/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:17:53 by kslotova          #+#    #+#             */
/*   Updated: 2022/01/27 14:01:56 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_rev_strchr(const char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		ft_error_exit("error\n");
	while (s[i] == '#' || s[i] == '.')
		i++;
	if (s[i] != '\0')
		ft_error_exit("error\n");
	return (0);
}

int	check_neighbours(char **grid, int row, int col)
{
	int	flag;

	flag = 0;
	if (col < 3 && grid[row][col + 1])
		if (grid[row][col + 1] == '#')
			flag++;
	if (row < 3 && grid[row + 1][col])
		if (grid[row + 1][col] == '#')
			flag++;
	if (col != 0 && grid[row][col - 1])
		if (grid[row][col - 1] == '#')
			flag++;
	if (row != 0 && grid[row - 1][col])
		if (grid[row - 1][col] == '#')
			flag++;
	return (flag);
}

void	is_shape_valid(char **grid, t_etris *ts)
{
	ts->flag = check_neighbours(grid, ts->r, ts->c);
	if (ts->flag == 0)
		ft_error_exit("error\n");
	if (ts->flag >= 1)
		ts->counter++;
	if (ts->flag >= 2)
		ts->neigh_i++;
}

int	validity_checker(char **grid)
{
	t_etris	ts;

	ts.counter = 0;
	ts.r = -1;
	ts.neigh_i = 0;
	while (grid[++ts.r] != NULL)
	{
		ts.c = -1;
		while (++ts.c <= 4)
		{
			ts.flag = 0;
			if (grid[ts.r][ts.c] == '#')
				is_shape_valid(grid, &ts);
		}
	}
	if (ts.neigh_i < 1)
		ft_error_exit("error\n");
	if (ts.counter == 4)
		return (1);
	else
		ft_error_exit("error\n");
	return (0);
}

void	piece_validity(int	**array, t_etris *trs)
{
	if (validity_checker(trs->grid))
	{
		array[trs->pcs] = ft_grid_to_intarray(trs->grid);
		trs->pcs++;
	}
}
