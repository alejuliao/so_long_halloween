/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:09:10 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/15 22:45:48 by alexandreju      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	b_zero(t_so_long *data)
{
	data->numbers.wall = 0;
	data->numbers.portal = 0;
	data->numbers.jack = 0;
	data->numbers.gift = 0;
}

void	read_map(t_so_long *data, char *filen)
{
	char	*line;
	char	*map;
	char	*temp;

	data->file = filen;
	data->fd = open(data->file, O_RDONLY);
	map = ft_strdup("");
	while ((line = get_next_line(data->fd)))
	{
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
		free(line);
	}
	data->map.matrix = ft_split(map, '\n');
	free(map);
	count_x_y(data);
	int i = 0;                                       // retirar depois
	while (data->map.matrix[i])                      // retirar depois
		ft_printf(">> %s\n", data->map.matrix[i++]); // retirar depois
	close(data->fd);
}

void	count_x_y(t_so_long *data)
{
	int	lines;
	int	columns;
	int	f;

	f = 0;
	lines = 0;
	b_zero(data);
	columns = ft_strlen(data->map.matrix[lines]);
	while (data->map.matrix[lines])
	{
		while (data->map.matrix[lines][f])
		{
			if (ft_strrchr("10CPE", data->map.matrix[lines][f]) == NULL)
				my_erros(data, 0, "Invalid map");
			count_c(data->map.matrix[lines][f], data);
			f++;
		}
		f = 0;
		lines++;
	}
	if (lines == columns)
		my_erros(data, 0, "Invalid map");
	data->map.line = lines;
	data->map.column = columns;
	// ft_printf("%d",data->numbers.gift);
	if (data->numbers.wall < 12 || data->numbers.portal != 1
		|| data->numbers.jack != 1 || data->numbers.gift < 1)
		my_erros(data, 0, "Something wrong with map!");
	check_walls(data);
}
void	check_walls(t_so_long *data)
{
	int	lines;
	int	columns;
	int	i;

	i = 0;
	lines = data->map.line;
	columns = data->map.column;
	// refazer
	while (columns > i)
	{
		if (data->map.matrix[0][i] != '1' || data->map.matrix[lines
			- 1][i] != '1')
			my_erros(data, 0, "The map missing wall");
		i++;
	}
	i = 0;
	while (lines > i)
	{
		if (data->map.matrix[i][0] != '1' || data->map.matrix[i][columns
			- 1] != '1')
			my_erros(data, 0, "The map missing wall");
		i++;
	}
}

void	count_c(char c, t_so_long *data)
{
	if (c == '1')
		data->numbers.wall++;
	if (c == 'E')
		data->numbers.portal++;
	if (c == 'P')
		data->numbers.jack++;
	if (c == 'C')
		data->numbers.gift++;
}
void	draw_walls(t_so_long *data, int w, int h)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_image_to_window(data->mlx, data->images.background, 0, 0);
	while (data->map.matrix[x])
	{
		while (data->map.matrix[x][y])
		{
			if (data->map.matrix[x][y] == '1')
				mlx_image_to_window(data->mlx, data->images.wall, y * w, x * h);
			if (data->map.matrix[x][y] == 'C')
				mlx_image_to_window(data->mlx, data->images.gift, y * w, x * h);
			if (data->map.matrix[x][y] == 'P')
				mlx_image_to_window(data->mlx, data->images.jack, y * w, x * h);
			if (data->map.matrix[x][y] == 'C')
				mlx_image_to_window(data->mlx, data->images.gift, y * w, x * h);
			if (data->map.matrix[x][y] == 'E')
				mlx_image_to_window(data->mlx, data->images.tree, y * w, x * h);
			y++;
		}
		y = 0;
		x++;
	}
}

void	create_image(t_so_long *data, mlx_image_t **image, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
}
