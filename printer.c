/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:25:22 by oairola           #+#    #+#             */
/*   Updated: 2022/01/27 14:20:31 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printer(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		write(1, grid[i], ft_strlen(grid[i]));
		write(1, "\n", 1);
		i++;
	}
	freer(grid);
}
