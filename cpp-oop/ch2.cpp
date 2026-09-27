/*practice2_1
#include <iostream>

using  namespace std;

int main(void)
{
	int n = 10, m;
	char c = 'A';
	double d;

	int* p = &n;
	char* q = &c;
	double* r = &d;

	*p = 25;
	*q = 'A';
	*r = 3.14;
	m = *p + 10;

	cout << n << ' ' << *p << "\n";
	cout << c << ' ' << *q << "\n";
	cout << d << ' ' << *r << "\n";
	cout << m << "\n";
}
*/

/*practice2_2
#include <iostream>

using namespace std;

int main(void)
{
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	int* chr_ptr;

	chr_ptr = arr;

	chr_ptr++;

	cout << chr_ptr << "\n"; //주소
	cout << *chr_ptr << "\n"; //2
	cout << arr << "\n"; //주소
	cout << arr + 4 << "\n";  //주소
	cout << &arr[3] << "\n"; //주소  
	cout << arr[4] << "\n"; //5
	
	cout << *(chr_ptr + 3) << endl;  //5

}
*/

/*practice2_3
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
	cout << i << " " << n << " " << refn << endl;

	refn = i;
	refn++;
	cout << i << " " << n << " " << refn << endl;

	int* p = &refn;
	*p = 20;
	cout << i << " " << n << " " << refn << endl;
}
*/

/*practice2_4
#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int m = 2, n = 9;
	swap(m, n);
	cout << m << " " << n;
}
*/

/*practice2_5
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

	cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl; //주소 주소 주소 주소

	int* p = K;
	cout << p[0] << " " << p[1] << " " << p[2] << endl; //7 8 9
	cout << *(p + 0) << " " << *(p + 1) << " " << *(p + 2) << endl; //7 8 9

	p = &K[2];
	cout << *p << " " << *(p - 2) << endl; //9 7
	cout << p[0] << " " << p[-2] << endl; //9 7

	return 0;
}
*/

/*ex2_2
#include <iostream>

using namespace std;

int main(void)
{
	int K[3] = { 7, 8, 9 };
	int M[3] = { 6, 5, 4 };
	int N[2] = { 1, 2 };

	int* p;
	int* q[3];
	q[0] = K;
	q[1] = M;
	q[2] = N;

	cout << K << " " << &K[0] << " " << &K[1] << " " << &K[2] << endl; //주소 주소 주소 주소

	p = K;
	cout << p[0] << " " << p[1] << " " << p[2] << endl; //7 8 9
	cout << *(p + 0) << " " << *(p + 1) << " " << *(p + 2) << endl; //7 8 9

	p = M;
	cout << p[0] << " " << p[1] << " " << p[2] << endl; //6 5 4
	cout << *(p + 0) << " " << *(p + 1) << " " << *(p + 2) << endl; //6 5 4

	cout << q[0][0] << " " << q[0][1] << " " << q[0][2] << endl; //7 8 9
	cout << *(q[0] + 0) << " " << *(q[0] + 1) << " " << *(q[0] + 2) << endl; //7 8 9
	cout << q[1][0] << " " << q[1][1] << " " << q[1][2] << endl; //6 5 4
	cout << *(q[1] + 0) << " " << *(q[1] + 1) << " " << *(q[1] + 2) << endl; //6 5 4

	cout << *(q[2] + 0) << " " << *(q[2] + 1) << endl; //1 2
	cout << q[2][0] << " " << q[2][1] << endl; //1 2

	cout << *(*(q + 2) + 0) << " " << *(*(q + 2) + 1) << endl; //1 2
}


/*ex2_3
#include <iostream>

using namespace std;

void pfunc_1_(int *a, int *b)
{
	cout << *a << " " << *b << endl;
	*a = 30, *b = 40;
}

int main(void)
{
	int a = 10, b = 20;
	pfunc_1_(&a, &b);
	cout << a << " " << b << endl;
}
*/

/*ex2_4
#include <iostream>

using namespace std;

void pfunc_2_(int& c, int& d)
{
	cout << c << " " << d << endl;
	c = 30, d = 40;
}

int main(void)
{
	int a = 10, b = 20;
	pfunc_2_(a, b);
	cout << a << " " << b << endl;
}
*/

/*ex2_5
#include <iostream>

using namespace std;

int main(void)
{
	int M[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int(*ptr)[3];
	int* p;
	int** pt;

	ptr = M;
	cout << ptr << " " <<  M << endl; //주소 주소
	cout << ptr + 1 << " " << M + 1 << endl; //주소 주소
	cout << *(ptr + 1) << " " << ptr[1] << " " << *(M + 1) << " " << M[1] << endl; //주소 주소 주소 주소
	cout << **(ptr + 1) << " " << **(M + 1) << " " << *M[1] << " " << M[1][0] << endl; //4 4 4 4
}
*/

/*ex2_6
#include <iostream>

using namespace std;

int main(void)
{
	int annnnnnnnnnnnnnnnnnnnn = 10;
	int b[5] = { 10, 20, 30, 40, 50 };

	int& c = annnnnnnnnnnnnnnnnnnnn;

	cout << c << endl;

	return 0;
}
*/

/*ex2_7
#include <iostream>

using namespace std;

bool average(int a[], int size, int& avg) 
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum = sum + a[i];
	}

	avg = sum / 6;

	return true;
}

int main(void)
{
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg))
	{
		cout << "평균은 " << avg << endl;
	}
	else
	{
		cout << "매개 변수 오류" << endl;
	}
}
*/

/*ex2_8
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

	cout << "두 정수를 입력하세요>> ";
	cin >> x >> y;

	b = bigger(x, y, big);

	if (b)
	{
		cout << "same" << endl;
	}
	else
	{
		cout << "큰 수는 " << big << endl;
	}
}
*/

/*ex2_9
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
		cout << "M을 발견할 수 없다" << endl;
		return 0;
	}

	loc = 'm'; // 'M' 위치에 'm' 기록
	cout << s << endl; // "mike"가 출력됨
}
*/

