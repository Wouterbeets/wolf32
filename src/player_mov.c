/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 11:16:44 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/15 11:27:48 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_is_up(t_data *d)
{
	d->usery = d->usery - 1;
}

void	ft_is_down(t_data *d)
{
	d->usery = d->usery + 1;
}

void	ft_is_left(t_data *d)
{
	d->usery = d->usery - 1;
}

void	ft_is_right(t_data *d)
{
	d->usery = d->usery + 1;
}
