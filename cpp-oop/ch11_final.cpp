/*오버라이딩과 가상 함구 호출
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f()
	{
		cout << "Base::f() called" << endl;
	}
};

class Derived : public Base {
public:
	virtual void f()
	{
		cout << "Derived::f() called" << endl;
	}
};

void main()
{
	Derived d, * pDer;
	pDer = &d;
	pDer->f();

	Base* pBase;
	pBase = pDer;
	pBase->f();
}
*/

/*동적 바인딩
#include <iostream>
using namespace std;

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


void main()
{
	Shape* pShape = new Shape();
	pShape->paint();
	delete pShape;
}
*/

/*동적 바인딩
#include <iostream>
using namespace std;

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

class Circle : public Shape {
	virtual void draw()
	{
		cout << "Circle::draw() called" << endl;
	}
};

void main()
{
	Shape* pShape = new Circle();
	pShape->paint();
	delete pShape;
}
*/

/*상속이 반복되는 경우 가상 함수 호출
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f()
	{
		cout << "Base::f() called" << endl;
	}
};

class Derived : public Base {
public:
	virtual void f()
	{
		cout << "Derived::f() called" << endl;
	}
};

class GrandDerived : public Derived {
public:
	virtual void f()
	{
		cout << "GrandDerived::f() called" << endl;
	}
};

void main()
{
	GrandDerived g;
	Base *bp;
	Derived *dp;
	GrandDerived *gp;

	bp = dp = gp = &g;

	bp->f();
	dp->f();
	gp->f();
}
*/

/*범위 지정 연사자::를 이용한 기본 클래스의 가상 함수 호출
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw()
	{
		cout << "--Shape--";
	}
};

class Circle : public Shape {
public:
	virtual void draw()
	{
		Shape::draw();
		cout << "Circle" << endl;
	}
};

void main()
{
	Circle circle;
	Shape* pShape = &circle;

	pShape->draw();
	pShape->Shape::draw();
}
*/

/*소멸자를 가상함수로 선언
#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base {
public:
	virtual ~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

void main()
{
	Derived* dp = new Derived();
	Base* bp = new Derived;

	delete dp;
	delete bp;
}
*/

/*실습 11-0
#include <iostream>
using namespace std;

class SHAPE 
{
	string name;
public:
	virtual float getArea() 
	{ 
		return 0.0; 
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}
};

class OVAL :public SHAPE{
	int a, b;
public:
	OVAL(string name, int a, int b)
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

class TRIANG :public SHAPE {
	int a, b;
public:
	TRIANG(string name, int a, int b)
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

void main() 
{
	OVAL oval((char*)"빈대떡", 10, 20);
	TRIANG triang((char*)"찰떡", 30, 40);

	cout << oval.getName() << " 넓이는" << oval.getArea() << endl;
	cout << triang.getName() << " 넓이는" << triang.getArea() << endl;

	SHAPE* pShape;
	pShape = &oval; // upcasting
	cout << pShape->getName() << "넓이는" << pShape->getArea() << endl;

	pShape = &triang; // upcasting
	cout << pShape->getName() << "넓이는" << pShape->getArea() << endl;

}
*/

/*실습11-1
#include <iostream>
using namespace std;

class Shape {
	string name;
public:
	virtual float getArea()
	{ 
		return 0.0; 
	}
	void setName(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}
};

class Oval :public Shape {
	int a, b;
public:
	Oval(string name, int a, int b)
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

class Rect :public Shape {
	int a, b;
public:
	Rect(string name, int a, int b)
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

class Triangular :public Shape {
	int a, b;
public:
	Triangular(string name, int a, int b)
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

void main()
{
	Shape* p[3];
	p[0] = new Oval((char*)"빈대떡", 10, 20); // upcasting
	p[1] = new Rect((char*)"찰떡", 30, 40); // upcasting 
	p[2] = new Triangular((char*)"토스트", 30, 40); // upcasting

	for (int i = 0; i < 3; i++)
	{
		cout << p[i]->getName() << " 넓이는" << p[i]->getArea() << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		delete p[i];
	}
}
*/

/*실습 11-2
#include <iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0; // 두정수의합리턴
	virtual int subtract(int a, int b) = 0; // 두정수의차리턴
	virtual double average(int a[], int size) = 0; // 배열a의평균리턴. size는배열의크기
};

class GoodCalc :public Calculator {
	virtual int add(int a, int b)
	{
		return a + b;
	}
	virtual int subtract(int a, int b)
	{
		return a - b;
	}
	virtual double average(int a[], int b)
	{
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
			sum = sum + a[i];
		}

		return sum / 5;
	}
};

void main()
{
	int a[] = { 1,2,3,4,5 };

	Calculator* p = new GoodCalc();

	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;

	delete p;
}
*/

/*실습 11-3
#include <iostream>
using namespace std;

class Calculator {
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

class Adder :public Calculator {
	virtual int calc(int a, int b)
	{
		return a + b;
	}
};

class Subtractor : public Calculator {
	virtual int calc(int a, int b)
	{
		return a - b;
	}
};

void main()
{
	Adder adder;
	Subtractor subtractor;

	adder.run();
	subtractor.run();
}
*/

