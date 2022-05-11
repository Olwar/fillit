/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:45:40 by oairola           #+#    #+#             */
/*   Updated: 2022/01/27 14:04:25 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**freer_grid(char **grid, int grid_side)
{
	int	i;
	int	j;

	j = grid_side;
	i = 0;
	while (i < grid_side)
	{
		j = grid_side;
		while (grid[i][j] != '\0')
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	while (grid[i] != NULL)
	{
		free(grid[i]);
		grid[i] = NULL;
		i++;
	}
	return (grid);
}
