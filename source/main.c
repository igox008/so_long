/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:54:54 by alaassir          #+#    #+#             */
/*   Updated: 2023/12/27 07:17:57 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void lk(void)
{
	system("leaks so_long");
}

char	**map_maker(char *str, size_t *last)
{
	int		fd;
	char	*line;
	char	*all;
	char	**map;

	all = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("can not open file", 1), NULL);
	line = get_next_line(fd);
	while (line)
	{
		all = ft_strjoin(all, line);
		ft_free(&line, 0, 0, 0);
		(*last)++;
		line = get_next_line(fd);
	}
	map = ft_split(all, '\n');
	return (free(all), all = NULL, map);
}

int	main(int ac, char **av)
{
	char	**map;
	size_t	last;

	last = 0;
	map = NULL;
	if (ac == 2 && check_ext(av[1]) == true)
	{
		map = map_maker(av[1], &last);
		if (!map)
			return (0);
		if (!map_chek(map, last))
			return (arr_fail(map, last),ft_putendl_fd("Invalid Map", 1), 0);
		if (!flood_fill_it(map, last))
			return (arr_fail(map, last),ft_putendl_fd("No way to win", 1), 0);
	}
	else
		return (arr_fail(map, last),ft_putendl_fd("ERROR:\nWrong input", 1),1);
	// atexit(lk);
	return (arr_fail(map, last),ft_putendl_fd("Correct", 1),0);
}
