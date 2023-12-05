/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:24:07 by aherrman          #+#    #+#             */
/*   Updated: 2023/12/05 15:51:01 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	ft_error(char *str)
{
	ft_putstr_fd("Error ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}