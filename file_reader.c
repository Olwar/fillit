/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:53:28 by kslotova          #+#    #+#             */
/*   Updated: 2022/01/27 15:05:13 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	file_reader(t_etris *ts)
{
	ts->counter = 0;
	while (ts->gnl_flag != 0)
	{
		ts->grid = (char **)malloc(sizeof(char *) * 5);
		ft_bzero(ts->grid, 5 * sizeof(char *));
		while (ts->counter <= 3)
		{
			ts->gnl_flag = get_next_line(ts->fd, &ts->line);
			if (ts->gnl_flag <= 0 || ft_rev_strchr(ts->line) != 0 \
			|| ft_strlen(ts->line) % 4 != 0)
				ft_error_exit("error\n");
			ts->grid[ts->counter] = ft_strdup(ts->line);
			ft_strdel(&ts->line);
			ts->counter++;
		}
		piece_validity(ts->arr, &*ts);
		freer(ts->grid);
		ts->gnl_flag = get_next_line(ts->fd, &ts->line);
		ft_strdel(&ts->line);
		if (ts->gnl_flag < 0)
			ft_error_exit("error\n");
		else
			ts->counter = 0;
	}
}
