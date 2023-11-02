/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:30:24 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/11/02 12:21:55 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
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
// this->value = other.getRawBits();
// commented above line does not use an overloaded assignment operator
// below line is using an overloaded assignment operator
	*this = other;
}

//int constructor
Fixed::Fixed(const int intVal)
{
	cout << "Int constructor called" << endl;
	value = intVal << numBits;
}

//float constructor
Fixed::Fixed(const float floatVal)
{
	float			rounded;
	float			remaining;
	int				rounded_int;

	value = 0;
	cout << "Float constructor called" << endl;
	rounded = roundf(floatVal);

	if (floatVal >= 0.0)
	{
		if(rounded > floatVal)
			rounded -= 1.0;
		remaining = floatVal - rounded;
	}
	else
	{
		if (rounded < floatVal)
			rounded += 1.0;
		remaining = rounded - floatVal;
	}
	rounded_int = static_cast<int> (rounded);
	value = rounded_int << numBits;
	remaining /= (1.0 / (1 << numBits));
	rounded_int = static_cast<int> (roundf(remaining));
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
		return (left + !(!(value & (1 << (numBits - 1)))));
	else
		return (left - !(!(value & (1 << (numBits - 1)))));
}

float	Fixed::toFloat(void) const
{
	float	toStream;
	int		temp;

	if (value >= 0)
	{
		toStream = static_cast<float> (value >> numBits);
		toStream += (value & ((1 << numBits) - 1)) * (1.0) / (1 << numBits);
	}
	else
	{
		temp = value >> numBits;
		toStream = static_cast<float> (temp);
		toStream -= (value & ((1 << numBits) - 1)) * (1.0) / (1 << numBits);
	}
	return (toStream);
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
	float	remainder;

// check that is there any value on the right of fixed point?
	remainder = fixed.toFloat() / roundf(fixed.toFloat());
	if (remainder != 1.0)
		os << fixed.toFloat();
	else
		os << fixed.toInt();
	return (os);
}
