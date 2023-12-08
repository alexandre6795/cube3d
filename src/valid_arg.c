/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:21:10 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/08 15:20:46 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_valid_map(char **file, t_cube *cube, int len)
{
	t_tmp	tmp;

	tmp = init_temp();
	tmp.j = start_map(file, len);
	tmp.k = end_map(file, len);
	tmp.i = tmp.j;
	while (file[tmp.i])
	{
		file[tmp.i] = ft_strtrim(file[tmp.i], " ");
		if (tmp.i == tmp.j || tmp.i == tmp.k)
		{
			if (file[tmp.i][0] != '1' && file[tmp.i][0] != ' ')
				return (ft_error("map not close"));
		}
		else
		{
			if (file[tmp.i][0] != '1' && file[tmp.i][ft_strlen(file[tmp.i])
				- 1] != '1')
				return (ft_error("map not close"));
		}
		tmp.i++;
	}
	if (valid_perso(file, tmp.j) != 0)
		return (ft_error("map don't have initial position for user"));
	return (0);
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
		if (count >= 6 && ft_valid_tex(file[i]) != 0)
			return (ft_error("too many texture"));
		else
			cube->texture->path[count++] = ft_strdup(file[i]);
		i++;
	}
	if (count > 6)
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