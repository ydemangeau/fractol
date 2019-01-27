/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:03:04 by ydemange          #+#    #+#             */
/*   Updated: 2019/01/27 19:47:36 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, OUTPUT_WIDTH,
			OUTPUT_HEIGHT, "fractol");
	mlx->img = mlx_new_image(mlx->mlx_ptr, OUTPUT_WIDTH, OUTPUT_HEIGHT);
	mlx->img_ptr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->sl, &mlx->endian);
}

void			put_pxl_to_img(t_mlx *mlx, int x, int y, int color)
{
	if (mlx->x < OUTPUT_WIDTH && mlx->y < OUTPUT_HEIGHT)
	{
		color = mlx_get_color_value(mlx->mlx_ptr, color);
		ft_memcpy(mlx->img_ptr + 4 * OUTPUT_WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void			put_pixel(t_mlx *mlx)
{
	if (mlx->i == mlx->max_iteration)
		put_pxl_to_img(mlx, mlx->x, mlx->y, 0);
	else
		put_pxl_to_img(mlx, mlx->x, mlx->y, (mlx->color * mlx->i));
}

int				check_error(int argc, char **argv)
{
	if (argc != 2 || (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 3)
			|| argv[2] || argv[1][1] != '\0')
	{
		ft_putendl("Usage : fractol/ 1:Mandelbrot 2:Julia 3:Tricorn");
		exit(0);
	}
	return (ft_atoi(argv[1]));
}

int				main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (!(mlx = malloc(sizeof(t_mlx))))
		return (-1);
	mlx->fract = check_error(argc, argv);
	init(mlx);
	if (mlx->fract == 1)
		mandelbrot_init(mlx);
	else if (mlx->fract == 2)
		julia_init(mlx);
	else
		tricorn_init(mlx);
	event(mlx);
	return (0);
}
