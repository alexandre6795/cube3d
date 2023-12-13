/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:20:15 by akastler          #+#    #+#             */
/*   Updated: 2023/12/13 14:34:17 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int skip_wp(char *str)
{
    int i;

    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    return (i);
}

int open_textures(t_cube *cube)
{
    int i;

    i = 0;
    while(cube->texture->path[i])
    {
        if (ft_strncmp(cube->texture->path[i], "NO", 2) == 0)
            cube->texture->nord = mlx_load_png(cube->texture->path[i] + skip_wp(cube->texture->path[i] + 2) + 2);
        else if (ft_strncmp(cube->texture->path[i], "SO", 2) == 0)
            cube->texture->south = mlx_load_png(cube->texture->path[i] + skip_wp(cube->texture->path[i] + 2) + 2);
        else if (ft_strncmp(cube->texture->path[i], "EA", 2) == 0)
            cube->texture->est = mlx_load_png(cube->texture->path[i] + skip_wp(cube->texture->path[i] + 2) + 2);
        else if (ft_strncmp(cube->texture->path[i], "WE", 2) == 0)
            cube->texture->west = mlx_load_png(cube->texture->path[i] + skip_wp(cube->texture->path[i] + 2) + 2);
        i++;
    }
    if (!cube->texture->nord || !cube->texture->south || !cube->texture->est || !cube->texture->west)
        return (ft_error("Error\nTexture not found"));
    return (0);
    
}