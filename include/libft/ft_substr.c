/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:52:38 by sbouheni          #+#    #+#             */
/*   Updated: 2023/12/12 10:52:45 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	substring = malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	if (ft_strlen(s) == 0 || len == 0)
		start = 0;
	ft_strlcpy(substring, s += start, len + 1);
	return (substring);
}
