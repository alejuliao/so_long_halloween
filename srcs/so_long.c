/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:40:06 by alexandreju       #+#    #+#             */
/*   Upda2ted: 2024/02/12 11:09:41 by alexandreju      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

void    errors(char *txt)
{
    ft_printf("%s\n", txt);
    exit(1);
}

int	main(int argc, char **argv)
{
    t_so_long   data;
    if(argc != 2)
        errors("The number of arguments must be 2");
    read_map(&data, argv[1]);

    init_game(&data);

    ffree(&data);
    
    return (0);
}

