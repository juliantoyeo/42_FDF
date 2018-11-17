/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 03:17:19 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/08 03:17:20 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int keycode, t_win *p)
{
	if (keycode == 53 || keycode == 82)
		ft_free_exit(p);
	if (keycode == 8 || keycode == 49)
		ft_back_to_normal(p);
	if (keycode == 126 || keycode == 125)
		ft_alt(p, keycode);
	if (keycode == 124 || keycode == 123 || keycode == 43 || keycode == 47)
		ft_angle(p, keycode);
	return (0);
}

int		mouse_hook(int bt, int x, int y, t_win *p)
{
	if (bt == 1)
		p->mouse_press = 1;
	if (bt == 1)
	{
		p->i.click_x = x;
		p->i.click_y = y;
	}
	if (bt == 4)
	{
		p->zoom += ALT;
		ft_redraw(p);
	}
	if (bt == 5)
	{
		if (p->zoom - ALT >= -49)
			p->zoom -= ALT;
		ft_redraw(p);
	}
	return (0);
}

int		mouse_hookup(int bt, int x, int y, t_win *p)
{
	x = 0;
	y = 0;
	if (bt == 1)
		p->mouse_press = 0;
	return (0);
}

int		mouse_move(int x, int y, t_win *p)
{
	if (p->mouse_press == 1)
	{
		p->i.x = (x - p->i.click_x);
		p->i.y = (y - p->i.click_y);
		p->drag.x += p->i.x;
		p->drag.y += p->i.y;
		ft_redraw(p);
		p->i.click_x = x;
		p->i.click_y = y;
	}
	if (p->mouse_press == 0)
	{
		p->i.x = 0;
		p->i.y = 0;
	}
	return (0);
}
