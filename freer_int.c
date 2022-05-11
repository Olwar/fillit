/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:49:24 by kslotova          #+#    #+#             */
/*   Updated: 2022/01/27 14:50:13 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	freer_int(int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		grid[i] = NULL;
		i++;
	}
	free(grid);
}
