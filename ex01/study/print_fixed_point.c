/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fixed_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:17:07 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/10/20 08:20:37 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ieee754.h>
#include <math.h>
#include <stdio.h>

#define LOG2_10 3.321928095
#define EPSILON 0.000000005

#define flt_zero(x) (fabs(x) < EPSILON)

int max_digs_rt = 3;  /* maximum # of 0's right of decimal before using
                         scientific notation */
int max_digs_lf = 5;  /* max # of digits left of decimal */

void print_real(double r, int width, int dec)
{
    int mag;
    double fpart, temp;
    char format[8];
    char num_format[3] = {'l',0,0};
    union ieee754_double *dl;

    dl = (union ieee754_double*)&r;
    mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;
    if (r == 0)
        mag = 0;
    if ((mag > max_digs_lf-1) || (mag < -max_digs_rt)) {
        num_format[1] = 'e';
        temp = r/pow(10, mag);      /* see if number will have a decimal */
        fpart = temp - floor(temp); /* when written in scientific notation */
    }
    else {
        num_format[1] = 'f';
        fpart = r - floor(r);
    }
    if (flt_zero(fpart))
        dec = 0;
    if (width == 0) {
        snprintf(format, 8, "%%.%d%s", dec, num_format);
    }
    else {
        snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
    }
    printf(format, r);
}
