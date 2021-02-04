/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorie <kcorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:50:10 by kcorie            #+#    #+#             */
/*   Updated: 2021/02/04 22:13:27 by kcorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../includes/keys.h"
# include <mlx.h>
# include <fcntl.h>
# include <pthread.h>

# define SIZE_W 1500
# define THREAD 150
# define PARTY	SIZE_W / THREAD

typedef struct			s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct			s_color
{
	int					col1;
	int					col2;
	int					col3;
}						t_color;

typedef struct s_frctl	t_frctl;

struct					s_frctl
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*img_ptr;
	int					size_line;
	int					bpp;
	int					endian;
	t_complex			c;
	t_complex			min;
	t_complex			max;
	t_complex			fuck;
	double				offset_x;
	double				offset_y;
	double				tmp;
	int					mousej;
	int					max_iter;
	int					(*f)(t_complex, t_frctl *);
};

typedef struct			s_thr
{
	pthread_t			p;
	int					in;
	int					end;
	t_frctl				fcl;
}						t_thr;

/*
** paint.c
*/

void					put_pixel_to_img(t_frctl *f, int x, int y, t_color c);
void					color(int iter, int x, int y, t_frctl *f);
void					total_black(t_frctl *f, int x, int y);

/*
** hook.c
*/

int						kill_win(t_frctl *f);
int						hook_mousedown(int key, int x, int y, t_frctl *f);
int						hook_mousemove(int x1, int y1, t_frctl *f);
int						hook_keydown(int key, t_frctl *f);
void					hooks(t_frctl *f);

/*
** render.c
*/

void					zoom_cmplx(t_frctl *f, t_complex mouse, double z);
int						zooming(t_frctl *f, int x, int y, int key);
t_complex				complex_solve(double re, double im);

/*
** fractal.c
*/

int						mandelbrot(t_complex c, t_frctl *f);
int						julia(t_complex c, t_frctl *f);
void					*fractal(void *thread);
int						choose_frctl(t_frctl *fr, char *av);

/*
** main.c
*/

void					frctl_pthrd(t_frctl *f);
void					frctl_solve(t_frctl *f);
void					create_win(t_frctl *f);

#endif
