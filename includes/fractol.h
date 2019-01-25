/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:53:03 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/24 23:56:23 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"

# define KEY_ESC		53
# define KEY_Z		6
# define OUTPUT_WIDTH 1920
# define OUTPUT_HEIGHT 1080

typedef struct			s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				color;
	int				fract;
	unsigned int	max_iteration;
	unsigned int	i;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			tmp;
	double			x1;
	double			y1;
	double			x;
	double			y;
	double			start_x;//
	double			start_y;//
	double			zoom;
}						t_mlx;

void				put_pixel(t_mlx mlx);
void				mandelbrot_init(t_mlx *mlx);
void				julia_init(t_mlx *mlx);
void				tricorn_init(t_mlx *mlx);
void				mandelbrot(t_mlx *mlx);
void				julia(t_mlx *mlx);
void				tricorn(t_mlx *mlx);
void				event(t_mlx *mlx);
#endif
