/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:50:35 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/30 20:33:32 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	find_position(t_filler *f, int i)
{
	int j;

	j = -1;
	while (++j < f->brd.x)
	{
		if (f->board[i][j] == f->player && f->my_pos.y == -1)
		{
			f->my_pos.x = j;
			f->my_pos.y = i;
		}
		else if (f->board[i][j] == f->opponent && f->opp_pos.y == -1)
		{
			f->opp_pos.x = j;
			f->opp_pos.y = i;
		}
	}
}

static void	board_xy(t_filler *f, char *line)
{
	int i;

	i = 7;
	f->brd.y = ft_atoi(line + i);
	while (line[++i] >= '0' && line[i] <= '9')
		;
	f->brd.x = ft_atoi(line + i);
}

int			get_board(t_filler *f)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) == 0)//	Plateau
		get_next_line(0, &line);// Plateau
	if (f->brd.x == 0 && f->brd.y == 0)
		board_xy(f, line);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	f->board = (char**)malloc(sizeof(char*) * (f->brd.y + 1));
	i = -1;
	while (++i < f->brd.y)
	{
		get_next_line(0, &line);
		f->board[i] = ft_strsub(line, 4, f->brd.x);
		if (f->my_pos.y == -1 || f->opp_pos.y == -1)
			find_position(f, i);
		ft_strdel(&line);
	}
	f->board[f->brd.y] = 0;
	return (1);
}
