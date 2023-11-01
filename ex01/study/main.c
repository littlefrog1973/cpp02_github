/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:21:12 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/11/01 11:54:10 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

void print_real(double r, int width, int dec);

int	main(void)
{
	float	x;
	int		x_int;

	print_real(2.0 / 3.0,5, 3);
	printf("\n");
	x = 598.45;
	x_int = (int) x * 100 / 100;
	printf("(int) x = %d\n", x_int );
	printf("")
	return (0);
}
