/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:45:38 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/10 11:09:53 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	get_token(t_filler *f)
{
	char	*line;
	int		i;

	i = 5;
	get_next_line(0, &line);
	f->tok.y = ft_atoi(line + i);
	while (line[++i] >= '0' && line[i] <= '9')
		;
	f->tok.x = ft_atoi(line + i);
	ft_strdel(&line);
	f->token = (char**)malloc(sizeof(char*) * (f->tok.y + 1));
	i = -1;
	while (++i < f->tok.y)
	{
		get_next_line(0, &(line));
		f->token[i] = ft_strdup(line);
		ft_strdel(&line);
	}
	f->token[f->tok.y] = 0;
}
