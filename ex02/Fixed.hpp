/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:19:18 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/11/02 22:39:32 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

class Fixed
{
private:
	int	value;
	static const int numBits = 8;
public:
	//constructor
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int intVal);
	Fixed(const float floatVal);

	//member function
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed&	operator=(const Fixed& other);
	Fixed&	operator+(const Fixed& other);
	Fixed&	operator-(const Fixed& other);
	Fixed&	operator++(void);
	int		operator>(const Fixed& other);
	int		operator<(const Fixed& other);
	int		operator>=(const Fixed& other);
	int		operator<=(const Fixed& other);
	int		operator!=(const Fixed& other);
	int		operator==(const Fixed& other);
	~Fixed();
};

// Declare the insertion operator as a non-member function
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
