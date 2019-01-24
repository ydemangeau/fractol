/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:53:25 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/23 20:47:34 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_mlx mlx)
{
	while (++mlx.y < OUTPUT_HEIGHT)
	{
		mlx.x = -1;
		while (++mlx.x < OUTPUT_WIDTH)
		{
			mlx.c_i = (mlx.y - OUTPUT_HEIGHT / 2.0) / (0.5 * mlx.zoom * OUTPUT_HEIGHT) + mlx.start_y;
			mlx.c_r = 1.5 * (mlx.x - OUTPUT_WIDTH / 2.0) / (0.5 * mlx.zoom * OUTPUT_WIDTH) + mlx.start_x;
			mlx.z_r = 0;
			mlx.z_i = 0;
			mlx.i = 0;
			while ((mlx.z_r * mlx.z_r + mlx.z_i * mlx.z_i) < 4.0 && mlx.i < MAX_ITERATION) 
			{
				mlx.tmp = mlx.z_r;
				mlx.z_r = mlx.z_r * mlx.z_r - mlx.z_i * mlx.z_i + mlx.c_r;
				mlx.z_i = 2.0 * mlx.z_i * mlx.tmp + mlx.c_i;
				++mlx.i;
			}
			put_pixel(mlx);
		}
	}
}

void	julia(t_mlx mlx)
{
	while (++mlx.y < OUTPUT_HEIGHT)
	{
		mlx.x = -1;
		while (++mlx.x < OUTPUT_WIDTH)
		{
			mlx.c_i = 0.01;
			mlx.c_r = 0.285;
			mlx.z_r = 1.5 * (mlx.x - OUTPUT_WIDTH / 2.0) / (0.5 * mlx.zoom * OUTPUT_WIDTH) + mlx.start_x;
			mlx.z_i = (mlx.y - OUTPUT_HEIGHT / 2.0) / (0.5 * mlx.zoom * OUTPUT_HEIGHT) + mlx.start_y;
			mlx.i = 0;
			while ((mlx.z_r * mlx.z_r + mlx.z_i * mlx.z_i) < 4.0 && mlx.i < MAX_ITERATION) 
			{
				mlx.tmp = mlx.z_r;
				mlx.z_r = mlx.z_r * mlx.z_r - mlx.z_i * mlx.z_i + mlx.c_r;
				mlx.z_i = 2.0 * mlx.z_i * mlx.tmp + mlx.c_i;
				++mlx.i;
			}
			put_pixel(mlx);
		}
	}
}

void	burningship(t_mlx mlx)
{
	while (++mlx.y < OUTPUT_HEIGHT)
	{
		mlx.x = -1;
		while (++mlx.x < OUTPUT_WIDTH)
		{
			mlx.c_i = (mlx.y - OUTPUT_HEIGHT / 2.0) / (0.5 * mlx.zoom * OUTPUT_HEIGHT) + mlx.start_y;
			mlx.c_r = 1.5 * (mlx.x - OUTPUT_WIDTH / 2.0) / (0.5 * mlx.zoom * OUTPUT_WIDTH) + mlx.start_x;
			mlx.z_r = mlx.c_r;
			mlx.z_i = mlx.c_i;
			mlx.i = 0;
			while ((mlx.z_r * mlx.z_r + mlx.z_i * mlx.z_i) < 4.0 && mlx.i < MAX_ITERATION) 
			{
				mlx.tmp = mlx.z_r * mlx.z_r - mlx.z_i * mlx.z_i + mlx.c_i;
				mlx.z_r = ft_abs(2 * mlx.z_r * mlx.z_i) + mlx.c_r;
				mlx.z_i = ft_abs(mlx.tmp);
				++mlx.i;
			}
			put_pixel(mlx);
		}
	}
}


