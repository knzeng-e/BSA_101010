/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_minimum2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knzeng-e <knzeng-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:38:23 by knzeng-e          #+#    #+#             */
/*   Updated: 2016/03/22 18:39:02 by knzeng-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	find_minimum2(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= c && b <= a)
		return (b);
	else if (c <= a && c <= b)
		return (c);
	return (a);
}
