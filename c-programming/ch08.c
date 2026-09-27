/*Ex1 func_exam1
#include <stdio.h>

void print_stars()
{
	for (int i = 0; i < 30; i++)
	{
		printf("*");
	}
}

int main(void)
{
	print_stars();
	printf("\nHello World!\n");
	print_stars();

	return 0;
}
*/

/*Ex2 max
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int main(void)
{
	int x, y;

	printf("정수를 입력하시오: ");
	scanf("%d", &x);

	printf("정수를 입력하시오: ");
	scanf("%d", &y);

	int larger;
	larger = max(x, y);
	printf("더 큰값은 %d입니다.", larger);

	return 0;
}
*/

/*Ex3 func_exam2
#include <stdio.h>

happyBirthday()
{
	printf("생일축하 합니다!\n");
	printf("생일축하 합니다!\n");
	printf("사랑하는 친구의 생일축하 합니다!");
}

int main(void)
{
	happyBirthday();
	return 0;
}
*/

/*Ex4 odd
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_integer()
{
	int value;
	printf("정수를 입력하시오: ");
	scanf("%d", &value);
	return value;
}

int add(int x, int y)
{
	return x + y;
}

int main(void)
{
	int x = get_integer();
	int y = get_integer();

	int sum = add(x, y);
	printf("두수의 합은 %d입니다.", sum);

	return 0;
}
*/

/*Ex5 factorial
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n)
{
	long result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

int main(void)
{
	int n;

	printf("알고 싶은 팩토리얼의 값은? ");
	scanf("%d", &n);

	printf("%d!의 값은 %d입니다. \n", n, factorial(n));

	return 0;
}
*/

/*Ex6 temperature
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void menu()
{
	printf("'c' 섭씨온도에서 화씨온도로 변환\n");
	printf("'f' 화씨온도에서 섭씨온도로 변환\n");
	printf("'q' 종료\n");
}

double CtoF(double c_temp)
{
	return 9.0 / 5.0 * c_temp + 32;
}

double FtoC(double f_temp)
{
	return (f_temp - 32.0) * 5.0 / 9.0;
}

int main(void)
{
	char choice;
	double temp;

	while (1)
	{
		menu();
		printf("메뉴에서 선택하세요. ");
		choice = getchar();

		if (choice == 'q')
		{
			break;
		}
		else if (choice == 'c')
		{
			printf("섭씨온도: ");
			scanf("%lf", &temp);
			printf("화씨온도: %lf\n", CtoF(temp));
		}
		else if (choice == 'f')
		{
			printf("화씨온도: ");
			scanf("%lf", &temp);
			printf("섭씨온도: %lf\n", FtoC(temp));
		}

		getchar();
	}
	return 0;
}
*/

/*Ex7 combination
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long combination(int n, int r)
{
	return (factorial(r) / (factorial(n - r) * factorial(r)));
}

int get_integer(void)
{
	int n;

	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	return n;
}

long factorial(int n)
{
	long result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
		return result;
	}
}

int main(void)
{
	int a, b;

	a = get_integer();
	b = get_integer();

	printf("C(%d, %d) = %d", a, b, combination(a, b));

	return 0;
}
*/

/*Ex8 prime number
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_integer(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	return number;
}

int is_prime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int n, result;
	n = get_integer();

	if (is_prime(n) == 1)
	{
		printf("%d은 소수입니다.\n", n);
	}
	else
	{
		printf("%d은 소수가 아닙니다.\n", n);
	}
	return 0;
}
*/

/*Ex9 lotto1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", rand());
	}

	return 0;
}
*/

/*Ex10 lotto2
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", (rand()%45) + 1);
	}
	return 0;
}
*/

/*Ex11 lotto3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 45

int main(void)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", 1+rand()%MAX);
	}
	return 0;
}
*/

/*Ex12 coingame
#define _CRT_SECURE_NO_WARNNGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coin_toss();

int main(void)
{
	int front = 0, back = 0;

	srand((unsigned)time(NULL));

	for (int coin = 0; coin < 100; coin++)
	{
		if (coin_toss() == 1)
		{
			front++;
		}
		else
		{
			back++;
		}
	}

	printf("동전의 앞면: %d\n", front);
	printf("동전의 뒷면: %d", back);

	return 0;
}

int coin_toss(void)
{
	int random = rand() % 2;

	if (random == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
*/

/*Ex13 racing_game
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch
#include <time.h>

void race(int car_number, int distance)
{
	printf("CAR #%d:", car_number);

	for (int i = 0; i < distance / 10; i++)
	{
		printf("*");
	}
	printf("\n");
}

int main(void)
{
	int car1 = 0, car2 = 0;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 6; i++)
	{
		car1 += rand() % 100;
		car2 += rand() % 100;

		race(1, car1);
		race(1, car2);

		printf("---------------------\n");
		_getch();
	}

	return 0;
}
*/

/*Ex14 point
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int x, y, r, g, b;

	HDC hdc;
	hdc = GetWindowDC(GetForegroundWindow());

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		x = rand() % 300;
		y = rand() % 300;

		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;

		SetPixel(hdc, x, y, RGB(r, g, b));
	}

	_getch();

	return 0;
}
*/

/*Ex15 trigonometric
#include <stdio.h>
#include <math.h>

int main(void)
{
	double pi = 3.1415926535;
	double x, y;

	x = pi / 2;
	y = sin(x);

	printf("sin( %f ) = %f\n", x, y);
	
	y = cos(x);

	printf("cos( %f ) = %f\n", x, y);

	return 0;
}
*/

/*Ex16 system
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	system("dir");
	printf("아무 키나 치세요\n");
	_getch();
	system("cls");

	return 0;
}
*/

/*Ex17 tree height

나무와의 거리: tree_distance
바닥에서 눈까지의 거리: floor_eye
각도: degree
나무의 높이: tree_height

radian = degree * ( pi / 180)


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	double tree_distance, floor_eye, degree, tree_height, radian;

	printf("나무와의 길이(단위는 미터): ");
	scanf("%lf", &tree_distance);

	printf("측정자의 키(단위는 미터): ");
	scanf("%lf", &floor_eye);

	printf("각도(단위는 도): ");
	scanf("%lf", &degree);

	radian = degree * (3.141592 / 180.0);

	tree_height = floor_eye + tan(radian) * tree_distance;

	printf("나무의 높이(단위는 미터): %lf", tree_height);

	return 0;
}
*/

/*Ex18 graph
#include <windows.h>
#include <stdio.h>
#include <math.h>
#define PI 3.141592

double rad(double degree)
{
	return PI * degree / 180.0;
}

int main(void)
{
	int degree, x, y;
	double radian, result;

	HWND hwnd = GetForegroundWindow();
	HDC hdc = GetWindowDC(hwnd);

	MoveToEx(hdc, 30, 200, 0);
	LineTo(hdc, 500, 200);

	MoveToEx(hdc, 30, 200, 0);
	LineTo(hdc, 30, 0);

	for (degree = 0; degree <= 360; degree++)
	{
		result = sin(rad((double)degree));
		x = degree + 30;
		y = 200 - (int)(100.0 * result);
		SetPixel(hdc, x, y, RGB(255, 0, 0));
	}

	return 0;
}
*/

/*Ex19 get_integer
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_integer();
double get_double();
char get_char();

int main(void)
{
	double f, g;
	f = get_double();
	g = get_double();
	printf("실수의 합=%lf", f+g);

	return 0;
}

int get_integer(int n)
{
	printf("정수를 입력하시오: ");
	scanf("%d", &n);
	return n;
}

double get_double(double n)
{
	printf("실수를 입력하시오: ");
	scanf("%lf", &n);
	return n;
}

char get_char(char n)
{
	printf("문자를 입력하시오: ");
	scanf("%c", &n);
	return n;
}
*/

/*test1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double square(double number)
{
	return number * number;
}

int main(void)
{
	double number;

	printf("정수를 입력하시오: ");
	scanf("%lf", &number);

	printf("주어진 정수 %lf의 제곱은 %lf입니다.", number, square(number));

	return 0;
}
*/

/*test2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void check_alpha(char ch)
{

	if (ch >= 97 && ch <= 122)
	{
		printf("%c는 알파벳 문자입니다.", ch);
	}
}

int main(void)
{
	char ch;

	printf("문자를 입력하시오: ");
	scanf("%c", &ch);

	check_alpha(ch);

	return 0;
}
*/

/*test3
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592
#include <stdio.h>

double cal_area(double radius)
{
	double area;
	area = PI * radius * radius;

	return area;
}

int main(void)
{
	double r;

	printf("원의 반지름을 입력하시오: ");
	scanf("%lf", &r);

	printf("원의 면적은 %lf입니다.", cal_area(r));

	return 0;
}
*/

/*test4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_leap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		printf("%d년은 366일 입니다.", year);
	}
	else
	{
		printf("%d년은 365일 입니다.", year);
	}
}

int main(void)
{
	int year;

	printf("연도를 입력하시오: ");
	scanf("%d", &year);

	is_leap(year);

	return 0;
}
*/

/*test5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int round(double f)
{
	return (int)(f + 0.5);
}

int main(void)
{
	double number;

	printf("실수를 입력하시오: ");
	scanf("%lf", &number);

	printf("반올림한 값은 %d입니다.", round(number));

	return 0;
}
*/

/*test6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int even(int n)
{
	if (n % 2 == 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int absolute(int n)
{
	return abs(n);
}

int sign(int n)
{
	if (n < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	if (even(number) == 1)
	{
		printf("even()의 결과: 짝수\n");
	}
	else
	{
		printf("even()의 결과: 홀수\n");
	}

	printf("absolute()의 결과: %d\n", absolute(number));

	if (sign(number) == -1)
	{
		printf("sign()의 결과: 음수");
	}
	else
	{
		printf("sign()의 결과: 양수");
	}

	return 0;
}
*/

/*test7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_tax(int income)
{
	if (income > 1000)
	{
		return (income - 1000) * 0.1 + 1000 * 0.08;
	}
	else
	{
		return income * 0.08;
	}
}

int main(void)
{
	int income;

	printf("소득을 입력하시오(만원): ");
	scanf("%d", &income);

	printf("소득세는 %d입니다.", get_tax(income));

	return 0;
}
*/

/*test8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592

double sin_degree(double degree)
{
	return (PI * degree) / 180.0;
}

int main(void)
{
	printf("sin(0.00000)의 값은 %lf\n", sin_degree(0.000000));
	printf("sin(10.00000)의 값은 %lf\n", sin_degree(10.000000));
	printf("sin(20.00000)의 값은 %lf\n", sin_degree(20.000000));
	printf("sin(30.00000)의 값은 %lf\n", sin_degree(30.000000));
	printf("sin(40.00000)의 값은 %lf\n", sin_degree(40.000000));
	printf("sin(50.00000)의 값은 %lf\n", sin_degree(50.000000));
	printf("sin(60.00000)의 값은 %lf\n", sin_degree(60.000000));
	printf("sin(70.00000)의 값은 %lf\n", sin_degree(70.000000));
	printf("sin(80.00000)의 값은 %lf\n", sin_degree(80.000000));
	printf("sin(90.00000)의 값은 %lf\n", sin_degree(90.000000));
	printf("sin(100.00000)의 값은 %lf\n", sin_degree(100.000000));
	printf("sin(110.00000)의 값은 %lf\n", sin_degree(110.000000));
	printf("sin(120.00000)의 값은 %lf\n", sin_degree(120.000000));
	printf("sin(130.00000)의 값은 %lf\n", sin_degree(130.000000));
	printf("sin(140.00000)의 값은 %lf\n", sin_degree(140.000000));
	printf("sin(150.00000)의 값은 %lf\n", sin_degree(150.000000));
	printf("sin(160.00000)의 값은 %lf\n", sin_degree(160.000000));
	printf("sin(170.00000)의 값은 %lf\n", sin_degree(170.000000));
	printf("sin(180.00000)의 값은 %lf\n", sin_degree(180.000000));

	double degree;
	printf("각도: ");
	scanf("%lf", &degree);

	printf("%lf", sin_degree(degree));

	return 0;
}
*/

/*test9
#include <stdio.h>
#include <stdlib.h>

int b_rand()
{
	return rand() % 2;
}

int main(void)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", b_rand());
	}

	return 0;
}
*/

/*test10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int b_rand()
{
	return rand() % 2;
}

int main(void)
{
	int f_b, com;
	char input;

	srand((unsigned)time(NULL));

	while (1)
	{
		com = b_rand();

		printf("앞면 또는 뒷면(1 또는 0): ");
		scanf("%d", &f_b);

		if (f_b == com)
		{
			printf("맞았습니다.\n");
		}
		else
		{
			printf("틀렸습니다.\n");
		}

		printf("계속하시곘습니까?(y 또는 n): ");
		scanf(" %c", &input); //한칸 띄고 %c하면 잘 작동

		if (input == 'n')
		{
			break;
		}
		else
		{
			continue;
		}
	}

	return 0;
}
*/

/*test11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double f_rand()
{
	return rand() / (double)RAND_MAX;
}

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%lf ", f_rand());
	}

	return 0;
}
*/

/*test12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_value(int number)
{
	for (int i = 1; i <= number; i++)
	{
		printf("*");
	}
	printf("\n");

}

int main(void)
{
	int number;
	int n;

	while (1)
	{
		printf("값을 입력하시오(종료는 음수): ");
		scanf("%d", &number);

		print_value(number);

		if (number < 0)
		{
			break;
		}
	}

	return 0;
}
*/

/*test13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void is_multiple(int n, int m)
{
	if (n % m == 0)
	{
		printf("%d는 %d의 배수입니다.", n, m);
	}
}

int main(void)
{
	int number1, number2;

	printf("첫번째 정수를 입력하시오: ");
	scanf("%d", &number1);

	printf("두번쨰 정수를 입려과시오: ");
	scanf("%d", &number2);

	is_multiple(number1, number2);

	return 0;
}
*/

/*test14
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double get_distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(void)
{
	double a1, a2;
	double b1, b2;

	printf("첫번째 점의 좌표를 입력하시오: (x, y) ");
	scanf("%lf %lf", &a1, &a2);

	printf("첫번째 점의 좌표를 입력하시오: (x, y) ");
	scanf("%lf %lf", &b1, &b2);

	printf("두점 사이의 거리는 %lf입니다.", get_distance(a1, a2, b1, b2));

	return 0;
}
*/

/*test15
#include <stdio.h>

int is_prime(int number)
{
	int count = 0;

	for (int i = 1; i <= number; i++)
	{
		if (number % i == 0)
		{
			count++;
		}
	}

	if (count > 2)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int main(void)
{
	for (int i = 2; i <= 100; i++)
	{
		if (is_prime(i) == 2)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
*/

/*test16
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n)
{
	int f = 1;

	for (int i = 1; i <= n; i++)
	{
		f = f * i;
	}

	return f;
}

int main(void)
{
	int number;
	double result = 1.0;

	printf("어디까지 계산할까요: ");
	scanf("%d", &number);

	for (int i = 1; i <= number; i++)
	{
		result = result + 1.0 / factorial(i);
	}

	printf("오일러의 수는 %f입니다.", result);

	return 0;
}
*/

/*test17
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define E 0.000001

double absolute(double a, double b)
{
	if (a > b)
	{
		return a - b;
	}
	else
	{
		return (a - b) * (-1);
	}
}

double min(double a, double b)
{
	if (a > b)
	{
		return b;
	}
	else if (a < b)
	{
		return a;
	}
}

double f_equal(double a, double b)
{
	if (absolute(a, b) / min(a, b) < E)
	{
		printf("두 개의 실수는 근사적으로 같음");
	}
	else
	{
		printf("두 개의 실수는 서로 다름");
	}
}

int main(void)
{
	double a, b;

	printf("실수를 입력하시오: ");
	scanf("%lf", &a);

	printf("실수를 입력하시오: ");
	scanf("%lf", &b);

	absolute(a, b);
	min(a, b);
	f_equal(a, b);

	return 0;
}
*/

/*test18
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void option()
{
	printf("========================================\n");
	printf("MENU\n");
	printf("========================================\n");
	printf("1. 덧셈\n");
	printf("2. 뺄셈\n");
	printf("3. 곱셈\n");
	printf("4. 나눗셈\n");
	printf("5. 나머지\n");
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}

int rest(int a, int b)
{
	return a % b;
}

int main(void)
{
	int menu;
	int number1, number2;
	int result;
	char input;

	while (1)
	{
		option();

		printf("원하는 메뉴를 선택하시오(1-5): ");
		scanf("%d", &menu);

		printf("숫자 2개를 입력하시오: ");
		scanf("%d %d", &number1, &number2);

		switch (menu)
		{
		case 1:
			result = add(number1, number2);
			break;

		case 2:

			result = sub(number1, number2);
			break;

		case 3:
			result = mul(number1, number2);
			break;

		case 4:
			result = div(number1, number2);
			break;

		case 5:
			result = rest(number1, number2);
			break;
		}

		printf("연산결과: %d\n", result);

		printf("계속하려면 y를 누르시오: ");
		scanf(" %c", &input);

		if (input == 'y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
		return 0;
}
*/

