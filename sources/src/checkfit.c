/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 00:48:54 by eLopez            #+#    #+#             */
/*   Updated: 2018/02/02 13:53:33 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	checkfit(t_filler *f, int x, int y)
{
	int	i;
	int	j;
	int	overlaps;

	if (x + f->tok.x > f->brd.x || y + f->tok.y > f->brd.y)
		return (0);
	overlaps = 0;
	j = -1;
	while (++j < f->tok.y)
	{
		i = -1;
		while (++i < f->tok.x)
		{
			if (MASK(f->board[y + j][x + i]) == f->player &&
					f->token[j][i] == '*')
				++overlaps;
			else if (MASK(f->board[y + j][x + i]) == f->opponent &&
					f->token[j][i] == '*')
				return (0);
		}
	}
	if (overlaps == 1)
		return (1);
	return (0);
}
