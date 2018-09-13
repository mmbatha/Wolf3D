/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:14:19 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/25 11:47:46 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/wolf3d.h"

static void		ft_exit(void)
{
	exit(1);
}

void			ft_error_init(void)
{
	ft_putendl_fd("There was an error initialising this program!", 2);
	ft_exit();
}

void			ft_error_map(void)
{
	ft_putendl_fd("There was an error with the given map!", 2);
	ft_exit();
}

void			ft_error_parse(void)
{
	ft_putendl_fd("There was an error with the arguments passed!", 2);
	ft_putstr(USAGEMSG);
	ft_exit();
}

void			ft_error_txtrs(void)
{
	ft_putendl_fd("There was an error loading image textures!", 2);
	ft_exit();
}
