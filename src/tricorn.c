/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:19:22 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/27 20:10:03 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			tricorn_init(t_mlx *mlx)
{
	mlx->start_x = -2.1;
	mlx->start_y = -1.8;
	mlx->zoom = 300;
	mlx->max_iteration = 50;
	mlx->color = 265;
	tricorn(mlx);
}

void			tricorn(t_mlx *mlx)
{
	mlx->y = -1;
	while (++mlx->y < OUTPUT_HEIGHT)
	{
		mlx->x = -1;
		while (++mlx->x < OUTPUT_WIDTH)
		{
			mlx->c_r = mlx->x / mlx->zoom + mlx->start_x;
			mlx->c_i = mlx->y / mlx->zoom + mlx->start_y;
			mlx->z_r = 0.0;
			mlx->z_i = 0.0;
			mlx->i = 0;
			while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i) < 4.0 &&
					mlx->i < mlx->max_iteration)
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = -2 * mlx->z_i * mlx->tmp + mlx->c_i;
				mlx->i++;
			}
			put_pixel(mlx);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}
