/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:52:59 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/15 11:10:05 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include ".MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_startpos
{
	int				x;
	int				y;
	char			sens;
}					t_startpos;

typedef struct s_image
{
	char			**path;
	mlx_texture_t	*nord;
	mlx_texture_t	*south;
	mlx_texture_t	*est;
	mlx_texture_t	*west;
	int				*floor;
	int				*sky;
	mlx_image_t		*black;
	mlx_image_t		*white;
	mlx_image_t		*red;
}					t_image;

typedef struct s_tmp
{
	int				i;
	int				j;
	int				k;
	int				l;
	float			w;
	float			x;
	float			y;
	float			z;

}					t_tmp;

typedef struct s_player
{
	float			x;
	float			y;
}					t_player;

typedef struct s_map
{
	int				size_x;
	int				size_y;
	int				startline;
	char			**map;
}					t_map;

typedef struct s_cube
{
	t_startpos		*start;
	t_player		*player;
	t_image			*texture;
	t_map			*map;
	mlx_t			*mlx;

}					t_cube;

/*function declaration*/
// ft_error.c//
int					ft_error(char *str);
// ft_free.c//
void				ft_free_all(t_cube *cube);
// valid_arg.c//
int					ft_valid_arg(int ac, char **av, t_cube *cube);
// utils.c//
t_tmp				init_temp(void);
void				cube_strtrim(char **tab);
void				cube_trim_nl(char **tab);
void				sizemap(t_cube *cube);
// map.c//
int					valid_perso(char **file, int start, t_cube *cube);
int					valid_tex(char *str, char **file);
int					invalid_char(char **file, int start);
// ft_flood_fill.c//
int					ft_flood_fill(t_cube *cube);
// textures.c//
int					graphique_load(t_cube *cube);
// create_world.c//
void				create_world(t_cube *cube);

#endif