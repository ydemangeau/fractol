/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:20:05 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/27 19:47:55 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_event(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_A)
		mlx->color = 265;
	if (key == KEY_S)
		mlx->color = 990000;
	if (key == KEY_D)
		mlx->color = 1687215;
	if (key == KEY_F)
		mlx->color = 10028508;
	if (mlx->fract == 1)
		mandelbrot(mlx);
	else if (mlx->fract == 2)
		julia(mlx);
	else
		tricorn(mlx);
	return (0);
}

void	zoom(int x, int y, t_mlx *mlx)
{
	mlx->start_x = (x / mlx->zoom + mlx->start_x) - (x / (mlx->zoom * 1.6));
	mlx->start_y = (y / mlx->zoom + mlx->start_y) - (y / (mlx->zoom * 1.6));
	mlx->zoom *= 1.6;
	mlx->max_iteration++;
}

void	dezoom(int x, int y, t_mlx *mlx)
{
	mlx->start_x = (x / mlx->zoom + mlx->start_x) - (x / (mlx->zoom / 1.6));
	mlx->start_y = (y / mlx->zoom + mlx->start_y) - (y / (mlx->zoom / 1.6));
	mlx->zoom /= 1.6;
	mlx->max_iteration--;
}

int		mouse_event(int mousecode, int x, int y, t_mlx *mlx)
{
	if (mousecode == 4 || mousecode == 1)
		zoom(x, y, mlx);
	else if (mousecode == 5 || mousecode == 2)
		dezoom(x, y, mlx);
	if (mlx->fract == 1)
		mandelbrot(mlx);
	else if (mlx->fract == 2)
		julia(mlx);
	else
		tricorn(mlx);
	return (0);
}

void	event(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 6, 0L, julia_mouse, mlx);
	mlx_key_hook(mlx->win_ptr, key_event, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_event, mlx);
	mlx_loop(mlx->mlx_ptr);
}
