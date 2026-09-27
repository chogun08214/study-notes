/* EX1 arithmetic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, result;
	printf("두개의 정수를 입력하시오: ");
	scanf("%d %d", &a, &b);

	result = a + b;
	printf("%d + %d = %d\n", a, b, result);

	result = a - b;
	printf("%d - %d = %d\n", a, b, result);

	result = a * b;
	printf("%d * %d = %d\n", a, b, result);

	result = a / b;
	printf("%d / %d = %d\n", a, b, result);

	result = a % b;
	printf("%d %% %d = %d", a, b, result);

	return 0;
}
*/

/* EX2 arithmetic1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b, result;
	printf("두개의 실수를 입력하시오: ");
	scanf("%lf %lf", &a, &b);

	result = a + b;
	printf("%f + %f = %f\n", a, b, result);

	result = a - b;
	printf("%f - %f = %f\n", a, b, result);

	result = a * b;
	printf("%f * %f = %f\n", a, b, result);

	result = a / b;
	printf("%f / %f = %f\n", a, b, result);

	return 0;
}
*/

/* EX3 modulo
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MINUTE 60

int main(void)
{
	int a;

	printf("초를 입력하시오: ");
	scanf("%d", &a);

	int m, s;

	m = a / MINUTE;
	s = a % MINUTE;
	printf("%d초는 %d분 %d초입니다.", a, m, s);

	return 0;
}
*/

/* EX4 incdec
#include <stdio.h>

int main(void)
{
	int x=10, y=10;
	printf("x=%d\n", x);
	printf("++x의 값=%d\n", ++x);
	printf("x=%d\n\n", x);

	printf("y=%d\n", y);
	printf("y++의 값=%d\n", y++);
	printf("y=%d", y);

	return 0;
}
*/

/* EX5 change
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int price, money1, a5000, a1000, a500, a100, money2;

	printf("물건 값을 입력하시오: ");
	scanf("%d", &price);
	printf("사용자가 낸 돈: ");
	scanf("%d", &money1);

	money2 = money1 - price; //거스름돈

	a5000 = money2 / 5000;
	printf("오천원권: %d\n", a5000);
	money2 = money2 % 5000;

	a1000 = money2 / 1000;
	printf("천원권: %d\n", a1000);
	money2 = money2 % 1000;

	a500 = money2 / 500;
	printf("오백원권: %d\n", a500);
	money2 = money2 % 500;

	a100 = money2 / 100;
	printf("백원권: %d\n", a100);
	money2 = money2 % 100;

	return 0;
}
*/

/* EX6 assignment
#include <stdio.h>

int main(void)
{
	int x, y;

	x = 1;
	printf("수식 x+1의 값은 %d\n", x+1);
	printf("수식 y=x+1의 값은 %d\n", y=x+1);
	printf("수식 y=10+(x=2+7)의 값은 %d\n", y = 10 + (x = 2 + 7));
	printf("수식 y=x=3의 값은 %d\n", y=x=3);

	return 0;
}
*/

/* EX7 abbr
#include <stdio.h>

int main(void)
{
	int x = 10, y = 10, z = 33;

	x += 1;
	y *= 2;
	z %= 10 + 20;

	printf("x = %d y = %d z = %d", x, y, z);

	return 0;
}
*/

/* EX8 relational
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y;

	printf("두개의 정수를 입력하시오: ");
	scanf("%d %d", &x, &y);

	printf("x == y의 결과값: %d\n", x==y);
	printf("x != y의 결과값: %d\n", x!=y);
	printf("x > y의 결과값: %d\n", x>y);
	printf("x < y의 결과값: %d\n", x<y);
	printf("x >= y의 결과값: %d\n", x>=y);
	printf("x <= y의 결과값: %d\n", x <=y);

	return 0;
}
*/

/* EX9 logic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y;

	printf("두개의 정수를 입력하시오: ");
	scanf("%d %d", &x, &y);

	printf("1 && 0의 결과값: %d\n", 1&&0);
	printf("1 || 0의 결과값: %d\n", 1||0);
	printf("!1의 결과값: %d", !1);

	return 0;
}
*/

/* EX10 leapyear
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int year, result;
	printf("연도를 입력하시오: ");
	scanf("%d", &year);

	result = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	printf("result = %d", result);

	return 0;
}
*/

/* EX11 condition
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y;

	printf("첫번째 수= ");
	scanf("%d", &x);

	printf("두번째 수 = ");
	scanf("%d", &y);

	printf("큰 수 = %d\n", (x>y)?x:y);
	printf("작은 수 = %d", (x<y)?x:y);

	return 0;
}
*/

/* EX12 bit_op
#include <stdio.h>

int main(void)
{
	printf("AND : %08X\n", 0x9 & 0xA);
	printf("OR : %08X\n", 0x9 | 0xA);
	printf("XOR : %08X\n", 0x9 ^ 0xA);
	printf("NOT : %08X\n", ~0x9);
	printf("<< : %08X\n", 0x4 << 1);
	printf(">> : %08X\n", 0x4 >> 1);

	return 0;
}
*/

/* EX13 to_binary
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	unsigned int num;
	printf("10진수: ");
	scanf("%u", &num);

	unsigned int mask = 1 << 7;
	printf("2진쉬 ");
	
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	printf("\n");

	return 0;
}
*/

/* EX14 xor_enc
#include <stdio.h>

int main(void)
{
	char data = 'a';
	char key = 0xff;

	char encrpted_data;
	encrpted_data = data ^ key;

	printf("암호화된 문자 = %c\n", encrpted_data);

	char orig_data;
	orig_data = encrpted_data ^ key;
	printf("원래의 데이터 = %c\n", orig_data);

	return 0;
}
*/

/* EX15 convert1
#include<stdio.h>

int main(void)
{
	char c;
	int i;
	float f;

	c = 10000;
	i = 1.23456 + 10;
	f = 10 + 20;
	printf("c = %d, i = %d, f = %f", c, i, f);

	return 0;
}
*/

/* EX16 typecast
#include <stdio.h>

int main(void)
{
	int i;
	double f;

	f = 5 / 4;
	printf("%f\n", f);

	f = (double)5 / 4;
	printf("%f\n", f);

	f = 5.0 / 4;
	printf("%f\n", f);

	f = (double)5 / (double)4;
	printf("%f\n", f);

	i = 1.3 + 1.8;
	printf("%d\n", i);

	i = (int)1.3 + (int)1.8;
	printf("%d\n", i);

	return 0;
}
*/

/* EX17 prec
#include <stdio.h>

int main(void)
{
	int x = 0, y = 0;
	int result;

	result = 2 > 3 || 6 > 7;
	printf("%d\n", result);

	result = 2 || 3 && 3 > 2;
	printf("%d\n", result);

	result = x = y = 1;
	printf("%d\n", result);

	result = -++x + y--;
	printf("%d\n", result);

	return 0;
}
*/

/* EX18 temerature
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

int main(void)
{
	double c_temp, f_temp;

	printf("화씨 온도를 입력하시오: ");
	scanf("%lf", &f_temp);

	c_temp = 5.0 / 9.0 * (f_temp - 32);
	printf("섭씨온도는 %f입니다.", c_temp);

	return 0;
}
*/

/* EX19
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1, num2;
	int a, b;

	printf("2개의 정수를 입력하시오: ");
	scanf("%d %d", &num1, &num2);

	a = num1 / num2;
	b = num1 % num2;

	printf("몫: %d 나머지: %d", a, b);

	return 0;
}
*/

/* EX20
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double num1, num2;
	double a, b, c, d;

	printf("실수를 압력하시오: ");
	scanf("%lf %lf", &num1, &num2);

	a = num1 + num2;
	b = num1 - num2;
	c = num1 * num2;
	d = num1 / num2;

	printf("%f %f %f %f", a, b, c, d);

	return 0;
}
*/

/* EX21
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b, c;
	int max;

	printf("3개의 정수를 입력하시오: ");
	scanf("%d %d %d", &a, &b, &c);

	max = (a > b) ? a : b;
	max = (max > c) ? max : c;

	printf("최대값: %d", max);

	return 0;
}
*/

/* EX22
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int cm, feet;
	double inch;

	printf("키를 입력하시오(cm): ");
	scanf("%d", &cm);

	feet = cm / (12 * 2.54);
	inch = (cm / 2.54) - (feet * 12);
	printf("%dcm는 %d피트 %lf인치입니다.", cm, feet, inch);

	return 0;
}
*/

/* EX23
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, ten, one;

	printf("정수를 입력하시오: ");
	scanf("%d", &a);

	ten = a / 10;
	one = a % 10;
	printf("십의 자리: %d\n", ten);
	printf("일의 자리: %d\n", one);

	return 0;
}
*/

/* EX24
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b;
	printf("정수를 입력하시오: ");
	scanf("%d", &a);

	b = ~a + 1;
	printf("2의 보수: %d", b);
}
*/

/* EX25
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, result;
	printf("정수를 입력하시오: ");
	scanf("%d", &x);

	printf("2를 곱하고 싶은 횟수: ");
	scanf("%d", &y);

	result = 10 << 3;
	printf("10<<3의 값: %d", result);

	return 0;
}
*/

/* EX26
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.14

int main(void)
{
	double r, A1, A2;

	printf("구의 반지름을 입력하시오: ");
	scanf("%lf", &r);

	A1 = 4 * PI * r * r;
	A2 = (4 * PI * r * r * r) / 3;

	printf("표면적은 %f입니다.\n", A1);
	printf("체적은 %f입니다.\n", A2);

	return 0;
}
*/

/* EX27
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double BC, AC, AE, DE;

	printf("지팡이의 높이를 입력하시오: ");
	scanf("%lf", &BC);

	printf("지팡이 그림자의 길이를 입력하시오: ");
	scanf("%lf", &AC);

	printf("피라미드까지의 거리를 입력하시오: ");
	scanf("%lf", &AE);

	DE = (AE * BC) / AC;
	printf("피라미드의 높이는 %f입니다.", DE);

	return 0;
}
*/

/* EX28
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y;

	printf("x좌표를 입력하시오: ");
	scanf("%d", &x);

	printf("y좌표를 입력하시오: ");
	scanf("%d", &y);

	(x > 0 && y > 0) ? printf("1사분면") : printf("");
	(x < 0 && y > 0) ? printf("2사분면") : printf("");
	(x < 0 && y < 0) ? printf("3사분면") : printf("");
	(x > 0 && y < 0) ? printf("4사분면") : printf("");
}
*/

/* EX29
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double d, o, r, circle;

	printf("거리를 입력하시오: ");
	scanf("%lf", &d);

	printf("각도를 입력하시오: ");
	scanf("%lf", &o);

	circle = (900 * 360) / 7.2;
	r = circle / (2 * 3.14);

	printf("지구의 반지름은 %f", r);

	return 0;
}
*/

/* EX30
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char c1, c2, c3, c4;
	unsigned int result;

	printf("첫번째 문자를 입력하시오: ");
	scanf(" %c", &c1);

	printf("두번째 문자를 입력하시오: ");
	scanf(" %c", &c2);

	printf("세번째 문자를 입력하시오: ");
	scanf(" %c", &c3);

	printf("네번째 문자를 입력하시오: ");
	scanf(" %c", &c4);

	result = (c4 << 24) | (c3 << 16) | (c2 << 8) | c1;
	printf("결과값: %x", result);

	return 0;
}
*/