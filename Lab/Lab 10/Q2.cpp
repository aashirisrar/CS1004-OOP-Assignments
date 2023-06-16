#include <iostream>
using namespace std;

class BasicShape
{
	double area;

public:
	double getArea()
	{
		return area;
	}

	void setArea(double area)
	{
		this->area = area;
	}

	virtual void calcArea() = 0;

};

class Circle : public BasicShape
{
	long centerX;
	long centerY;
	double radius;

public:
	Circle(long cenX, long cenY, double rad)
	{
		centerX = cenX;
		centerY = cenY;
		radius = rad;
	}

	void calcArea()
	{
		setArea(3.14159 * radius * radius);
	}

	long getCenterX()
	{
		return centerX;
	}

	long getCenterY()
	{
		return centerY;
	}
};

class Rectangle : public BasicShape
{
	long width;
	long length;

public:
	Rectangle(long wid, long len)
	{
		width = wid;
		length = len;
	}

	void calcArea()
	{
		setArea(length * width);
	}

};

int main()
{
	Circle circle(2,3,4);
	Rectangle rectangle(2,3);

	circle.calcArea();
	cout << "Circle: " << circle.getArea() << endl;

	rectangle.calcArea();
	cout << "Rectangle: " << rectangle.getArea() << endl;
	
	system("PAUSE");
	return 0;
}