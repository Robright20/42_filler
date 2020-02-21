/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fokrober <robright28@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:16:20 by zael-mab          #+#    #+#             */
/*   Updated: 2020/02/21 22:20:11 by fokrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	f_get_token(t_map *token)
{
	char	*line;
	int		i;
	int		j;

	i = token->rows;
	j = 0;
	token->content = (char*)ft_memalloc(token->rows * token->cols + 1);
	token->heatmap = NULL;
	token->charset = TOKEN_CHARSET;
	while (i-- && get_next_line(STDIN, &line) > 0)
	{
		while (line[j])
		{
			if (!(line[j] == '.' || line[j] == '*'))
				exit(EXIT_FAILURE);
			j++;
		}
		ft_strcat(token->content, line);
		free(line);
	}
}

void	get_token_dim(char *line, t_map *token)
{
	static t_string expect = (t_string){"Piece ", 6};
	char			**tab;
	char			*c;

	c = ft_strchr(line, ':');
	if (c && ft_strncmp(expect.s, line, expect.size) == 0)
	{
		*c = '\0';
		tab = ft_strsplit(&line[expect.size], ' ');
		if (ft_tab2dlen(tab) == 2 && ft_isnumber(tab[0]) && ft_isnumber(tab[1]))
		{
			token->rows = ft_atoi(tab[0]);
			token->cols = ft_atoi(tab[1]);
			token->size = token->rows * token->cols;
			ft_memdel2d((void**)tab);
		}
	}
	if (token->rows == 0 || token->cols == 0)
	{
		ft_putstr_fd("error token !\n", STDERR);
		exit(EXIT_FAILURE);
	}
}

void	ft_memdel2d(void **mem)
{
	int		i;

	i = 0;
	if (mem)
	{
		while (mem[i])
			free(mem[i++]);
		free(mem);
	}
}
