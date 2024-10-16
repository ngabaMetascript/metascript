#include <iostream>
#include <string>
#include <vector>
#include "Elt.h"

int main()
{
	string test = "WEB";
	c2D::Point2D *a = new c2D::Point2D(1,1), *b = new c2D::Point2D(3,1),*c = new c2D::Point2D(3,0);
	c2D::Line *l1 = new c2D::Line(a,b), *l2 = new c2D::Line(b,c);
	l1->setName("jkjkjkjskj");

	c2D::Rectangle* r1 = new c2D::Rectangle(l1,l2);	
	r1->setName("recky");
	std::cout<<r1->renderer(test);
	int x_2D;
	return 0; 
} 
