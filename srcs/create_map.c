/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 04:40:06 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/05 04:40:12 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static int	ft_map_init(t_map *map, char *str)
{
	int		fd;
	int		n_lines;
	char	*line;

	n_lines = 0;
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	while ((get_next_line(fd, &line)))
	{
		n_lines++;
		FREE(line);
	}
	if (close(fd) == -1)
		return (0);
	(*map).tab = (t_value **)malloc(sizeof(t_value *) * n_lines + 1);
	(*map).tab[n_lines] = NULL;
	(*map).n_rows = n_lines;
	return (0);
}

static int	ft_fill_alt_color(t_map *map, char **elem_2, t_count *c, int i)
{
	if ((ft_valid_int(elem_2[0])) == 0)
		(*map).tab[i][(*c).i++].alt = ft_atoi(elem_2[0]);
	else
		return (-1);
	if (elem_2[1] && elem_2[1][0] == '0' &&
		(elem_2[1][1] == 'x' || elem_2[1][1] == 'X'))
	{
		if ((ft_valid_hex(elem_2[1] + 2)) == 0)
			(*map).tab[i][(*c).i - 1].color = ft_atoi_base(elem_2[1] + 2, 16);
	}
	else
		(*map).tab[i][(*c).i - 1].color = 0xFFFFFF;
	return (0);
}

static int	ft_fill_map(t_map *map, char *line, int i)
{
	int		size;
	char	**elem;
	t_count c;
	char	**elem_2;

	elem = ft_strsplit(line, ' ');
	size = ft_double_len((void **)elem);
	(*map).tab[i] = (t_value *)malloc(sizeof(t_value) * size);
	c.j = 0;
	c.i = 0;
	while (elem[c.j])
	{
		elem_2 = ft_strsplit(elem[c.j], ',');
		if ((ft_fill_alt_color(map, elem_2, &c, i)) == -1)
		{
			ft_free_double((void **)elem_2);
			ft_free_double((void **)elem);
			return (-1);
		}
		c.j++;
		ft_free_double((void **)elem_2);
	}
	ft_free_double((void **)elem);
	(*map).n_cols = size;
	return (0);
}

int			ft_create_map(t_map *map, char *str)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	ft_map_init(map, str);
	if (!(fd = open(str, O_RDONLY)))
		return (0);
	while ((get_next_line(fd, &line)))
	{
		if ((ft_fill_map(map, line, i)) == -1)
		{
			FREE(line);
			return (-1);
		}
		i++;
		FREE(line);
	}
	if (close(fd) == -1)
		return (0);
	return (0);
}

int			ft_draw_map(t_win *p)
{
	int		i;
	int		j;
	double	angle_1;
	double	angle_2;

	angle_1 = M_PI_2 - p->angle_1;
	angle_2 = M_PI_2 - p->angle_2;
	i = 0;
	while (p->map.tab[i])
		ft_draw_horizontal(p, i++, angle_1, angle_2);
	j = 0;
	while (j < p->map.n_cols)
		ft_draw_vertical(p, j++, angle_1, angle_2);
	return (0);
}
