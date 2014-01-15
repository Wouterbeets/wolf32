/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:13:10 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/15 15:44:10 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# define WIDTH		800
# define MGDA		mlx_get_data_addr
# define HEIGHT		600
# define BLOCKSIZE	20
# define GREY		0x868686
# define BLUE		0x0893CF
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307
# define FOV		60
# define PI			3.14159265359

typedef struct		s_map
{
	int				x;
	int				y;
	char*			name;
	int				start;
	int				wall;
	int				empty;
}					t_map;

typedef struct		s_img
{
	int				line_size;
	int				bpp;
	int				endian;
	char			*data;
	void			*ptr;
}					t_img;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	int				i;
	int				x;
	int				userx;
	int				y;
	int				usery;
	int				bgfill;
	int				dirx;
	int				diry;
	int				***map;
	t_map			*info;
	t_img			*bg;
	t_img			*img;
}					t_data;

/*get_map.c*/
int					**ft_fill_map(char *line, t_map *info);
void				ft_fill_map_info(char *line, t_map *info);
int					***ft_get_map(int ac, char **av, t_map *info);

/*ft_mlx.c*/
void				ft_mlx(t_data *d);
int					expose_hook(t_data *d);
void				ft_draw(t_data *d);
int					key_hook(int keycode, t_data *d);

/*image.c*/
void				make_bg(t_data *d);
void				ft_pixel_to_img(char *data, t_data *d, int color);
void				ft_create_image(t_data *d);
void				get_user_pos(t_data *d);

/*player moves*/
void				ft_is_up(t_data *d);
void				ft_is_down(t_data *d);
void				ft_is_left(t_data *d);
void				ft_is_right(t_data *d);

void	raycast(t_data *d);
void	add_walls(t_data *d);
# endif /*HEADER_H*/
