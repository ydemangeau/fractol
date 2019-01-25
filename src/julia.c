/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:10:27 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/25 00:20:16 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		julia_init(t_mlx *mlx)
{
	mlx->start_x = -1.2;
	mlx->start_y = -1.2;
	mlx->zoom = 300;
	mlx->max_iteration = 50;
	mlx->color = 265;
	mlx->c_r = 0.285;
	mlx->c_i = 0.01;
	julia(mlx);
}

void	julia(t_mlx *mlx)
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
			while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i) < 4.0 && mlx->i < mlx->max_iteration) 
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = 2.0 * mlx->z_i * mlx->tmp + mlx->c_i;
				++mlx->i;
			}
			put_pixel(*mlx);
		}
	}
}

