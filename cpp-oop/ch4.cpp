/*practice4_1
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string name;
	string address("서울기 성북수 삼선동 389");
	string copyAddress(address);

	char text[] = { 'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0' };
	string title(text);

	cin >> name;
	cout << address << "\n";
	cout << copyAddress << "\n";
	cout << text << "\n";
	cout << title << "\n";

	return 0;
}
*/

/*practice4_2
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string src = "C++ Programming";
	string dest;

	dest = src;

	cout << "src = " << src << "\n";
	cout << "dest = " << dest << "\n";
}
*/

/*practice4_3
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s1;
	string s2 = "123";
	string s3 = "abcdefg";

	cout << "s1 = " << s1.size() << "\n";
	cout << "s2 = " << s2.size() << "\n";
	cout << "s3 = " << s3.size() << "\n";
}
*/

/*practice4_4
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str1 = "abcde";
	string str2 = "fghj";

	str1 = str1 + str2;

	if (str1 == "abcdefghj")
	{
		cout << "str1 and \"abcdefghj\" are identical.\n";
	}
	if ("123456" != str1)
	{
		cout << "\"123456\" and str1 are NOT identical.\n";
	}
}
*/

/*practice4_5
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string text = "Napster's pay-to-play service is officially out, "
				 "and we have a review of the now-legit Napster. "
				 "We also size up its companion music player from Samsung.";

	cout << "Offset of 'offcial' = " << text.find("offcial") << "\n";
}
*/

/*practice4_6
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	vector<int> v; // 정수만삽입가능한벡터생성
	v.push_back(1); // 벡터에정수1 삽입
	v.push_back(2); // 벡터에정수2 삽입
	v.push_back(3); // 벡터에정수3 삽입
	for (int i = 0; i < v.size(); i++) // 벡터의모든원소출력
		cout << v[i] << " "; // v[i]는벡터의i번째원소
	cout << endl;
	v[0] = 10; // 벡터의첫번째원소를10으로변경
	int n = v[2]; // n에3이저장
	v.at(2) = 5; // 벡터의3 번째원소를5로변경
	for (int i = 0; i < v.size(); i++) // 벡터의모든원소출력
		cout << v[i] << " "; // v[i]는벡터의i번째원소
	cout << endl;
}
*/

/*practice4_7 class
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
	cout << "donut 면적은 " << area << endl;

	Circle pizza;
	pizza.radius = 30; 
	area = pizza.getArea(); 
	cout << "pizza 면적은" << area << endl;
}
*/

/*ex4_1
#include <iostream>

using namespace std;

class Rectangle {
public:
	int width;
	int height;
	int getArea();
};

int Rectangle::getArea()
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

/*ex4_2
#include <iostream>

using namespace std;

class Circle {
public:
	int radius;
	double getArea()
	{
		double area = 3.14 * radius * radius;
		return area;
	}
};

int main(void)
{
	Circle A, B, C;
	A.radius = 10;
	cout << A.getArea() << endl;

	Circle* p = &A;
	cout << (*p).radius << endl;
	cout << p->radius << endl;
	cout << (*p).getArea() << endl;
	cout << p->getArea() << endl;

}
*/

