/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:21:10 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 15:19:20 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_valid_map(char **file, t_cube *cube)
{
	if (invalid_char(file, cube->map->startline) != 0)
		return (ft_error("invalid char in map"));
	if (valid_perso(file, cube->map->startline, cube) != 0)
		return (ft_error("map don't have initial position for user"));
	ft_flood_fill(cube);
	return (0);
}
int	ft_valid_texture(char **file, t_cube *cube)
{
	int		i;
	int		count;
	char	**tmp;

	tmp = copy_tab(file);
	i = 0;
	count = 0;
	cube_strtrim(tmp);
	while (tmp[i])
	{
		if (count >= 6 && valid_tex(tmp[i]) != 0)
			return (ft_free_tab(tmp, ft_error("too many texture")));
		else if (count <= 5 && valid_tex(tmp[i]) != 0)
			cube->texture->path[count++] = ft_strdup(tmp[i]);
		else if (ft_strlen(tmp[i]) != 0)
			break ;
		i++;
	}
	ft_free_tab(tmp, 0);
	cube->map->startline = i;
	if (count < 6)
		return (ft_error("error on texture"));
	return (0);
}

int	valid_insidefile(char *av, t_cube *cube)
{
	int		fd;
	char	*line;
	int		i;
	char	**file;

	i = 0;
	fd = open(av, O_RDONLY);
	file = ft_calloc(ft_size(open(av, O_RDONLY)) + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		else
			file[i++] = line;
	}
	cube_trim_nl(file);
	close(fd);
	if (ft_valid_texture(file, cube) != 0 || ft_valid_map(file, cube) != 0)
		return (ft_free_tab(file, 1));
	return (ft_free_tab(file, 0));
}

int	ft_valid_file(char *av)
{
	char	*s;
	int		i;
	int		fd;

	i = ft_strlen(av);
	if (i < 5)
	{
		ft_error("file don't have 4 caracter in name\n");
		return (1);
	}
	s = av + i - 4;
	if (ft_strncmp(s, ".cub", 4) != 0)
	{
		ft_error("file extention is not .cub \n");
		return (1);
	}
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (ft_error("can't open file"));
	close(fd);
	return (0);
}

int	ft_valid_arg(int ac, char **av, t_cube *cube)
{
	if (ac != 2)
		return (ft_error("Invalid number of arguments"));
	if (ft_valid_file(av[1]) == 0)
		return (valid_insidefile(av[1], cube));
	else
		return (1);
}