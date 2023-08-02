/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 08:22:51 by micheng           #+#    #+#             */
/*   Updated: 2023/08/02 08:22:57 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <mlx.h>
#include <math.h>

void draw_line(t_vars *vars, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;

    if (x0 < x1)
        sx = 1;
    else
        sx = -1;

    if (y0 < y1)
        sy = 1;
    else
        sy = -1;

    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    {
        mlx_pixel_put(vars->render.mlx, vars->render.win, x0, y0, 0xFF0000); // Draw the pixel
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
