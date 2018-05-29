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

    row = -1;
    colum = -1;
    if (data->player == 'O')
    {
        while (data->token[++colum])
        {
            while(data->token[colum][++row])
            {
                if(data->token[colum][row] = '*' && data->map[*i][*j] == 'O')
                {
                    ft_printf("POSITION = %i %i\n", *i, *j);
                }
            }
            row = -1;
        }
    }
//    else if (data->player == 'X')
//    {
//
//    }
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
