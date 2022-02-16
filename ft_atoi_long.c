/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:07:42 by shavok            #+#    #+#             */
/*   Updated: 2022/02/02 01:06:48 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(char *str)

{
	long	ret;
	int		m;
	int		i;

	i = 0;
	m = 1;
	ret = 0;
	while ((str[i] != '\0' && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m = -1;
		i++;
	}
	if (str[i] == '0' && str[i + 1] == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * m);
}
