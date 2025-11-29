/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:47:53 by vvieira           #+#    #+#             */
/*   Updated: 2025/11/29 11:48:03 by vvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	res;
	double	res2;
	int		sign;
	int		i;

	res = 0;
	res2 = 1;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		res2 /= 10;
		res = res + (str[i++] - '0') * res2;
	}
	return (res * sign);
}