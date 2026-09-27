/*
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
		cout << "생성자 실행 radius = " << radius << endl;
	}
	Circle(int r)
	{
		radius = r;
		cout << "생성자 실행 radius = " << radius << endl;
	}
	~Circle()
	{
		cout << "소멸자 실행 radius = " << radius << endl;
	}

	int getRadius()
	{
		return radius;
	}

	void setRadius(int radius)
	{
		this->radius = radius;
	}
};

void increase(Circle c)
{
	int r = c.getRadius();
	c.setRadius(r + 1);
}

void increase(Circle* p)
{
	int r = p->getRadius();
	p->setRadius(r + 1);
}
*/

/*값에 의한 호출로 객체 전달
void main()
{
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}
*/

/*주소에 의한 호출로 객체 전달
void main()
{
	Circle waffle(30);
	increase(&waffle);
	cout << waffle.getRadius() << endl;
}
*/

/* 객체 리턴
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	Circle(int radius)
	{
		this->radius = radius;
	}
	
	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

Circle getCircle()
{
	Circle tmp(30);
	return tmp;
}

void main()
{
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle();
	cout << c.getArea() << endl;
}
*/

/*객체에 대한 참조
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	Circle(int radius)
	{
		this->radius = radius;
	}

	void setRadius(int radius)
	{
		this->radius = radius;
	}

	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

void main()
{
	Circle circle;
	Circle& refc = circle;
	refc.setRadius(10);
	cout << refc.getArea() << " " << circle.getArea() << endl;
}
*/

/*참조에 의한 호출로 Circle 객체에 참조 전달
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
		cout << "생성자 실행 radius = " << radius << endl;
	}
	Circle(int radius)
	{
		this->radius = radius;
		cout << "생성자 실행 radius = " << radius << endl;
	}
	~Circle()
	{
		cout << "소멸자 실행 radius = " << radius << endl;
	}

	int getRadius()
	{
		return radius;
	}

	void setRadius(int radius)
	{
		this->radius = radius;
	}
};

void increaseCircle(Circle &c)
{
	int r = c.getRadius();
	c.setRadius(r + 1);
}

void main()
{
	Circle waffle(30);
	increaseCircle(waffle);
	cout << waffle.getRadius() << endl;
}
*/

/*Circle의 복사 생성자와 객체 복사
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	Circle(int radius)
	{
		this->radius = radius;
	}

	Circle(Circle& c);
	
	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

Circle::Circle(Circle& c)
{
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius = " << radius << endl;
}

void main()
{
	Circle src(30);
	Circle dest(src);

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}
*/

/*실습 8-1
#include <iostream>

using namespace std;

class Circle {
private:
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	Circle(int radius)
	{
		this->radius = radius;
	}
	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

void Swap(Circle &a, Circle &b)
{
	Circle tmp = a;
	a = b;
	b = tmp;
}

void main()
{
	Circle A(10);
	Circle B(20);

	cout << "A의 면적 = " << A.getArea() << " " << "B의 면적 = " << B.getArea() << endl;

	Swap(A, B);

	cout << "A의 면적 = " << A.getArea() << " " << "B의 면적 = " << B.getArea() << endl;
}
*/

/*실습 8-2
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{ 
		radius = 1; 
	}
	Circle(int radius) 
	{ 
		this->radius = radius; 
	}

	void setRadius(int radius) 
	{ 
		this->radius = radius; 
	}
	double getArea() 
	{ 
		return 3.14 * radius * radius; 
	}
};

void readRadius(Circle &cir)
{
	int tmp;

	cout << "정수 값으로 반지름을 입력하세요>>";
	cin >> tmp;

	cir.setRadius(tmp);

}

void main()
{
	Circle donut;
	readRadius(donut);
	cout << "donut의면적= " << donut.getArea() << endl;
}
*/

/*실습 8-3
#include <iostream>

using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value); // 매개변수value로멤버value를초기화한다.
	Accumulator& add(int n);  // value에n을더해값을누적한다.
	int get();// 누적된값value를리턴한다.
};

Accumulator::Accumulator(int value)
{
	this->value = value;
}

Accumulator& Accumulator::add(int n)
{
	this->value = value + n;
	return *this;
}

int Accumulator::get()
{
	return value;
}

void main()
{
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc의value 멤버가28이된다.
	cout << acc.get() << endl; // 28 출력
}
*/

/*실습 8-4
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Book {
	char* title;    // 제목문자열
	int price;       // 가격
public:
	Book(char* title, int price);
	Book(Book& obj);
	~Book();
	void set(char* title, int price);
	void show() 
	{ 
		cout << title << " " << price << "원" << endl;
	}
};

Book::Book(char* title, int price)
{
	this->price = price;
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
}

Book::Book(Book& obj)
{
	this->price = obj.price;
	int length = strlen(obj.title);
	this->title = new char[length + 1];
	strcpy(this->title, obj.title);
}

Book::~Book()
{
	delete[] this->title;
	cout << "소멸자" << endl;
}

void Book::set(char* title, int price)
{
	delete[] this->title;
	int length = strlen(title);
	this->title = new char[length + 1];

	strcpy(this->title, title);
	this->price = price;
}

void main()
{
	Book cpp((char*)"명품C++", 10000);
	Book java(cpp);
	java.set((char*)"명품자바", 12000);
	cpp.show();
	java.show();
}
*/

/*실습 8-5
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Book {
	char title[100];    // 제목문자열
	int price;       // 가격
public:
	Book(char* title, int price);
	~Book();
	void set(char* title, int price);
	void show() 
	{ 
		cout << title << ' ' << price << "원" << endl; 
	}
};

Book::Book(char* title, int price)
{
	strcpy(this->title, title);
	this->price = price;
}

Book::~Book()
{
	cout << "소멸자" << endl;
}

void Book::set(char* title, int price)
{
	strcpy(this->title, title);
	this->price = price;
}

void main() 
{
	Book cpp((char*)"명품C++", 10000);
	Book java(cpp);
	java.set((char*)"명품자바", 12000);
	cpp.show();
	java.show();
}
*/

