/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:18:27 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/08 03:18:29 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_free_exit(t_win *p)
{
	mlx_destroy_window(p->mlx, p->win);
	ft_free_double((void **)p->map.tab);
	FREE(p);
	exit(0);
	return (0);
}

int		ft_back_to_normal(t_win *p)
{
	p->x = p->c_x;
	p->y = p->c_y;
	p->drag.x = 0;
	p->drag.y = 0;
	p->zoom = 0;
	p->alt = 0;
	p->angle_1 = ANGLE_1;
	p->angle_2 = ANGLE_2;
	ft_redraw(p);
	return (0);
}

int		ft_alt(t_win *p, int keycode)
{
	if (keycode == 126)
	{
		p->alt++;
		ft_redraw(p);
	}
	if (keycode == 125)
	{
		if (p->alt - 1 >= 0)
			p->alt--;
		ft_redraw(p);
	}
	return (0);
}

int		ft_angle(t_win *p, int keycode)
{
	if (keycode == 124)
	{
		if (p->angle_1 + 0.1 <= 1.1)
			p->angle_1 += 0.1;
		ft_redraw(p);
	}
	if (keycode == 123)
	{
		if (p->angle_1 - 0.1 >= -1.1)
			p->angle_1 -= 0.1;
		ft_redraw(p);
	}
	if (keycode == 43)
	{
		if (p->angle_2 + 0.1 <= 1.1)
			p->angle_2 += 0.1;
		ft_redraw(p);
	}
	if (keycode == 47)
	{
		if (p->angle_2 - 0.1 >= -1.1)
			p->angle_2 -= 0.1;
		ft_redraw(p);
	}
	return (0);
}
