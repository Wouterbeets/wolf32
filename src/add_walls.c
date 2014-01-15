/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:05:50 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/15 15:45:12 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	raycast(t_data *d)
{
	int	degrees;
	int		dist;
	float	rad;
	int		x;
	int		y;

	dist = 0;
	degrees = 0;
	x = d->userx;
	y = d->usery;
	ft_putnbr(dist);
	ft_putchar('\n');
	while (degrees < 60)
	{
		while (d->map[x / BLOCKSIZE][y / BLOCKSIZE])
		{
			ft_putstr("dist = ");
			ft_putnbr(dist);
			ft_putchar('\t');
			ft_putstr("x = ");
			ft_putnbr(x / BLOCKSIZE);
			ft_putchar('\t');
			ft_putstr("y = ");
			ft_putnbr(y / BLOCKSIZE);
			ft_putchar('\t');
			ft_putstr("map x y = ");
			ft_putnbr(*d->map[x / BLOCKSIZE][y / BLOCKSIZE]);
			rad = degrees * 0.17453295;
			ft_putchar('\t');

			x = d->userx + cos(rad) * dist;
			y = d->usery + sin(rad) * dist;
			ft_putstr("after conversion x = ");
			ft_putnbr(x / BLOCKSIZE);
			ft_putchar('\t');
			ft_putstr("y = ");
			ft_putnbr(y / BLOCKSIZE);
			dist++;
			ft_putchar('\n');
			if (*d->map[x / BLOCKSIZE][y / BLOCKSIZE] == 1)
			{
				ft_putstr("entered if 2 ");
				break;
			}
		}
		ft_putstr("out");
		ft_putchar('\n');
		ft_putnbr(dist);
		dist = 0;
		x = d->userx;
		y = d->usery;
		degrees++;
	}
}

void	add_walls(t_data *d)
{
	raycast(d);
}
