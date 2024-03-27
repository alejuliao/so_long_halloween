/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:30 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/26 21:01:12 by laj              ###   ########.fr       */
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

}
void	move(int position_x, int position_y, t_so_long *data)
{
	int x;
	int y;

	x = data->images.jack->instances[0].x + position_x;
	y = data->images.jack->instances[0].y + position_y;
	if (check_wall(data, x, y))
	{
		check_gift(data, x, y);
		data->images.jack->instances[0].x = x;
		data->images.jack->instances[0].y = y;
		data->moves = data->moves + 1;
		// ft_printf("%d\n", data->moves);
	}
}
void	check_gift(t_so_long *data, int x, int y)
{
	int	i;
	int	x_gift;
	int	y_gift;

	i = 0;
	ft_printf("gifts: %d\n", data->numbers.gift_img);
	while (i < data->numbers.gift)
	{
		x_gift = data->gift[i].image->instances[0].x;
		y_gift = data->gift[i].image->instances[0].y;
		if (x == x_gift && y == y_gift)
		{
			ft_printf("Foi aqui->?\n");
			if (data->gift[i].image->instances->enabled == 1)
			{
				data->gift[i].image->instances[0].enabled = 0;
				data->numbers.gift_img--;
			}
		}
		i++;
	}
	if(data->map.matrix[y/64][x/64] == 'E' && data->numbers.gift_img < 1)
		my_errors(data, 0, "win");
// return;
}
void	render_gift(t_so_long *data, int x, int y, int *value)
{
	create_image(data, &data->gift[*value].image, GIFT);
	mlx_image_to_window(data->mlx, data->gift[*value].image, x * 64, y * 64);
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
