/*practice7_1
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

/*practice 7_2
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
	double getArea();
};

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main(void)
{
	Circle circleArray[3] = { Circle(10), Circle(20), Circle() };

	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
	}
}
*/

/*practice7_3
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
	double getArea();
};

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main(void)
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
			cout << "Circle [" << i << "," << j << "]의면적은";
			cout << circles[i][j].getArea() << endl;
		}
	}
}
*/

/*practice 7_4
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

int main(void)
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

/*practice7_5
#include <iostream>

using namespace std;

int main(void)
{
	int* p;

	p = new int;

	if (!p)
	{
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}

	*p = 5;
	int n = *p;
	cout << "*p = " << *p << "\n";
	cout << "n = " << n << "\n";

	delete p;
}
*/

/*practice7_6
#include <iostream>

using namespace std;

int main(void)
{
	cout << "입력할 정수는?";
	int n;
	cin >> n;

	if (n <= 0)
	{
		return 0;
	}

	int* p = new int[n];

	if (!p)
	{
		cout << "메모리를 할당할 수 없습니다.";
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
		sum = sum + p[i];
	}

	cout << "평균 = " << sum / n << endl;

	delete[]p;
}
*/

/*practice7_7
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
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle()
{
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main(void)
{
	Circle* p, * q;
	p = new Circle;
	q = new Circle(30);

	cout << p->getArea() << endl << q->getArea() << endl;

	delete p;
	delete q;
}
*/

/*practice7_8
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
	cout <<"기본생성자radius = " << radius << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "인자생성자radius = " << radius << endl;
}

Circle::~Circle()
{
	cout << "소멸자 radius = " << radius << endl;
}

int main(void)
{
	Circle* pArray = new Circle[3];

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
		cout << pArray[i].getArea() << "\n";
	}

	Circle* p = pArray;
	for (int i = 0; i < 3; i++)
	{
		cout << p->getArea() << "\n";
		p++;
	}

	delete[]pArray;
}
*/

/*ex7_1
#include <iostream>

using namespace std;

class Circle
{
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::~Circle()
{
	cout << "반지름" << this->radius << " 원소멸" << endl;
}

Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << " 원생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << " 원생성" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main(void)
{
	Circle circleArray[3];

	circleArray[0].radius = 100;
	circleArray[1].radius = 50;
	circleArray[2].radius = 70;

	Circle* p = &circleArray[1];
	cout << (*p).radius << ' ' << p->radius << endl;

	Circle carray[3] = { Circle(20), Circle(10), Circle() };
	Circle* q;
	q = carray;
	cout << carray[0].radius << ' ' << q[0].radius << endl;

	q = &carray[1];
	cout << q[-1].radius << ' ' << q[0].radius << ' ' << q[1].radius << endl;
}
*/

/*ex7_2
#include <iostream>

using namespace std;

class Color {
	int red, green, blue;
public:
	Color() 
	{ 
		red = green = blue = 0; 
	}
	Color(int r, int g, int b) 
	{ 
		red = r; green = g; blue = b; 
	}
	void setColor(int r, int g, int b) 
	{ 
		red = r; green = g; blue = b; 
	}
	void show() 
	{ 
		cout << red << ' ' << green << ' ' << blue << endl; 
	}
};

int main(void)
{
	Color screenColor(255, 0, 0); // 빨간색의screenColor객체생성
	Color* p; // Color 타입의포인터변수p 선언
	p = &screenColor; // (1) p가screenColor의주소를가지도록코드작성
	p->show(); // (2) p와show()를이용하여screenColor색출력
	Color colors[3]; // (3) Color의일차원배열colors 선언. 원소는3개
	p = colors; // (4) p가colors 배열을가리키도록코드작성
	// (5) p와setColor()를이용하여colors[0], colors[1], colors[2]가
	// 각각빨강, 초록, 파랑색을가지도록코드작성
	colors[0].setColor(255, 0, 0);
	colors[1].setColor(0, 255, 0);
	colors[2].setColor(0, 0, 255);
	// (6) p와show()를이용하여colors 배열의모든객체의색출력. for 문이용
	for (int i = 0; i < 3; i++)
	{
		p[i].show();
	}

	return 0;
}
*/

/*ex7_3
#include <iostream>

using namespace std;

class Person 
{
	string name;
public:
	Person() 
	{ 
		name = ""; 
	}
	Person(string name) 
	{ 
		this->name = name; 
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

class Family 
{
	string name;
	Person* p; // Person 배열포인터
	int size; // Person 배열의크기. 가족구성원수
public:
	Family(string name, int size); // size 개수만큼Person 배열동적생성
	void setName(int index, string name);
	void show(); // 모든가족구성원출력
	~Family();
};

Family::Family(string name, int size)
{
	this->name = name;
	this->size = size;
	p = new Person[size];
}

void Family::setName(int index, string name)
{
	p[index].setName(name);
}

void Family::show()
{
	cout << name << " 가족은 다음과 같이 " << size << "명입니다." << endl;
	for (int n = 0; n < size; n++)
	{
		cout << p[n].getName() << endl;
	}

}

Family::~Family()
{
	delete[] p;
}

int main(void) 
{
	Family simpson("Simpson", 3); // 3명으로구성된Simpson 가족
	simpson.setName(0, "Mr. Simpson");
	simpson.setName(1, "Mrs. Simpson");
	simpson.setName(2, "Bart Simpson");
	simpson.show();
}
*/

/*ex7_4
#include <iostream>

using namespace std;

int main(void)
{
	int A[5];

	A[0] = 100;
	A[1] = 200;
	A[2] = 300;
	A[3] = 400;
	A[4] = 500;

	for (int i = 0; i < 5; i++)
	{
		printf("%d \n", A[i]);
	}
}
*/

/*ex7_5
#include <iostream>

void main(void)
{
	int* A = (int*)malloc(5 * sizeof(int));
	A[0] = 100;
	A[1] = 200;
	A[2] = 300;
	A[3] = 400;
	A[4] = 500;

	for (int i = 0; i < 5; i++)
	{
		printf("%d, %d \n", A[i], *(A + i));
	}

	free(A);
}
*/

/*ex7_6
#include <iostream>

void main(int number)
{
	int* A = new int[number]; //(int*)malloc(5 * sizeof(int));
	A[0] = 100;
	A[1] = 200;
	A[2] = 300;
	A[3] = 400;
	A[4] = 500;

	for (int i = 0; i < 5; i++)
	{
		printf("%d \n", A[i]);
	}

	delete[] A;//free(A);
}
*/

/*ex7_7
#include <iostream>

using namespace std;

class Circle
{
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::~Circle()
{
	cout << "반지름" << this->radius << " 원소멸" << endl;
}

Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << " 원생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << " 원생성" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

void main()
{

	Circle* p;
	Circle* q;
	p = new Circle;
	q = new Circle(10);

	cout << p->getArea() << endl;
	cout << q->getArea() << endl;

	delete p;
	delete q;
}
*/

/*ex7_8
#include <iostream>

using namespace std;

class Circle
{
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

Circle::~Circle()
{
	cout << "반지름" << this->radius << " 원소멸" << endl;
}

Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << " 원생성" << endl;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << " 원생성" << endl;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

void main()
{
	Circle* p = new Circle[3];

	cout << p[0].getArea() << endl;
	cout << p[1].getArea() << endl;
	cout << p[2].getArea() << endl;

	Circle* q = p;
	cout << q[0].getArea() << endl;
	cout << q[1].getArea() << endl;
	cout << q[2].getArea() << endl;

	cout << (q + 0)->getArea() << endl;
	cout << (q + 1)->getArea() << endl;
	cout << (q + 2)->getArea() << endl;

	delete[] p;
}
*/

/*ex7_9
#include <iostream>

using namespace std;

class A {
public:
	int value;
};

class B {
public:
	int counter;
	A sub;
};

void main()
{
	B abc;

	abc.sub.value = 100;
	abc.counter = 200;
}
*/

/*ex7_10
void main()
{
	//int abc = 100;
	int* p = new int(200);

	cout << *p << endl;

	delete p;
}
*/