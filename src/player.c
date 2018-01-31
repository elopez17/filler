/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:34:16 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/10 11:10:23 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_player(t_filler *f)
{
	char	*line;

	get_next_line(0, &line);
	if (line[10] == '1')
	{
		f->player = 'O';
		f->opponent = 'X';
	}
	else
	{
		f->player = 'X';
		f->opponent = 'O';
	}
	ft_strdel(&line);
}
