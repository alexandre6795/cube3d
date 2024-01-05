/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:05:05 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/21 10:46:21 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int fd)
{
	int		i;
	char	*s;
	int		t;

	t = fd;
	i = 0;
	while (1)
	{
		s = get_next_line(t);
		if (s == NULL)
			break ;
		else
			i++;
		free(s);
	}
	close(t);
	return (i);
}
