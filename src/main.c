/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:03:04 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/18 17:05:20 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw(t_mlx mlx)
{
	mlx.start_x = -0.75;
	mlx.start_y = 0.0
	mlx.zoom = 0.8;
	unsigned char line_buffer[OUTPUT_WIDTH * 3];
	mlx.y = -1;
	mlx.x = -1;
	unsigned int i;

	i = 0;
	while (++y < OUTPUT_HEIGHT)
	{
		mlx.p_i = (y - OUTPUT_HEIGHT / 2.0) / (0.5 * mlx.zoom * OUTPUT_HEIGHT) + mlx.start_y;
		while (++x < OUTPUT_WIDTH)
		{
			mlx.p_r = 1.5 * (mlx.x - OUTPUT_WIDTH / 2.0) / (0.5 * mlx.zoom * OUTPUT_WIDTH) + mlx.start_x;
			mlx.new_r = 0;
			mlx.new_i = 0;
			mlx.old_r = 0;
			mlx.old_i = 0;
			while ((mlx.new_r * mlx.new_r + mlx.new_i * mlx.new_i) < 4.0 && i < MAX_ITERATION)
			{
				mlx.old_r = mlx.new_r;
				mlx.old_i = mlx.new_i;
				mlx.new_r = mlx.old_r * mlx.old_r - mlx.old_i * mlx.old_i + mlx.p_r;
				mlx.new_i = 2.0 * mlx.old_r * mlx.old_i + mlx.p_i;
				++i;
			}
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, 0xFFFFFF);
		}
	}
}

int		main()
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, OUTPUT_HEIGHT, OUTPUT_WIDTH, "fractol");
	draw(mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
