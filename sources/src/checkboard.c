/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 00:48:54 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/30 22:45:04 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	checkboard(t_filler *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < f->brd.y)
	{
		x = -1;
		while (++x < f->brd.x)
		{
			if (checkfit(f, x, y))
				addnode(f, x, y);
		}
	}
	if (f->fit == NULL)
		f->gameover = 1;
}
