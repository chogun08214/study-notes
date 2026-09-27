/*pr1_1
#include <iostream>

double area(int r)
{
	return 3.14 * r * r;
}

int main(void)
{
	int n = 3;
	char c = '#';
	std::cout << c << 5.5 << '_' << n << "hello" << true << std::endl;
	std::cout << "n + 5 = " << n + 5 << "\n";
	std::cout << "면적은 " << area(n);
}
*/

/*pr1_2
#include <iostream>

using namespace std;

int main(void)
{
	cout << "너비를 입력하세요>>";
	int width;
	cin >> width;

	cout << "높이를 입력하세요>>";
	int height;
	cin >> height;

	int area = width * height;
	cout << "면적은 " << area << endl;
}
*/

/*pr1_3
#include <iostream>

using namespace std;

int main(void)
{
	cout << "이름을 입력하세요>>";
	
	char name[10];
	cin >> name;

	cout << "이름은 " << name << "입니다." << endl;
}
*/

/*pr1_4
#include <iostream>

using namespace std;

int main(void)
{
	cout << "주소를 입력하세요>>";

	char address[100];
	cin.getline(address, 100, '\n');

	cout << "주소는 " << address << "입니다." << endl;
}
*/

/*pr1_4
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string song = ("Falling in love with you");
	string elvis = ("Elvis Presley");
	string singer;

	cout << song << "를 부른 가수는(힌트: 첫글자는 " << elvis[0] << ")?";
	
	getline(cin, singer);
	if (singer == elvis)
	{
		cout << "맞았습니다" << endl;
	}
	else
	{
		cout << "틀렸습니다." << elvis << "입니다." << endl;
	}
}
*/

/*ex1_1
#include <iostream>

using namespace std;

int sum(int, int);

int main() 
{
	int n = 0;
	cout << "끝수를 입력하세요>>";
	cin >> n;

	if (n <= 0) {
		cout << "양수를 입력하세요!\n";
		return 0;
	}
	cout << "1에서 " << n << "까지의 합은 " << sum(1, n) << "입니다." << endl;

	return 0;
}

int sum(int a, int b) 
{
	int res = 0;
	for (int k = a; k <= b; k++) {
		res += k;
	}
	return res;
}
*/

/*ex1_2
#include <iostream>

using namespace std;

int main(void)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << "x" << j << "=" << i * j << " ";
		}
		cout << "\n";
	}
}
*/

/*ex1_3
#include <iostream>

using namespace std;

double biggest(double a[], int n)
{
	double max = a[0];

	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}

	return max;
}

int main(void)
{
	double a[5];
	cout << "5 개의 실수를 입력하라>>";

	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	cout << "제일 큰 수 = " << biggest(a, 5) << endl;
}
*/

/*pr1_4
#include <iostream>

using namespace std;

int main(void)
{
	char c[100]; 
	int count = 0;
	cout << "문자들을 입력하라(100개미만)." << endl;

	cin.getline(c, 100, '\n');

	for (int i = 0; i < 100; i++)
	{
		if (c[i] == 'x')
		{
			count++;
		}
	}

	cout << 'x' << "의 개수는 " << count << endl;
}
*/

/*ex1_5
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	char password1[100], password2[100];
	cout << "암호를 입력하세요>>";
	string pw1;
	getline(cin, pw1);

	cout << "새 암호를 입력하세요>>";
	string pw2;
	getline(cin, pw2);

	if (pw1 == pw2)
	{
		cout << "같습니다" << endl;
	}
	else
	{
		cout << "같지 않습니다" << endl;
	}
}
*/

/*ex1_6
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char name[100];
	char address[100];
	int age;

	cout << "이름은?";
	cin.getline(name, 100, '\n');

	cout << "주소는?";
	cin.getline(address, 100, '\n');

	cout << "나이는?";
	cin >> age;

	cout << "-------------------------------------------" << endl;

	cout << name << ". " << address << ". " << age << "세" << endl;
}
*/

/*ex1_7
#include <iostream>
using namespace std;
namespace KIM {
	float area(float r) {
		return 3.14 * r * r;
	}
}
namespace KANG {
	float area(float x, float y) {
		return x * y;
	}
}
int main()
{
	float A = KIM::area(10.0);
	float B = KANG::area(2, 3);
	cout << A << " / " << B << endl;
	return 0;
}
*/

/*pr2_1
#include <iostream>
using namespace std;
int main() {
	int n = 10, m;
	char c = 'A';
	double d;
	int* p = &n; // p는n의주소값을가짐
	char* q = &c; // q는c의주소값을가짐
	double* r = &d; // r은d의주소값을가짐
	*p = 25; // n에25가저장됨
	*q = 'A'; // c에문자'A'가저장됨
	*r = 3.14; // d에3.14가저장됨
	m = *p + 10; // p가가리키는값(n 변수값)+10을m에저장
	cout << n << ' ' << *p << "\n"; // 둘다25가출력됨
	cout << c << ' ' << *q << "\n"; // 둘다'A'가출력됨
	cout << d << ' ' << *r << "\n"; // 둘다3.14가출력됨
	cout << m << "\n"; // m 값35 출력
}
*/

/*pr2_2
#include <iostream>

using namespace std;

int main(void)
{
	cout << "i" << " " << "n" << " " << "refn" << endl;
	int i = 1;
	int n = 2;
	int& refn = n;
	n = 4;
	refn++;
	cout << i << " " << n << " " << refn << endl; //1 5 5

	refn = i;
	refn++;
	cout << i << " " << n << " " << refn << endl; //1 2 2

	int* p = &refn;
	*p = 20;
	cout << i << " " << n << " " << refn << endl; //1 20 20
}
*/

/*pr2_3
#include <iostream>

using namespace std;

char& find(char s[], int index)
{
	return s[index];
}

int main(void)
{
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S';
	cout << name << endl;

	char& ref = find(name, 2);
	ref = 't';
	cout << name << endl;
}
*/

/*ex2_1
#include <iostream>

using namespace std;

int main(void)
{
	int K[3] = { 7, 8, 9 };
	int M[3] = { 6, 5, 4 };
	int* p; int* q[2];

	cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl; //주소

	p = K;
	cout << p[0] << " " << p[1] << " " << p[2] << endl; //7 8 9
	cout << *(p + 0) << " " << *(p + 1) << " " << *(p + 2) << endl; //7 8 9

	p = M;
	cout << p[0] << " " << p[1] << " " << p[2] << endl;//6 5 4
	cout << *(p + 0) << " " << *(p + 1) << " " << *(p + 2) << endl; //6 5 4

	q[0] = K;  q[1] = M;
	cout << q[0][0] << " " << q[0][1] << " " << q[0][2] << endl; //7 8 9
	cout << *(q[0] + 0) << " " << *(q[0] + 1) << " " << *(q[0] + 2) << endl; //7 8 9
	cout << q[1][0] << " " << q[1][1] << " " << q[1][2] << endl; //6 5 4
	cout << *(q[1] + 0) << " " << *(q[1] + 1) << " " << *(q[1] + 2) << endl; //6 5 4

}
*/

/*ex2_2
#include <iostream>

using namespace std;

void pfunc_1_(int *a, int *b)
{
	cout << *a << " " <<* b << endl;
	*a = 30; *b = 40;
}
void main()
{
	int a = 10, b = 20;
	pfunc_1_(&a, &b);
	cout << a << " " << b << endl;
}
*/

/*ex2_3
#include <iostream>

using namespace std;

int main(void)
{
	int M[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int(*ptr)[3]; 
	int* p;         
	int** pt;

	ptr = M;
	cout << ptr << " " << M << endl; //주소
	cout << ptr + 1 << " " <<  M + 1 << endl; //주소
	cout << *(ptr + 1) <<  " " << ptr[1] << " " << * (M + 1) << " " << M[1] << endl; //주소
	cout << **(ptr + 1) << " " << * *(M + 1) << " " << * M[1] << " " << M[1][0] << endl; //4

	p = M[0];
	cout << p << " " << M[0] << " " << * M << endl; //주소
	cout << p + 1 << " " << M[0] + 1 << " " << * M + 1 << endl; //주소
	cout << *(p + 1) << " " <<  * (M[0] + 1) << " " << * (*M + 1) << endl; //2 2 2

	pt = &p;   
	cout << *pt << " " << p << endl; //주소
	cout << **pt << " " << * p << endl; //1 1
}
*/

/*ex2_4
#include <iostream>

using namespace std;

bool average(int a[], int size, int& avg)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}

	avg = sum / size;

	return true;
}

int main(void)
{
	int x[] = { 0, 1, 2, 3, 4, 5 };
	int avg;
	if (average(x, 5, avg) == true)
	{
		cout << "평균은 " << avg << endl;
	}
	else
	{
		cout << "매개변수 오류" << endl;
	}
}
*/

/*ex2_5
#include <iostream>

using namespace std;

bool bigger(int a, int b, int& big)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		if (a > b)
		{
			big = a;
		}
		else
		{
			big = b;
		}
		return false;
	}
}

int main(void)
{
	int x, y, big;
	bool b;

	cout << "두정수를입력하세요>> ";
	cin >> x >> y;

	b = bigger(x, y, big);

	if (b)
		cout << "same" << endl;
	else
		cout << "큰수는 " << big << endl;
}
*/

/*ex2_6
#include <iostream>

using namespace std;

char& find(char a[], char c, bool& success)
{
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == c)
		{
			success = true;

			return a[i];
		}
		else
		{
			success = false;
		}
	}
}

int main(void)
{
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);

	if (b == false) 
	{
		cout << "M을발견할수없다" << endl;
		return 0;
	}
	loc = 'm'; // 'M' 위치에'm' 기록
	cout << s << endl;
}
*/

/*pr3_1
#include <iostream>

using namespace std;

int big(int a, int b)
{
	if (a < b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int big(int array[], int size)
{
	int max = array[0];

	for (int i = 0; i < size; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}

	return max;
}

int main(void)
{
	int array[5] = { 1, 9, -2, 8, 6 };
	cout << big(2, 3) << endl;
	cout << big(array, 5) << endl;
}
*/

/*pr3_2
#include <iostream>

using namespace std;

void fillLine(int n = 25, char c = '*')
{
	for (int i = 0; i < n; i++)
	{
		cout << c;
	}
	cout << endl;
}

int main(void)
{
	fillLine();
	fillLine(10, '%');
}
*/

/*pr3_3
#include <iostream>

using namespace std;

template <class T>
void print(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print(char array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << (int)array[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int x[] = { 1, 2, 3, 4, 5 };
	double d[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

	print(x, 5);
	print(d, 5);

	char c[5] = { 1, 2, 3, 4, 5 };
	print(c, 5);
}
*/

/*ex3_1
#include <iostream>

using namespace std;

void f(char c = ' ', int line = 1)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << c;
		}
		cout << endl;
	}
}

int main(void)
{
	f();
	f('%');
	f('@', 5);
}
*/

/*ex3_2
#include <iostream>

using namespace std;

int big(int a, int b, int c = 100)
{
	if (a > b)
	{
		if (a < c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (b < c)
		{
			return b;
		}
		else
		{
			return c;
		}
	}
}

int main(void)
{
	int x = big(3, 5); // 3과 5중큰값5는 최대값 100보다 작으므로, 5 리턴
	int y = big(300, 60); // 300과 60중큰값300이 최대값 100보다 크므로, 100 리턴
	int z = big(30, 60, 50); // 30과 60 중큰값60이 최대값 50보다 크므로, 50 리턴
	cout << x << ' ' << y << ' ' << z << endl;
}
*/

/*ex3_3
#include <iostream>

using namespace std;

template <class T1, class T2>
T1 add(T1 arr[], T2 num)
{
	T1 sum = 0;

	for (int i = 0; i < num; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int main(void)
{
	int x[] = { 1, 2, 3, 4, 5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };

	cout << "sum of x[] = " << add(x, 5) << endl;
	cout << "sum of d[] = " << add(d, 6) << endl;
}
*/

/*ex3_4
#include <iostream>

using namespace std;

template <class T>
void reverseArray(T* x, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		T temp = x[i];
		x[i] = x[size - i - 1];
		x[size - i - 1] = temp;
	}

}

int main(void)
{
	int x[] = { 1, 10, 100, 5, 4 };

	reverseArray(x, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << x[i] << " " << endl;
	}
}
*/

/*pr4_1
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string name;
	string address("서울시 서초구 방배동");
	string copyAddress(address);

	char text[] = { 'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0' };
	string title(text);

	cin >> name;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << text << endl;
	cout << title <<  endl;

	return 0;
}
*/

/*pr4_2
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string src = "C++ Programming";
	string dest;

	dest = src;

	cout << src << endl;
	cout << dest << endl;
}
*/

/*pr4_3
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s1;
	string s2 = "123";
	string s3 = "abcdefg";

	cout << "s1 = " << s1.size() << endl;
	cout << "s2 = " << s2.size() << endl;
	cout << "s3 = " << s3.size() << endl;
}
*/

/*pr4_4
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string text = "Napster's pay-to-play service is officially out, "
		"and we have a review of the now-legit Napster. "
		"We also size up its companion music player from Samsung.";

	cout << "Offset of 'offcial' = " << text.find("official");
}
*/

/*pr4_5
#include <iostream>

using namespace std;

class Circle {
public:
	int radius;
	double getArea();
};

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main(void)
{
	Circle donut;
	donut.radius = 1;
	double area = donut.getArea();
	cout << "면적은 " << area << endl;
}
*/

/*ex4_3
#include <iostream>

using namespace std;

class Rectangle {
public:
	int width;
	int height;
	double getArea();
};

double Rectangle::getArea()
{
	return width * height;
}

int main(void)
{
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;

	cout << "사각형의 면적은 " << rect.getArea() << endl;
}
*/

/*pr5_1
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
}

Circle::Circle(int r)
{
	radius = r;
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main(void)
{
	Circle donut;
	double area = donut.getArea();
	cout << "면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "면적은 " << area << endl;
}
*/

/*pr5_2
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
	cout << "반지름 " << radius << "인 원 생성\n";
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성\n";
}

Circle::~Circle()
{
	cout << "반지름 " << radius << "인 원 소멸\n";
}

int main(void)
{
	Circle donut;
	Circle pizza(30);

	return 0;
}
*/

/*pr5_3
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
	cout << "반지름 " << radius << "인 원 생성\n";
}

Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성\n";
}

Circle::~Circle()
{
	cout << "반지름 " << radius << "인 원 소멸\n";
}

double Circle::getArea()
{
	return 3.14 * radius * radius;
}

Circle globalDonut(1000);
Circle glpbalPizza(2000);

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
	int height;
	int width;
	Rectangle();
	Rectangle(int a, int b);
	Rectangle(int c);

	bool isSquare();
};

Rectangle::Rectangle()
{
	width = 1, height = 1;
}

Rectangle::Rectangle(int a, int b)
{
	width = a, height = b;
}

Rectangle::Rectangle(int c)
{
	width = height = c;
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

	if (rect1.isSquare()) cout << "rect1은정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2는정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3는정사각형이다." << endl;
}
*/

/*ex5_2
#include <iostream>

using namespace std;

class Oval {
public:
	int width;
	int height;
	Oval(int a, int b);
	Oval();
	~Oval();
	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();
};

Oval::Oval(int a, int b)
{
	width = a, height = b;
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
	width = w, height = h;
}
void Oval::show()
{
	cout << width << " " << height << endl;
}

int main(void)
{
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
}
*/

/*ex6_1
#include <iostream>

using namespace std;

class Ram {
	char mem[100 * 1024]; // 100KB 메모리
	int size;
public:
	Ram(); // mem을0으로초기화하고size를100*1024로초기화
	~Ram(); // "메모리제거됨" 문자열출력
	char read(int address);    // address 주소의메모리를읽어리턴
	void write(int address, char value); // address 주소에value 저장
	// 주소가범위를벗어나는오류발생하면에러메시지출력함.
};

Ram::Ram()
{
	size = 100 * 124;

	for (int i = 0; i < size; i++)
	{
		mem[i] = 0;
	}
}
Ram::~Ram()
{
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address)
{
	return mem[address];
}
void Ram::write(int address, char value)
{
	mem[address] = value;


}


int main(void)
{
	Ram ram;
	ram.write(100, 20); // 100 번지에 20 저장
	ram.write(101, 30); // 101 번지에 30 저장
	char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
	ram.write(102, res); // 102 번지에 50 저장

	cout << "102 번지의 값 = " << (int)ram.read(102) << endl; // 102 번지 메모리 값 출력
}
*/

/*ex6_2
#include <iostream>

using namespace std;

class Math {
public:
	static int abs(int a)
	{
		return a > 0 ? a : -a;
	}
	static int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	static int min(int a, int b)
	{
		return (a > b) ? b : a;
	}
};

int main(void)
{
	Math A;
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(-3, -8) << endl;

	cout << A.abs(-5) << endl;
	cout << A.max(10, 8) << endl;
	cout << A.min(-3, -8) << endl;

}
*/

/*ex6_3
#include <iostream>

using namespace std;

class Person2 {
public:
	int money;
	string name;


	Person2() {
		money = 0;
	}
	Person2(string name_in) {
		money = 0;
		name = name_in;
	}
	~Person2() {
		cout << name << "의 money는 " << money << endl;
	}

	void addMoney(int money_in) {
		money += money_in;
	}

	static int sharedMoney;

	static void addShared(int money_in) {
		sharedMoney += money_in;
	}

};

int Person2::sharedMoney = 0;

void main()
{
	Person2 A("KANG"), B("KIM");
	// 3월
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	// 4월
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	cout << "공금 = " << Person2::sharedMoney << endl;
	Person2::addShared(100);
	cout << "공금 = " << Person2::sharedMoney << endl;
}
*/

/*pr7_1
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

int main(void)
{
	Circle circleArray[3];
	// 배열의 각 원소객체의멤버접근
	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);
	// (1) Circle 객체 배열 생성
   // (2)
	for (int i = 0; i < 3; i++) // 배열의 각 원소 객체의 멤버 접근
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;

	Circle* p;
	p = circleArray;

	for (int i = 0; i < 3; i++) 
	{ // 객체 포인터로 배열 접근
		cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}
}
*/

/*expr_2
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

int main(void)
{
	Circle circleArray[3] = { Circle(10), Circle(20), Circle() };

	for (int i = 0; i < 3; i++)
	{
		cout << "Circle " << i << "의면적은" << circleArray[i].getArea() << endl;
	}
}
*/

/*pr7_3
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle circles[2][3];
	circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);
	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);
	for (int i = 0; i < 2; i++)  // 배열의각원소객체의멤버접근
		for (int j = 0; j < 3; j++) {
			cout << "Circle [" << i << "," << j << "]의면적은";
			cout << circles[i][j].getArea() << endl;
		}
}
*/

/*pr7_4
#include <iostream>
using namespace std;

class Circle 
{
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea();
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	Circle pizza(30);
	// 객체이름으로멤버접근
	cout << donut.getArea() << endl;
	// 객체포인터로멤버접근
	Circle* p;
	p = &donut;
	cout << p->getArea() << endl; // donut의getArea() 호출
	cout << (*p).getArea() << endl; // donut의getArea() 호출
	p = &pizza;
	cout << p->getArea() << endl; // pizza의getArea() 호출
	cout << (*p).getArea() << endl; // pizza의getArea() 호출
}
*/

/*pr7_5
#include <iostream>

using namespace std;

int main(void)
{
	int* p = new int;
	if (!p)
	{
		cout << "메모리를 할당할 수 없습니다.";
	}

	*p = 5;
	int n = *p;

	cout << "*p = " << *p << endl;
	cout << "n = " << n << endl;

	delete p;
}
*/

/*pr7_6
#include <iostream>

using namespace std;

int main(void)
{
	cout << "입력할정수의개수는?";
	int n;
	cin >> n; // 정수의개수입력

	if (n <= 0)
	{
		return 0;
	}

	int* p = new int[n];
	if (!p) 
	{
		cout << "메모리를할당할수없습니다.";
		return 0;
	}

	for (int i = 0; i < n; i++) 
	{
		cout << i + 1 << "번째정수: "; // 프롬프트출력
		cin >> p[i]; // 키보드로부터정수입력
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += p[i];
	cout << "평균= " << sum / n << endl;

	delete[] p;

}
*/

