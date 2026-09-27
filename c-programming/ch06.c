/* EX1 if1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	if (number > 0)
		printf("양수입니다.\n");
	printf("입력된 값은 %d입니다.", number);

	return 0;
}
*/

/* EX2 if2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	if (number < 0)
		number = -number;

	printf("절대값은 %d입니다", number);

	return 0;
}
*/

/* EX3 if_else1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	if (number % 2 == 0)
		printf("입력된 정수는 짝수입니다.\n");
	else
		printf("입력된 정수는 홀수입니다.\n");

	return 0;
}
*/

/* EX4 if_else2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, result;;

	printf("분자를 입력하시오: ");
	scanf("%d", &a);

	printf("분모를 입력하시오: ");
	scanf("%d", &b);

	if (b == 0)
		printf("0으로 나눌 수는 없습니다.\n");
	else
	{
		result = a / b;
		printf("결과는 %d입니다.", result);

		return 0;
	}
}
*/

/* EX5 leap_year
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int year, yy;

	printf("연도를 입력하시오: ");
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("%d년은 윤년입니다.\n", year);
	else
		printf("%d년은 윤년이 아닙니다.\n", year);

	return 0;
}
*/

/* EX6 grade
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int score;

	printf("성적을 입력하시오: ");
	scanf("%d", &score);

	if (score >= 90)
		printf("학점 A");
	else if (score >= 80)
		printf("학점 B");
	else if (score >= 70)
		printf("학점 C");
	else if (score >= 60)
		printf("학점 D");
	else
		printf("학점 F");

	return 0;
}
*/

/* EX7 charclass
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char code;

	printf("문자를 입력하시오: ");
	scanf("%c", &code);

	if (code >= 'A' && code <= 'Z')
		printf("%c는 대문자입니다.\n", code);
	else if (code >= 'a' && code <= 'z')
		printf("%c는 소문자입니다.\n", code);
	else if (code >= 0 && code <= 9)
		printf("%c는 숫자입니다.\n", code);
	else
		printf("%c는 기타 문자입니다.\n", code);

	return 0;
}
*/

/* EX8 calc1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, result;
	char c;

	printf("수식을 입력하시오(예: 2 + 5)\n");
	
	printf(">> ");
	scanf("%d %c %d", &x, &c, &y);

	if (c == '+')
		result = x + y;
	else if (c == '-')
		result = x - y;
	else if (c == '*')
		result = x * y;
	else if (c == '/')
		result = x / y;
	else if (c == '%')
		result = x % y;
	else
		printf("지원되지 않는 연산자입니다.\n");

	printf("%d %c %d = %d", x, c, y, result);
	return 0;
}
*/

/* EX9 quad_eq
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main(void)
{
	double a, b, c, find;

	printf("계수 a, 계수 b, 계수 c를 차례대로 입력하시오: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	if (a == 0)
		printf("방정식의 근은 %f입니다.\n", -c / b);
	else
	{
		find = b * b - 4 * a * c;
		if (find >= 0)
		{
			printf("방정식의 근은 %f입니다.\n", (-b + sqrt(find)) / (2 * a));
			printf("방정식의 근은 %f입니다.\n", (-b - sqrt(find)) / (2 * a));
		}
		else
			printf("실근은 존재하지 않습니다.\n");
	}
	return 0;
}
*/

/* EX10 days_in_month
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int month, day;

	printf("달을 입력하시오: ");
	scanf("%d", &month);

	switch (month)
	{
	case 2:
		day = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	default:
		day = 31;
		break;
	}
	printf("%d월의 일수는 %d입니다.", month, day);

	return 0;
}
*/

/* EX11 calc2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, result;
	char calc;

	printf("수식을 입력하시오(예: 2 + 5)\n");

	printf(">> ");
	scanf("%d %c %d", &x, &calc, &y);

	switch (calc)
	{
	case '+':
		result = x + y;
		break;
	case '-':
		result = x - y;
		break;
	case '*':
		result = x * y;
		break;
	case '/':
		result = x / y;
		break;
	case '%':
		result = x % y;
		break;
	default:
		printf("유효한 연산자가 아닙니다.");
		break;
	}
	printf("%d %c %d = %d", x, calc, y, result);
	return 0;
}
*/

/* EX12 goto
#include <stdio.h>

int main(void)
{
	int i = 1;

loop:
	printf("%d * %d = %d\n", 3, i, 3 * i);
	i++;
	if (i == 10) goto end;
	goto loop;

end:
	return 0;
}
*/

/* EX13 proper_tri
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;

	printf("삼각형의 3변을 입력하시오: ");
	scanf("%d %d %d", &a, &b, &c);

	if (a + b > c && a + c > b && b + c > a)
		printf("올바른 삼각형");
	else
		printf("올바르지 않은 삼각형");

	return 0;
}
*/

/* EX14
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char c;
	printf("문자를 입력하시오: ");
	scanf("%c", &c);

	switch (c)
	{
	case 'a':
	case'e':
	case 'i':
	case'o':
	case'u':
		printf("모음입니다.");
		break;
	default:
		printf("자음입니다");
	}
	return 0;
}
*/

/* EX15 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b;

	printf("정수를 입력하시오: ");
	scanf("%d", &a);

	printf("정수를 입력하시오: ");
	scanf("%d", &b);

	if (a % b == 0)
		printf("약수입니다.");
	else
		printf("약수가 아닙니다.");

	return 0;
}
*/

/* EX16
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c, min;

	printf("3개의 정수를 입력하시오: ");
	scanf("%d %d %d", &a, &b, &c);

	if (a > b)
	{
		if (b > c)
			min = c;
		else
			min = b;
	}
	else
	{
		if (a > c)
			min = c;
		else
			min = a;
	}

	printf("제일 작은 정수는 %d입니다.", min);
	return 0;
}
*/

/* EX17
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int user, computer;

	printf("선택하시오(1:가위 2:바위 3:보) ");
	scanf("%d", &user);

	computer = (rand() % 3 + 1);
	
	if (user == 1)
		if (computer == 1)
			printf("비겼습니다.");
		else if (computer == 2)
			printf("컴퓨터가 이겼습니다.");
		else
			printf("사용자가 이겼습니다.");
	if (user == 2)
		if (computer == 1)
			printf("사용자가 이겼습니다.");
		else if (computer == 2)
			printf("비겼습니다.");
		else
			printf("컴퓨터가 이겼습니다.");
	if (user == 3)
		if (computer == 1)
			printf("컴퓨터가 이겼습니다");
		else if (computer == 2)
			printf("사용자가 이겼습니다.");
		else
			printf("비겼습니다.");

	printf("%d", computer);

	return 0;
}
*/

/* EX18
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int height, age;

	printf("키를 입력하시오(cm): ");
	scanf("%d", &height);

	printf("나이를 입력하시오: ");
	scanf("%d", &age);

	if (height >= 140 && age >= 10)
		printf("타도 좋습니다.");
	else
		printf("죄송합니다.");

	return 0;
}
*/

/* EX19
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int month;

	printf("월번호를 입력하시오: ");
	scanf("%d", &month);

	switch (month)
	{
	case 1:
		printf("Jan");
		break;
	case 2:
		printf("Feb");
		break;
	case 3:
		printf("Mar");
		break;
	case 4:
		printf("Apr");
		break;
	case 5:
		printf("May");
		break;
	case 6:
		printf("Jun");
		break;
	case 7:
		printf("Jul");
		break;
	case 8:
		printf("Aug");
		break;
	case 9:
		printf("Sep");
		break;
	case 10:
		printf("Oct");
		break;
	case 11:
		printf("Nov");
		break;
	case 12:
		printf("Dec");
		break;
	default:
		printf("적절한 월이 아닙니다.");
	}
	return 0;

}
*/

/* EX20
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int weight, height, standard_weight;

	printf("키와 체중을 입력하세요: ");
	scanf("%d %d", &height, &weight);

	standard_weight = (height - 100) * 0.9;

	if (weight > standard_weight)
		printf("과체중입니다.");
	else if (weight < standard_weight)
		printf("저체중입니다.");
	else
		printf("표준체중입니다.");

	return 0;
}
*/

/* EX21
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int time, age;

	printf("현재 시간과 나이를 입력하시오(시간, 나이): ");
	scanf("%d %d", &time, &age);

	if (time < 17)
	{
		if (age >= 13 && age < 65)
			printf("요금은 34000원 입니다.");
		else
			printf("요금은 25000원 입니다.");
	}
	else
		printf("요금은 10000원 입니다.");

	return 0;
}
*/

/* EX22
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double number, result;

	printf("x의 값을 입력하시오: ");
	scanf("%lf", &number);

	if (number <= 0)
		result = number * number + (-9 * number) + 2;
	else
		result =(7 * number) + 2;

	printf("f(x)의 값은 %f", result);
}
*/

/* EX23
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y;

	printf("좌표(x y): ");
	scanf("%d %d", &x, &y);

	if (x > 0 && y > 0)
		printf("1사분면");
	else if (x > 0 && y < 0)
		printf("4사분면");
	else if (x < 0 && y>0)
		printf("2사문면");
	else if (x < 0 && y < 0)
		printf("3사분면");
	else
		printf("좌표축 위");

	return 0;
}
*/

/* EX24
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char alpha;

	printf("문자를 입력하시오: ");
	scanf("%c", &alpha);

	switch (alpha)
	{
	case 'R':
	case 'r':
		printf("Rectangle");
		break;
	case 'T':
	case 't':
		printf("Triangle");
		break;
	case 'C':
	case 'c':
		printf("Circle");
		break;
	default:
		printf("Unknown");
	}
	return 0;
}
*/

