#include <iostream>
#include <string>
#include "Rectangle2D.h"
using namespace std;

double Rectangle2D::getx() const
{
	return x;
}

double Rectangle2D::gety() const
{
	return y;
}

const double Rectangle2D::setx(double X)
{
	x = X;
	return x;
}

const double Rectangle2D::sety(double Y)
{
	y = Y;
	return y;
}

double Rectangle2D::getWidth() const
{
	return width;
}

double Rectangle2D::getHeight() const 
{
	return height;
}

const double Rectangle2D::setWidth(double Width)
{
	width = Width;
	return width;
}

const double Rectangle2D::setHeight(double Height)
{
	height = Height;
	return height;
}

Rectangle2D::Rectangle2D()
{
	x = 0;
	y = 0;
	width = 1;
	height = 1;
}

Rectangle2D::Rectangle2D(double X, double Y, double Width, double Height)
{
	x = X;
	y = Y;
	width = Width;
	height = Height;
}

double Rectangle2D::getArea(double width, double height) const
{
	double area = (width * height);
	return area;
}

double Rectangle2D::getPerimeter(double width, double height) const
{
	double perimeter = ((width * 2) + (height * 2));
	return perimeter;
}

bool Rectangle2D::contains(double xIn, double yIn) const
{
	bool within;
	double xA = x - (width / 2);
	double yA = y + (height / 2);
	double xB = x + (width / 2);
	double yB = yA;
	double xC = xB;
	double yC = y - (height / 2);

	if (((xA < xIn) && (xIn < xB)) && ((yC < yIn) && (yIn < yB)))
		within = true;
	else
		within = false;
	return within;
}

bool Rectangle2D::contains(const Rectangle2D &r) const
{
	double LeftUpperX = r.getx() - (r.getWidth() / 2);
	double LeftUpperY = r.gety() + (r.getHeight() / 2);
	double RightUpperX = r.getx() + (r.getWidth() / 2);
	double RightLowerY = r.gety() - (r.getHeight() / 2);

	if ((contains(LeftUpperX, LeftUpperY)) && (contains(RightUpperX, LeftUpperY)) && (contains(RightUpperX, RightLowerY)))
		return true;
	else
		return false;
}

bool Rectangle2D::overlaps(const Rectangle2D &r) const
{
	double LeftUpperX = r.getx() - (r.getWidth() / 2);
	double LeftUpperY = r.gety() + (r.getHeight() / 2);
	double RightUpperX = r.getx() + (r.getWidth() / 2);
	double RightLowerY = r.gety() - (r.getHeight() / 2);

	if ((contains(LeftUpperX, LeftUpperY)) || (contains(RightUpperX, LeftUpperY)) || (contains(RightUpperX, RightLowerY)) || (contains(LeftUpperX, RightLowerY)))
		return true;
	else
		return false;
}