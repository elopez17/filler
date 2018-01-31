/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eLopez <elopez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:06:40 by eLopez            #+#    #+#             */
/*   Updated: 2018/01/31 02:07:06 by eLopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <mlx.h>
# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# define KEYESC 53
# define MASK(c) (c & 0xdf)
# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_visualizer
{
	t_point	brd;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		len;
	int		zoom;
	int		fd;
}				t_vis;

typedef struct	s_fits
{
	char			**board;
	t_point			place;
	t_point			new;
	t_point			dist;
	struct s_fits	*next;
}				t_fits;

typedef struct	s_filler
{
	char	player;
	t_point	my_pos;
	t_point	opp_pos;
	char	opponent;
	char	**board;
	t_point	brd;
	char	**token;
	t_point	tok;
	t_fits	*fit;
	t_point	place;
	int		gameover;
	int		fd;
}				t_filler;

void			putgrid(t_vis *v);
int				key_press(int key, t_vis **v);
void			fill_spot(t_vis *v, int x, int y, char c);
void			skiplines(t_vis *v, int lines);
int				process(t_vis *v);
void			putpixel(t_vis *v, int x, int y, char c);
void			get_player(t_filler *f);
int				get_board(t_filler *f);
void			get_token(t_filler *f);
int				checkfit(t_filler *f, int x, int y);
void			checkboard(t_filler *f);
void			addnode(t_filler *f, int x, int y);
void			getplace(t_filler *f);

#endif
