/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:13:47 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/24 16:34:13 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_dt_init(t_scope *s)
{
	s->dltdist_x = sqrt(1 + (s->raydir_y * s->raydir_y)
			/ (s->raydir_x * s->raydir_x));
	s->dltdist_y = sqrt(1 + (s->raydir_x * s->raydir_x)
			/ (s->raydir_y * s->raydir_y));
	if (s->raydir_x < 0)
	{
		s->step_x = -1;
		s->sddist_x = (s->raypos_x - s->map_x) * s->dltdist_x;
	}
	else
	{
		s->step_x = 1;
		s->sddist_x = (s->map_x + 1.0 - s->raypos_x) * s->dltdist_x;
	}
	if (s->raydir_y < 0)
	{
		s->step_y = -1;
		s->sddist_y = (s->raypos_y - s->map_y) * s->dltdist_y;
	}
	else
	{
		s->step_y = 1;
		s->sddist_y = (s->map_y + 1.0 - s->raypos_y) * s->dltdist_y;
	}
}

void	ft_dt(t_scope *s)
{
	s->hit = 0;
	while (s->hit == 0)
	{
		if (s->sddist_x < s->sddist_y)
		{
			s->sddist_x += s->dltdist_x;
			s->map_x += s->step_x;
			s->side = 0;
		}
		else
		{
			s->sddist_y += s->dltdist_y;
			s->map_y += s->step_y;
			s->side = 1;
		}
		if (s->map[s->map_x][s->map_y] > 0)
			s->hit = 1;
	}
}

void	ft_ray_init(t_scope *s, int x)
{
	s->cam_x = 2 * x / (double)(WINSIZE_W) - 1;
	s->raypos_x = s->pos_x;
	s->raypos_y = s->pos_y;
	s->raydir_x = s->dir_x + s->pln_x * s->cam_x;
	s->raydir_y = s->dir_y + s->pln_y * s->cam_x;
	s->map_x = (int)s->raypos_x;
	s->map_y = (int)s->raypos_y;
	ft_dt_init(s);
	ft_dt(s);
	if (s->side == 0)
		s->wlldist = (s->map_x - s->raypos_x +
				(1 - s->step_x) / 2) / s->raydir_x;
	else
		s->wlldist = (s->map_y - s->raypos_y +
				(1 - s->step_y) / 2) / s->raydir_y;
}

void	ft_flr_clng(t_scope *s, int x)
{
	if (s->txtr == 0)
	{
		if (s->start > 0)
		{
			s->colour = LIGHT_BLUE;
			s->y = -1;
			if (x < WINSIZE_W && s->y < WINSIZE_H)
				while (++s->y < s->start)
				{
					ft_memcpy(s->image_ptr + 4 * WINSIZE_W * s->y + x * 4, \
					&s->colour, sizeof(int));
				}
		}
	}
	if (s->end > 0)
	{
		s->colour = DARK_GREY;
		s->y = s->end - 1;
		if (x < WINSIZE_W && s->y < WINSIZE_H)
			while (++s->y < WINSIZE_H)
				ft_memcpy(s->image_ptr + 4 * WINSIZE_W * s->y + x * 4, \
				&s->colour, sizeof(int));
	}
}

void	ft_cast_ray(t_scope *s)
{
	s->x = -1;
	s->image = mlx_new_image(s->mlx, WINSIZE_W, WINSIZE_H);
	s->image_ptr = GETDA(s->image, &s->bits_per_px, &s->s_line, &s->endn);
	if (s->txtr == 1)
		ft_drw_sky(s);
	while (++s->x < WINSIZE_W)
	{
		ft_ray_init(s, s->x);
		s->line_hght = (int)(WINSIZE_H / s->wlldist);
		s->start = -s->line_hght / 2 + WINSIZE_H / 2;
		if (s->start < 0)
			s->start = 0;
		s->end = s->line_hght / 2 + WINSIZE_H / 2;
		if (s->end >= WINSIZE_H)
			s->end = WINSIZE_H - 1;
		s->colour = (s->side == 1) ? DARK_ORANGE : LIME;
		ft_drw_wll(s->x, s->start - 1, s->end, s);
		if (s->txtr == 0)
			ft_flr_clng(s, s->x);
	}
	mlx_put_image_to_window(s->mlx, s->window, s->image, 0, 0);
	mlx_destroy_image(s->mlx, s->image);
}
