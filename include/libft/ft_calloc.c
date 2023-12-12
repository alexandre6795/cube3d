/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:24:16 by sbouheni          #+#    #+#             */
/*   Updated: 2023/12/12 10:54:15 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			length;
	unsigned char	*location;

	length = count * size;
	location = malloc(length);
	if (location)
	{
		ft_bzero(location, length);
		return (location);
	}
	errno = ENOMEM;
	return (NULL);
}
