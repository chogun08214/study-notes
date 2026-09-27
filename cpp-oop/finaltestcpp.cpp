#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*********************************************************************************/

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();

	double getArea()
	{
		return 3.14 * radius * radius;
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

Circle::Circle()
{
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius)
{
	this->radius = radius;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle()
{
	cout << "소멸자 실행 radius = " << radius << endl;
}

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

void increaseREF(Circle& c)
{
	int r = c.getRadius();
	c.setRadius(r + 1);
}

void ch8_ex1() //값에 의한 호출
{
	Circle waffle(30);
	increase(waffle); //소멸자 호출
	cout << waffle.getRadius() << endl; //radius 값 변화없음
}

void ch8_ex2() //주소에 의한 호출
{
	Circle waffle(30);
	increase(&waffle); //생성자와 소멸자가 호출 되지 않음
	cout << waffle.getRadius() << endl; //radius 값 변화
}

void ch8_ex3() //참조에 의한 호출
{
	Circle waffle(30);
	increaseREF(waffle);
	cout << waffle.getRadius() << endl; //radius 값 변화
}

Circle getCircle() //class인 Circle반환
{
	Circle tmp(30); //radius = 30
	return tmp;
}

void ch8_ex4() //객체 리턴
{
	Circle c;
	cout << c.getArea() << endl;

	c = getCircle(); //객체 리턴
	cout << c.getArea() << endl;
}

void ch8_ex5() //객체에 대한 참조
{
	Circle circle;
	Circle& refc = circle; //circle객체에 대한 참조 변수 refc 선언
	refc.setRadius(10);
	cout << refc.getArea() << " " << circle.getArea() << endl;
}

void ch8_ex6() //얕은 복사
{
	int* A = new int[10];
	int* B;

	for (int n = 0; n < 10; n++)
	{
		A[n] = n * 10;
	}

	B = A; //얕은 복사

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", B[i]);
	}

	delete []A;
}

void ch8_ex7() //깊은 복사
{
	int* A = new int[10];
	int* B = new int[10];

	for (int n = 0; n < 10; n++)
	{
		A[n] = n * 10;
	}

	for (int i = 0; i < 10; i++)
	{
		B[i] = A[i]; //깊은 복사
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", B[i]);
	}

	delete []A;
	delete []B;
}

class Circle1 {
	int radius;
public:
	Circle1()
	{
		radius = 1;
	}
	Circle1(int radius)
	{
		this->radius = radius;
	}
	Circle1(Circle1& c);

	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

Circle1::Circle1(Circle1& c)
{
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius = " << radius << endl;
}

void ch8_ex8()
{
	Circle1 src(30);
	Circle1 dest(src); //복사생성자 호출

	cout << "원본의면적= " << src.getArea() << endl;
	cout << "사본의면적= " << dest.getArea() << endl;
}

class Circle2 
{
private:
	int radius;
public:
	Circle2() 
	{ 
		radius = 1; 
	}
	Circle2(int radius)
	{ 
		this->radius = radius; 
	}
	double getArea() 
	{
		return 3.14 * radius * radius;
	}
};

void swap(Circle2& a, Circle2& b)
{
	Circle2 tmp = a;
	a = b;
	b = tmp;
}

void ch8_test1()
{
	Circle2 A(10);
	Circle2 B(20);

	cout << "A의 면적 = " << A.getArea() << " " << "B의 면적 = " << B.getArea() << endl;

	swap(A, B);
	cout << "A의 면적 = " << A.getArea() << " " << "B의 면적 = " << B.getArea() << endl;
}

class Circle3 
{
	int radius;
public:
	Circle3() 
	{ 
		radius = 1; 
	}
	Circle3(int radius) 
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

void readRadius(Circle3& c)
{
	int radius;
	cout << "정수값으로 반지름을 입력하세요>>";
	cin >> radius;
	c.setRadius(radius);
}

void ch8_test2()
{
	Circle3 donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}

class Accumulator 
{
	int value;
public:
	Accumulator(int value); // 매개변수value로멤버value를초기화한다.
	Accumulator& add(int n);  // value에n을더해값을누적한다.
	int get();  // 누적된값value를리턴한다.
};

Accumulator::Accumulator(int value)
{
	this->value = value;
}

Accumulator& Accumulator::add(int n) //함수 형태 주의
{
	this->value += n;
	return *this; //전부 반환한다는 의미
}

int Accumulator::get()
{
	return value;
}

void ch8_test3()
{
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc의value 멤버가28이된다.
	cout << acc.get() << endl; // 28 출력
}

class Book {
	char* title;    // 제목문자열
	int price;       // 가격
public:
	Book(char* title, int price);
	Book(Book& b);
	~Book();
	void set(char* title, int price);
	void show() 
	{ 
		cout << title << " " << price << "원" << endl;
	}
};

Book::Book(char* title, int price) //주의 
{
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::Book(Book& b)
{
	int length = strlen(b.title);
	this->title = new char[length + 1];
	strcpy(this->title, b.title);
	this->price = b.price;
}

Book::~Book()
{
	delete[] this -> title; //반드시 삽입
}

void Book::set(char* title, int price) 
{
	delete[] this->title; //주의 
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
	this->price = price;
}

void ch8_test4()
{
	Book cpp((char*)"명품C++", 10000);
	Book java = cpp;
	java.set((char*)"명품자바", 12000);
	cpp.show();
	java.show();
}

class Book1 {
	char title[100];    // 제목문자열
	int price;       // 가격
public:
	Book1(char* title, int price);
	Book1(Book1& b);
	~Book1();
	void set(char* title, int price);
	void show() 
	{ 
		cout << title << ' ' << price << "원" << endl; 
	}
};

Book1::Book1(char* title, int price) //주의 
{
	strcpy(this->title, title);
	this->price = price;
}

Book1::Book1(Book1& b)
{
	strcpy(this->title, b.title);
	this->price = b.price;
}

void Book1::set(char* title, int price)
{
	strcpy(this->title, title);
	this->price = price;
}

void ch8_test5()
{
	Book cpp((char*)"명품C++", 10000);
	Book java(cpp);
	java.set((char*)"명품자바", 12000);
	cpp.show();
	java.show();
}

class Rect {
	int width, height;
public:
	Rect(int width, int height)
	{
		this->width = width;
		this->height = height;
	}

	friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s)
{
	if (r.width == s.width || r.height == s.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ch9_ex1() //전역 함수를 firend로 선언
{
	Rect a(3, 4), b(4, 5);

	if (equals(a, b))
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
}

class Rect1; //반드시 선언

class RectManager {
public:
	bool equals(Rect1 r, Rect1 s);
};

class Rect1{
	int width, height;
public:
	Rect1(int width, int height)
	{
		this->width = width;
		this->height = height;
	}

	friend bool RectManager::equals(Rect1 r, Rect1 s);
};

bool RectManager::equals(Rect1 r, Rect1 s)
{
	if (r.width == s.width || r.height == s.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ch9_ex2() //다른 class의 멤버 함수를 firend로 선언
{
	Rect1 a(3, 4), b(3, 4);
	RectManager man;

	if (man.equals(a, b))
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
}

class Rect2;

class RectManager1 { // RectManager클래스선언
public:
	bool equals(Rect2 r, Rect2 s);
	void copy(Rect2& dest, Rect2& src);
};

class Rect2 { // Rect클래스선언
	int width, height;
public:
	Rect2(int width, int height) 
	{ 
		this->width = width; this->height = height; 
	}
	
	friend RectManager1;
};

bool RectManager1::equals(Rect2 r, Rect2 s)
{
	if (r.width == s.width || r.height == s.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void RectManager1::copy(Rect2& dest, Rect2& src)
{
	dest.width = src.width;
	dest.height = src.height;
}

void ch9_ex3() //다른 class전체를 friend로 선언
{
	Rect2 a(3, 4), b(5, 6); 
	RectManager1 man;

	man.copy(b, a); // a를b에복사한다.
	if (man.equals(a, b))
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
}

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	Power operator+(Power op2)
	{
		Power tmp;
		tmp.kick = this->kick + op2.kick;
		tmp.punch = this->punch + op2.punch;
		return tmp;
	}

	Power operator-(Power op2)
	{
		Power tmp;
		tmp.kick = this->kick - op2.kick;
		tmp.punch = this->punch - op2.punch;
		return tmp;
	}

	bool operator==(Power op2)
	{
		if (this->kick == op2.kick && this->punch && op2.punch)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Power operator+=(Power op2)
	{
		this->kick = this->kick + op2.kick;
		this->punch = this->punch + op2.punch;
		return *this;
	}

	Power operator++()
	{
		this->kick++;
		this->punch++;
		return *this;
	}

	Power operator++(int x)
	{
		Power tmp = *this;
		kick++;
		punch++;
		return tmp;
	}

	friend Power operator+(int op1, Power op2);

	void show()
	{
		cout << "kick = " << kick << " " << "punch = " << punch << endl;
	}
};

Power operator+(int op1, Power op2)
{
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;
	return tmp;
}

void ch9_ex4() //연산자 중복
{
	Power a(3, 5), b(4, 6), c, d, e, f, g, h, i, j, k;
	c = a + b; //+연산자 //fiend로 작성할 경우 firend Power operator+(Power op1, Power op2)
	//tmp.kick = op1.kick + op2.kick;
	c.show();
	d = a - b; //-연산자
	d.show();

	if (a == b) //==연산자
	{
		cout << "same" << endl;
	}
	else
	{
		cout << "different" << endl;
	}

	e = a += b; //+=연산자
	e.show();
	f = ++a; //전위 ++연산자 //fiend로 작성할 경우 Power operator++(Power& op)
	//op.kick++;
	f.show();
	g = a++; //후위 ++연산자//fiend로 작성할 경우 Power operator++(Power& op, int x)
	//Power tmp = op;
	//op.kick++;
	//return tmp;
	g.show();
	h = 2 + a; //2+a연산
	h.show();
}

class Complex {
	float re, im;
public:
	Complex() 
	{ 
		re = im = 0; 
	}
	Complex(float im, float re) 
	{ 
		this->re = re; this->im = im; 
	}
	Complex operator+(Complex in) 
	{
		Complex tmp;
		tmp.re = this->re + in.re;
		tmp.im = this->im + in.im;
		return tmp;
	}
	Complex operator-(Complex op2)
	{
		Complex tmp;
		tmp.re = this->re - op2.re;
		tmp.im = this->im - op2.im;
		return tmp;
	}
	void show()
	{
		cout.precision(5);
		if (im >= 0)
		{
			cout << re << " + j" << im << endl;
		}
		else
		{
			cout << re << " -j" << -im << endl;
		}
	}
};

void ch9_test0()
{
	Complex X(2, 3), Y(3, 4), Z;
	Z = X + Y;
	Z.show();
	Z = X - Y;
	Z.show();
}

class Complex1 {
	float re, im;
public:
	Complex1() { re = im = 0; }
	Complex1(float im, float re) { this->re = re; this->im = im; }
	
	void show()
	{
		cout.precision(5);
		if (im >= 0)
			cout << re << " + j" << im << endl;
		else
			cout << re << " -j" << -im << endl;
	}

	friend Complex1 operator+(Complex1 op1, Complex1 op2);
	friend Complex1 operator-(Complex1 op1, Complex1 op2);
};

Complex1 operator+(Complex1 op1, Complex1 op2)
{
	Complex1 tmp;
	tmp.re = op1.re + op2.re;
	tmp.im = op1.im + op2.im;
	return tmp;
}

Complex1 operator-(Complex1 op1, Complex1 op2)
{
	Complex1 tmp;
	tmp.re = op1.re - op2.re;
	tmp.im = op1.im - op2.im;
	return tmp;
}

void ch9_test0_extend()
{
	Complex1 X(2, 3), Y(3, 4), Z;
	Z = X + Y;
	Z.show();
	Z = X - Y;
	Z.show();
}

class Book2 {
	string title;
	int price;
	int pages;
public:
	Book2(string title = "", int price = 0, int pages = 0) 
	{
		this->title = title; 
		this->price = price; 
		this->pages = pages;
	}

	Book2 operator+=(int op2)
	{
		this->price = this->price + op2;
		return *this; //주의
	}
	Book2 operator-=(int op2)
	{
		this->price = this->price - op2;
		return *this; //주의
	}

	bool operator!() //test5
	{
		if (this->price == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend bool operator == (Book2& A, int price); //test3
	
	void show() 
	{
		cout << title << " " << price << "원" << pages << " 페이지" << endl;
	}
	string getTitle() 
	{
		return title;
	}
};

void ch9_test1()
{
	Book2 a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;    // 책a의가격500원증가
	b -= 500;     // 책b의가격500원감소
	a.show();
	b.show();
}

bool operator == (Book2& A, int price)
{
	if (A.price = price)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ch9_test3()
{
	Book2 a((char*)"명품C++", 30000, 500), b((char*)"고품C++", 30000, 500);
	// price 비교
	if (a == 30000)
	{
		cout << "정가30000원" << endl;
	}
	else
	{
		cout << "정가30000원 아님" << endl;
	}
}

void ch9_test5()
{
	Book2 book((char*)"벼룩시장", 0, 50); // 가격은0
	if (!book)
	{
		cout << "공짜다" << endl;
	}
}

class Point {
	int x, y;
public:
	void set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void showPoint()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color)
	{
		this->color = color;
	}
	void showColorPoint()
	{
		cout << color << ":";
		showPoint(); // Point의showPoint() 호출
	}
};

void ch10_ex1() //파생 클래스
{
	Point p;
	ColorPoint cp;
	cp.set(3, 4); //주의
	cp.setColor("Red");
	cp.showColorPoint();
}

void ch10_ex2() //upcasting 
{
	ColorPoint cp;
	ColorPoint* pDer = &cp; //pDer은 모든 public멤버 접근 가능
	Point* pBase = pDer; //pBase는 기본 class의 public멤버 접근 가능

	pDer->set(3, 4);
	pBase->showPoint();
	pDer->setColor("Red");
	pDer->showColorPoint();
}

void ch10_ex3() //downcasting
{
	ColorPoint cp;
	ColorPoint* pDer; //pDer은 모든 public멤버 접근 가능
	Point* pBase = &cp; //upcast | pBase는 기본 class의 public멤버 접근 가능

	pBase->set(3, 4);
	pBase->showPoint();

	pDer = (ColorPoint*)pBase; //downcasting 주의
	pDer->setColor("Red");
	pDer->showColorPoint();
}

class Circle4 {
private:
	int radius;
public:
	Circle4()
	{ 
		radius = 1;
	}
	Circle4(int radius) 
	{ 
		this->radius = radius; 
	}
	double getArea() 
	{ 
		return 3.14 * radius * radius; 
	}
	void setRadius(int radius)
	{
		this->radius = radius;
	}
	int getRadius()
	{
		return radius;
	}
};

class NamedCircle : public Circle4 {
	string name;
public:
	NamedCircle()
	{
		setRadius(0);
		this->name = name;
	}
	NamedCircle(int radius, string name)
	{
		setRadius(radius);
		this->name = name;
	}
	void show()
	{
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
};

void ch10_test1()
{
	NamedCircle waffle(3, "waffle"); // 반지름이3이고이름이waffle인원
	waffle.show();
}

class Circle5 {
private:
	int radius;
public:
	Circle5()
	{
		radius = 1;
	}
	Circle5(int radius)
	{
		this->radius = radius;
	}
	double getArea()
	{
		return 3.14 * radius * radius;
	}
	void setRadius(int radius)
	{
		this->radius = radius;
	}
	int getRadius()
	{
		return radius;
	}
};

class NamedCircle1 : public Circle5 {
	string name;
public:
	NamedCircle1()
	{
		setRadius(0);
		this->name = name;
	}
	NamedCircle1(int radius, string name)
	{
		setRadius(radius);
		this->name = name;
	}
	void setNamedCircle1(int radius, string name)
	{
		setRadius(radius);
		this->name = name;
	}
	string getName()
	{
		return name;
	}
	
	void show()
	{
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}

	friend void FindMaxAreaPizza(NamedCircle1 pizza[], int size);
};

void FindMaxAreaPizza(NamedCircle1 pizza[], int size)
{
	int max = 0;
	int index = 0;

	for (int i = 0; i < size; i++)
	{
		if (pizza[i].getRadius() > max)
		{
			max = pizza[i].getRadius();
			index = i;
		}
	}

	cout << "가장 면적이 큰 피자는 " << pizza[index].getName() << "피자입니다" << endl;
}

void ch10_test2()
{
	NamedCircle1 pizza[5];

	cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;

	for (int i = 0; i < 5; i++)
	{
		int radius;
		string name;
		cin >> radius;
		cin >> name;
		pizza[i].setNamedCircle1(radius, name);
	}

	FindMaxAreaPizza(pizza, 5);
}

class BaseArray {
private:
	int capacity;    // 동적할당된메모리용량
	int* mem;       // 정수배열을만들기위한메모리포인터
protected:
	BaseArray(int capacity = 100)
	{
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() 
	{ 
		delete[] mem; 
	}
	void put(int index, int val) 
	{ 
		mem[index] = val; 
	}
	int get(int index) 
	{ 
		return mem[index]; 
	}
	int getCapacity() 
	{
		return capacity; 
	}
	void MakeQueue(int capacity = 100) //생성
	{
		this->capacity = capacity;
		mem = new int[capacity]; //주의
	}
};

class MyQueue : public BaseArray {
	int index;
public:
	MyQueue(int cap)
	{
		MakeQueue(cap);
		index = 0;
	}
	void enqueue(int n)
	{
		put(index, n);
		index++;
	}
	int capacity()
	{
		return getCapacity();
	}
	int length()
	{
		return index;
	}
	int dequeue() //주의
	{
		int value = get(0);
		index--;
		for (int i = 0; i < index; i++)
		{
			//mem[i] = mem[i + 1];
			put(i, get(i + 1));
		}

		return value;
	}
};

void ch10_test3()
{
	MyQueue mQ(100);

	int n;

	cout << "큐에삽입할5개의정수를입력하라>> ";
	for (int i = 0; i < 5; i++) 
	{
		cin >> n;
		mQ.enqueue(n); // 큐에삽입
	}
	cout << "큐의용량: " << mQ.capacity() << ", 큐의크기: " << mQ.length() << endl;
	cout << "큐의원소를순서대로제거하여출력한다>> ";

	while (mQ.length() != 0) 
	{
		cout << mQ.dequeue() << ' '; // 큐에서제거하여출력
	}

	cout << endl << "큐의현재크기: " << mQ.length() << endl;
}

class Base {
public:
	void f()
	{
		cout << "Base::f() called" << endl;
	}
};

class Derived : public Base {
public:
	void f()
	{
		cout << "Derived::f() called" << endl; 
	}
};

void ch11_ex1() //상속관계에서 함수를 중복
{
	Derived d, * pDer;
	pDer = &d;
	pDer->f();

	Base* pBase;
	pBase = pDer; //upcasting
	pBase->f();
}

class Base1 {
public: 
	virtual void f() //가상함수(존재감 없어짐)
	{
		cout << "Base::f() called" << endl;
	}
};

class Derived1 : public Base1 {
public:
	virtual void f() //가상함수, 오버라이딩
	{
		cout << "Derived::f() called" << endl;
	}
};

void ch11_ex2() //오버라이딩과 가상함수
{
	Derived1 d, * pDer;
	pDer = &d;
	pDer->f();

	Base1* pBase;
	pBase = pDer;
	pBase->f();
}

class SHAPE
{
public:
	virtual void draw() {}
};

class CIRCLE : public SHAPE {
public:
	virtual void draw()
	{
		cout << "Circle draw" << endl;
	}
};

class RECT : public SHAPE {
public:
	virtual void draw()
	{
		cout << "Rect draw" << endl;
	}
};

class LINE : public SHAPE {
public:
	virtual void draw() {
		cout << "Line draw" << endl;
	}
};

void paint(SHAPE* pShape) {
	pShape->draw();
}

void ch11_ex3() //오버 라이딩
{
	paint(new CIRCLE); //up-casting
	paint(new RECT);
	paint(new LINE);
}

void ch11_ex4() //오버 라이딩
{
	CIRCLE C;
	RECT R;
	LINE L;

	paint(&C);
	paint(&R);
	paint(&L);
}

class Shape {
public:
	void paint()
	{
		draw();
	}
	virtual void draw()
	{
		cout << "Shape::draw() called" << endl;
	}
};

void ch11_ex5() //동적 바인딩
{
	Shape* pShape = new Shape();
	pShape->paint();
	delete pShape;
}

/*
class Shape1 {
public:
	void paint()
	{
		draw();
	}

	virtual void draw()
	{
		cout << "Shape::draw() called" << endl;
	}
};

class Circle5 : public Shape1 {
	virtual void draw()
	{
		cout << "Circle::draw() called" << endl;
	}
};

void ch11_ex6() //동적 바인딩
{
	Shape1* pShape = new Circle5();
	pShape->paint();
	delete pShape;
}
*/

class Base2 {
public:
	virtual void f()
	{
		cout << "Base::f() called" << endl;
	}
};

class Derived2 : public Base2 {
public:
	void f() { cout << "Derived::f() called" << endl; }
};

class GrandDerived : public Derived2 {
public:
	void f() { cout << "GrandDerived::f() called" << endl; }
};

void ch11_ex7() //상속이 반복되는 경우 가상 함수 호출
{
	GrandDerived g;
	Base2* bp;
	Derived2* dp;
	GrandDerived* gp;

	bp = dp = gp = &g;

	bp->f();
	dp->f();
	gp->f();
}

class Shape2 {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};

class Circle6 : public Shape2
{
public:
	void draw()
	{
		Shape2::draw(); //기본 클래스의 draw 실행
		cout << "Circle" << endl;
	}
};

void ch11_ex8() //범위 지정 연산자::를 이용한 클래스의 가상 함수 호출
{
	Circle6 circle;
	Shape2* pShape = &circle;

	pShape->draw();
	pShape->Shape2::draw();
}

class Base5 {
public:
	virtual ~Base5() { cout << "~Base()" << endl; }
};
class Derived5 : public Base5 {
public:
	virtual ~Derived5() { cout << "~Derived()" << endl; }
};

void ch11_ex9() //가상 소멸자
{
	Derived5* dp = new Derived5();
	Base5* bp = new Derived5();
	
	delete dp; // Derived의 포인터로 소멸
	delete bp;  // Base의 포인터로 소멸
}

class Shape3 {
	string name;
public:
	virtual float getArea() 
	{ 
		return 0.0; 
	}
	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;
	}
};

class Oval3 : public Shape3 {
	int a, b;
public:
	Oval3(string name, int a, int b)
	{
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea()
	{
		return 3.14 * a * b;
	}
};

class Rect3 : public Shape3 {
	int a, b;
public:
	Rect3(string name, int a, int b)
	{
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea()
	{
		return a * b;
	}
};

class Triangular3 : public Shape3 {
	int a, b;
public:
	Triangular3(string name, int a, int b)
	{
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea()
	{
		return 0.5 * a * b;
	}
};

void ch11_test0()
{
	Oval3* p0;
	Rect3* p1;
	Triangular3* p2;

	p0 = new Oval3("빈대떡", 10, 20);
	p1 = new Rect3("찰떡", 30, 40);
	p2 = new Triangular3("토스트", 30, 40);

	cout << p0->getName() << " 넓이는" << p0->getArea() << endl;
	cout << p1->getName() << " 넓이는" << p1->getArea() << endl;
	cout << p2->getName() << " 넓이는" << p2->getArea() << endl;

	delete p0;
	delete p1; 
	delete p2;
}

class Shape4 {
	string name;
public:
	virtual float getArea() 
	{ 
		return 0.0; 
	}
	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;
	}
};

class OVAL1 : public Shape4 {
	int a, b;
public:
	OVAL1(string name, int a, int b)
	{
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea()
	{
		return 3.14 * a * b;
	}
};

class RECT1 : public Shape4 {
	int a, b;
public:
	RECT1(string name, int a, int b)
	{
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea()
	{
		return 3.14 * a * b;
	}
};

class TRIANGULAR1 : public Shape4 {
	int a, b;
public:
	TRIANGULAR1(string name, int a, int b)
	{
		setName(name);
		this->a = a;
		this->b = b;
	}
	virtual float getArea()
	{
		return 3.14 * a * b;
	}
};

void ch11_test1()
{
	Shape4* p[3];
	p[0] = new OVAL1("빈대떡", 10, 20); // upcasting
	p[1] = new RECT1("찰떡", 30, 40); // upcasting 
	p[2] = new TRIANGULAR1("토스트", 30, 40); // upcasting

	for (int i = 0; i < 3; i++)
	{
		cout << p[i]->getName() << " 넓이는" << p[i]->getArea() << endl;
	}

	for (int i = 0; i < 3; i++) delete p[i];
}

class Calculator {
public:
	virtual int add(int a, int b) = 0; // 두정수의합리턴
	virtual int subtract(int a, int b) = 0; // 두정수의차리턴
	virtual double average(int a[], int size) = 0; // 배열a의평균리턴. size는배열의크기
};

class GoodCalc : public Calculator { //주의
	virtual int add(int a, int b)
	{
		return a + b;
	}
	virtual int subtract(int a, int b)
	{
		return a - b;
	}
	virtual double average(int a[], int size)
	{
		double sum = 0.0;

		for (int i = 0; i < size; i++)
		{
			sum = sum + a[i];
		}

		return sum / size;
	}
};

void ch11_test2()
{
	int a[] = { 1,2,3,4,5 };
	Calculator* p = new GoodCalc();

	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;

	delete p;
}

class Calculator1 {
	void input() 
	{
		cout << "정수2 개를입력하세요>> ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0; // 두정수의합리턴
public:
	void run() 
	{
		input();
		cout << "계산된값은" << calc(a, b) << endl;
	}
};

class Adder : public Calculator1 {
	virtual int calc(int a, int b)
	{
		return a + b;
	}
};

class Subtractor : public Calculator1 {
	virtual int calc(int a, int b)
	{
		return a - b;
	}
};

void ch11_test3()
{
	Adder adder;
	Subtractor subtractor;
	adder.run();
	subtractor.run();
}

template <class T> class Stack {
protected:
	int m_size;
	int m_top;
	T* m_buffer;
public:
	Stack()
	{
		m_buffer = NULL;
		m_size = m_top = 0;
	}
	Stack(int size)
	{
		m_buffer = new T[size];
		m_size = size;
	}
	~Stack()
	{
		delete[] m_buffer;
	}
	void Push(T value);
	T Pop();
};

template <class T> void Stack<T>::Push(T value)
{
	m_buffer[m_size] = value;
}

void ch12_ex1() //클래스 템플릿으로 정의한 stack 클래스
{
	Stack<int> A;
	Stack<int> B;
}

typedef Stack<int> StackInt; //typedef문으로 템플릿 정의
typedef Stack<int>* pStackInt;

template <class T1, class T2, int MAX> class TwoArray {
	T1 arr1[MAX];
	T2 arr2[MAX];
};

template <class T1, class T2> class Gclass {
	T1 data1;
	T2 data2;
public:
	Gclass();
	void set(T1 a, T2 b);
	void get(T1& a, T2& b);
};

template <class T1, class T2> Gclass<T1, T2>::Gclass()
{
	data1 = 0;
	data2 = 0;
}

template <class T1, class T2> void Gclass<T1, T2>::set(T1 a, T2 b)
{
	data1 = a;
	data2 = b;
}

template <class T1, class T2> void Gclass<T1, T2>::get(T1& a, T2& b)
{
	a = data1;
	b = data2;
}

void ch12_ex2()
{
	int a;
	double b;

	Gclass<int, double> x;

	x.set(2, 0.5);
	x.get(a, b);
	cout << "a=" << a << " " << "b=" << b << endl;

	char c;
	float d;

	Gclass<char, float> y;

	y.set('m', 12.5);
	y.get(c, d);
	cout << "c=" << c << " " << "d=" << d << endl;
}

template<class T> T* remove(T* src, int sizeSrc, T* minus, int sizeMinus, int& retSize)
{
	T* output = new T[sizeSrc];

	int index = 0;

	for (int k = 0; k < sizeSrc; k++)
	{
		bool equal = false;

		for (int i = 0; i < sizeMinus; i++)
		{
			if (src[k] == minus[i])
			{
				equal = true;
			}
		}

		if (equal == false)
		{
			output[index] = src[k];
			index++;
		}
	}

	retSize = index;
	if (retSize == 0)
	{
		delete[] output;
		return NULL;
	}

	return output;
}

void ch12_test1()
{
	// remove() 함수를int로구체화하는경우
	cout << "정수배열{1,2,3,4}에서 정수배열{-3,5,10,1,2,3}을 뺍니다" << endl;
	int x[] = { 1,2,3,4 };
	int y[] = { -3,5,10,1,2,3 };
	int retSize;
	int* p = remove(x, 4, y, 6, retSize);

	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
	}
	else 
	{
		for (int i = 0; i < retSize; i++) // 배열의모든원소출력
			cout << p[i] << ' ';
		cout << endl;
		delete[] p; // 할당받은배열반환
	}

	double xx[] = { 1,2, 3, 4 };
	double yy[] = { -3, 5, 10, 1, 2, 3 };
	double* pp = remove(xx, 4, yy, 6, retSize);

	if (retSize == 0)
	{
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
	}
	else
	{
		for (int i = 0; i < retSize; i++) // 배열의 모든 원소 출력
		{
			cout << p[i] << " ";
		}
		cout << endl;
		delete[] pp; // 할당받은 배열 반환
	}
}

void ch12_ex3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++)
	{
		int n = *it;
		n = n * 2;
		*it = n;
	}

	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
}

void ch12_ex4()
{
	map<string, string> dic;
	dic.insert({ "love", "사랑" }); //앞: key, 뒤: value
	dic.insert({ "man", "사람" }); //앞: key, 뒤: value

	string kor = dic["love"];
	cout << kor << " " << dic["love"] << " " << dic.at("love") << endl;

	map<int, int>dicInt;
	dicInt.insert({ 100, 200 });
	dicInt.insert({ 200, 400 });
	cout << dicInt[200] << " " << dicInt.at(200) << endl;

}

void ch12_ex5()
{
	// 동적배열을생성해서임의의영문자를추가한다.
	vector<char> vec;
	vec.push_back('e');
	vec.push_back('b');
	vec.push_back('a');
	vec.push_back('d');
	vec.push_back('c');

	// sort() 함수를사용해서정렬한다.
	sort(vec.begin() + 1, vec.end());

	// 정렬후상태를출력한다.
	cout << "vector 정렬후\n";

	//vector<char>::iterator it;
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it;
	}

}

void ch12_test2()
{
	map<string, string> dic; // 맵컨테이너생성. 키는영어단어, 값은한글단어
	// 단어3개를map에저장
	dic.insert(make_pair("love", "사랑")); // ("love", "사랑") 저장
	dic.insert(make_pair("apple", "사과")); // ("apple", "사과") 저장
	dic["cherry"] = "체리"; // ("cherry", "체리") 저장

	cout << "저장된단어개수" << dic.size() << endl;

	string eng;
	while (true)
	{
		cout << "찾고싶은단어>> ";
		cin >> eng;// 사용자로부터키입력

		if (eng == "exit")
		{
			break;  // "exit"이입력되면종료
		}
		if (dic.find(eng) == dic.end())// eng'키'를끝까지찾았는데없음
		{
			cout << "없음" << endl;
		}
		else
		{
			cout << dic[eng] << endl; // dic에서eng의값을찾아출력
		}

	}
	cout << "종료합니다..." << endl;
}