/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:13:10 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/13 20:36:47 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define WIDTH 800
# define HEIGHT 600

typedef struct	s_map
{
	int		x;
	int		y;
	char*	name;
	int		start;
	int		wall;
	int		empty;
	void	*mlx;
	void	*win;
}				t_map;

/*get_map.c*/
int		**ft_fill_map(char *line, t_map *info);
void		ft_fill_map_info(char *line, t_map *info);
int		***ft_get_map(int ac, char **av, t_map *info);

# endif /*HEADER_H*/
