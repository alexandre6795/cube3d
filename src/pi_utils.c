/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:15:52 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/21 11:05:04 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

float	convert_deg_pirad(float deg)
{
	return ((deg / 180) * PI);
}

float	convert_pirad_deg(float pirad)
{
	return ((pirad / PI) * 180);
}
