#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"

#define MALLOC_ERROR 1
#define WIDTH   400
#define HEIGHT  400 

int main()
{
    void    *mlx_ptr;

    mlx_ptr = mlx_init(WIDTH,HEIGHT, "so_long" ,true);
    if (NULL == mlx_ptr)
        return (1);

    mlx_terminate(mlx_ptr);

    free(mlx_ptr); ptr:
    return(0);
}
// int main(void)
// {
//     int     fd;
//     char    *line;
//     int     lines;
    
//     // lines = 1;
//     // fd = open("filetext.txt", O_RDONLY);
//     // while((line = get_next_line(fd)))
//     //     ft_printf("%d->%s\n", lines++, line);
//     return (0);
// }