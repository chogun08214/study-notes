/*practice 1_1
#include <iostream>

double area(int r);
double f(double r);

double area(int r)
{
	return 3.14 * r * r;
}

double f(double r)
{
	return 3.14 * r * r;
}

int main(void)
{
	int n = 3;
	char c = '#';
	std::cout << c << 5.5 << '-' << n << "hello" << true << std::endl;
	std::cout << "n + 5 = " << n + 5 << "\n";
	std::cout << "면적은 " << area(n) << std::endl;

	double y = f(5.0);
	std::cout << y << "\n";

	return 0;
}
*/

/*practice1_2
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
	cout << "면적은 " << area;
}
*/

/*practice1_3
#include <iostream>

using namespace std;

int main(void)
{
	cout << "이름을 입력하세요>>";
	char name[11];
	cin >> name;

	cout << "이름은 " << name << "입니다";
}
*/

/*practice 1_4
#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	cout << "주소를 입력하세요>>";
	char address[100];
	cin.getline(address, 100, '\n');

	cout << "주소는 " << address << "입니다";
}
*/

/*practice1_5
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;

	cout << song + "를 부른 가수는";
	cout << "(힌트 : 첫글자는 " << elvis[0] << ")?";

	getline(cin, singer);
	if (singer == elvis)
	{
		cout << "맞았습니다.";
	}
	else
	{
		cout << "틀렸습니다. " + elvis + "입니다.";
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
	cout << "끝 수를 입력하세요>>";
	cin >> n;

	if (n <= 0) 
	{
		cout << "양수를 입력하세요!\n";
		return 0;
	}
	cout << "1에서 " << n << "까지의 합은 " << sum(1, n) << "입니다.";
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
			cout << i << "X" << j << "=" << i * j << " ";
		}
		cout << "\n";
	}
}
*/

/*ex1_3
#include <iostream>

using namespace std;

double biggest(double a[], int b)
{
	double max = a[0];

	for (int i = 0; i < b; i++)
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
	cout << "5개의 실수를 입력하라>>";

	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}

	cout << "제일 큰 수 = " << biggest(a, 5) << endl;
}
*/

/*ex1_4
#include <iostream>

using namespace std;

int main(void)
{
	char c[100];
	int count = 0;

	cout << "문자들을 입력하시오(100개미만)" << endl;
	cin.getline(c, 100, '\n');

	for (int i = 0; i < 100; i++)
	{
		if (c[i] == 'x')
		{
			count++;
		}
	}

	cout << 'X' << "의 개수는 " << count << endl;
}
*/

/*ex1_5
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	char password1[100], password2[100];

	cout << "새 암호를 입력하세요>>";
	string pw1;
	getline(cin, pw1);

	string pw2;
	cout << "새 암호를 다시 한번 입력하세요>>";
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

	cout << "--------------------------------------------" << endl;

	cout << name << ". " << address << ". " << age << endl;

}
*/

/*ex1_7
#include <iostream>

using namespace std;

namespace KIM {
	float area(float r)
	{
		return 3.14 * r * r;
	}
}

namespace KANG {
	float area(float x, float y)
	{
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

/*ex1_8
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int a = 100;
	string song("Falling love with you");
	string symbol = "!!!!!";

	song = song + symbol;

	int index = song.find("love");

	cout << song << endl;
	cout << index << endl;

	return 0;
}
*/