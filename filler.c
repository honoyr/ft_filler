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
    data->sizex = 0;
    data->sizey = 0;
    data->token = NULL;
    data->x = 0;
    data->y = 0;
    data->player = 0;
    data->map = NULL;
}

void        ft_token_creator(t_bord *data)
{
    int     i;

    i = 0;
    if (!(data->token = (char**)malloc(sizeof(char*) * data->py)))
        return ;
    while (i != data->py)
    {
        data->token[i] = ft_strnew(data->px);
        i++;
    }
}

void        ft_map_creator(t_bord *data)
{
    int     i;

    i = 0;
    if (!(data->map = (char**)malloc(sizeof(char*) * data->sizey)))
        return ;
    while (i != data->sizey)
    {
        data->map[i] = ft_strnew(data->sizex);
        i++;
    }
}

void        token(char *token, t_bord *data, int *t)
{
    data->py =  ft_atoi(&token[6]);
    token = &token[6];
    while (ft_isdigit(*token) && token)
        token++;
    while (ft_isspace(*token) && token)
        token++;
    data->px =  ft_atoi(token);
    ft_token_creator(data);
    *t = -1;
}

void        ft_pars_bord(char *line, t_bord *data, int *i, int *t)
{
    if ((data->player != 'O' || data->player != 'X') && ft_strstr(line, "dgonor"))
        if (ft_strstr(line, "p1") && ft_strstr(line, "dgonor"))
            data->player  = 'O';
        else
            data->player  = 'X';
    if (!data->sizey && !data->sizex)
        if (ft_strstr(line, "Plateau"))
            board_size(line, data, i);
    if (*i == -1 && data->sizey != *i)
    {
        *i += 1;
        ft_strcpy(data->map[*i], line + 4);
    }
    if (ft_strstr(line, "Piece"))
        token(line, data, t);
    if (data->token && *t == -1)
    {
        *t += 1;
        ft_strcpy(data->token[*i], line);
    }
}

void       board_size(char *mapsize, t_bord *data, int *i)
{
    data->sizey =  ft_atoi(&mapsize[8]);
    mapsize = &mapsize[8];
    while (ft_isdigit(*mapsize) && mapsize)
        mapsize++;
    while (ft_isspace(*mapsize) && mapsize)
        mapsize++;
    data->sizex =  ft_atoi(mapsize);
    ft_map_creator(data);
    *i = -1;
}


int     filler(char **line)
{
    int     fd;
    t_bord  data;
    static int index;
    static int token;
    int     i;

    i = 0;
    index = 0;
    token = 0;
//    line = NULL;
//    line = ft_strdup("Piece 2 3:\n ***");
    step_order(&data);
//    while ((get_next_line(0, &line) > 0) || (!data.py && !data.px))
    while (line)
    {
        ft_pars_bord(line[i], &data, &index, &token);
//        ft_printf("%c\n", data.player);
//        ft_printf("%s\n", (*(data.map) + i));
//        ft_printf("%s\n", (*(data.token) + i));
        ft_strdel(&line[i]);
        i++;
    }
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
    line[4] = ft_strdup("launched players/carli.filler");
    line[5] = ft_strdup("$$$ exec p1 : [players/carli.filler]");
    line[6] = ft_strdup("launched players/dgonor.filler");
    line[7] = ft_strdup("$$$ exec p2 : [players/dgonor.filler]");
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