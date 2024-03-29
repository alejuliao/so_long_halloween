/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:40:26 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/26 20:29:42 by laj              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # ifndef HEIGHT
// #  define HEIGHT 64
// # endif

// # ifndef WIDTH
// #  define WIDTH 64
// # endif


# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


// PATH IMAGES
# define BACKGROUND "./assets/background.png"
# define JACK "./assets/jackright.png"
# define PUMPKIN "./assets/pumpkin.png"
# define WALL "./assets/wall.png"
# define GIFT "./assets/gift.png"
# define TREE "./assets/tree.png"


typedef struct s_gift
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}				t_gift;


// a ordem da declaração tbm importa aqui, se o map estiver embaixo,n irá funcionar
typedef struct s_map
{
	char		**matrix;
	int			line;
	int			column;
}				t_map;

typedef struct s_images
{
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*portal;
	mlx_image_t	*jack;
	mlx_image_t	*tree;
}				t_images;


typedef struct s_numbers
{
	int	background;
	int	wall;
	int	portal;
	int	jack;
	int	gift;
	int	tree;
	int	gift_img;
}				t_numbers;

typedef struct s_so_long
{
	int			fd;
	mlx_t		*mlx;
	char		*file;
	t_map		map;
	t_images	images;
	int			moves;
	t_numbers	numbers;
	t_gift		gift[1000];
}				t_so_long;

// functions
void	read_map(t_so_long *data, char *filen);
void	matrix(t_so_long *data);
void	ffree(t_so_long *data);
void	ft_hook(mlx_key_data_t key, void *param);
void	init_game(t_so_long *data);
void	count_x_y(t_so_long *data);
void	draw_walls(t_so_long *data, int width, int height);
void	create_image(t_so_long *data, mlx_image_t **image, char *path);
void	my_errors(t_so_long *data, int mlx_valid, char *message);
void	count_c(char c, t_so_long *data);
void	b_zero(t_so_long *data);
void	check_walls(t_so_long *data);
void	move(int	position_x, int position_y, t_so_long *data);
int		check_wall(t_so_long *core, int x, int y);
void	check_gift(t_so_long *data, int x, int y);
void	render_gift(t_so_long *data, int x, int y, int *value);

#endif
