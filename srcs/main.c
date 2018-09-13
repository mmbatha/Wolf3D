/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:32:50 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/24 17:40:21 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../libft/includes/libft.h"
#include "../includes/wolf3d.h"

static int		ft_quit(void)
{
	exit(0);
	return (0);
}

void			ft_mlx_win_init(t_scope *s)
{
	char *title;

	title = ft_strjoin("Wolf3D - ", s->map_name);
	s->mlx = mlx_init();
	s->window = mlx_new_window(s->mlx, WINSIZE_W, WINSIZE_H, title);
	ft_strdel(&title);
}

void			ft_wolf3d_init(t_scope *s)
{
	s->pos_x = 3;
	s->pos_y = 3;
	s->dir_x = -1;
	s->dir_y = 0;
	s->pln_x = 0;
	s->pln_y = 0.66;
	s->ms = 0.05;
	s->rs = 0.05;
	s->mv_up = 0;
	s->mv_dn = 0;
	s->mv_lt = 0;
	s->mv_rt = 0;
	s->txtr_x = 0;
	s->txtr_y = 0;
	ft_load_txtrs(s);
}

int				main(int argc, char **argv)
{
	t_scope		*s;

	if (argc != 2)
		ft_error_parse();
	if (!(s = ft_memalloc(sizeof(t_scope))))
		ft_error_init();
	if (!(ft_parse(s, argv)))
		ft_error_map();
	ft_mlx_win_init(s);
	mlx_hook(s->window, 17, 0L, ft_quit, s);
	mlx_hook(s->window, 2, 1L << 0, ft_frstky_press, s);
	mlx_hook(s->window, 3, 1L << 1, ft_ky_rls, s);
	s->help = 1;
	ft_wolf3d_init(s);
	ft_cast_ray(s);
	mlx_loop_hook(s->mlx, ft_mv_plyr, s);
	mlx_loop(s->mlx);
	free(&s->map[0][0]);
	free(s);
	return (0);
}
