/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:33:54 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/15 18:29:03 by mnaumann         ###   ########.fr       */
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

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {
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

// since the 1st approach couldn't handle negative values, I had to change the approach
// now, each triangle and point are shifted to the positive quadrant
// dynamic shifting brought more issues, so I ressorted tu use fixed values
Fixed area(Point const a, Point const b, Point const c) {
    return ((a.getX() * (b.getY() - c.getY()) + 
             b.getX() * (c.getY() - a.getY()) + 
             c.getX() * (a.getY() - b.getY()))) / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    
	//edge check
	if (isOnLine(a, b, point) || isOnLine(b, c, point) || isOnLine(c, a, point))
	return false;
	
	// Shift coordinates by +50 to ensure positive values
    Fixed shift(50);
    Point shifted_a(a.getX() + shift, a.getY() + shift);
    Point shifted_b(b.getX() + shift, b.getY() + shift);
    Point shifted_c(c.getX() + shift, c.getY() + shift);
    Point shifted_p(point.getX() + shift, point.getY() + shift);
    
    // Calculate the main triangle area first
    Fixed totalArea = area(shifted_a, shifted_b, shifted_c);
    if (totalArea < 0)
        totalArea = totalArea * Fixed(-1);
    
    // Calculate sub-triangles
    Fixed area1 = area(shifted_p, shifted_b, shifted_c);
    if (area1 < 0)
        area1 = area1 * Fixed(-1); // just for safety
    
    Fixed area2 = area(shifted_a, shifted_p, shifted_c);
    if (area2 < 0)
        area2 = area2 * Fixed(-1);
    
    Fixed area3 = area(shifted_a, shifted_b, shifted_p);
    if (area3 < 0)
        area3 = area3 * Fixed(-1);

    // Compare areas without converting to float
    Fixed sum = area1 + area2 + area3;
    
    return (totalArea == sum);
}

//extra check if point is on the edge of the triangle
bool isOnLine(Point const a, Point const b, Point const point) {
    // Check if point lies on line segment using cross product
    Fixed crossProduct = (point.getY() - a.getY()) * (b.getX() - a.getX()) -
                        (point.getX() - a.getX()) * (b.getY() - a.getY());
    
    // If cross product is 0 and point is within segment bounds
    if (crossProduct == Fixed(0)) {
        // Check if point is within the bounds of the line segment
        Fixed minX = Fixed::min(a.getX(), b.getX());
        Fixed maxX = Fixed::max(a.getX(), b.getX());
        Fixed minY = Fixed::min(a.getY(), b.getY());
        Fixed maxY = Fixed::max(a.getY(), b.getY());
        
        return (point.getX() >= minX && point.getX() <= maxX &&
                point.getY() >= minY && point.getY() <= maxY);
    }
    return false;
}

/*old version that cannot handle negative values
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
*/