/*practice3_1
#include <iostream>

using namespace std;

int big(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int big(int a[], int size)
{
	int max = a[0];

	for (int i = 0; i < size; i++)
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
	int array[5] = { 1, 9, -2, 8, 6 };
	cout << big(2, 3) << endl;
	cout << big(array, 5) << endl;
}
*/

/*practice3_2
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

/*practice3_3
#include <iostream>

using namespace std;

template <class T>
void print(T array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
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

int big(int a, int b)
{
	int max = (a > b) ? a : b;

	if (max < 100)
	{
		return max;
	}
	else
	{
		return 100;
	}
}

int big(int a, int b, int c)
{
	int max = (a > b) ? a : b;

	if (max < c)
	{
		return max;
	}
	else
	{
		return c;
	}
}

int main(void)
{
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);

	cout << x << " " << y << " " << z << endl;
}
*/

/*ex3_3
#include <iostream>

using namespace std;

template <class T1, class T2> T1 add(T1* x, T2 num)
{
	T1 sum = 0;

	for (int i = 0; i < num; i++)
	{
		sum = sum + x[i];
	}

	return sum;
}



int main(void)
{
	int x[] = { 1, 2, 3, 4, 5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
	char y[] = { 1,2, 3, 4, 5, 6 };

	cout << "sum of x[] = " << add(x, 5) << endl;
	cout << "sum of d[] = " << add(d, 6) << endl;
	cout << "sum of y[] = " << add(y, 6) << endl;
}
*/

/*ex3_4
#include <iostream>

using namespace std;

template <class T>
void reverseArray(T* x, T size)
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
		cout << x[i] << " ";
	}

	cout << endl;
}
*/

/*ex3_5 디폴트
#include <iostream>

using namespace std;

int sum3(int a, int b = 200, int c = 100)
{
	return a + b + c;
}

int main(void)
{
	int x = 10, y = 20, z = 30;

	int w = sum3(x, y, z); //60
	int u = sum3(x, y); //130
	int v = sum3(x); //310

	cout << w << " " << u << " " << v << endl;

	return 0;
}
*/

/*ex3_6 중복
#include <iostream>

using namespace std;

int ssum(int a, int b, int c)
{
	return a + b + c;
}

double ssum(double a, double b, double c)
{
	return a + b + c;
}

int main(void)
{
	cout << ssum(2, 5, 33) << endl;
	cout << ssum(2.5, 100.6, 10.7) << endl;

	return 0;
}
*/

/*ex3_7 템플렛
#include <iostream>

using namespace std;

template <class T>
void myswap(T& a, T& b)
{
	T temp = 0;
	temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int a = 4, b = 5;

	myswap(a, b);
	cout << a << " " << b << endl;

	double c = 0.3, d = 12.5;

	myswap(c, d);
	cout << c << " " << d << endl;
}
*/