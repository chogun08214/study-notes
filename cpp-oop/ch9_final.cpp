/*전역함수를 firend로 선언
#include <iostream>

using namespace std;

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
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	else
	{
		false;
	}
}

void main()
{
	Rect a(3, 4), b(4, 5);
	if (equals(a, b) == true)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
}
*/

/*다른 클래스의 멤버 함수를 friend로 선언
#include <iostream>

using namespace std;

class Rect;

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height)
	{
		this->width = width;
		this->height = height;
	}

	friend bool RectManager::equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main()
{
	Rect a(3, 4), b(3, 4);
	RectManager man;

	if (man.equals(a, b) == true)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
}
*/

/*다른 클래스 전체를 friend로 선언
#include <iostream>

using namespace std;

class Rect;

class RectManager {
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height)
	{
		this->width = width;
		this->height = height;
	}

	friend RectManager;
};

bool RectManager::equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void RectManager::copy(Rect& dest, Rect& src)
{
	dest.width = src.width;
	dest.height = src.height;
}

void main()
{
	Rect a(3, 4), b(5, 6);
	RectManager man;

	man.copy(b, a);
	if (man.equals(a, b) == true)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}
}
*/

/*2개의 Power 객체를 더하는 + 연산자 작성
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	Power operator+(Power op2);
};

void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power Power::operator+(Power op2)
{
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

void main()
{
	Power a(3, 5), b(4, 6), c;
	c = a + b; //operator 함수 호출
	a.show();
	b.show();
	c.show();
}
*/

/*2개의 Power 객체를 비교하는 == 연산자 작성
#include <iostream>

using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	bool operator==(Power op2);
};

void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

bool Power::operator==(Power op2)
{
	if (kick == op2.kick && punch == op2.punch)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main()
{
	Power a(3, 5), b(3, 5);

	a.show();
	b.show();

	if (a == b) //operator 함수 호출
	{
		cout << "두 파워가 같다" << endl;
	}
	else
	{
		cout << "두 파워가 같지 않다" << endl;
	}
}
*/

/*두 Power 객체를 더하는 += 연산자 작성
#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	Power operator+=(Power op2);
	void show();
};

void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power Power::operator+=(Power op2)
{
	kick = kick + op2.kick;
	punch = punch + op2.punch;
	return *this; //변경된 객체 자신 리턴
}

void main()
{
	Power a(3, 5), b(4, 6), c;

	a.show();
	b.show();

	c = a += b; //operator 함수 호출

	a.show();
	c.show();
}
*/

/*전위 ++ 연산자 작성
#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	Power operator++();
};

void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power Power::operator++()
{
	kick++;
	punch++;
	return *this;
}

void main()
{
	Power a(3, 5), b;

	a.show();
	b.show();

	b = ++a;

	a.show();
	b.show();
}
*/

/*후위 ++연산자 작성
#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	Power operator++(int x);
};

void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power Power::operator++(int x)
{
	Power tmp = *this;
	kick++;
	punch++;
	return tmp;
}

void main()
{
	Power a(3, 5), b;

	a.show();
	b.show();

	b = a++;

	a.show();
	b.show();
}
*/

/*2+a를 위한 +연산자 함수를 firend로 작성
#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	friend Power operator+(int op1, Power op2);
};

void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power operator+(int op1, Power op2)
{
	Power tmp;
	tmp.kick = op1 + op2.kick;
	tmp.punch = op1 + op2.punch;
	return tmp;
}

void main()
{
	Power a(3, 5), b;
	a.show();
	b.show();
	b = 2 + a; 
	a.show();
	b.show();
}
*/

/*a+b를 위한 연산자 함수를 firend로 작성
#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	friend Power operator+(Power op1, Power op2);
};

void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power operator+(Power op1, Power op2)
{
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}

void main()
{
	Power a(3, 5), b(4, 6), c;
	c = a + b; // 파워 객체 + 연산
	a.show();
	b.show();
	c.show();
}
*/

/*++연산자를 firend로 작성
#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	void show();
	friend Power operator++(Power& op);
	friend Power operator++(Power& op, int x);
};

void Power::show()
{
	cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power operator++(Power& op)
{
	op.kick++;
	op.punch++;
	return op;
}

Power operator++(Power& op, int x)
{
	Power tmp = op;
	op.kick++;
	op.punch++;
	return tmp;
}

void main()
{
	Power a(3, 5), b;
	b = ++a; // 전위++ 연산자
	a.show(); b.show();
	b = a++; // 후위++ 연산자
	a.show(); b.show();
}
*/

/*실습 9-0
#include <iostream>
using namespace std;

class Complex {
	float re, im;
public:
	Complex() 
	{ 
		re = im = 0; 
	}
	Complex(float im, float re) 
	{ 
		this->re = re; 
		this->im = im; 
	}
	Complex operator+(Complex in) 
	{
		Complex tmp;
		tmp.re = this->re + in.re;
		tmp.im = this->im + in.im;
		return tmp;
	}
	Complex operator-(Complex in)
	{
		Complex tmp;
		tmp.re = this->re - in.re;
		tmp.im = this->im - in.im;
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

void main()
{
	Complex X(2, 3), Y(3, 4), Z;
	Z = X + Y;
	Z.show();
	Z = X - Y;
	Z.show();
}
*/

/*실습 9-1, 9-2
#include <iostream>
using namespace std;

class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원" << pages << " 페이지" << endl;
	}
	string getTitle() {
		return title;
	}
	void operator+=(int value)
	{
		this->price = this->price + value;
	}
	void operator-=(int value)
	{
		this->price = this->price - value;
	}
};

void main()
{
	Book a((char*)"청춘", 20000, 300), b((char*)"미래", 30000, 500);
	a += 500;    // 책a의가격500원증가
	b -= 500;     // 책b의가격500원감소
	a.show();
	b.show();
}
*/

/*실습 9-3, 9-4
#include <iostream>
using namespace std;

class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원" << pages << " 페이지" << endl;
	}
	string getTitle() {
		return title;
	}

	friend bool operator==(Book& A, int prcie);
};

bool operator == (Book& A, int price)
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

void main()
{
	Book a((char*)"명품C++", 30000, 500), b((char*)"고품C++", 30000, 500);
	// price 비교
	if (a == 30000)
	{
		cout << "정가30000원" << endl;
	}
}
*/

/*실습 9-5
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(char* title, int price);
	bool operator!()
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
};

Book::Book(char* title, int price)
{
	this->price = price;
	int length = strlen(title);
	this->title = new char[length + 1];
	strcpy(this->title, title);
}

void main()
{
	Book book((char*)"벼룩시장", 0); // 가격은0
	if (!book)
	{
		cout << "공짜다" << endl;
	}
}
*/

