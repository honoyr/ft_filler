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
    if ()
    {
        data->y = data->tmp_y;
        data->x = data->tmp_x;
    }
}

void        fit_token(t_bord *data, int *i, int *j)
{
    int     row;
    int     colum;
    char    c;

    row = -1;
    colum = -1;
    c = data->player == 'O' ? 'O': 'X';
    while (data->token[++colum])
    {
        while(data->token[colum][++row])
        {
            if(data->token[colum][row] == '*' && data->map[*i][*j] == c)
            {
//                printf("POSITION = %i %i\n", *i, *j);
//                printf("POINT = %i %i\n", colum, row);
//                printf("REAL %i %i\n", *i - colum, *j - row);
                if (*i - colum >= 0 && *j - row >= 0)
                {
                    data->tmp_y = *i - colum;
                    data->tmp_x = *j - row;
                }
                city_block(data);
//                ft_printf("%i %i\n", data->y, data->x);
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
}
