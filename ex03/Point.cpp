/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:33:54 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/15 16:59:22 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(float x, float const y) : _x(x), _y(y) {
}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()) {
}

Point::~Point() {
}

Point &Point::operator=(Point const &rhs) {
    (void)rhs;
    return *this;
}

Fixed Point::getX(void) const {
	return this->_x;
}

Fixed Point::getY(void) const {
	return this->_y;
}

Fixed area(Point const a, Point const b, Point const c) {
    return ((b.getX() - a.getX()) * (c.getY() - a.getY()) - 
            (c.getX() - a.getX()) * (b.getY() - a.getY())) / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate areas of three triangles formed by point and two vertices
    Fixed totalArea = Fixed(abs(area(a, b, c).toFloat()));
    Fixed area1 = Fixed(abs(area(point, b, c).toFloat()));
    Fixed area2 = Fixed(abs(area(a, point, c).toFloat()));
    Fixed area3 = Fixed(abs(area(a, b, point).toFloat()));
    
    // Point is inside if sum of three areas equals total triangle area
    return (area1 + area2 + area3) == totalArea;
}
