/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:13:35 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/24 16:34:18 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			ft_put_pxl_image(t_scope *s, int x, int y, int colour)
{
	if (s->txtr == 1 && x < WINSIZE_W && y < WINSIZE_H)
	{
		s->txtr_y = abs((((y * 256 - WINSIZE_H * 128 + s->line_hght * 128) * \
		64) / s->line_hght) / 256);
		ft_memcpy(s->image_ptr + 4 * WINSIZE_W * y + x * 4, \
		&s->txtrs[s->id].data[s->txtr_y % 64 * s->txtrs[s->id].s_line + \
		s->txtr_x % 64 * s->txtrs[s->id].bits_per_px / 8], sizeof(int));
	}
	else if (x < WINSIZE_W && y < WINSIZE_H)
		ft_memcpy(s->image_ptr + 4 * WINSIZE_W * y + x * 4, &colour, \
		sizeof(int));
}

void			ft_drw_wll(int x, int start, int end, t_scope *s)
{
	if (s->txtr == 1)
	{
		s->id = s->map[s->map_x][s->map_y];
		if (s->side == 0)
			s->wll_x = s->raypos_y + s->wlldist * s->raydir_y;
		else
			s->wll_x = s->raypos_x + s->wlldist * s->raydir_x;
		s->txtr_x = (int)(s->wll_x * (double)(64));
		if (s->side == 0 && s->raydir_x > 0)
			s->txtr_x = 64 - s->txtr_x - 1;
		if (s->side == 1 && s->raydir_y < 0)
			s->txtr_x = 64 - s->txtr_x - 1;
		s->txtr_x = abs(s->txtr_x);
	}
	while (++start <= end)
		ft_put_pxl_image(s, x, start, s->colour);
}

void			ft_drw_sky(t_scope *s)
{
	s->txtr_x = 0;
	while (s->txtr_x < WINSIZE_W)
	{
		s->txtr_y = 0;
		while (s->txtr_y < WINSIZE_H / 2)
		{
			ft_memcpy(s->image_ptr + 4 * WINSIZE_W * s->txtr_y + s->txtr_x * 4,\
				&s->txtrs[6].data[s->txtr_y % 512 * s->txtrs[6].s_line + \
				s->txtr_x % 512 * s->txtrs[6].bits_per_px / 8], sizeof(int));
			s->txtr_y++;
		}
		s->txtr_x++;
	}
	ft_drw_flr(s);
}

void			ft_drw_flr(t_scope *s)
{
	s->txtr_x = 0;
	while (s->txtr_x < WINSIZE_W)
	{
		s->txtr_y = WINSIZE_H / 2;
		while (s->txtr_y < WINSIZE_H)
		{
			ft_memcpy(s->image_ptr + 4 * WINSIZE_W * s->txtr_y + s->txtr_x * 4,\
				&s->txtrs[5].data[s->txtr_y % 128 * s->txtrs[5].s_line + \
				s->txtr_x % 128 * s->txtrs[5].bits_per_px / 8], sizeof(int));
			s->txtr_y++;
		}
		s->txtr_x++;
	}
}
