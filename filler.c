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
}

int     filler(char *s)
{
    char    *line;
    int     fd;
    t_bord  data;

    line = NULL;
//    if ((fd = open("test.rtf", O_RDONLY)) < 0)
//        return (-1);
    step_order(&data);
    while ((get_next_line(0, &line) > 0) || (!data.py && !data.px))
    {
        step_order(&data);
        data.map = line;
        data.py = 0;
        data.px = 0;
        ft_printf("%i %i\n", data.py, data.px);

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