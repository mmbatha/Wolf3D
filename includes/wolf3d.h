/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:43:23 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/25 11:13:57 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/includes/libft.h"

# define WINSIZE_H		720
# define WINSIZE_W		1280
# define USAGEMSG		"usage: ./wolf3d [valid map name]\n"

/*
** Colours
*/

# define RED    		0xFF0000
# define GOLD   		0xFFD700
# define LIME   		0x00FF00
# define BLUE   		0x0000FF
# define GREY   		0x808080
# define WHITE  		0xFFFFFF
# define LIGHT_BLUE		0x66CCFF
# define DARK_GREY		0x333333
# define DARK_ORANGE	0xDD8800
# define BLACK			0x000000
# define SKY_BLUE		0x87CEEB

/*
** Keys
*/

# define KEY_XC		53
# define KEY_UP		126
# define KEY_DN		125
# define KEY_LT		123
# define KEY_RT		124
# define KEY_H		4
# define KEY_T		17
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LS		257
# define KEY_RS		258
# define KEY_DL		117

/*
** Norm tricks
*/

# define FTOI			mlx_xpm_file_to_image
# define GETDA			mlx_get_data_addr
# define PRINT			mlx_string_put

typedef struct	s_texture
{
	void		*image;
	char		*data;
	int			bits_per_px;
	int			s_line;
	int			endn;
}				t_texture;

typedef	struct	s_scope
{
	t_texture	txtrs[8];
	char		*map_name;
	void		*mlx;
	void		*window;
	void		*image;
	void		*image_ptr;
	int			**map;
	int			new_lines;
	int			line_len;
	int			bits_per_px;
	int			endn;
	int			s_line;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_hght;
	int			start;
	int			end;
	int			colour;
	int			mv_up;
	int			mv_dn;
	int			mv_lt;
	int			mv_rt;
	int			help;
	int			txtr_x;
	int			txtr_y;
	int			id;
	int			txtr;
	int			flrtxtr_x;
	int			flrtxtr_y;
	int			x;
	int			y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		pln_x;
	double		pln_y;
	double		cam_x;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;
	double		sddist_x;
	double		sddist_y;
	double		dltdist_x;
	double		dltdist_y;
	double		wlldist;
	double		olddir_x;
	double		oldpln_x;
	double		ms;
	double		rs;
	double		wll_x;
	double		flr_x;
	double		flr_y;
	double		crflrtxtr_x;
	double		crflrtxtr_y;
	double		crdist;
	double		wght;
}				t_scope;

/*
** Draw.c
*/

void			ft_drw_sky(t_scope *s);
void			ft_drw_flr(t_scope *s);
void			ft_drw_wll(int x, int start, int end, t_scope *s);
void			ft_put_pxl_image(t_scope *s, int x, int y, int colour);

/*
** Keyhook.c
*/

int				ft_frstky_press(int keycode, t_scope *s);
int				ft_scndky_press(int keycode, t_scope *s);
int				ft_ky_rls(int keycode, t_scope *s);
void			ft_mv_plyrside(t_scope *s);
int				ft_mv_plyr(t_scope *s);

/*
** Headsup.c
*/

void			ft_hlp_text(t_scope *s);

/*
** Textures.c
*/

void			ft_load_txtrs(t_scope *s);
void			ft_reload_txtrs(t_scope *s, int a, int b);

/*
** Main.c
*/

void			ft_mlx_win_init(t_scope *s);
void			ft_wolf3d_init(t_scope *s);

/*
** Parse_map.c
*/

int				ft_chck_map(char *buff, t_scope *s);
int				ft_parse(t_scope *s, char **argv);
int				ft_reparse(t_scope *s, char **argv);

/*
** Cast_ray.c
*/

void			ft_cast_ray(t_scope *s);
void			ft_ray_init(t_scope *s, int x);
void			ft_flr_clng(t_scope *s, int x);
void			ft_dt(t_scope *s);
void			ft_dt_init(t_scope *s);

/*
** Error.c
*/

void			ft_error_map(void);
void			ft_error_init(void);
void			ft_error_parse(void);
void			ft_error_txtrs(void);

#endif
