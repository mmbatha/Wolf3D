/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 18:29:51 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/23 18:29:54 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_linelen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != '\n')
		count++;
	return (count);
}
