/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_dealer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:14:23 by kslotova          #+#    #+#             */
/*   Updated: 2022/01/27 14:15:11 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**dots_b(char **grid, int *tetri, int *rocole)
{
	int	tetri_x;
	int	tetri_y;

	tetri_x = 0;
	tetri_y = 1;
	while (tetri_x != 8)
	{
		grid[rocole[0] + tetri[tetri_y]][rocole[1] + tetri[tetri_x]] = '.';
		tetri_x += 2;
		tetri_y += 2;
	}
	return (grid);
}

char	**putdots(char **grid, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (grid[i][j] && j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}
