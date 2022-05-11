/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_dealer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:10:56 by kslotova          #+#    #+#             */
/*   Updated: 2022/01/27 13:45:09 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_find_min(int *piece, int *min_x, int *min_y)
{
	int	min;
	int	i;

	i = 0;
	min = piece[0];
	while (i <= 6)
	{
		if (piece[i] < min)
			min = piece[i];
		i += 2;
	}
	i = 1;
	*min_x = min;
	min = piece[1];
	while (i <= 7)
	{
		if (piece[i] < min)
			min = piece[i];
		i += 2;
	}
	*min_y = min;
}

void	piece_mover(t_etris *ts)
{
	while (ts->x_count <= 6)
	{
		ts->array[ts->x_count] = ts->array[ts->x_count] - ts->min_x;
		ts->array[ts->y_count] = ts->array[ts->y_count] - ts->min_y;
		ts->x_count += 2;
		ts->y_count += 2;
	}
}

int	*ft_grid_to_intarray(char **grid)
{
	t_etris	ts;

	ts.array = ft_intnew(8);
	ts.x_count = 0;
	ts.y_count = 1;
	ts.i = 0;
	ts.r = -1;
	while (grid[++ts.r] != NULL && ts.i != 8)
	{
		ts.c = -1;
		while (grid[ts.r][++ts.c])
		{
			if (grid[ts.r][ts.c] == '#')
			{
				ts.array[ts.i++] = ts.c;
				ts.array[ts.i++] = ts.r;
			}
		}
	}
	ft_find_min(ts.array, &ts.min_x, &ts.min_y);
	piece_mover(&ts);
	return (ts.array);
}
