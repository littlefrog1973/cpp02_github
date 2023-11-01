/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:19:18 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/10/19 00:40:43 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Fixed
{
private:
	int	value;
	static const int numBits;
public:
	//constructor
	Fixed();
	//copy constructor
	Fixed(const Fixed& other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed&	operator=(const Fixed& other);
/*	{
		cout << "Copy assignment operator called" << endl;
		if (this != &other)
		{
			this->value = other.getRawBits();
		}
		return *this;
	}
*/
	~Fixed();
};
