/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:03:04 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/23 20:47:36 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_mlx	init()
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, OUTPUT_WIDTH, OUTPUT_HEIGHT, "fractol");
	mlx.start_x = -0.75;
	mlx.start_y = 0.0;
	mlx.zoom = 0.8;
	mlx.x = -1;
	mlx.y = -1;
	return (mlx);
}

void	put_pixel(t_mlx mlx)
{
	if (mlx.i == MAX_ITERATION)
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, mlx.x, mlx.y, 0);
	else
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, mlx.x, mlx.y, (265 * mlx.i));
}

int		key_event(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == 6)
	{
		mlx->zoom += 0.5;
		mandelbrot(*mlx);
	}
	return (0);
}

int		check_error(int argc, char **argv)
{
	if (argc != 2 || (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 3) || argv[2])
	{
		ft_putendl("Usage : fractol/ 1:Mandelbrot 2:Julia 3:TODO");
		exit(0);
	}
	return (ft_atoi(argv[1]));
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	int		res;

	res = check_error(argc, argv);
	mlx = init();
	if (res == 1)
		mandelbrot(mlx);
	else
		julia(mlx);
	mlx_key_hook(mlx.win_ptr, key_event, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
