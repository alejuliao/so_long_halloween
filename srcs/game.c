/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:11 by alexandreju       #+#    #+#             */
/*   Updated: 2024/03/05 20:11:25 by laj              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void init_game(t_so_long *data)
{
	// mlx_texture_t	*texture;
	mlx_texture_t	*logo;
	// mlx_image_t *img;
	// mlx_image_t *jack;
	int	height;
	int width;


	width = data->map.column * 64;
	height = data->map.line * 64;

	data->mlx = mlx_init(width, height, "The Nightmare Before Christmas", true);

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
	mlx_key_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
}
