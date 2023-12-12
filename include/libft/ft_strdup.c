/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:23:41 by sbouheni          #+#    #+#             */
/*   Updated: 2023/12/12 12:55:16 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;

	new_str = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (new_str)
	{
		ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
		return (new_str);
	}
	errno = ENOMEM;
	return (NULL);
}
