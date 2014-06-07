#ifndef RECTANGLE2D_H_
#define RECTANGLE2D_H_
using namespace std;

class Rectangle2D
{
private:
	double x, y;
	double width, height;
public:
	double getx() const;
	double gety() const;
	const double setx(double X);
	const double sety(double Y);
	double getWidth() const;
	double getHeight() const;
	const double setWidth(double Width);
	const double setHeight(double Height);

	Rectangle2D();
	Rectangle2D(double x, double y, double width, double height);

	double getArea(double width, double height) const;
	double getPerimeter(double width, double height) const;
	bool contains(double xIn, double yIn) const;
	bool contains(const Rectangle2D &r) const; 
	bool overlaps(const Rectangle2D &r) const;
};
#endif