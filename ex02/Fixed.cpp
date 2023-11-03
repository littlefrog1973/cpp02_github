/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:30:24 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/11/03 10:37:51 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
//#include <cmath>

//constructor
Fixed::Fixed()
{
//	cout << "Default constructor called" << endl;
	value = 0;
}

//copy constructor
Fixed::Fixed(const Fixed& other)
{
//	cout << "Copy constructor called" << endl;
// this->value = other.getRawBits();
// commented above line does not use an overloaded assignment operator
// below line is using an overloaded assignment operator
	*this = other;
}

//int constructor
Fixed::Fixed(const int intVal)
{
//	cout << "Int constructor called" << endl;
	value = intVal << numBits;
}

//float constructor
Fixed::Fixed(const float floatVal)
{
	float			rounded;
	float			remaining;
	int				rounded_int;

	value = 0;
//	cout << "Float constructor called" << endl;
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
//	cout << "Destructor called" << endl;
	value = 0;
}

int		Fixed::getRawBits(void) const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
//	cout << "setRawBits member function called" << endl;
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
//	cout << "Copy assignment operator called" << endl;
	if (this != &other)
	{
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed&	Fixed::operator++(void)
{
//	cout << "Increment operator called" << endl;
	(this->value)++;
	return *this;
}

Fixed&	Fixed::operator+(const Fixed& other)
{
	int	left;
	int	right;
	int	left_point;
	int	right_point;

	if (this->value * other.getRawBits() >= 0)
		this->value = this->value + other.getRawBits();
	else
	{
		left = this->value >> numBits;
		right = other.getRawBits() >> numBits;
		left_point = this->value & ((1 << numBits) - 1);
		right_point = other.getRawBits() & ((1 << numBits) - 1);
		if (this->value > 0 && other.getRawBits() < 0)
			left_point = left_point - right_point;
		else
			left_point = right_point - left_point;
		left = left + right;
		if ((left >= 0) && (left_point >= 0))
			left = (left << numBits) | left_point;
		else if ((left < 0) && (left_point < 0))
			left = (left << numBits) | (-left_point);
		else if ((left < 0) && (left_point > 0))
			left = ((left + 1) << numBits) | ((1 << numBits) - left_point);
		this->value = left;
	}
	return *this;
}

Fixed&	Fixed::operator-(const Fixed& other)
{
	this->value = this->value - other.getRawBits();
	return *this;
}

int	Fixed::operator>(const Fixed& other)
{
	if (this->value > other.getRawBits())
		return (1);
	else
		return (0);
}

int	Fixed::operator<(const Fixed& other)
{
	if (this->value < other.getRawBits())
		return (1);
	else
		return (0);
}

int	Fixed::operator>=(const Fixed& other)
{
	if (this->value >= other.getRawBits())
		return (1);
	else
		return (0);
}

int	Fixed::operator<=(const Fixed& other)
{
	if (this->value <= other.getRawBits())
		return (1);
	else
		return (0);
}

int	Fixed::operator!=(const Fixed& other)
{
	if (this->value != other.getRawBits())
		return (1);
	else
		return (0);
}

int	Fixed::operator==(const Fixed& other)
{
	if (this->value == other.getRawBits())
		return (1);
	else
		return (0);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	float	remainder;

// check that is there any value on the right of fixed point?
	remainder = fixed.toFloat() / roundf(fixed.toFloat());
	if (remainder != 1.0)
		os << std::fixed << std::setprecision(8) << fixed.toFloat();
	else
		os << fixed.toInt();
	return (os);
}
