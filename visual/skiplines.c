/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skiplines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:22:40 by eLopez            #+#    #+#             */
/*   Updated: 2017/12/11 15:26:00 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	skiplines(t_vis *v, int lines)
{
	char	*line;

	while (lines-- > 0)
	{
		if (get_next_line(v->fd, &line) <= 0)
			break ;
		ft_strdel(&line);
	}
}
