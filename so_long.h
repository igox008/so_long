/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:02:09 by alaassir          #+#    #+#             */
/*   Updated: 2023/12/29 16:26:39 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include "libft-custom/libft.h"
# include "libft-custom/get_next_line.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_corr
{
    int	x;
    int	y;
}t_corr;

typedef struct s_map
{
    char			*map;
    struct s_map	*next;
}t_map;

void	incr(int *arr, char c);
bool	check_ext(char *str);
bool	map_chek(char **str, int last);
bool	all_one(char *first, char *last);
t_corr	get_xy(char **map, char c);
char	**arr_fail(char** array, size_t row);
char	**copy_map(char **map, int last);
bool	skip(char c);
void	flood(char **map, size_t x, size_t y, size_t rows);
bool	flood_fill_it(char **map, size_t rows);

#endif