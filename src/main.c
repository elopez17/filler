#include <filler.h>

static void	init(t_filler *f)
{
	f->brd.y = 0;
	f->brd.x = 0;
	f->gameover = 0;
	f->my_pos.x = -1;
	f->my_pos.y = -1;
	f->opp_pos.x = -1;
	f->opp_pos.y = -1;
	f->place.y = -1;
	f->place.x = -1;
	f->fit = (t_fits*)NULL;
}

static void	fill_memdel(t_filler *f)
{
	t_fits	*tmp;

	while (f->fit != NULL)
	{
		free_2d(&(f->fit->board));
		tmp = f->fit->next;
		free(f->fit);
		f->fit = tmp;
	}
	f->fit = NULL;
	free_2d(&(f->board));
	free_2d(&(f->token));
}

int main()
{
	t_filler	*f;

	f = (t_filler*)ft_memalloc(sizeof(t_filler));
	init(f);
	get_player(f);
	f->fd = open("info.txt", O_RDWR | O_TRUNC | O_APPEND);
	while (get_board(f))
	{
		get_token(f);
		checkboard(f);
		getplace(f);
		ft_printf("%d %d\n", f->place.y, f->place.x);
		fill_memdel(f);
		if (f->gameover == 1)
			break ;
	}
	close(f->fd);
	return (0);
}
