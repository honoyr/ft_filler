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
    char    *map;
    char    *token;
    int     sizey;
    int     sizex;
    int     py;
    int     px;
}                   t_bord;

int     filler(char *s);

#endif
