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

    tem_y = 0;
    tem_x = 0;

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
    int     len;

    i = -1;
    j = -1;
//    len = 0;
//    ft_printf("I'm here 1\n");
//    ft_printf("data->enemy = %c\n", data->enemy);

//    while (data->map[++i])
//    {
//        while (data->map[i][++j])
//            ft_printf("%c", data->map[i][j]);
//        ft_printf("\n");
//        j = -1;
//    }
//    i = -1;
//    j = -1;
    while (data->map[++i])
    {
        while (data->map[i][++j])
        {
            if(data->map[i][j] == data->enemy || data->map[i][j] == data->enemy + 32)
            {
//                ft_printf("I'm here 2\n");
                len = distance_block(data, &i, &j);
                if (len < data->dist)
                {
                    data->dist = len;
                    data->y = data->tmp_y;
                    data->x = data->tmp_x;
//                    ft_printf("COORDINATES = %i %i\n", data->y, data->x);
                }
            }
        }
        j = -1;
    }
}

int         check_enemy(t_bord *data, int i, int j)
{
    int     row;
    int     colum;
    int     player;
    int     enemy;
    int     star;
    int     dot;

    row = -1;
    colum = -1;
    player = 0;
    enemy = 0;
    star = 0;
    dot = 0;
    while (data->token[++colum])
    {
//        while(data->token[colum][++row])
//        {
//            if (i + colum <= data->map_y && j + row <= data->map_x && data->token[colum][row] == '*')
//                star++;
//            if(i + colum <= data->map_y && j + row <= data->map_x && data->token[colum][row] == '*' &&
//               (data->map[i + colum][j + row] != data->enemy))
//                enemy++;
//            if (i + colum <= data->map_y && j + row <= data->map_x && data->token[colum][row] == '*' &&
//                (data->map[i + colum][j + row] == data->player)) // вывод в данной части не коректен
//                player++;
//        }
        while(data->token[colum][++row] && (i + colum) < data->map_y && (j + row) < data->map_x)
        {
            if (data->token[colum][row] == '*')
                star++;
            if(data->token[colum][row] == '*' &&
               ((data->map[i + colum][j + row] != data->enemy)))
                enemy++;
//            if(data->token[colum][row] == '*' &&
//               (data->map[i + colum][j + row] == '.'))
//                dot++;
            if (data->token[colum][row] == '*' &&
                (data->map[i + colum][j + row] == data->player))
                player++;
        }
        row = -1;
    }
//    row = -1;
//    colum = -1;
//    while (data->token[++colum])
//    {
//        while(data->token[colum][++row])
//        {
//
//        }
//        row = -1;
//    }
//    ft_printf("\nSTAR = %i\nENEMY = %i\nPLAYER = %i\nCOORDIN = %i %i\n", star, enemy, player, data->tmp_y, data->tmp_x);
//    if (enemy == star)
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
//                ft_printf("TMP = %i %i\n", *i, *j);
                if (*i - colum >= 0 && *j - row >= 0)
                {
//                    ft_printf("COR = %i %i\n", *i - colum, *j - row);
                    if (check_enemy(data, (*i - colum), (*j - row)))
                    {
                        data->tmp_y = *i - colum;
                        data->tmp_x = *j - row;
//                    ft_printf("TMP = %i %i\n", data->tmp_y, data->tmp_x);
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
}
