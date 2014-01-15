/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:59:11 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/15 12:04:03 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_user_pos(t_data *d)
{
	if (d->userx == 0 && d->usery == 0)
	{
		while (d->map[d->usery])
		{
			while (d->map[d->usery][d->userx])
			{
				if (*d->map[d->usery][d->userx] == d->info->start)
				{
					d->usery = d->usery * BLOCKSIZE;
					d->userx = d->userx * BLOCKSIZE;
					return ;
				}
				d->userx++;
			}
			d->usery++;
			d->userx = 0;
		}
	}
}

void	make_bg(t_data *d)
{
	if (d->bgfill == 0)
	{
		d->x = 0;
		d->y = 0;
		while (d->y < HEIGHT)
		{
			while (d->x < WIDTH)
			{
				if(d->y > HEIGHT / 2)
					ft_pixel_to_img(d->bg->data, d, GREY);
				else
					ft_pixel_to_img(d->bg->data, d, BLUE);
				d->x++;
			}
			d->x = 0;
			d->y++;
		}
		d->bgfill = 1;
		ft_memcpy(d->img->data, d->bg->data, sizeof(d->bg->data));
	}
	else
	{
		free(d->bg->data);
		ft_memcpy(d->img->data, d->bg->data, sizeof(*d->bg->data));
	}
}

void	ft_pixel_to_img(char *data, t_data *d, int color)
{
		unsigned int	new_color;
		int				i;

		new_color = mlx_get_color_value(d->mlx, color);
		i = d->x * 4 + d->y * d->bg->line_size;
		data[i] = (new_color & 0xFF);
		data[i + 1] = (new_color & 0xFF00) >> 8;
		data[i + 2] = (new_color & 0xFF0000) >> 16;
}

void	ft_create_image(t_data *d)
{
	d->bg->ptr = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img->ptr = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img->data = MGDA(d->img->ptr, &d->img->bpp, &d->img->line_size, &d->img->endian);
	d->bg->data = MGDA(d->bg->ptr, &d->bg->bpp, &d->bg->line_size, &d->bg->endian);
}
