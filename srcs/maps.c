/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:09:10 by alexandreju       #+#    #+#             */
/*   Updated: 2024/03/06 20:56:28 by alexandreju      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
    data->map.matrix = ft_split(map,'\n');
    free(map);
	count_x_y(data);
	// exit(0);
	// checkmap(data);
	int i = 0;
	while (data->map.matrix[i])
		ft_printf(">> %s\n",data->map.matrix[i++]);
    close(data->fd);
}

void count_x_y(t_so_long *data)
{
	int	lines;
	int	columns;
	int	f;
	
	
	f=0;
	lines = 0;
	columns = ft_strlen(data->map.matrix[lines]);
	while(data->map.matrix[lines])
	{
		while(data->map.matrix[lines][f])
		{
			if(ft_strrchr("10CPE", data->map.matrix[lines][f]) == NULL)
				my_erros(data, "Invalid map");
			f++;
		}
		f=0;
		lines++;
	}
	data->map.line = lines;
	data->map.column = columns;
};

void draw_walls(t_so_long *data, int width, int height)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	mlx_image_to_window(data->mlx, data->images.background, 0, 0);
	while(data->map.matrix[x])
	{
		while(data->map.matrix[x][y])
		{
			if(data->map.matrix[x][y] == '1')
				mlx_image_to_window(data->mlx, data->images.wall, y * width, x * height );
			if(data->map.matrix[x][y] == 'C')
				mlx_image_to_window(data->mlx, data->images.gift, y * width, x * height );
			if(data->map.matrix[x][y] == 'P')
				mlx_image_to_window(data->mlx, data->images.jack, y * width, x * height );
			if(data->map.matrix[x][y] == 'C')
				mlx_image_to_window(data->mlx, data->images.gift, y * width, x * height );
			if(data->map.matrix[x][y] == 'E')
				mlx_image_to_window(data->mlx, data->images.tree, y * width, x * height );
			y++;
		}
		y = 0;
		x++;
	}
}


void create_image(t_so_long *data,mlx_image_t **image, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
}
