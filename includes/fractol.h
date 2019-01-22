/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:53:03 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/18 17:06:44 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"

# define KEY_ESC		53
# define MAX_ITERATION 142
# define OUTPUT_WIDTH 1000
# define OUTPUT_HEIGHT 1000

typedef struct			s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		new_r;
	double		new_i;
	double		old_r;
	double		old_i;
	double		p_r;
	double		p_i;
	double		x;
	double		y;
	double		start_x;
	double		start_y;
	double		zoom;
}						t_mlx;

typedef struct			s_fractol
{
	
}						t_fractol;

#endif
