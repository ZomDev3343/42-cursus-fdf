/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:49:30 by truello           #+#    #+#             */
/*   Updated: 2024/01/17 19:52:21 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_strrepl(char *str, char bef, char aft)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == bef)
			str[i] = aft;
}
