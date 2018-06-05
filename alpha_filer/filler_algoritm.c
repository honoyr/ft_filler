/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_algoritm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:47:00 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/29 18:47:02 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void        city_block(t_bord *data)
{
	int     i;
	int     j;
	int     len;

	i = -1;
	j = -1;
	while (data->map[++i])
	{
		while (data->map[i][++j])
		{
			if(data->map[i][j] == data->enemy)
			{
				len = distance_block(data, &i, &j);
				if (len < data->dist)
				{
					data->dist = len;
					data->y = data->tmp_y;
					data->x = data->tmp_x;
				}
			}
		}
		j = -1;
	}
}

// int			help_check_enemy(t_bord *data, int column, int *row)
// {
// 	while(data->token[column][++row] && ((j + row) < data->map_x))
// 	{
// 		if (data->token[column][row] == '*')
// 			star++;
// 		if((data->token[column][row] == '*') &&
// 			(data->map[i + column][j + row] != data->enemy))
// 			enemy++;
// 		if ((data->token[column][row] == '*') &&
// 		(data->map[i + column][j + row] == data->player))
// 			player++;
// 		*row += 1;
// 	}
// }

int         check_enemy(t_bord *data, int i, int j)
{
	int     row;
	int     column;
	int     player;
	int     enemy;
	int     star;

	row = -1;
	column = -1;
	player = 0;
	enemy = 0;
	star = 0;
	while (data->token[++column] && ((i + column) < data->map_y))
	{
		while(data->token[column][++row] && ((j + row) < data->map_x))
		{
			if (data->token[column][row] == '*')
				star++;
			if(data->token[column][row] == '*' &&
				((data->map[i + column][j + row] != data->enemy)))
				enemy++;
			if (data->token[column][row] == '*' &&
				(data->map[i + column][j + row] == data->player))
				player++;
		}
		// help_check_enemy(data, column, &row)
		if (row < data->px)
		{
			while (data->token[column][row])
			{
				if (data->token[column][row] == '*')
					return (0);
				row++;
			}
		}
		row = -1;
	}
	if (column < data->py)
		return (0);
	if (enemy == star && player == 1)
		return (1);
	return (0);
}

void        fit_token(t_bord *data, int *i, int *j)
{
	int     row;
	int     colum;

	row = -1;
	colum = -1;
	while (data->token[++colum])
	{
		while(data->token[colum][++row])
		{
			if(data->token[colum][row] == '*' &&
			   (data->map[*i][*j] == data->player))
			{
				if (*i - colum >= 0 && *j - row >= 0)
				{
					if (check_enemy(data, (*i - colum), (*j - row)))
					{
						data->tmp_y = *i - colum;
						data->tmp_x = *j - row;
						city_block(data);
					}
				}
			}
		}
		row = -1;
	}
}

void        filler_algoritm(t_bord *data)
{
	int     i;
	int     j;

	i = j = -1;
	while (data->map[++i])
	{
		while (data->map[i][++j])
		{
			fit_token(data, &i, &j);
		}
		j = -1;
	}
	ft_printf("%i %i\n", data->y, data->x);
	data->dist = 10000;
	data->column = -1;
	data->row = -1;
}
