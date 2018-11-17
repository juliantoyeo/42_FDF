/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 04:19:00 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/05 04:19:02 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int	ft_init_map_point(t_point *adj, t_point *pre, t_point *nex)
{
	(*adj).x = 0;
	(*adj).y = 0;
	(*pre).x = 0;
	(*pre).y = 0;
	(*nex).x = 0;
	(*nex).y = 0;
	return (0);
}

static	int	ft_get_color(t_win **p, int i, int j)
{
	(*p)->color = (*p)->map.tab[i][j].color;
	if (i != 0)
		if ((*p)->map.tab[i - 1][j].color != 0xFFFFFF)
			(*p)->color = (*p)->map.tab[i - 1][j].color;
	return (0);
}

static	int	ft_get_next_prev(t_win *p, t_count c, t_point adj, t_point *point)
{
	int		gap;
	int		alt;

	alt = ALT + p->alt;
	gap = GAP + p->zoom;
	(*point).x = p->x + (c.j * gap) + adj.x + p->drag.x;
	(*point).y = p->y + (c.i * gap) - (p->map.tab[c.i][c.j].alt *
		(alt + (p->zoom / alt))) - adj.y + p->drag.y;
	return (0);
}

int			ft_draw_vertical(t_win *p, int j, double angle_1, double angle_2)
{
	t_count c;
	t_point	adj;
	t_point	prev;
	t_point	next;

	c.i = 0;
	c.j = j;
	ft_init_map_point(&adj, &prev, &next);
	adj.y = (p->y + (c.i * (GAP + p->zoom))) -
	((sin(p->angle_2) * (p->x + (c.j * (GAP + p->zoom)))) / sin(angle_2));
	while (p->map.tab[c.i])
	{
		adj.x = (p->x + (0 * (GAP + p->zoom))) -
		((sin(p->angle_1) * (p->y + (c.i * (GAP + p->zoom)))) / sin(angle_1));
		ft_get_color(&p, c.i, c.j);
		ft_get_next_prev(p, c, adj, &next);
		if (prev.x != 0 && prev.y != 0)
			ft_draw_line(p, prev, next);
		ft_get_next_prev(p, c, adj, &prev);
		c.i++;
	}
	prev.x = 0;
	prev.y = 0;
	return (0);
}

int			ft_draw_horizontal(t_win *p, int i, double angle_1, double angle_2)
{
	t_count c;
	t_point	adj;
	t_point	prev;
	t_point	next;

	c.i = i;
	c.j = 0;
	ft_init_map_point(&adj, &prev, &next);
	adj.x = (p->x + (c.j * (GAP + p->zoom))) -
	((sin(p->angle_1) * (p->y + (c.i * (GAP + p->zoom)))) / sin(angle_1));
	while (c.j < p->map.n_cols)
	{
		adj.y = (p->y + (0 * (GAP + p->zoom))) -
		((sin(p->angle_2) * (p->x + (c.j * (GAP + p->zoom)))) / sin(angle_2));
		ft_get_color(&p, c.i, c.j);
		ft_get_next_prev(p, c, adj, &next);
		if (prev.x != 0 && prev.y != 0)
			ft_draw_line(p, prev, next);
		ft_get_next_prev(p, c, adj, &prev);
		c.j++;
	}
	prev.x = 0;
	prev.y = 0;
	return (0);
}
