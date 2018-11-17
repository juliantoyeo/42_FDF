/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyeo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 08:26:31 by jyeo              #+#    #+#             */
/*   Updated: 2018/03/10 08:26:33 by jyeo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_check_elem_2(char **elem_2)
{
	int		res;

	res = 0;
	if ((ft_valid_int(elem_2[0])) != 0)
		res = -1;
	if (elem_2[1])
	{
		if (elem_2[1][0] == '0' &&
			(elem_2[1][1] == 'x' || elem_2[1][1] == 'X'))
		{
			if ((ft_valid_hex(elem_2[1] + 2)) == -1)
				res = -1;
		}
		else
			res = -1;
	}
	return (res);
}

static int	ft_check_elem(char **elem)
{
	int		i;
	int		res;
	char	**elem_2;

	res = 0;
	i = 0;
	while (elem[i])
	{
		elem_2 = ft_strsplit(elem[i], ',');
		res = ft_check_elem_2(elem_2);
		i++;
		ft_free_double((void **)elem_2);
	}
	ft_free_double((void **)elem);
	return (res);
}

static int	ft_check_file(int fd)
{
	int		res;
	int		size;
	int		count;
	char	*line;
	char	**elem;

	count = 0;
	while ((res = get_next_line(fd, &line)))
	{
		if (res < 0)
			return (-1);
		elem = ft_strsplit(line, ' ');
		size = (int)ft_double_len((void **)elem);
		if (count == 0)
			count = size;
		else if (count != size)
		{
			ft_free_double((void **)elem);
			FREE(line);
			return (-1);
		}
		FERROR((ft_check_elem(elem)) == -1, line, -1);
		FREE(line);
	}
	return (0);
}

int			ft_check(int ac, char **av)
{
	int		fd;

	if (ac == 1 || ac == 2)
	{
		av[1] = "1500";
		av[2] = "1500";
	}
	ERROR(!(fd = open(av[0], O_RDONLY)), -1);
	if (ac == 0 || ac > 3 || ft_valid_int(av[1]) != 0
		|| ft_valid_int(av[2]) != 0 || ft_atoi(av[1]) > 3000
		|| ft_atoi(av[2]) > 3000 || ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0)
		return (-1);
	ERROR((ft_check_file(fd)) == -1, -1);
	ERROR((close(fd)) == -1, -1);
	return (0);
}
