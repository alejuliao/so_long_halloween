/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:09:10 by alexandreju       #+#    #+#             */
/*   Updated: 2024/03/05 20:05:53 by laj              ###   ########.fr       */
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
	checkmap(data);
	int i = 0;
	while (data->map.matrix[i])
		ft_printf(">> %s\n",data->map.matrix[i++]);
    close(data->fd);
}

void count_x_y(t_so_long *data)
{
	int	lines;
	int	columns;

	lines = 0;
	columns = ft_strlen(data->map.matrix[lines]);
	while(data->map.matrix[lines])
		lines++;
	data->map.line = lines;
	data->map.column = columns;
};
void	checkmap(t_so_long *data)
{
	int i = 0;
	int f = 0;
	int	x = data->map.line - 1;

	ft_printf("x%d\n", x);
	while(data->map.matrix[i])
	{
		while(data->map.matrix[i][f])
		{
			// ft_printf(">%d\n",ft_strlen(data->map.matrix[i]));
			if(ft_strrchr("10CPE", data->map.matrix[i][f]) == NULL)
				{
					perror("invalid map");
					ffree(data);
					exit(1);
				}
			if(data->map.matrix[0][f] != '1'
				|| data->map.matrix[i][0] != '1'
					// || data->map.matrix[i][data->map.line] != '1'
					// 	|| data->map.matrix[x][f] != '1'
						)
			{
				ft_printf(">>>>>%c\n", data->map.matrix[0][f]);
				perror("invalid map");
				ffree(data);
				exit(1);
			}
			f++;
		}
		f = 0;
		i++;
	}
}

void draw_walls(t_so_long *data, int width, int height)
{
	int	x;
	int y;

	x = 0;
	y = 0;

	mlx_image_to_window(data->mlx, data->images.background, 0, 0);
	mlx_resize_image(data->images.background, width,  height);
	mlx_resize_image(data->images.wall, 64,  64);

// works, but
	while(x != data->map.column + 1)
	{
		if(x == 1 || x == data->map.column)
			mlx_image_to_window(data->mlx, data->images.wall, x * WIDTH  - 64, y * HEIGHT - 64);
		// else if(x == 1 || x == data->map.line)
			// mlx_image_to_window(data->mlx, data->images.wall, x * WIDTH - 64, y * HEIGHT - 64);
		else if(y == 1 || y == data->map.line)
			mlx_image_to_window(data->mlx, data->images.wall, x * WIDTH - 64, y * HEIGHT - 64);
		if(++y > data->map.line)
		{
			y = 1;
			x++;
			// ft_putchar_fd('\n',1);
		}
	}
	// while(data->map.matrix[x])
	// {
	// 	while(data->map.matrix[x][y] && (data->map.matrix[x][y]) == '1')
	// 	{
	// 		mlx_image_to_window(data->mlx, data->images.wall, x * WIDTH  - 64, y * HEIGHT - 64);
	// 		y++;
	// 	}
	// 	y = 0;
	// 	x++;
	// }
}


void create_image(t_so_long *data,mlx_image_t **image, char *path, int width, int height)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
}
