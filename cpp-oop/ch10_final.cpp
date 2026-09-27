/*Point 클래스를 상속받는 ColorPoint 클래스 
#include <iostream>
using namespace std;

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
	void showColorPoint();
};

void ColorPoint::showColorPoint()
{
	cout << color << ":";
	showPoint();
}

void main()
{
	Point p; // 기본클래스의객체생성
	ColorPoint cp; // 파생클래스의객체생성
	cp.set(3, 4); // 기본클래스의멤버호출
	cp.setColor("Red"); // 파생클래스의멤버호출
	cp.showColorPoint(); // 파생클래스의멤버호출
}
*/

/*생성자 호출 관계 및 실행 순서
#include <iostream>
using namespace std;

class A {
public:
	A()
	{
		cout << "생성자A" << endl;
	}
	~A() 
	{ 
		cout << "소멸자A" << endl; 
	}
};

class B : public A {
public:
	B()
	{
		cout << "생성자B" << endl;
	}
	~B()
	{
		cout << "소멸자B" << endl;
	}
};

class C : public B{
public:
	C()
	{
		cout << "생성자C" << endl;
	}
	~C()
	{
		cout << "소멸자C" << endl;
	}
};

void main()
{
	C c;
}
*/

/*기본 클래스의 디폴트 생성자의 암시적 호출
#include <iostream>
using namespace std;

class A {
public:
	A()
	{
		cout << "생성자A" << endl;
	}
	A(int x)
	{
		cout << "매개변수생성자 A" << x << endl;
	}
};

class B :public A {
public:
	B()
	{
		cout << "생성자B" << endl;
	}
};

void main()
{
	B b;
}
*/

/*기본 클래스에 디폴트 생성자가 없는 경우
#include <iostream>
using namespace std;

class A {
public:
	A(int x)
	{
		cout << "매개변수생성자 A" << x << endl;
	}
};

class B : public A {
public:
	B()
	{
		cout << "생성자B" << endl;
	}
};

void main()
{
	B b;
}
*/

/*파생클래스의 매개변수를 가진 생성자가 기본 클래스의 디폴트 생성자 호출
#include <iostream>
using namespace std;

class A {
public:
	A()
	{
		cout << "생성자 A" << endl;
	}
	A(int x)
	{
		cout << "매개변수생성자 A" << x << endl;
	}
};

class B : public A {
public:
	B()
	{
		cout << "생성자 B" << endl;
	}
	B(int x)
	{
		cout << "매개변수생성자 B" << x << endl;
	}
};

void main()
{
	B b(5);
}
*/

/*파생 클래스의 생성자에서 명시적으로 기본 클래스의 특정한 생성자의 명시적 호출
#include <iostream>
using namespace std;

class A {
public:
	A()
	{
		cout << "생성자 A" << endl;
	}
	A(int x)
	{
		cout << "매개변수생성자 A" << x << endl;
	}
};

class B : public A {
public:
	B()
	{
		cout << "생성자 B" << endl;
	}
	B(int x) : A(x + 3)
	{
		cout << "매개변수생성자 B" << x << endl;
	}
};

void main()
{
	B b(5);
}
*/

/*private 상속사례
#include <iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a)
	{
		this->a = a;
	}
public:
	void showA()
	{
		cout << a;
	}
};

class Derived : private Base {
	int b;
protected:
	void setB(int b)
	{
		this->b = b;
	}
public:
	void showB()
	{
		cout << b;
	}
};

void main()
{
	Derived x;
	//x.a = 5; //오류 
	//x.setA(10); //오류
	//x.showA(); //오류

	//x.b = 10; //오류
	//x.setB(10); //오류
	x.showB();
}
*/

/*protected 상속 사례
#include <iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a)
	{
		this->a = a;
	}
public:
	void showA()
	{
		cout << a;
	}
};

class Derived : protected Base {
	int b;
protected:
	void setB(int b)
	{
		this->b = b;
	}
public:
	void showB()
	{
		cout << b;
	}
};

void main()
{
	Derived x;
	//x.a = 5; //오류
	//x.setA(10); // 오류
	//x.showA(); // 오류
	//x.b = 10; // 오류
	//x.setB(10); // 오류
	x.showB();
}
*/

/*상속이 중첩될 때 접근 지정
#include <iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a)
	{
		this->a = a;
	}
public:
	void showA()
	{
		cout << a;
	}
};

class Derived : private Base {
	int b;
protected:
	void setB(int b)
	{
		this->b = b;
	}
public:
	void showB()
	{
		setA(5);
		showA();
		cout << b;
	}
};

class GrandDerived : private Derived
{
	int c;
protected:
	void setAB(int x) 
	{
		//setA(x); //오류 
		//showA(); //오류
		setB(x); 
	}
};
*/

/*다중 상속 선언 및 멤버 호출
#include <iostream>
using namespace std;

class MP3 {
public:
	void play();
	void stop();
};

class MobilePhone {
public:
	bool sendCall();
	bool receiveCall();
	bool sendSMS();
	bool receiveSMS();
};

class MusicPhone : public MP3, public MobilePhone {
public:
	void dial();
};

void MusicPhone::dial()
{
	play();
	sendCall();
}

void main()
{
	MusicPhone hanphone;
	hanPhone.play();
	hanPhone.sendSMS();
}
*/

/*실습 10-1
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
	int getRadius()
	{
		return radius;
	}
	void setRadius(int radius)
	{
		this->radius = radius;
	}
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle()
	{
		setRadius(0);
		name = "NULL";
	}
	NamedCircle(int radius, string name)
	{
		setRadius(radius);
		this->name = name;
	}
	void show()
	{
		cout << "반지름이 " << getRadius() << "인 waffle" << endl;
	}
};

void main()
{
	NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
	waffle.show();
}
*/

/*실습10-2
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
	int getRadius()
	{
		return radius;
	}
	void setRadius(int radius)
	{
		this->radius = radius;
	}
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle()
	{
		setRadius(0);
		name = "NULL";
	}
	NamedCircle(int radius, string name)
	{
		setRadius(radius);
		this->name = name;
	}
	void setNamedCircle(int radius, string name)
	{
		setRadius(radius);
		this->name = name;
	}

	friend void FindLargestNamedCircle(NamedCircle* namedcircled, int size);
};

void FindLargestNamedCircle(NamedCircle* namedcircle, int size)
{
	int r_max = namedcircle[0].getRadius();
	int index_max = 0;

	for (int i = 1; i < size; i++)
	{
		if (namedcircle[i].getRadius() > r_max)
		{
			r_max = namedcircle[i].getRadius();
			index_max = i;
		}
	}

	cout << "가장 면적이 큰 피자는 반경이 " << r_max << "인 " << namedcircle[index_max].name << "이다." << endl;
}

void main()
{
	NamedCircle pizza[5];

	cout << "5개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	
	for (int i = 0; i < 5; i++)
	{
		int radius;
		string name;
		cin >> radius;
		cin >> name;
		pizza[i].setNamedCircle(radius, name);
	}

	FindLargestNamedCircle(pizza, 5);
}
*/

/*실습 10-3
#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;    // 동적할당된메모리용량
	int* mem;       // 정수배열을만들기위한메모리포인터
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; 
		mem = new int[capacity];
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
	void MakeQueue(int capacity = 100)
	{
		this->capacity = capacity;
		mem = new int[capacity];
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
	int dequeue()
	{
		int value = get(0); // mem[0] 
		index--;
		for (int i = 0; i < index; i++)
		{
			//mem[i] = mem[i + 1];
			put(i, get(i + 1));
		}

		return value;
	}
};

void main() 
{
	MyQueue mQ(100);
	int n;

	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
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
*/

