/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:17:13 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/31 16:40:53 by elopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	v_init(t_vis *v)
{
	char	*line;
	int		i;
	int		j;

	i = 7;
	j = -1;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, 800, 800, "elopez @ 42");
	v->img = mlx_new_image(v->mlx, 800, 800);
	v->addr = mlx_get_data_addr(v->img, &(v->bpp), &(v->len), &(v->endian));
	skiplines(v, 9);
	get_next_line(v->fd, &line);
	v->brd.y = ft_atoi(line + i);
	while (line[++i] >= '0' && line[i] <= '9')
		;
	v->brd.x = ft_atoi(line + i);
	ft_strdel(&line);
	skiplines(v, 1);
	while (++j < v->brd.y && get_next_line(v->fd, &line))
	{
		i = 3;
		while (line[++i])
			(line[i] != '.') ? fill_spot(v, i - 4, j, line[i]) : 0;
		ft_strdel(&line);
	}
}

static int	key_hook(int key, t_vis **v)
{
	if (key == 36)
		while (process(*v))
			mlx_do_sync((*v)->mlx);
	else if (key == KEYESC)
	{
		mlx_destroy_image((*v)->mlx, (*v)->img);
		mlx_destroy_window((*v)->mlx, (*v)->win);
		close((*v)->fd);
		ft_memdel((void**)v);
		exit(0);
	}
	return (0);
}

static int	mouse_hook(int key, int x, int y, t_vis **v)
{
	if (key == 4 || key == 5)
	{
		process(*v);
		process(*v);
	}
	else if (x || y)
		;
	return (0);
}

int main()
{
	t_vis	*v;

	v = (t_vis*)ft_memalloc(sizeof(t_vis));
	v->fd = 0;
	v_init(v);
	v->zoom = 1;
	while (v->brd.x * (v->zoom + 1) <= 800 && v->brd.y * (v->zoom + 1) <= 700)
		++(v->zoom);
	putgrid(v);
	mlx_hook(v->win, 2, 0, &key_hook, &v);
	mlx_hook(v->win, 4, 0, &mouse_hook, &v);
	mlx_loop(v->mlx);
	return (0);
}
