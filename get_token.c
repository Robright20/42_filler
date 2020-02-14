/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 23:16:20 by zael-mab          #+#    #+#             */
/*   Updated: 2020/02/13 01:04:27 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void        f_get_token(t_map *token)
{
	char	*line;
	int 	i;
	int 	j;

	i = token->rows;
	j = 0;
	token->content = (char*)ft_memalloc(token->rows * token->cols + 1);
	while (i-- && get_next_line(STDIN, &line) > 0)
	{
		while (line[j])
		{
			if (!(line[j] == '.' || line[j] == '*'))
				exit (EXIT_FAILURE);
			j++;
		}
		ft_strcat(token->content, line);
		free(line);
	}
	//dprintf(g_fderr, "%s", token->content);
}

void	get_token_dim(char *line, t_map *token)
{
	static t_string expect = (t_string){"Piece ", 6};
	char	**tab;
	char	*c;

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
    // dprintf(g_fderr, "\nr%d | l%d\n", token->rows, token->cols);
	if (token->rows == 0 || token->cols == 0) 
	{
		ft_putstr_fd("error token !\n", g_fderr);
		exit(EXIT_FAILURE);
	}
}
