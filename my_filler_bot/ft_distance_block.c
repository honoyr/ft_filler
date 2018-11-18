/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:30:55 by dgonor            #+#    #+#             */
/*   Updated: 2018/06/05 16:30:57 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int			distance_block(t_bord *data, int *i, int *j)
{
	int		tem_y;
	int		tem_x;

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
