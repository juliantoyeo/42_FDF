/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:21:03 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/02 08:21:04 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx/mlx.h"
# include <math.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# define GAP 50
# define ALT 7
# define ANGLE_1 0.7
# define ANGLE_2 0.5

typedef	struct		s_move
{
	int				x;
	int				y;
	int				click_x;
	int				click_y;
}					t_move;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef	struct		s_count
{
	int				i;
	int				j;
}					t_count;

typedef	struct		s_vect
{
	double			x;
	double			y;
	double			mag;
}					t_vect;

typedef	struct		s_dline
{
	int				dx;
	int				dy;
	int				adj;
	int				diff;
}					t_dline;

typedef	struct		s_value
{
	int				alt;
	int				color;
}					t_value;

typedef	struct		s_map
{
	t_value			**tab;
	int				n_rows;
	int				n_cols;
}					t_map;

typedef	struct		s_win
{
	int				c_x;
	int				c_y;
	int				x;
	int				y;
	int				color;
	int				zoom;
	int				alt;
	int				mouse_press;
	int				view;
	t_move			i;
	t_point			drag;
	double			angle_1;
	double			angle_2;
	t_map			map;
	void			*mlx;
	void			*win;
}					t_win;

int					ft_create_map(t_map *map, char *str);
int					ft_check(int ac, char **av);
int					ft_draw_map(t_win *p);
int					ft_draw_line(t_win *p, t_point prev, t_point next);
int					ft_draw_vertical(t_win *p, int j, double a_1, double a_2);
int					ft_draw_horizontal(t_win *p, int i, double a_1, double a_2);
int					key_hook(int keycode, t_win *p);
int					mouse_hook(int bt, int x, int y, t_win *p);
int					mouse_hookup(int bt, int x, int y, t_win *p);
int					mouse_move(int x, int y, t_win *p);
int					ft_free_exit(t_win *p);
int					ft_back_to_normal(t_win *p);
int					ft_alt(t_win *p, int keycode);
int					ft_angle(t_win *p, int keycode);
int					ft_redraw(t_win *p);

#endif
