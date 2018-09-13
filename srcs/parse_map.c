/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmbatha <mmbatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:12:29 by mmbatha           #+#    #+#             */
/*   Updated: 2018/08/24 17:54:19 by mmbatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				ft_chck_map(char *buff, t_scope *s)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	s->line_len = ft_linelen(buff);
	s->new_lines = ft_countlines(buff);
	while (buff[i] && buff[i] != '\0')
	{
		if ((buff[i] < 48 || buff[i] > 57) && buff[i] != ' ' && buff[i] != '\n')
			return (0);
		len++;
		if (buff[i] == '\n')
		{
			if (len - 1 != s->line_len)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}

int				ft_reparse(t_scope *s, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(s->map[i] = ft_memalloc(sizeof(int) * s->line_len)))
			return (0);
		while (++j < s->line_len)
		{
			if (str[k] == ' ')
				k++;
			s->map[i][j] = ft_atoi(&str[k]);
			k++;
		}
		i++;
		free(str);
	}
	return (1);
}

static int		ft_chck_side(t_scope *s)
{
	int		i;

	i = 0;
	while (i < s->line_len)
	{
		if (s->map[0][i] == 0)
			return (0);
		if (s->map[s->new_lines - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < s->new_lines)
	{
		if (s->map[i][0] == 0)
			return (0);
		if (s->map[i][s->line_len - 1] == 0)
			return (0);
		i++;
	}
	if (s->map[3][3] != 0)
		return (0);
	return (1);
}

int				ft_parse(t_scope *s, char **argv)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_strnew(65536);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
		ft_error_parse();
	if (!(ft_chck_map(buff, s)))
		ft_error_map();
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i++] == ' ')
			s->line_len--;
	}
	ft_strdel(&buff);
	s->map_name = argv[1];
	close(fd);
	if (!(s->map = ft_memalloc(sizeof(int *) * s->new_lines))
			|| !(ft_reparse(s, argv)))
		return (0);
	if (!ft_chck_side(s))
		ft_error_map();
	return (1);
}
