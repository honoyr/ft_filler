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

void        fit_token(t_bord *data, int *i, int *j)
{
    int     row;
    int     colum;
    int     map;
    char    c;

    row = -1;
    colum = -1;
    map = *i;
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
                data->y = *i - colum;
                data->x = *j - row;
//                printf("%i %i\n", *i - colum, *j - row);
//                printf("%i %i\n", *i, *j);
//                map++;
                break ;
            }
        }
        if (data->y && data->y)
            break ;
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
//    ft_printf("%i %i\n", data->p, data->x);
}
