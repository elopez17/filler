/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:45:14 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/31 00:19:18 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	getfinal(t_vis *v, char *line)
{
	if (line[3] == 'O')
		mlx_string_put(v->mlx, v->win, 350, 710, 0x0000ffff, line);
	else
		mlx_string_put(v->mlx, v->win, 350, 735, 0x00ff0000, line);
	mlx_string_put(v->mlx, v->win, 250, 710, 0x0000ffff, "Player 1");
	mlx_string_put(v->mlx, v->win, 250, 735, 0x00ff0000, "Player 2");
}

int		process(t_vis *v)
{
	char	*line;
	int		x;
	int		y;

	y = -1;
	while (get_next_line(v->fd, &line) > 0)
	{
		if (ft_isdigit(line[0]))
		{
			++y;
			x = 3;
			while (++x < v->brd.x + 4)
				if (line[x] == 'o' || line[x] == 'x')
					fill_spot(v, x - 4, y, line[x]);
			if (y == v->brd.y - 1)
			{
				mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
				ft_strdel(&line);
				break ;
			}
		}
		line[0] == '=' && line[1] == '=' ? getfinal(v, line) : 0;
		ft_strdel(&line);
	}
	return (0);
}
