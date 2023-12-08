/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:52:59 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/08 15:08:39 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include ".MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_startpos
{
	int			x;
	int			y;
	char		sens;
}				t_startpos;

typedef struct s_image
{
	char		**path;
	mlx_image_t	*nord;
	mlx_image_t	*south;
	mlx_image_t	*est;
	mlx_image_t	*west;
	mlx_image_t	*floor;
	mlx_image_t	*sky;
}				t_image;

typedef struct s_tmp
{
	int			i;
	int			j;
	int			k;
	int			l;
	float		w;
	float		x;
	float		y;
	float		z;

}				t_tmp;

typedef struct s_player
{
	float		x;
	float		y;
}				t_player;

typedef struct s_map
{
	int			size_x;
	int			size_y;
	char		**map;
}				t_map;

typedef struct s_cube
{
	t_startpos	*start;
	t_player	*player;
	t_image		*texture;
	t_map		*map;
	mlx_t		*mlx;

}				t_cube;

/*function declaration*/
// ft_error.c//
int				ft_error(char *str);
// ft_free.c//
void			ft_free_all(t_cube *cube);
// valid_arg.c//
int				ft_valid_arg(int ac, char **av, t_cube *cube);
// utils.c//
t_tmp			init_temp(void);
// map.c//
int				start_map(char **file, int len);
int				stop_map(char **file, int len);
int				valid_perso(char **file, int start);
#endif