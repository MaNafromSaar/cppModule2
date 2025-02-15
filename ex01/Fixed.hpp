/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:04:25 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/14 20:31:14 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int _value;
		static const int _fractional_bits = 8;
	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();
		Fixed &operator=(Fixed const &rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &rhs);

#endif