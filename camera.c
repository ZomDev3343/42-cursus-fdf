/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:32:18 by truello           #+#    #+#             */
/*   Updated: 2024/01/18 16:34:04 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_camera
{
    int fov;
    int far;
    int aspect;
    int x;
    int y;
}   t_camera;

t_camera    make_camera(void)
{
    t_camera    cam;

    cam.fov = 90;
    cam.far = 1000;
    cam.aspect = 1;
    cam.x = 0;
    cam.y = 0;
    return (cam);
}