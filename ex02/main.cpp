/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:34:26 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/11/03 10:35:37 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int	main(void)
{
	Fixed	a(10.25f);
	Fixed	b(5);
	Fixed	c(1234.4321f);
	Fixed	d(b);
	Fixed	f;

/*
	std::cout << "a is " << a << endl;
	std::cout << "b is " << b << endl;
	std::cout << "c is " << c << endl;
	std::cout << "d is " << d << endl;

	std::cout << "a is " << a.toInt() << " as integer" << endl;
	std::cout << "b is " << b.toInt() << " as integer" << endl;
	std::cout << "c is " << c.toInt() << " as integer" << endl;
	std::cout << "d is " << d.toInt() << " as integer" << endl;

	std::cout << endl;
	if (a >= c)
		std::cout << "a >= c" << std::endl;
	if (a <= c)
		std::cout << "a <= c" << std::endl;
	if (a != c)
		std::cout << "a != c" << std::endl;
	if (a == c)
		std::cout << "a == c" << std::endl;

	std::cout << endl;

	++a;
	std::cout << "++a = " << a << endl;
	++a;
	std::cout << "++a = " << a << endl;
*/
	std::cout << "a = " << a << endl;
	std::cout << "b = " << b << endl;
	f = a + b;
	std::cout << "a + b = " << f << endl;
	f = a - b;
	std::cout << "a - b = " << f << endl;
	f = b - a;
	std::cout << "b - a = " << f << endl;

	return 0;
}
