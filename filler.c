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
    data->px = 0;
    data->py = 0;
    data->map_x = 0;
    data->map_y = 0;
    data->token = NULL;
    data->x = 0;
    data->y = 0;
    data->player = 0;
    data->map = NULL;
}

char        **ft_map_creator(int y, int x)
{
    int     i;
    char **data;


    i = 0;
    if (!(data = (char**)malloc(sizeof(char*) * y + 1)))
        return (NULL);
    while (i != y)
    {
        data[i] = ft_strnew(x);
        i++;
    }
    data[i] = NULL;
    return (data);
}

void        token_size(char *token, t_bord *data, int *t)
{
    data->py =  ft_atoi(&token[6]);
    token = &token[6];
    while (ft_isdigit(*token) && token)
        token++;
    while (ft_isspace(*token) && token)
        token++;
    data->px =  ft_atoi(token);
    data->token = ft_map_creator(data->py, data->px);
    *t = 200;
}

void       board_size(char *mapsize, t_bord *data, int *c)
{
    data->map_y =  ft_atoi(&mapsize[8]);
    mapsize = &mapsize[8];
    while (ft_isdigit(*mapsize) && mapsize)
        mapsize++;
    while (ft_isspace(*mapsize) && mapsize)
        mapsize++;
    data->map_x =  ft_atoi(mapsize);
    data->map = ft_map_creator(data->map_y, data->map_x);
    *c = 300;
}

void        whoami(char *line, t_bord *data)
{
    if (ft_strstr(line, "p1") && ft_strstr(line, "dgonor"))
        data->player = 'O';
    else if (ft_strstr(line, "p2") && ft_strstr(line, "dgonor"))
        data->player = 'X';
}
void        ft_pars_bord(char *line, t_bord *data, int *i, int *t)
{
    int     order;

    order = 0;
    if (!data->player)
        whoami(line, data);
    if (!data->map_y && !data->map_x)
        if (ft_strstr(line, "Plateau"))
            board_size(line, data, t);
    if (*t > 301 && data->map)
    {
        *i += 1;
        ft_strcpy(data->map[*i], line + 4);
        ft_printf("%s\n", data->map[*i]);
        if (*i == data->map_y - 1)
            *i = *t = -1;
    }
    if (ft_strstr(line, "Piece"))
    {
        token_size(line, data, t);
        if (data->player == 'O' && data->player % 2)
            order++;
    }
    if (data->token && *t > 200)
    {
        *i += 1;
        ft_strcpy(data->token[*i], line);
        ft_printf("%s\n", data->token[*i]);
        if (*i == data->py - 1)
        {
            *i = *t = -1;
            if (!(data->player % 2) && )
                filler_algoritm(data);
            while (data->token[*i += 1])
                ft_strdel(&data->token[*i]);
        }
    }
}

//void        filler_algoritm(t_bord *data)
//{
//
//}

int     filler(char **line)
{
    int     fd;
    t_bord  data;
    static int index;
    static int token;
    int     i;

    i = 0;
    index = -1;
    token = 0;
    step_order(&data);
//    while ((get_next_line(0, &line) > 0) || (!data.py && !data.px))
    while (line[i])
    {
//        if (token > 101 && data.map)
//        {
//            index += 1;
//            ft_strcpy(data.map[index], line + 4);
//            ft_printf("%s\n", data.map[index]);
//            if (index == data.map_y - 1)
//                index = token = -1;
//        }
        ft_pars_bord(line[i], &data, &index, &token);
        ft_strdel(&line[i]);
        i++;
        token++;
    }
    ft_printf("%c\n", data.player);
    return (0);
}

int     main(void)
{
    char **line;

    line = (char**)malloc(sizeof(char*) * 25);
    line[0] = ft_strdup("# -------------- VM  version 1.1 ------------- #");
    line[1] = ft_strdup("#                                              #");
    line[2] = ft_strdup("# 42 / filler VM Developped by: Hcao - Abanlin #");
    line[3] = ft_strdup("# -------------------------------------------- #");
    line[4] = ft_strdup("launched players/dgonor.filler");
    line[5] = ft_strdup("$$$ exec p1 : [players/dgonor.filler]");
    line[6] = ft_strdup("launched players/carli.filler");
    line[7] = ft_strdup("$$$ exec p2 : [players/carli.filler]");
    line[8] = ft_strdup("Plateau 3 17:");
    line[9] = ft_strdup("    01234567890123456");
    line[10] = ft_strdup("000 ....O............");
    line[11] = ft_strdup("001 .............X...");
    line[12] = ft_strdup("002 .................");
    line[13] = ft_strdup("Piece 2 3:");
    line[14] = ft_strdup("*..");
    line[15] = ft_strdup("**.");
    line[16] = ft_strdup("<got (O): [0, 5]");
    line[17] = ft_strdup("Plateau 3 17:");
    line[18] = ft_strdup("    01234567890123456");
    line[19] = ft_strdup("000 ....o............");
    line[20] = ft_strdup("001 ....oo.......X...");
    line[21] = ft_strdup("002 .................");
    line[22] = ft_strdup("Piece 2 2:");
    line[23] = ft_strdup("**");
    line[24] = ft_strdup("..");
    line[25] = NULL;
    filler(line);
    return (0);
}