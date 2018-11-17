/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 04:37:53 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/05 04:37:54 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_init(t_dline *dline, t_point prev, t_point next)
{
	(*dline).dx = next.x - prev.x;
	(*dline).dy = next.y - prev.y;
	(*dline).adj = 1;
	return (0);
}

static int	ft_draw_line_low(t_win *p, t_point prev, t_point next)
{
	int		y;
	t_dline	dline;

	ft_init(&dline, prev, next);
	if (dline.dy < 0)
	{
		dline.adj = -1;
		dline.dy = -dline.dy;
	}
	dline.diff = (2 * dline.dy) - dline.dx;
	y = prev.y;
	while (prev.x < next.x)
	{
		if ((prev.x < p->c_x * 4) && prev.x > 0 && (y < p->c_y * 4) && y > 0)
			mlx_pixel_put(p->mlx, p->win, prev.x, y, p->color);
		if (dline.diff > 0)
		{
			y = y + dline.adj;
			dline.diff = dline.diff - (2 * dline.dx);
		}
		dline.diff = dline.diff + (2 * dline.dy);
		prev.x++;
	}
	return (0);
}

static int	ft_draw_line_high(t_win *p, t_point prev, t_point next)
{
	int		x;
	t_dline	dline;

	ft_init(&dline, prev, next);
	if (dline.dx < 0)
	{
		dline.adj = -1;
		dline.dx = -dline.dx;
	}
	dline.diff = (2 * dline.dx) - dline.dy;
	x = prev.x;
	while (prev.y < next.y)
	{
		if ((x < p->c_x * 4) && x > 0 && (prev.y < p->c_y * 4) && prev.y > 0)
			mlx_pixel_put(p->mlx, p->win, x, prev.y, p->color);
		if (dline.diff > 0)
		{
			x = x + dline.adj;
			dline.diff = dline.diff - (2 * dline.dy);
		}
		dline.diff = dline.diff + (2 * dline.dx);
		prev.y++;
	}
	return (0);
}

int			ft_draw_line(t_win *p, t_point prev, t_point next)
{
	if (abs(next.y - prev.y) < abs(next.x - prev.x))
	{
		if (prev.x > next.x)
			ft_draw_line_low(p, next, prev);
		else
			ft_draw_line_low(p, prev, next);
	}
	else
	{
		if (prev.y > next.y)
			ft_draw_line_high(p, next, prev);
		else
			ft_draw_line_high(p, prev, next);
	}
	return (0);
}
