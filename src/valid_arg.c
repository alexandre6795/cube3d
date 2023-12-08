/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:21:10 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/08 11:34:32 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_valid_map(char **file, t_cube *cube,int len)
{
	int	i;

	i = 0;
	while (file[i])
	{
		file[i] = ft_strtrim(file[i], " ");
		if(i == 0)
	}
}

int	ft_valid_texture(char **file, t_cube *cube)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file[i])
	{
		file[i] = ft_strtrim(file[i], " ");
		if (ft_strncmp(file[i], "NO", 2) == 0)
			cube->texture->path[count++] = ft_strdup(file[i] + 2);
		else if (ft_strncmp(file[i], "SO", 2) == 0)
			cube->texture->path[count++] = ft_strdup(file[i] + 2);
		else if (ft_strncmp(file[i], "WE", 2) == 0)
			cube->texture->path[count++] = ft_strdup(file[i] + 2);
		else if (ft_strncmp(file[i], "EA", 2) == 0)
			cube->texture->path[count++] = ft_strdup(file[i] + 2);
		else if (ft_strncmp(file[i], "C", 1) == 0)
			cube->texture->path[count++] = ft_strdup(file[i] + 1);
		else if (ft_strncmp(file[i], "F", 1) == 0)
			cube->texture->path[count++] = ft_strdup(file[i] + 1);
		i++;
	}
	if (count != 6)
		return (ft_error("texture missing"));
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
	file = malloc(sizeof(char *) * ft_size(open(av, O_RDONLY)));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			file[i++] = NULL;
			break ;
		}
		else
			file[i++] = line;
	}
	close(fd);
	if (ft_valid_texture(file, cube) != 0 || ft_valid_map(file, cube,
			ft_tablen(file)) != 0)
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
		return (ft_valid_insidefile(av[1]));
	else
		return (1);
}