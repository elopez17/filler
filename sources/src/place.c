#include <filler.h>

void	getplace(t_filler *f)
{
	t_fits	*tmp;
	t_point	dist;

	tmp = f->fit;
	dist = (t_point){f->brd.x + 1, f->brd.y + 1};
	while (tmp != NULL)
	{
		if (tmp->dist.x + tmp->dist.y <= dist.x + dist.y)
		{
			dist.x = tmp->dist.x;
			dist.y = tmp->dist.y;
			f->place.x = tmp->place.x;
			f->place.y = tmp->place.y;
		}
		tmp = tmp->next;
	}
}
