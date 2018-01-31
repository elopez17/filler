/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:33:42 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/30 23:23:54 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	putpixel(t_vis *v, int x, int y, char c)
{
	int i;
	int	color;

	if (x < 0 || x >= 800 || y < 0 || y >= 800)
		return ;
	if (c == 'O' || c == 'o')
		color = 0x0000ffff;
	else
		color = (c == 'X' || c == 'x') ? 0x00ff0000 : 0x0;
	if (c == 'g')
		color = 0x0000ff00;
	i = (v->bpp / 8) * x + v->len * y;
	if (v->endian == 0)
	{
		v->addr[i++] = (0x000000ff & color);
		v->addr[i++] = (0x0000ff00 & color) >> 8;
		v->addr[i++] = (0x00ff0000 & color) >> 16;
		v->addr[i++] = (0xff000000 & color) >> 24;
	}
}
