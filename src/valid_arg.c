/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:21:10 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/05 16:11:04 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_valid_texture(char **map)
{
}

int	valid_insidefile(char *av)
{
	int		fd;
	char	*line;
	int		i;
	char	**file;

	i = 0;
	fd = open(av, O_RDONLY);
	file = malloc(sizeof(char *) * fd_size(fd));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			file[i] = NULL;
			break ;
		}
		else
			file[i++] = line;
		close(fd);
		if (ft_valid_texture(file) != 0 || ft_valid_map(file) != 0)
			return (ft_free_tab(file, 1));
		return (ft_free_tab(file, 0));
	}
}

int	ft_valid_file(char *av)
{
	char	*s;
	int		i;
	int		fd;

	i = ft_strlen(av[1]);
	if (av[i - 4] == '.' && av[i - 5] == '/' && av[i - 4])
	{
		ft_error("file .cub is not correct\n");
		return (1);
	}
	s = av[1] + i - 4;
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

int	ft_valid_arg(ac, av);
{
	int err;

	err = 0;
	if (ac != 2)
		err += ft_error("Invalid number of arguments");
	if (ft_valid_file(av[1]) == 0)
		err += ft_valid_insidefile(av[1]);
	else
		err += 1;

	if (err != 0)
		return (1);
}