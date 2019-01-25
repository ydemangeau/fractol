/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:03:04 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/25 19:16:52 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, OUTPUT_WIDTH, OUTPUT_HEIGHT, "fractol");
}

void	put_pixel(t_mlx mlx)
{
	if (mlx.i == mlx.max_iteration)
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, mlx.x, mlx.y, 0);
	else
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, mlx.x, mlx.y, (mlx.color * mlx.i));
}

int		check_error(int argc, char **argv)
{
	if (argc != 2 || (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 3) 
			|| argv[2] || argv[1][1] != '\0')
	{
		ft_putendl("Usage : fractol/ 1:Mandelbrot 2:Julia 3:Tricorn");
		exit(0);
	}
	return (ft_atoi(argv[1]));
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		return (-1);
	mlx->fract = check_error(argc, argv);
	init(mlx);
	if (mlx->fract == 1)
		mandelbrot_init(mlx);
	else if (mlx->fract == 2)
		julia_init(mlx);
	else
		tricorn_init(mlx);
	event(mlx);
	return (0);
}
