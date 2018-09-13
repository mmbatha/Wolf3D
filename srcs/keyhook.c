/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kyhook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:10:36 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/17 17:16:55 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_scndky_press(int keycode, t_scope *s)
{
	if (keycode == KEY_H)
	{
		if (s->help == 0)
			s->help = 1;
		else
			s->help = 0;
	}
	else if (keycode == KEY_T)
	{
		if (s->txtr == 0)
			s->txtr = 1;
		else
			s->txtr = 0;
	}
	return (0);
}

int		ft_frstky_press(int keycode, t_scope *s)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		s->mv_up = 1;
	else if (keycode == KEY_S || keycode == KEY_DN)
		s->mv_dn = 1;
	else if (keycode == KEY_D || keycode == KEY_RT)
		s->mv_rt = 1;
	else if (keycode == KEY_A || keycode == KEY_LT)
		s->mv_lt = 1;
	else if (keycode == KEY_LS || keycode == KEY_RS)
		s->ms = 0.1;
	else if (keycode == KEY_XC)
		exit(1);
	else if (keycode == KEY_DL)
		ft_wolf3d_init(s);
	else
		ft_scndky_press(keycode, s);
	return (0);
}

int		ft_ky_rls(int keycode, t_scope *s)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		s->mv_up = 0;
	else if (keycode == KEY_S || keycode == KEY_DN)
		s->mv_dn = 0;
	else if (keycode == KEY_D || keycode == KEY_RT)
		s->mv_rt = 0;
	else if (keycode == KEY_A || keycode == KEY_LT)
		s->mv_lt = 0;
	else if (keycode == KEY_LS || keycode == KEY_RS)
		s->ms = 0.05;
	return (0);
}

void	ft_mv_plyrside(t_scope *s)
{
	if (s->mv_rt == 1)
	{
		s->olddir_x = s->dir_x;
		s->dir_x = s->dir_x * cos(-s->rs) - s->dir_y * sin(-s->rs);
		s->dir_y = s->olddir_x * sin(-s->rs) + s->dir_y * cos(-s->rs);
		s->oldpln_x = s->pln_x;
		s->pln_x = s->pln_x * cos(-s->rs) - s->pln_y * sin(-s->rs);
		s->pln_y = s->oldpln_x * sin(-s->rs) + s->pln_y * cos(-s->rs);
	}
	if (s->mv_lt == 1)
	{
		s->olddir_x = s->dir_x;
		s->dir_x = s->dir_x * cos(s->rs) - s->dir_y * sin(s->rs);
		s->dir_y = s->olddir_x * sin(s->rs) + s->dir_y * cos(s->rs);
		s->oldpln_x = s->pln_x;
		s->pln_x = s->pln_x * cos(s->rs) - s->pln_y * sin(s->rs);
		s->pln_y = s->oldpln_x * sin(s->rs) + s->pln_y * cos(s->rs);
	}
}

int		ft_mv_plyr(t_scope *s)
{
	if (s->mv_up == 1)
	{
		if (s->map[(int)(s->pos_x + s->dir_x * s->ms)][(int)(s->pos_y)] == 0)
			s->pos_x += s->dir_x * s->ms;
		if (s->map[(int)(s->pos_x)][(int)(s->pos_y + s->dir_y * s->ms)] == 0)
			s->pos_y += s->dir_y * s->ms;
	}
	if (s->mv_dn == 1)
	{
		if (s->map[(int)(s->pos_x - s->dir_x * s->ms)][(int)(s->pos_y)] == 0)
			s->pos_x -= s->dir_x * s->ms;
		if (s->map[(int)(s->pos_x)][(int)(s->pos_y - s->dir_y * s->ms)] == 0)
			s->pos_y -= s->dir_y * s->ms;
	}
	ft_mv_plyrside(s);
	ft_cast_ray(s);
	if (s->help == 1)
		ft_hlp_text(s);
	return (0);
}
