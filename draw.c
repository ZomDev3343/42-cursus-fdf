/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/01/18 16:34:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_pixel(t_img *img, int x, int y, int color)
{
    int     pos;
    char    *dest;

    if (x > img->vars->win_width || x < 0
        || y > img->vars->win_height || y < 0)
        return ;
    pos = (y * img->line_length + x * (img->bits_per_pixel / 8));
    dest = img->addr + pos;
    *((unsigned int *)dest) = color;
}

void    draw_square(t_img *img, int x, int y, int size)
{
    int             i;
    unsigned int    color;

    i = -1;
    color = 0xFFFFFFFF;
    while (++i < size)
    {
        draw_pixel(img, x + i, y, color);
        draw_pixel(img, x + size, y + i, color);
        draw_pixel(img, x + i, y + size, color);
        draw_pixel(img, x, y + i, color);
    }
    draw_pixel(img, x + size, y + size, color);
}