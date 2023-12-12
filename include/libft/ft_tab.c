/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:55:23 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/12 11:25:12 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_free_tab(char **tab, int r)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (r);
}

char	**copy_tab(char **tab)
{
	int i;
	char **copy;

	i = 0;
	copy = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	if (!copy)
		return (NULL);
	while (tab[i])
	{
		copy[i] = ft_strdup(tab[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_printf("tab[%d] = [%s]\n", i, tab[i]);
		i++;
	}
}