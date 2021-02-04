/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:50:51 by kcorie            #+#    #+#             */
/*   Updated: 2021/02/04 22:12:03 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel_to_img(t_frctl *f, int x, int y, t_color c)
{
	int			i;

	i = (int)(x * 4 + f->size_line * y);
	f->img_ptr[i] = c.col1;
	f->img_ptr[i + 1] = c.col2;
	f->img_ptr[i + 2] = c.col3;
}

void	color(int iter, int x, int y, t_frctl *f)
{
	t_color		color;
	double		t;

	t = (double)iter / f->max_iter;
	color.col1 = 0;
	color.col2 = 0;
	color.col3 = 0;
	if (iter < f->max_iter)
	{
		color.col1 = 0xf620b3 * t * t * t;
		color.col2 = 0x10eab3 * t * t;
		color.col3 = 0x0FF138 * t;
	}
	put_pixel_to_img(f, x, y, color);
}

void	total_black(t_frctl *f, int x, int y)
{
	t_color		blck;

	blck.col1 = 0;
	blck.col2 = 0;
	blck.col3 = 0;
	put_pixel_to_img(f, x, y, blck);
}
