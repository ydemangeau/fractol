/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:53:25 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/27 19:49:55 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			mandelbrot_init(t_mlx *mlx)
{
	mlx->start_x = -2.05;
	mlx->start_y = -1.3;
	mlx->zoom = 300;
	mlx->max_iteration = 50;
	mlx->color = 265;
	mandelbrot(mlx);
}

void			mandelbrot(t_mlx *mlx)
{
	mlx->y = -1;
	while (++mlx->y < OUTPUT_HEIGHT)
	{
		mlx->x = -1;
		while (++mlx->x < OUTPUT_WIDTH)
		{
			mlx->c_r = mlx->x / mlx->zoom + mlx->start_x;
			mlx->c_i = mlx->y / mlx->zoom + mlx->start_y;
			mlx->z_r = 0;
			mlx->z_i = 0;
			mlx->i = 0;
			while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i) < 4.0 &&
					mlx->i < mlx->max_iteration)
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = 2.0 * mlx->z_i * mlx->tmp + mlx->c_i;
				++mlx->i;
			}
			put_pixel(mlx);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}
