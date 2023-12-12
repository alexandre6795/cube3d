/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:21:10 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 12:52:39 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_valid_map(char **file, int len, t_cube *cube)
{
	t_tmp	tmp;

	printf("coucou valid map\n");
	tmp = init_temp();
	tmp.j = start_map(file, len, true);
	tmp.k = start_map(file, len, false);
	tmp.i = tmp.j;
	if (valid_perso(file, tmp.j, cube) != 0)
		return (ft_error("map don't have initial position for user"));
	// if (valid_first_and_last_line(file[tmp.i], file[tmp.k]) != 0)
	// 	return (ft_error("map not close"));
	// while (file[tmp.i])
	// {
	// 	if (file[tmp.i][0] != '1' && file[tmp.i][ft_strlen(file[tmp.i])
	// 		- 1] != '1')
	// 		return (ft_error("map not close"));
	// 	tmp.i++;
	// }
	ft_flood_fill(cube);
	return (0);
}
int	ft_valid_texture(char **file, t_cube *cube)
{
	int		i;
	int	count;

	printf("coucou texute\n");
	i = 0;
	count = 0;
	cube_strtrim(file);
	print_tab(file);
	while (file[i])
	{
		if (count >= 6 && valid_tex(file[i]) != 0)
			return (ft_error("too many texture"));
		else if (count < 6 && valid_tex(file[i]) == 0)
			cube->texture->path[count++] = ft_strdup(file[i]);
		i++;
	}
	(void)cube;
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

	printf("coucou insidefile\n");
	i = 0;
	fd = open(av, O_RDONLY);
	file = ft_calloc(ft_size(open(av, O_RDONLY)) + 1, sizeof(char *));
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
	}
	close(fd);
	if (ft_valid_texture(file, cube) != 0 || ft_valid_map(file,
			ft_tablen(file),
			cube) != 0)
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