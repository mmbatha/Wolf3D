/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headsup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:33:40 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/25 10:59:12 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_hlp_text(t_scope *s)
{
	int colour;

	colour = GREY;
	PRINT(s->mlx, s->window, 10, 10, colour, "Move: [W], [A], [S], [D] or \
	arrows");
	PRINT(s->mlx, s->window, 10, 30, colour, "Sprint: [SHIFT]");
	PRINT(s->mlx, s->window, 10, 50, colour, "Reset: [DEL]");
	PRINT(s->mlx, s->window, 10, 70, colour, "Show/Hide: [T]");
	PRINT(s->mlx, s->window, 10, 90, colour, "Show/Hide this key: [H]");
	PRINT(s->mlx, s->window, 10, 110, colour, "Quit: [ESC]");
	PRINT(s->mlx, s->window, 10, 130, RED, "Challenge: Find the WALL OF \
	MOERANE!");
}
