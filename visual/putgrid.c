/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putgrid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:21:43 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/11 21:40:26 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	putgrid(t_vis *v)
{
	int	x;
	int y;

	y = v->zoom;
	while (y <= v->brd.y * v->zoom)
	{
		x = 0;
		while (++x <= v->brd.x * v->zoom)
			putpixel(v, x, y, 'g');
		y += v->zoom;
	}
	while (x > 0)
	{
		y = 0;
		while (++y <= v->brd.y * v->zoom)
			putpixel(v, x, y, 'g');
		x -= v->zoom;
	}
}
