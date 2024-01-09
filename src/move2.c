/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:27:48 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/09 09:03:45 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	rot_left(t_cube *cube)
{
	cube->player->angle -= convert_deg_pirad(1) * CAM_SENSIVITY;
	if (cube->player->angle < 0)
		cube->player->angle += convert_deg_pirad(360);
}

void	rot_right(t_cube *cube)
{
	cube->player->angle += convert_deg_pirad(1) * CAM_SENSIVITY;
	if (cube->player->angle > convert_deg_pirad(360))
		cube->player->angle -= convert_deg_pirad(360);
}
