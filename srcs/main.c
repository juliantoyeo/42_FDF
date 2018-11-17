/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:21:12 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/02 08:21:13 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_redraw(t_win *p)
{
	mlx_clear_window(p->mlx, p->win);
	ft_draw_map(p);
	return (0);
}

static int	ft_init(t_win **p, char **av)
{
	*p = (t_win *)malloc(sizeof(t_win));
	(*p)->x = ft_atoi(av[1]) / 4;
	(*p)->y = ft_atoi(av[2]) / 4;
	(*p)->c_x = (*p)->x;
	(*p)->c_y = (*p)->y;
	(*p)->mlx = mlx_init();
	(*p)->win = mlx_new_window((*p)->mlx, (*p)->x * 4, (*p)->y * 4, "fdf");
	(*p)->angle_1 = ANGLE_1;
	(*p)->angle_2 = ANGLE_2;
	(*p)->color = 0xFFFFFF;
	(*p)->zoom = 0;
	(*p)->alt = 0;
	(*p)->mouse_press = 0;
	(*p)->drag.x = 0;
	(*p)->drag.y = 0;
	(*p)->i.x = 0;
	(*p)->i.y = 0;
	(*p)->i.click_x = 0;
	(*p)->i.click_y = 0;
	if ((ft_create_map(&(*p)->map, av[0])) == -1)
		return (-1);
	return (0);
}

int			main(int ac, char **av)
{
	t_win	*p;

	ac--;
	av++;
	if ((ft_check(ac, av)) == -1)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	if ((ft_init(&p, av)) == -1)
	{
		ft_printf("ERROR\n");
		ft_free_exit(p);
	}
	ft_draw_map(p);
	mlx_key_hook(p->win, key_hook, (void *)p);
	mlx_mouse_hook(p->win, mouse_hook, (void *)p);
	mlx_hook(p->win, 5, 1L << 3, mouse_hookup, (void *)p);
	mlx_hook(p->win, 6, 1L << 6, mouse_move, (void *)p);
	mlx_loop(p->mlx);
	return (0);
}
