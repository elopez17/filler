/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:50:35 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/02 13:51:48 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static t_point	shortest(t_filler *f, t_fits *fit)
{
	t_point	dist;
	int		x;
	int		y;

	dist.x = f->brd.x;
	dist.y = f->brd.y;
	y = -1;
	while (++y < f->brd.y && (x = -1) == -1)
		while (++x < f->brd.x)
		{
			if (MASK(f->board[y][x]) == f->opponent && ABS(fit->new.y - y) <
					dist.y && ABS(fit->new.x - x) < dist.x)
			{
				dist.x = ABS(fit->new.x - x);
				dist.y = ABS(fit->new.y - y);
			}
		}
	return (dist);
}

void			addnode(t_filler *f, int x, int y)
{
	t_fits	*fit;
	int		j;
	int		i;

	j = -1;
	fit = (t_fits*)malloc(sizeof(t_fits));
	fit->place.x = x;
	fit->place.y = y;
	fit->board = (char**)malloc(sizeof(char*) * f->brd.y + 1);
	while (++j < f->brd.y)
		fit->board[j] = ft_strdup(f->board[j]);
	fit->board[f->brd.y] = 0;
	j = -1;
	while (++j < f->tok.y && (i = -1) == -1)
		while (++i < f->tok.x)
			if (f->token[j][i] == '*' && (fit->new.x = x + i) > -1)
			{
				fit->new.y = y + j;
				fit->board[y + j][x + i] = '*';
			}
	fit->dist = shortest(f, fit);
	fit->next = f->fit;
	f->fit = fit;
}
