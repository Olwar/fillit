/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kslotova <kslotova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:26:45 by oairola           #+#    #+#             */
/*   Updated: 2022/01/27 15:00:58 by kslotova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	real_array_maker(t_etris *ts)
{
	int	i;

	i = 25;
	while (i >= 0)
	{
		if (ts->arr[i] != NULL)
		{
			ts->real_arr[ts->counter] = ft_intdup(ts->arr[i], 8);
			ts->counter++;
		}
		i--;
	}
	i = 0;
	while (i < 26)
	{
		free(ts->arr[i]);
		ts->arr[i] = NULL;
		i++;
	}
	free(ts->arr);
	if (ts->pcs > 26)
		ft_error_exit("error\n");
}

int	main(int argc, char **argv)
{
	t_etris	ts;

	ts.gnl_flag = 1;
	ts.pcs = 0;
	if (argc != 2)
		ft_error_exit("usage: ./fillit input_file\n");
	ts.fd = open(argv[1], O_RDONLY);
	if (!ts.fd || ts.fd < 0)
		ft_error_exit("error\n");
	ts.arr = (int **)malloc(sizeof(int *) * 26);
	ft_bzero(ts.arr, sizeof(int *) * 26);
	file_reader(&ts);
	ts.real_arr = (int **)malloc(sizeof(int *) * ts.pcs);
	ft_bzero(ts.real_arr, sizeof(int *) * ts.pcs);
	real_array_maker(&ts);
	ts.size = ft_sqrt(4 * (ts.pcs - 1));
	ts.size = size_increaser(ts.size, ts.real_arr, 0);
	ts.grid = create_grid(ts.pcs);
	ts.pcs--;
	ts.grid = solver(ts);
	printer(ts.grid);
	freer_int(ts.real_arr, ts.pcs + 1);
	return (0);
}
