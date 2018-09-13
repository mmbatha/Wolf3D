/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 07:45:54 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/24 17:27:15 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char			*ft_strjoin(char const *str1, char const *str2)
{
	char	*new_str;

	if (!(new_str = ft_strnew((ft_strlen(str1) + ft_strlen(str2)))) || !str1 \
			|| !str2)
		return (NULL);
	new_str = ft_strcpy(new_str, str1);
	new_str = ft_strcat(new_str, str2);
	return (new_str);
}
