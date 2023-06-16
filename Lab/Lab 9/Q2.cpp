#include <iostream>
using namespace std;

class Shape
{
protected:
	int length;
	int breadth;
	int height;


};

class Painting
{
public:
	float getCost(float area)
	{
		float cost = area * 70;
		return cost;
	}
};

class Square : public Shape, public Painting
{

public:
	Square(int l)
	{
		length = l;
	}

	int getArea()
	{
		int area = length * length;
		return area;
	}
};

class Rectangle : public Shape, public Painting
{

public:
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}

	int getArea()
	{
		int area = length * breadth;
		return area;
	}
};

class Triangle : public Shape, public Painting
{

public:
	Triangle(int b, int h)
	{
		breadth = b;
		height = h;
	}

	float getArea()
	{
		float area = 0.5 * breadth * height;
		return area;
	}
};

int main() 
{
	Square sq(5);
	Rectangle rec(5,7);
	Triangle tri(5,12);

	cout << "Square Area: " << sq.getArea()<<endl;
	cout << "Paint cost: $" << sq.getCost(sq.getArea()) << endl;

	cout << "Rectangle Area: " << rec.getArea() << endl;
	cout << "Paint cost: $" << rec.getCost(rec.getArea()) << endl;

	cout << "Triangle Area: " << tri.getArea() << endl;
	cout << "Paint cost: $" << tri.getCost(tri.getArea()) << endl;
	

	system("PAUSE");
	return 0;
}

