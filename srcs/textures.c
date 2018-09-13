/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 08:38:55 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/25 11:10:06 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_load_txtrs(t_scope *s)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	s->txtrs[0].image = FTOI(s->mlx, "textures/0.xpm", &a, &b);
	s->txtrs[0].data = GETDA(s->txtrs[0].image, &s->txtrs[0].bits_per_px, \
			&s->txtrs[0].s_line, &s->txtrs[0].endn);
	s->txtrs[1].image = FTOI(s->mlx, "textures/1.xpm", &a, &b);
	s->txtrs[1].data = GETDA(s->txtrs[1].image, &s->txtrs[1].bits_per_px, \
			&s->txtrs[1].s_line, &s->txtrs[1].endn);
	s->txtrs[2].image = FTOI(s->mlx, "textures/2.xpm", &a, &b);
	s->txtrs[2].data = GETDA(s->txtrs[2].image, &s->txtrs[2].bits_per_px, \
			&s->txtrs[2].s_line, &s->txtrs[2].endn);
	s->txtrs[3].image = FTOI(s->mlx, "textures/3.xpm", &a, &b);
	s->txtrs[3].data = GETDA(s->txtrs[3].image, &s->txtrs[3].bits_per_px, \
			&s->txtrs[3].s_line, &s->txtrs[3].endn);
	s->txtrs[4].image = FTOI(s->mlx, "textures/4.xpm", &a, &b);
	s->txtrs[4].data = GETDA(s->txtrs[4].image, &s->txtrs[4].bits_per_px, \
			&s->txtrs[4].s_line, &s->txtrs[4].endn);
	s->txtrs[7].image = FTOI(s->mlx, "textures/m64.xpm", &a, &b);
	s->txtrs[7].data = GETDA(s->txtrs[7].image, &s->txtrs[7].bits_per_px, \
			&s->txtrs[7].s_line, &s->txtrs[7].endn);
	ft_reload_txtrs(s, a, b);
}

void	ft_reload_txtrs(t_scope *s, int a, int b)
{
	s->txtrs[5].image = FTOI(s->mlx, "textures/5.xpm", &a, &b);
	s->txtrs[5].data = GETDA(s->txtrs[5].image, &s->txtrs[5].bits_per_px, \
	&s->txtrs[5].s_line, &s->txtrs[5].endn);
	a = 512;
	b = 512;
	s->txtrs[6].image = FTOI(s->mlx, "textures/sky.xpm", &a, &b);
	s->txtrs[6].data = GETDA(s->txtrs[6].image, &s->txtrs[6].bits_per_px, \
	&s->txtrs[6].s_line, &s->txtrs[6].endn);
}
