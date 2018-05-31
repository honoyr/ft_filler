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

int        distance_block(t_bord *data, int *i, int *j)
{
    int     tem_y;
    int     tem_x;

//    tem_y = 0;
//    tem_x = 0;
//    len = 0;

    tem_y = *i - data->tmp_y;
    if (tem_y < 0)
        tem_y *= -1;
    tem_x = *j - data->tmp_x;
    if (tem_x < 0)
        tem_x *= -1;
    return (tem_y + tem_x);
}

void        city_block(t_bord *data)
{
    int     i;
    int     j;
    static int     len;

    i = -1;
    j = -1;
    len = 0;
    while (data->map[++i])
    {
        while (data->map[i][++j])
        {
            if(data->map[i][j] == data->enemy || data->map[i][j] == data->enemy + 32)
            {
                len = distance_block(data, &i, &j);
                if (data->dist > len)
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
            if(data->token[colum][row] == '*' && (data->map[*i][*j] == data->player || data->map[*i][*j] == data->player + 32))
            {
//                printf("POSITION = %i %i\n", *i, *j);
//                printf("POINT = %i %i\n", colum, row);
//                printf("REAL %i %i\n", *i - colum, *j - row);
                if (*i - colum >= 0 && *j - row >= 0)
                {
                    data->tmp_y = *i - colum;
                    data->tmp_x = *j - row;
                    city_block(data);
                }
//
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
}
