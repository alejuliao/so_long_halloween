/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:40:06 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/15 22:33:41 by alexandreju      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	errors(char *txt)
{
	ft_printf("%s\n", txt);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_so_long	data;


	if(ft_strncmp(ft_substr(argv[1],ft_strlen(argv[1])-4,4),".ber",4))
		exit(0);
	if (argc != 2)
		errors("The number of arguments must be 2");
	read_map(&data, argv[1]);
	init_game(&data);
	ffree(&data);
	return (0);
}
