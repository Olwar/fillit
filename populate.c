/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oairola <oairola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:22:34 by oairola           #+#    #+#             */
/*   Updated: 2022/01/28 09:15:48 by oairola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_abc(char **grid, int *tetri, int *rocole)
{
	int	tetri_x;
	int	tetri_y;

	tetri_x = 0;
	tetri_y = 1;
	while (tetri_x != 8)
	{
		grid[rocole[0] + tetri[tetri_y]][rocole[1] + tetri[tetri_x]] \
		= rocole[2];
		tetri_x += 2;
		tetri_y += 2;
	}
	return (grid);
}

int	size_increaser(int size, int **tetri, int last_pc)
{
	int	j;
	int	min;
	int	flag;

	j = -1;
	min = size;
	flag = 0;
	while (++j < 8)
	{
		if (tetri[last_pc][j] >= min)
		{
			min = (tetri[last_pc][j]);
			flag = 1;
		}
	}
	if (flag == 1)
		return (min + 1);
	else
		return (size);
}

int	populate_grid(t_etris *ts, int i)
{
	t_etris	trs;

	if (ts->pcs - i == -1)
		return (1);
	trs.rocole[0] = -1;
	while (++trs.rocole[0] < ts->size)
	{
		trs.rocole[2] = 65 - (ts->pcs - i) + ts->pcs;
		trs.rocole[1] = -1;
		while (++trs.rocole[1] < ts->size)
		{
			if (safe_chk(ts->grid, ts->real_arr[ts->pcs - i], trs.rocole, \
			ts->size))
			{
				ts->grid = put_abc(ts->grid, ts->real_arr[ts->pcs - i], \
				trs.rocole);
				if (populate_grid(ts, i + 1))
					return (1);
				ts->grid = dots_b(ts->grid, ts->real_arr[ts->pcs - i], \
				trs.rocole);
			}
		}
	}
	return (0);
}

char	**solver(t_etris ts)
{
	int	i;

	i = 0;
	while (!populate_grid(&ts, i))
	{
		ts.grid = putdots(ts.grid, ts.size);
		ts.size++;
		i = 0;
	}
	ts.grid = freer_grid(ts.grid, ts.size);
	return (ts.grid);
}
