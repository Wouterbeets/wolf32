/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:13:32 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/13 20:59:30 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_map(int ***map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			ft_putnbr(*map[i][j]);
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int		***map;
	t_map	info;
	if ((map = ft_get_map(ac, av, &info)))
	{
		info.mlx = mlx_init();
		info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "wow much improve");
		mlx_loop(new.mlx);
		ft_print_map(map);
	}
		return (0);
}
