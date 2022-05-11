/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:54:07 by oairola           #+#    #+#             */
/*   Updated: 2022/01/27 14:22:41 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	safe_chk(char **grid, int *tetri, int *rocole, int max_size)
{
	int	tetri_x;
	int	tetri_y;
	int	i;
	int	j;

	j = 0;
	i = 0;
	tetri_x = 0;
	tetri_y = 1;
	while (tetri_x != 8)
	{
		if (rocole[1] + tetri[tetri_x] >= max_size || \
		rocole[0] + tetri[tetri_y] >= max_size)
			return (0);
		if (grid[rocole[0] + tetri[tetri_y]][rocole[1] + tetri[tetri_x]] == '.')
		{
			tetri_x += 2;
			tetri_y += 2;
		}
		else
			return (0);
	}
	return (1);
}
