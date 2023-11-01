/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:30:24 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/10/19 01:06:20 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const static int numBits = 8;

//constructor
Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	value = 0;
}

//copy constructor
Fixed::Fixed(const Fixed& other)
{
	cout << "Copy constructor called" << endl;
//	this->value = other.value;
	this->value = other.getRawBits();
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
	value = 0;
}

int		Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	value = raw;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	cout << "Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->value = other.getRawBits();
	}
	return *this;
}
