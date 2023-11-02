/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:34:26 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/11/02 12:20:56 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int	main(void)
{
	Fixed	a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << endl;
	std::cout << "b is " << b << endl;
	std::cout << "c is " << c << endl;
	std::cout << "d is " << d << endl;

	std::cout << "a is " << a.toInt() << " as integer" << endl;
	std::cout << "b is " << b.toInt() << " as integer" << endl;
	std::cout << "c is " << c.toInt() << " as integer" << endl;
	std::cout << "d is " << d.toInt() << " as integer" << endl;
	return 0;
}
