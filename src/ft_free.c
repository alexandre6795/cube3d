/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:17:21 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/06 09:22:23 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

free_all_mlx(t_cube *cube)
{
    if(cube->texture->nord!=NULL)
    mlx_destroy_image(cube->mlx, cube->texture->nord);
    if(cube->texture->south!=NULL)
    mlx_destroy_image(cube->mlx, cube->texture->south);
    if(cube->texture->est!=NULL)
    mlx_destroy_image(cube->mlx, cube->texture->est);
    if(cube->texture->west!=NULL)
    mlx_destroy_image(cube->mlx, cube->texture->west);
    if(cube->texture->floor!=NULL)
    mlx_destroy_image(cube->mlx, cube->texture->floor);
    if(cube->texture->sky!=NULL)
    mlx_destroy_image(cube->mlx, cube->texture->sky);
    if(cube->mlx!=NULL)
    mlx_destroy(cube->mlx);
}

free_all_char(t_cube *cube)
{
  if(cube->map->map!=NULL)
  ft_free_tab(cube->map->map);
}

ft_free_all(t_cube *cube)
{
    free_all_mlx(cube);
    free_all_char(cube);
    free(cube->start);
    free(cube->player);
    free(cube->texture);
    free(cube->map);
    free(cube);
}