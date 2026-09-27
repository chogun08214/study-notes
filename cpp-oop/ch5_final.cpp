/*2개의 생성자를 가진 Circle 클래스
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
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

void main()
{
	Circle donut;
	double area = donut.getArea();
	cout << "dount 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}
*/

/*Circle 클래스에 소멸자 작성 및 실행
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
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle()
{
	cout << "반지름 " << radius << " 원 소멸" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

void main()
{
	Circle donut;
	Circle pizza(30);
}
*/

/*지역 객체와 전역 객체의 생성 및 소멸 순서
#include <iostream>

using namespace std;

class Circle {
public:
	int radius;

	Circle();
	Circle(int r);
	~Circle();
};

Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle()
{
	cout << "반지름 " << radius << " 원 소멸" << endl;
}

Circle globalDonut(1000);
Circle globalPizza(2000);

void f()
{
	Circle fDonut(100);
	Circle fPizza(200);
}

void main()
{
	Circle mainDonut;
	Circle mainPizza(30);
	f();
}
*/

