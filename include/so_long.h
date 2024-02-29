/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:40:26 by alexandreju       #+#    #+#             */
/*   Updated: 2024/02/28 21:02:31 by alexandreju      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef HEIGHT
#  define HEIGHT 64
# endif

# ifndef WIDTH
#  define WIDTH 64
# endif

// PATH IMAGES
# define BACKGROUND "./assets/background.png"
# define JACK "./assets/jackright.png"
# define PUMPKIN "./assets/pumpkin.png"
# define WALL "./assets/wall.png"

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//a ordem da declaração tbm importa aqui, se o map estiver embaixo, n irá funcionar
typedef struct s_map
{
	char	**matrix;
	int		line;
	int		column;
}			t_map;

typedef struct s_images
{
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*portal;
	mlx_image_t	*jack;
	mlx_image_t	*gift;
}	t_images;

typedef struct s_so_long
{
	int		fd;
	mlx_t	*mlx;
	char	*file;
	t_map	map;
	t_images	images;
}			t_so_long;

// functions
void		read_map(t_so_long *data, char *filen);
void		matrix(t_so_long *data);
void		ffree(t_so_long *data);
void		init_game(t_so_long *data);
void		count_x_y(t_so_long *data);
void		draw_walls(t_so_long *data, int width, int height);
void		create_image(t_so_long *data,mlx_image_t **image, char *path, int width, int height);
int			checkmap(char c);
void		ft_hook(void* param);
#endif
