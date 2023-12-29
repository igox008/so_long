/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:38:38 by alaassir          #+#    #+#             */
/*   Updated: 2023/12/28 14:13:06 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	incr(int *arr, char c)
{
	if (c == '0')
		arr[0]++;
	else if (c == '1')
		arr[1]++;
	else if (c == 'C')
		arr[2]++;
	else if (c == 'E')
		arr[3]++;
	else if (c == 'P')
		arr[4]++;
}

bool	all_one(char *first, char *last)
{
	size_t	i;

	i = 0;
	while (first[i] && last[i])
	{
		if (first[i] != '1' || last[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

t_corr	get_xy(char **map, char c)
{
	size_t	i;
	size_t	j;
	t_corr	p;

	i = 0;
	p.x = 0;
	p.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				p.x = j;
				p.y = i;
				return (p);
			}
			j++;
		}
		i++;
	}
	return (p);
}
