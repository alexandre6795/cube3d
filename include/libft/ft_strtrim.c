/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:21:53 by sbouheni          #+#    #+#             */
/*   Updated: 2023/12/12 09:16:18 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char  *s1, char  *set)
{
	size_t	i;
	size_t	j;

	if (set && s1)
	{
		i = 0;
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		j = ft_strlen(s1);
		while (j && ft_strrchr(set, s1[j]))
			j--;
		j = (j - i) + 1;
		free(s1);
		return (ft_substr(s1, i, j));
	}
	return (NULL);
}
