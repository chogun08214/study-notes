/*practice5_1
#include <iostream>

using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}


int main(void)
{
	Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}
*/

/*practice5_2
#include <iostream>

using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::~Circle()
{
	cout << "반지름 " << radius << "인 원 소멸" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main(void)
{
	Circle donut;
	Circle pizza(30);

	return 0;
}
*/

/*practice5_3
#include <iostream>

using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::~Circle()
{
	cout << "반지름 " << radius << "인 원 소멸" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

Circle globalDonut(1000);
Circle globalPizza(2000);

void f()
{
	Circle fDonut(100);
	Circle fPizza(200);
}

int main(void)
{
	Circle mainDonut;
	Circle mainPizza(30);
	f();
}
*/

/*ex5_1
#include <iostream>

using namespace std;

class Rectangle {
public:
	int width;
	int height;
	Rectangle()
	{
		width = 1, height = 1;
	}
	Rectangle(int a, int b)
	{
		width = a, height = b;
	}
	Rectangle(int c)
	{
		width = height = c;
	}
	bool isSquare();
	~Rectangle();
};

Rectangle::~Rectangle()
{
	cout << "소멸" << width << " " << height << endl;
}

bool Rectangle::isSquare()
{
	if (width == height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare())
	{
		cout << "rect1은 정사각형이다." << endl;
	}
	if (rect2.isSquare())
	{
		cout << "rect2은 정사각형이다." << endl;
	}
	if (rect3.isSquare())
	{
		cout << "rect3은 정사각형이다." << endl;
	}
}
*/

/*ex5_2
#include <iostream>

using namespace std;

class Oval {
public:
	int width, height;
	Oval(int width_in, int height_in);
	Oval();
	~Oval();
	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();
};

Oval::Oval(int widthin, int heightin)
{
	width = widthin, height = heightin;
}

Oval::Oval()
{
	width = height = 1;
}

Oval::~Oval()
{
	cout << "Oval 소멸 : " << "width = " << width << " , " << "heigh = " << height << endl;
}

int Oval::getWidth()
{
	return width;
}

int Oval::getHeight()
{
	return height;
}

void Oval::set(int w, int h)
{
	width = w;
	height = h;
}

void Oval::show()
{
	cout << "width = " << width << " " << "height = " << height << endl;
}

int main(void)
{
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();

	cout << b.getWidth() << ", " << b.getHeight() << endl;
}
*/

/*ex5_3
#include <iostream>

using namespace std;

class Rectangle2 {
private:
	int width;
	int height;
public:
	int getArea()
	{
		int area = width * height;
		return area;
	}
	bool setWidth(int input)
	{
		if (input < 0)
		{
			return false;
		}
		else
		{
			width = input;
			return true;
		}
	}
	bool setHeight(int input)
	{
		if (input < 0)
		{
			return false;
		}
		else
		{
			height = input;
			return true;
		}
	}
	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}
};

int main(void)
{
	Rectangle2 rect;

	if (rect.setWidth(-3) == false)
	{
		cout << "width error " << endl;
	}
	if (rect.setHeight(5) == false)
	{
		cout << "height error " << endl;
	}

	cout << "width = " << rect.getWidth() << endl;
	cout << "height = " << rect.getHeight() << endl;
	cout << "사각형의면적은 " << rect.getArea() << endl;
}
*/

/*ex5_4
#include <iostream>

using namespace std;

inline bool isEven(int B)
{
	if (B % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	int A = 11;

	if (isEven(A))
	{
		cout << A << "는 짝수다!!" << endl;
	}
	else
	{
		cout << A << "는 홀수다!!" << endl;
	}
}
*/

