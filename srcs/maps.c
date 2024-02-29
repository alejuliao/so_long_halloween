/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:09:10 by alexandreju       #+#    #+#             */
/*   Updated: 2024/02/28 21:44:48 by alexandreju      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ffree(t_so_long *data)
{
	int	i; //fazer um free pra quando der erro de leitura

	i = 0;
	while(data->map.matrix[i])
	{
		// ft_printf("%s",data->map.matrix[i]);
		free(data->map.matrix[i++]);
	}
		// ft_printf("aqui%s",data->map.matrix[i]);
	free(data->map.matrix);
	// mlx_terminate(data->mlx);
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
    data->map.matrix = ft_split(map,'\n');
    free(map);
	checkmap(data);
	int i = 0;
    close(data->fd);
	count_x_y(data);

}

void count_x_y(t_so_long *data)
{
	int	lines;
	int	columns;
	int	columnsf;

	lines = 0;
	columns = 0;
	// columns = ft_strlen(data->map.matrix[lines]);
	columnsf = ft_strlen(data->map.matrix[lines]);
	// while(data->map.matrix[lines])
	// {
	// 	while(data->map.matrix[lines][columns])
	// 	{
	// 		if(!checkmap((data->map.matrix[lines][columns])))
	// 		{
	// 			ft_printf("foi%c\n", data->map.matrix[lines][columns]);
	// 			ffree(data);
	// 		}
	// 		columns++;
	// 	}
	// 	ft_printf("\n");
	// 	columns = 0;
	// 	lines++;
	// }
	data->map.column = 5;
	data->map.line = columnsf;

};
void	checkmap(t_so_long *data)
{
	int i = 0;
	int f = 0;
	while(data->map.matrix[i])
	{
		while(data->map.matrix[i][f])
		{
			if(ft_strrchr("10CPE", data->map.matrix[i][f++]) == NULL)
				{
					perror("invalid map");
					ffree(data);
					exit(1);
				}
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

	// while(data->map.matrix[x][y] != NULL)
	// {
	// 	ft_printf("oi %d\n",x);
	// 	x++;
	// }

// works, but
	while(x != data->map.line + 1)
	{
		if(x == 1 || x == data->map.line)
			mlx_image_to_window(data->mlx, data->images.wall, x * WIDTH  - 64, y * HEIGHT - 64);
		// else if(x == 1 || x == data->map.line)
			// mlx_image_to_window(data->mlx, data->images.wall, x * WIDTH - 64, y * HEIGHT - 64);
		else if(y == 1 || y == data->map.column)
			mlx_image_to_window(data->mlx, data->images.wall, x * WIDTH - 64, y * HEIGHT - 64);
		if(++y > data->map.column)
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
void ft_hook(void* param)
{
	mlx_t* mlx = (mlx_t *)param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void init_game(t_so_long *data)
{
	// mlx_texture_t	*texture;
	mlx_texture_t	*logo;
	// mlx_image_t *img;
	// mlx_image_t *jack;
	int	height;
	int width;


	// height = data->map.column * 64;
	// width = data->map.line * 64;
	height = 64;
	width =  64;

	ffree(data);
	exit(1);
	data->mlx = mlx_init(width, height, "The Nightmare Before Christmas", true);
	mlx_terminate(data->mlx);

	//ICON
	logo = mlx_load_png(PUMPKIN);
	mlx_set_icon(data->mlx, logo);

	//BACKGROUND
	// texture = mlx_load_png(BACKGROUND);
	// img = mlx_texture_to_image(data->mlx, texture);
	// mlx_resize_image(img, (unsigned int)width,  (unsigned int)height);
	// mlx_delete_texture(texture);
	// mlx_image_to_window(data->mlx, img, 0, 0);
	create_image(data, &data->images.background, BACKGROUND, width, height);
	create_image(data, &data->images.wall, WALL, 64, 64);



	// texture = mlx_load_png(WALL);
	// data->images.wall = mlx_texture_to_image(data->mlx, texture);
	// mlx_delete_texture(texture);

	// mlx_image_to_window(data->mlx, jack, 0, 0);
	// texture = mlx_load_png(JACK);
	// jack = mlx_texture_to_image(data->mlx, texture);
	// mlx_image_to_window(data->mlx, jack,64,0);

	draw_walls(data, width, height);
	mlx_loop_hook(data->mlx, ft_hook, data->mlx);
	mlx_loop(data->mlx);
}

void create_image(t_so_long *data,mlx_image_t **image, char *path, int width,int height)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	*image = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
}
