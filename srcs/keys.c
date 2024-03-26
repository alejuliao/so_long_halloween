/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:30 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/25 22:09:33 by laj              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_hook(mlx_key_data_t key, void *param)
{
	t_so_long	*data;

	data = (t_so_long *)param;
	if (key.key == MLX_KEY_ESCAPE)
		my_errors(data, 1,"You leave the presents to Sandy Claws ");
	// refazer - verificar se é parede ou nao - refazer as keys
	if ((key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
		&& key.action == MLX_PRESS)
	{
		move(0, -64, data);
	}
	if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		move(0, +64, data);
	}
	if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		move(-64, 0, data);
	}
	if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		move(+64, 0, data);

	}
	data->moves = data->moves + 1;
	// refazer - contador
	ft_printf("%d\n", data->moves);
}
void	move(int position_x, int position_y, t_so_long *data)
{
	int x;
	int y;
	int i;

	i = 0;
	x = data->images.jack->instances[0].x + position_x;
	y = data->images.jack->instances[0].y + position_y;
	if (check_wall(data, x, y))
	{
		check_gift(data, x, y);
		data->images.jack->instances[0].x = x;
		data->images.jack->instances[0].y = y;
	}

}
void	check_gift(t_so_long *data, int x, int y)
{
	int	i;
	int	x_potion;
	int	y_potion;

	i = -1;

	while (i < data->numbers.gift)
	{
		x_potion = data->images.gift[i].image->instances[0].x;
		y_potion = data->images.gift[i].image->instances[0].y;
		if (x == x_potion && y == y_potion)
		{
			if (data->images.gift[i].image->instances->enabled == 1)
			{
				data->images.gift[i].image->instances[0].enabled = 0;
				data->numbers.gift_img--;
			}
			if (data->numbers.gift_img == 0)
				data->images.portal->enabled = 1;
			return;
		}
		i++;
	}
return;
	// 	int	i;

	// i = 0;
	// while (i < data->numbers.gift)
	// {
	// 	if ((data->images.gift.image->instances[i].x == x
	// 			&& data->images.gift.image->instances[i].y == y)
	// 		&& data->images.gift.image->instances[i].enabled)
	// 	{
	// 			data->images.gift.image->instances[i].enabled = false;
	// 			data->numbers.gift--;
	// 	}
	// 	i++;
	// }
	// if(data->map.matrix[y/64][x/64] == 'E' && data->numbers.gift < 1)
	// 	my_errors(data, 0, "win");
	// return (0);
		// if(data->map.matrix[y/64][x/64] == 'C')
		// {
		// 	data->images.gift->instances[1].enabled = false;
		// 	ft_printf("antes%c\n", data->map.matrix[y/64][x/64]);
		// 	data->map.matrix[y/64][x/64] == '0';
		// 	ft_printf("antes%c\n", data->map.matrix[y/64][x/64]);
		// 	data->numbers.gift--;
		// 	// mlx_image_to_window(data->mlx, data->images.tree, x , y);
		// }
}
void	render_gift(t_so_long *data, int x, int y, int *value)
{
	create_image(data, &data->images.gift[*value].image, GIFT);
	mlx_image_to_window(data->mlx, \
	data->images.gift[*value].image, x * 64, y * 64);
	(*value)++;
}
int	check_wall(t_so_long *data, int x, int y)
{
	int	wall_x;
	int	wall_y;
	int	i;

	i = 0;
	while (data->numbers.wall > i++)
	{

		wall_x = data->images.wall->instances[i].x;
		wall_y = data->images.wall->instances[i].y;
		if (wall_x == x && wall_y == y)
			return (0);
	}
	return (1);
}
