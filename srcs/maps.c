/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:09:10 by alexandreju       #+#    #+#             */
/*   Updated: 2024/02/13 22:43:33 by alexandreju      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#define BPP sizeof(int32_t)

void	ffree(t_so_long *data)
{
	int	i;

	i = 0;
	while(data->map.matrix[i])
		free(data->map.matrix[i++]);
	free(data->map.matrix);
}
void	read_map(t_so_long *data, char *filen)
{
	char	*line;
	char	*map;
	char	*temp;

	data->file = filen;
	data->fd = open(data->file, O_RDONLY);
	map = ft_strdup("");
	while (line = get_next_line(data->fd))
	{
		temp = ft_strjoin(map, line);
		free(map);
		map = temp;
		free(line);
	}
    data->map.matrix = ft_split(map,'\n');
    free(map);
	int i = 0;
	while(data->map.matrix[i])
	{
		ft_printf("%s\n",data->map.matrix[i++]);
	}
	
    close(data->fd);
	count_x_y(data);
}

void count_x_y(t_so_long *data)
{
	int	lines;
	int	columns;
	
	lines = 0;
	columns = ft_strlen(data->map.matrix[lines]);
	while(data->map.matrix[lines])
		++lines;
	data->map.column = columns;
	data->map.line = lines;
	ft_printf("lines %d\n",data->map.line);	
	ft_printf("columns %d\n",data->map.column);	
};

void draw_walls(t_so_long *data)
{
	int	x;
	int y;
	mlx_texture_t	*texture;
	mlx_image_t *jack;

	x = 1;
	y = 1;

printf("%p\n",data->images.walls);
	while(x != data->map.line + 1)
	{
		if(x == 1 || x == data->map.column)
			mlx_image_to_window(data->mlx, data->images.walls, (x*64) -64, (y*64)-64);
		else if(x == 1 || x == data->map.line)
			mlx_image_to_window(data->mlx, data->images.walls, (x*64) -64, (y*64)-64);
		else if(y == 1 || y == data->map.column)
			mlx_image_to_window(data->mlx, data->images.walls, (x*64) -64, (y*64)-64);
		else
			mlx_image_to_window(data->mlx, data->images.background, (x*64) -64, (y*64)-64);
		if(++y > data->map.column)
		{
			y = 1;
			x++;
			ft_putchar_fd('\n',1);
		}
	}
	
	
}
void init_game(t_so_long *data)
{
	mlx_texture_t	*logo;
	mlx_image_t	*texture;
	mlx_image_t *img;
	mlx_image_t *jack;
	int	height;
	int width;
	

	height = 320;
	width = 1000;

	data->mlx = mlx_init(width, height, "The Nightmare Before Christmas", true);
	//ICON
	logo = mlx_load_png(PUMPKIN);
	mlx_set_icon(data->mlx, logo);
	
	//BACKGROUND
	texture = mlx_load_png(BACKGROUND);
	data->images.background = mlx_texture_to_image(data->mlx, texture);
	mlx_resize_image(img, 64,  64);
	mlx_delete_texture(texture);
	// mlx_image_to_window(data->mlx, img, 0, 0);
    
	texture = mlx_load_png(WALL);
	data->images.walls = mlx_texture_to_image(data->mlx, texture);
	mlx_resize_image(img, (unsigned int)width,  (unsigned int)height);
	mlx_delete_texture(texture);
	
	// mlx_image_to_window(data->mlx, jack, 0, 0);
	// texture = mlx_load_png(JACK);
	// jack = mlx_texture_to_image(data->mlx, texture);
	// mlx_image_to_window(data->mlx, jack,64,0);
	
	draw_walls(data);
	mlx_loop(data->mlx);
}