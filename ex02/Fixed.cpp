/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:04:20 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/15 11:14:02 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const value) {
	//std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_fractional_bits;
}

Fixed::Fixed(float const value) {
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_fractional_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Fixed const &rhs) {
	out << rhs.toFloat();
	return out;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

// optional check for division by zero, try without!
Fixed Fixed::operator/(Fixed const &rhs) const {
	if (rhs.toFloat() == 0)
	{
		std::cout << "Division by zero is not allowed" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void) {
	this->_value++;
	return *this;
}

// switches right hand side value with left hand side value
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

bool Fixed::operator>(Fixed const &rhs) const {
	return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator<(Fixed const &rhs) const {
	return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return this->toFloat() >= rhs.toFloat();
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return this->toFloat() <= rhs.toFloat();
}

bool Fixed::operator==(Fixed const &rhs) const {
	return this->toFloat() == rhs.toFloat();
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return this->toFloat() != rhs.toFloat();
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}


float	Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_fractional_bits);
}

int		Fixed::toInt(void) const {
	return this->_value >> this->_fractional_bits;
}

// read ternary: Is a less than b? If true, return a, else return b
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b ? a : b);
}
