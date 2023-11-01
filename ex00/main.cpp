/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:34:26 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/10/18 16:35:55 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int	main(void)
{
/*
	Fixed	f_num1;
	Fixed	f_num2;

	cout << f_num1.getRawBits() << endl;
	f_num1.setRawBits(1111);
	f_num2 = f_num1;
	cout << f_num1.getRawBits() << endl;
	cout << f_num2.getRawBits() << endl;
	return (0);
*/
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
