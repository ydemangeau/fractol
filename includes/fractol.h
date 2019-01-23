/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:53:03 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/23 20:47:38 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"

# define KEY_ESC		53
# define MAX_ITERATION 142
# define OUTPUT_WIDTH 1920
# define OUTPUT_HEIGHT 1080

typedef struct			s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	unsigned int	i;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			tmp;
	double			x;
	double			y;
	double			start_x;
	double			start_y;
	double			zoom;
}						t_mlx;

void				put_pixel(t_mlx mlx);
void				mandelbrot(t_mlx mlx);
void				julia(t_mlx mlx);
#endif
