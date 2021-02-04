/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:50:36 by kcorie            #+#    #+#             */
/*   Updated: 2021/02/04 22:53:02 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		kill_win(t_frctl *f)
{
	mlx_destroy_window(f->mlx, f->win);
	exit(EXIT_SUCCESS);
}

int		hook_mousedown(int key, int x, int y, t_frctl *f)
{
	y = SIZE_W - y;
	if (key == LEFT_BUTTON)
		f->max_iter += 33;
	if (key == RIGHT_BUTTON)
		f->max_iter -= 33;
	if (key == SCROLL_UPPER || key == SCROLL_DOWN)
		if (zooming(f, x, y, key) == 0)
			return (0);
	frctl_pthrd(f);
	return (0);
}

int		hook_mousemove(int x1, int y1, t_frctl *f)
{
	double			x;
	double			y;

	x = (double)x1;
	y = (double)y1;
	if (f->mousej == 0)
		return (0);
	if (x < 0 || x > SIZE_W)
		x = (x > SIZE_W) ? SIZE_W : 0;
	if (y < 0 || y > SIZE_W)
		y = (y > SIZE_W) ? SIZE_W : 0;
	f->c = complex_solve((x - SIZE_W * 0.5) / SIZE_W,
						4.0 * ((SIZE_W - y) - SIZE_W * 0.5f) / SIZE_W);
	frctl_pthrd(f);
	return (0);
}

int		hook_keydown(int key, t_frctl *f)
{
	if (key == LEFT)
		f->offset_x -= f->tmp;
	else if (key == RIGHT)
		f->offset_x += f->tmp;
	else if (key == UP)
		f->offset_y += f->tmp;
	else if (key == DOWN)
		f->offset_y -= f->tmp;
	else if (key == PAUSE_5)
		f->mousej = (f->mousej == 1) ? 0 : 1;
	else if (key == REPLACE_FRACTAL_7)
	{
		if (f->f == mandelbrot)
			f->f = julia;
		else if (f->f == julia)
			f->f = mandelbrot;
	}
	else if (key == ESC)
		exit(EXIT_SUCCESS);
	frctl_pthrd(f);
	return (0);
}

void	hooks(t_frctl *f)
{
	mlx_hook(f->win, 2, 5, hook_keydown, f);
	mlx_hook(f->win, 6, 0, hook_mousemove, f);
	mlx_hook(f->win, 4, 5, hook_mousedown, f);
	mlx_hook(f->win, 17, 1L >> 15, kill_win, f);
}
