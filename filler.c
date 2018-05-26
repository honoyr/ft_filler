/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:37:56 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/25 13:37:58 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void        step_order(t_bord *data)
{
//    if (data->map)
//        free(&data->map);
    data->px = 0;
    data->py = 0;
    data->sizex = 0;
    data->sizey = 0;
//    if (data->token)
//        free(data->token);
    data->x = 0;
    data->y = 0;
    data->player = 0;
    data->map = NULL;
}

void        ft_map_creator(char *src, t_bord *data)
{
    char    **map;

    *map = NULL;
    if (src)
    {
        if (!(map = (char **)malloc(sizeof(char*) * data->sizey)))
            return ;
        while (ft_isdigit(*src) && src)
            src++;
        if (!(map = (char **)malloc(sizeof(char*) * data->sizey)))
            return ;
    }

}

void        ft_pars_bord(char *line, t_bord *data)
{
    static int  i;

    i =
    if (!data->player)
        if (ft_strstr(line, "p1") && ft_strstr(line, "dgonor"))
            data->player  = 'O';
        else
            data->player  = 'X';
    if (!data->sizey && !data->sizex)
        if (ft_strstr(line, "Plateau"))
            board_size(line, data);
    if (ft_strstr(line, "000"))
        ft_map_creator(line, data);
}

void       board_size(char *mapsize, t_bord *data)
{
    int     i;

    i = 0;
    if (ft_strstr(mapsize, "Plateau"))
    {
        data->sizey =  ft_atoi(&mapsize[8]);
        mapsize = &mapsize[8];
        while (ft_isdigit(*mapsize) && mapsize)
            mapsize++;
        while (ft_isspace(*mapsize) && mapsize)
            mapsize++;
        data->sizex =  ft_atoi(mapsize);
    }
}


int     filler(char *s)
{
    char    *line;
    int     fd;
    t_bord  data;
    static index;

    line = NULL;
    line = ft_strdup("Plateau 159 173:");
    step_order(&data);
//    while ((get_next_line(0, &line) > 0) || (!data.py && !data.px))
    while (line)
    {
        ft_pars_bord(line, &data);
        data.map = line;
        data.py = 12;
        data.px = 13;
        ft_printf("%i %i\n", data.py, data.px);
        step_order(&data);
        ft_strdel(&line);
    }
    ft_printf("%s", "11 6\n");
    return (0);
}

int     main(void)
{
//    ft_printf("%i", |);
    filler("HELLO");
    return (0);
}