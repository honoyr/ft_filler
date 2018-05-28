/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:56:26 by dgonor            #+#    #+#             */
/*   Updated: 2018/05/25 13:56:27 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER
# define FT_FILLER

# include "./libft/libft.h"

typedef struct      s_bord
{
    int     y;
    int     x;
    char    **map;
    char    **token;
    char    player;
    int     sizey;
    int     sizex;
    int     py;
    int     px;
}                   t_bord;

int     filler(char **line);

void        ft_pars_bord(char *line, t_bord *data, int *i, int *t);
void        ft_token_creator(t_bord *data);
void        ft_map_creator(t_bord *data);
void        token(char *token, t_bord *data, int *t);
void       board_size(char *mapsize, t_bord *data, int *i);

#endif
