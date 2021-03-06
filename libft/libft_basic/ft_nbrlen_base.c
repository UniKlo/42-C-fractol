/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:54:39 by khou              #+#    #+#             */
/*   Updated: 2019/02/18 02:20:21 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_nbrlen_base(int nbr, int base)
{
	int l;

	l = 0;
	while (nbr)
	{
		l++;
		nbr /= base;
	}
	return (l);
}
