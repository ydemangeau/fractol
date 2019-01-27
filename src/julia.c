/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:10:27 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/27 19:49:23 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				julia_mouse(int x, int y, t_mlx *mlx)
{
	if (mlx->fract == 2)
	{
		if (x <= 960 && y <= 540)
			mlx->c_r -= 0.1;
		else if (x >= 960 && y <= 540)
			mlx->c_r += 0.1;
		else if (x <= 960 && y >= 540)
			mlx->c_i -= 0.1;
		else if (x >= 960 && y >= 540)
			mlx->c_i += 0.1;
		julia(mlx);
	}
	return (0);
}

void			julia_init(t_mlx *mlx)
{
	mlx->start_x = -2.0;
	mlx->start_y = -1.8;
	mlx->zoom = 300;
	mlx->max_iteration = 50;
	mlx->color = 265;
	mlx->c_r = 0.285;
	mlx->c_i = 0.01;
	julia(mlx);
}

void			julia(t_mlx *mlx)
{
	mlx->y = -1;
	while (++mlx->y < OUTPUT_HEIGHT)
	{
		mlx->x = -1;
		while (++mlx->x < OUTPUT_WIDTH)
		{
			mlx->z_r = mlx->x / mlx->zoom + mlx->start_x;
			mlx->z_i = mlx->y / mlx->zoom + mlx->start_y;
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
