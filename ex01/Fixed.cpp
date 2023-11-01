/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:30:24 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/11/01 12:52:08 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <limits>
#include <cmath>

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
	this->value = other.getRawBits();
}

//int constructor
Fixed::Fixed(const int intVal)
{
	cout << "Int constructor called" << endl;
	value = intVal << numBits;
	if (intVal < 0)
		value = -value;
}

//float constructor
Fixed::Fixed(const float floatVal)
{
	float	rounded;
	int		rounded_int;

	cout << "Float constructor called" << endl;
	rounded = roundf(floatVal);
	if ((rounded <= floatVal) && (floatVal >= 0.0))
	{
		value = (int) rounded << numBits;
		rounded = floatVal - rounded;
	}
	else if ((rounded > floatVal && (floatVal >= 0.0)))
	{
		rounded -= 1.0;
		value = (int) rounded << numBits;
		rounded = floatVal - rounded;
	}
	else if ((rounded >= floatVal) && (floatVal < 0.0))
	{
		value = (int) rounded << numBits;
		value |= 0x80000000;
		rounded = rounded - floatVal;
	}
	else if ((rounded < floatVal) && (floatVal < 0.0))
	{
		rounded += 1.0;
		value = (int) rounded << numBits;
		value |= 0x80000000;
		rounded = rounded - floatVal;
	}
	rounded /= (1.0 / (1 << numBits));
	rounded_int = (int) rounded * 1;
	value |= rounded_int;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
	value = 0;
}

int		Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	value = raw;
}

int		Fixed::toInt(void) const
{
	unsigned int	left;

	left = value >> numBits;
	if (value >= 0)
		return (left);
	else
		return (left | 0x80000000);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << numBits));
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

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	if (fixed.getRawBits() & ((1 << 8) - 1))
		os << fixed.toFloat();
	else
		os << fixed.toInt();
	return (os);
}
