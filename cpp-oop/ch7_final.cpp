/*Circle 클래스의 배열 선언 및 활용
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	Circle(int r)
	{
		radius = r;
	}
	~Circle()
	{

	}

	void setRadius(int r)
	{
		radius = r;
	}
	double getArea();
};

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main(void)
{
	Circle circleArray[3];

	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
	}

	Circle* p;
	p = circleArray;

	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}
}
*/

/*객체 배열의 인자있는 생성자로 초기화
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	Circle(int r)
	{
		radius = r;
	}

	double getArea();
};

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

void main()
{
	Circle circleArray[3] = { Circle(10), Circle(20), Circle() };

	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
	}
}
*/

/*Circle 클래스의 2차원 배열 선언 및 활용
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	Circle(int r)
	{
		radius = r;
	}

	void setRadius(int r)
	{
		radius = r;
	}

	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

void main()
{
	Circle circles[2][3];

	circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);
	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "[" << i << "," << j << "]의 면적은 " << circles[i][j].getArea() << endl;
		}
	}
}
*/

/*객체 포인터 선언 및 사용
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle()
	{
		radius = 1;
	}
	Circle(int r)
	{
		radius = r;
	}

	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

void main()
{
	Circle donut;
	Circle pizza(30);

	cout << donut.getArea() << endl;

	Circle* p;
	p = &donut;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;

	p = &pizza;
	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;
}
*/

/*정수형 공간의 동적 할당 및 반환
#include <iostream>

using namespace std;

void main()
{
	int* p = new int;

	if (!p)
	{
		cout << "메모리를 할당할 수 없습니다" << endl;
	}

	*p = 5;
	int n = *p;
	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;
}
*/

/*정수형 배열의 동적 할당 및 반환
#include <iostream>

using namespace std;

int main(void)
{
	cout << "입력할 정수의 개수는?";
	int n;
	cin >> n;
	
	if (n <= 0)
	{
		return 0;
	}

	int* p = new int[n];

	if (!p)
	{
		cout << "메모리를 할당할 수 없습니다";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "번째 정수: ";
		cin >> p[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += p[i];
	}

	cout << "평균 = " << sum / n << endl;

	delete[] p;
}
*/

/*Circle 객체의 동적 생성 및 반환
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();

	void setRadius(int r)
	{
		radius = r;
	}

	double getArea();
};

Circle::Circle()
{
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle()
{
	cout << "소멸자 실행 raidus = " << radius << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

void main()
{
	Circle* p = new Circle;
	Circle* q = new Circle(30);

	cout << p->getArea() << endl;
	cout << q->getArea() << endl;


	delete p;
	delete q;
}
*/

/*Circle 배열의 동적 생성 및 반환
#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();

	void setRadius(int r)
	{
		radius = r;
	}

	double getArea()
	{
		return 3.14 * radius * radius;
	}
};

Circle::Circle()
{
	radius = 1;
	cout << "기본생성자 radius = " << radius << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "기본생성자 raidus = " << radius << endl;
}

Circle::~Circle()
{
	cout << "소멸자 radius = " << radius << endl;
}

void main()
{
	Circle* pArray = new Circle[3];

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
		cout << pArray[i].getArea() << endl;
	}

	Circle* p = pArray;

	for (int i = 0; i < 3; i++)
	{
		cout << p->getArea() << endl;
		p++;
	}

	delete[] pArray;
}
*/

