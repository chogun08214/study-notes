/*practice6_1
#include <iostream>

using namespace std;

class Person {
public:
	double money;
	void addMoney(int money_in)
	{
		money = money_in;
	}
	Person()
	{
		money = 0;
	}
	static int sharedMoney;
	static void addShared(int n)
	{
		sharedMoney += n;
	}
};

int Person::sharedMoney = 10;

int main(void)
{
	Person han;
	han.money = 100;
	han.sharedMoney = 200;

	Person lee;
	lee.money = 150;
	lee.addMoney(200);
	lee.addShared(200);

	cout << han.money << " " << lee.money << endl;
	cout << han.sharedMoney << " " << lee.sharedMoney <<  " " << Person::sharedMoney << endl;
}
*/

/*practice6_2
#include <iostream>

using namespace std;

class Person {
public:
	double money;
	void addMoney(int money)
	{
		this->money += money;
	}

	static int sharedMoney;
	static void addShared(int n)
	{
		sharedMoney += n;
	}
};

int Person::sharedMoney = 10;

int main(void)
{
	Person::addShared(50);
	cout << Person::sharedMoney << endl;

	Person han;
	han.money = 100;
	han.sharedMoney = 200;
	Person::sharedMoney = 300;
	Person::addShared(100);

	cout << han.money << " " << Person::sharedMoney << endl;
}
*/

/*ex6_1
#include <iostream>

using namespace std;

class Ram {
	char mem[100 * 1024];
	int size;
public:
	Ram();
	~Ram();
	char read(int address);
	void write(int address, char value);
};

Ram::Ram()
{
	for (int i = 0; i < size; i++)
	{
		mem[i] = 0;
	}

	size = 100 * 1024;
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

	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101);
	ram.write(102, res);

	cout << "102번지의 값 = " << (int)ram.read(102) << endl;
}
*/

/*ex6_2
#include <iostream>

using namespace std;

class Math {
public:
	static int abs(int a) { return a > 0 ? a : -a; }
	static int max(int a, int b) { return (a > b) ? a : b; }
	static int min(int a, int b) { return (a > b) ? b : a; }
};

int main(void)
{
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(-3, -8) << endl;

	Math A;
	cout << A.abs(-5) << endl;
	cout << A.max(10, 8) << endl;
	cout << A.min(-3, -8) << endl;
}
*/

/*ex6_3
#include <iostream>

using namespace std;

class Person {
public:
	int money;
	string name;

	Person()
	{
		money = 0;
	}
	Person(string name_in)
	{
		money = 0;
		name = name_in;
	}
	~Person()
	{
		cout << name << "의 money = " << money << endl;
	}
	void addMoney(int money_in)
	{
		money += money_in;
	}
	static int sharedMoney;
	static void addShared(int sharedmoney_in)
	{
		sharedMoney += sharedmoney_in;
	}
};

int Person::sharedMoney = 0;

int main(void)
{
	Person A("KANG"), B("KIM");

	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);

	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);

	cout << "공금 = " << Person::sharedMoney << endl;

	Person::addShared(100);
	cout << "공금 = " << Person::sharedMoney << endl;
}
*/

/*ex6_4
int main(void)
{
	Person A{ "KANG" };
	A.addMoney(100);
	A.addShared(5);

	Person* p = &A;

	cout << A.money << " " << (*p).money << " " << p->money << endl;
}
*/

