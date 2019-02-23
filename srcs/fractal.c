/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 00:47:16 by khou              #+#    #+#             */
/*   Updated: 2019/02/23 00:47:19 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	error_usage()
{
	ft_printf("usage:  ./fractol [jm]\nmodels: j - julia\n        \
m - mandelbrot\n        X - XXX\n        X - XXXX\n");
	exit(0);
}

void	error_arg(t_fflag *flag,int argc, char **argv)
{
	
	if (argc < 2)
		error_usage();
	int	i = 1;
	while (i < argc)
	{
//		ft_printf("%c\n", *argv[i]);
		if (*argv[i] == 'j' || *argv[i] == 'm')
		{
			if (!ft_strcmp("mandelbrot", argv[i]) || !ft_strcmp("m", argv[i]))
				flag->j = 1;
			else if (!ft_strcmp("julia", argv[i]) || !ft_strcmp("j", argv[i]))
				flag->m = 1;
			else
				error_usage();
		}
		else
			error_usage();
		i++;
	}
}
int		main(int argc, char **argv)
{
	t_frame frm;
	int		bpp;
	int		size_line;
	int		endian;
	t_fflag	flag;
//-- error management for argv ----
	error_arg(&flag, argc, argv);
	frm.mlx = mlx_init();
	frm.win = mlx_new_window(frm.mlx, WIN_W, WIN_H, "The VIEW");
	frm.img = mlx_new_image(frm.mlx, WIN_W, WIN_H);
	frm.data_img = mlx_get_data_addr(frm.img, &bpp, &size_line, &endian);
	if (!frm.mlx || !frm.win || !frm.img || !frm.data_img)
		exit(0);
	printf("endian: %d\n", endian);


	mlx_hook(frm.win, 2, 0, deal_key, &frm);
//	mlx_hook(frm.win, 4, 0, deal_mouse, &frm);
	mlx_hook(frm.win, 17, 0, red_close, &frm);
	mlx_loop_hook(frm.mlx, render, &frm);
	mlx_loop(frm.mlx);
	return (0);
}