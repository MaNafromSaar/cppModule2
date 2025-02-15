/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:04:28 by mnaumann          #+#    #+#             */
/*   Updated: 2025/02/15 17:22:52 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

using std::cout;

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
    
    Point inside(2.0f, 2.0f);
    Point outside(6.0f, 6.0f);
    
	cout << "Triangle with vertices at (" 
	<< a.getX() << "," << a.getY() << "), ("
	<< b.getX() << "," << b.getY() << "), and ("
	<< c.getX() << "," << c.getY() << ")" << std::endl;
	cout << "has an area of " << area(a, b, c) << " areal units" << std::endl;
	cout << "Point (" << inside.getX() 
		<< "," << inside.getY() << ") is " 
		<< (bsp(a, b, c, inside) ? "inside" : "outside") << std::endl;
	cout << "Point (" << outside.getX() 
		<< "," << outside.getY() << ") is " 
		<< (bsp(a, b, c, outside) ? "inside" : "outside") << std::endl;
    
	Point a2(-3.0f, 0.0f);
	Point b2(0.0f, 3.5f);
	Point c2(3.0f, 0.0f);

	Point inside3(0.0f, 0.0f);
	Point outside2(0.0f, 3.6f);
	Point inside2(-0.5f, 0.25f);

	cout << "Triangle with vertices at (" 
	<< a2.getX() << "," << a2.getY() << "), ("
	<< b2.getX() << "," << b2.getY() << "), and ("
	<< c2.getX() << "," << c2.getY() << ")" << std::endl;
	cout << "has an area of " << area(a2, b2, c2) << " areal units" << std::endl;
	cout << "Point (" << inside3.getX() 
		<< "," << inside3.getY() << ") is " 
		<< (bsp(a2, b2, c2, inside3) ? "inside" : "outside") << std::endl;
	cout << "Point (" << outside2.getX() 
		<< "," << outside2.getY() << ") is " 
		<< (bsp(a2, b2, c2, outside2) ? "inside" : "outside") << std::endl;
	cout << "Point (" << inside2.getX() 
		<< "," << inside2.getY() << ") is " 
		<< (bsp(a2, b2, c2, inside2) ? "inside" : "outside") << std::endl;
    return 0;
}
