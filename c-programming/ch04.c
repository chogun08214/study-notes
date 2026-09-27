/* EX1
#include <stdio.h>

int main(void)
{
	int x;
	printf("변수 x의         크기: %d\n", sizeof(x));

	printf("char형의         크기: %d\n", sizeof(char));
	printf("int형의          크기: %d\n", sizeof(int));
	printf("short형의        크기: %d\n", sizeof(short));
	printf("long형의         크기: %d\n", sizeof(long));
	printf("long long형의    크기: %d\n", sizeof(long long));
	printf("float형의        크기: %d\n", sizeof(float));
	printf("double형의       크기: %d\n", sizeof(double));

	return 0;
}
*/

/* EX2
#include <stdio.h>

int main(void)
{
	short year = 0; //short형 변수 선언
	int sale = 0; //int형 변수 선언
	long total_sale = 0; //long형 변수 선언
	long long large_value; //64비트 정수형

	year = 10;
	sale = 200000000;
	total_sale = year * sale;

	printf("total_sale = %d\n", total_sale);
	return 0;

}
*/

/* EX3
#include <stdio.h>
#include <limits.h>

int main(void)
{
	short s_money = SHRT_MAX; //최대값으로 초기화
	unsigned short u_money = USHRT_MAX; //최대값으로 초기화

	s_money = s_money + 1; //오버플로우 발생
	printf("s_money = %d\n", s_money);

	u_money = u_money + 1;
	printf("u_money = %u\n", u_money);

	return 0;
}
*/

/* EX4
#include <stdio.h>

int main(void)
{
	int x = 10;
	int y = 010;
	int z = 0x10;

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);

	return 0;
}
*/

/* EX5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define TAX_RATE 0.2

int main(void)
{
	const int MONTHS = 12;
	int m, y;

	printf("월급을 입력하시요: ");
	scanf("%d", &m);
	
	y = MONTHS * m;
	printf("연봉은 %d입니다.\n", y);
	printf("세금은 %f입니다.", y*TAX_RATE);

	return 0;
}
*/

/* EX6
#include <stdio.h>

int main(void)
{
	int x = 3;
	int y = -3;

	printf("x = %08X\n", x);
	printf("y = %08X\n", y);
	printf("x+y = %08X\n", x+y);

	return 0;
}
*/

/* EX7
#include <stdio.h>

int main(void)
{
	float x = 1.234567890123456789;
	double y = 1.234567890123456789;

	printf("float의 크기=%d\n", sizeof(float));
	printf("double의 크기=%d\n", sizeof(double));

	printf("x = %30.25f\n", x);
	printf("y = %30.25f\n", y);
}
*/

/* EX8 underflow
#include <stdio.h>

int main(void)
{
	float x = 1.23456e-38;;
	float y = 1.234556e-40;
	float z = 1.23456e-46;

	printf("x = %e\n", x);
	printf("y = %e\n", y);
	printf("z = %e\n", z);
}
*/

/* EX9 floating_error
#include <stdio.h>

int main(void)
{
	double x;

	x = (1.0e20 + 5.0) - 1.0e20;
	printf("%f \n", x);

	return 0;
}
*/

/* EX10 char_var
#include <stdio.h>
int main(void)
{
	char code1 = 'A';
	char code2 = 65;

	printf("code1 = %c\n", code1);
	printf("code2 = %c\n", code2);

	return 0;
}
*/

/* EX11 escape
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int id, ps;

	printf("아이디와 패스워드를 4개의 숫자로 입력하세요: \n");
	
	printf("id: ____\b\b\b\b");
	scanf("%d", &id);
	printf("pass: ____\b\b\b\b");
	scanf("%d", &ps);

	printf("입력된 아이디는 \"%d\"이고 패스워드는 \"%d\"입니다.", id, ps);

	return 0;
}
*/

/* EX12 char
#include <stdio.h>

int main(void)
{
	char code = 'A';

	printf("%d %d %d\n", code, code + 1, code +2);
	printf("%c %c %c\n", code, code + 1, code +2);

	return 0;
}
*/

/* EX13 sum_error
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, z;;
	int sum = 0;

	printf("3개의 정수를 입력하세요 (x, y, z): ");
	scanf("%d %d %d", &x, &y, &z);
	sum += x;
	sum += y;
	sum += z;

	printf("3개의 정수의 합은 %d", sum);

	return 0;
}
*/

/* EX 14 sun_light
#include <stdio.h>

int main(void)
{
	double LS = 300000;
	double DS = 149600000;

	double T;
	T = DS / LS;
	
	printf("빛의 속도는 %fkm/s\n", LS);
	printf("태양과 지구와의 거리 %fkm\n", DS);
	printf("도달 시간은 %f초", T);

	return 0;
}
*/

/* EX15
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b, c;
	printf("실수를 입력하시오: ");
	scanf("%lf", &a);

	printf("실수형식으로는 %9.6f입니다.\n", a);
	printf("지수형식으로는 %e", a);
}
*/

/* EX16
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a;

	printf("16진수 정수를 입력하시오: "); 
	scanf("%x", &a);

	printf("8진수로는 %#o입니다\n", a);
	printf("10진수로는 %d입니다\n", a);
	printf("16진수로는 %#x입니다", a);

	return 0;
}
*/

/* EX17
#include <stdio.h>

int main(void)
{
	int x = 10, y = 20;
	printf("x=%d y=%d\n", x, y);

	int a;
	a = x;
	x = y;
	y = a;
	
	printf("x=%d y=%d", x, y);

	return 0;
}
*/

/* EX18
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b, c, v;

	printf("상자의 가로 세로 톺이를 한번에 입력: ");
	scanf("%lf %lf %lf", &a, &b, &c);

	v = a * b * c;
	printf("상자의 부피는 %f입니다.", v);

	return 0;
}
*/

/* EX19
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PYEONG 3.3058

int main(void)
{
	int a;
	double b;
	printf("평을 입력하세요: ");
	scanf("%d", &a);

	b = a * PYEONG;
	printf("%f평입니다.", b);

	return 0;
}
*/

/* EX20
#include <stdio.h>

int main(void)
{
	double a;
	a = 3.32e-3 + 9.76e-8;
	printf("%f", a);
}
*/

/* EX21
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double m, v, E;

	printf("질량(kg): ");
	scanf("%lf", &m);

	printf("속도(m/s): ");
	scanf("%lf", &v);

	E = m * v * v / 2.0;
	printf("운동에너디(J): %f", E);
	return 0;
}
*/

/* EX22
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int AS;
	printf("아스키 코드값을 입력하시오: ");
	scanf("%d", &AS);

	printf("문자: %c입니다.", AS);

	return 0;
}
*/

/* EX23
#include <stdio.h>

int main(void)
{
	char code = 'a';

	printf("%c %c %c", code+1, code+2, code+3);
	return 0;
}
*/

/* EX24
#include <stdio.h>

int main(void)
{
	printf("\a화재가 발생하였습니다.");
	return 0;
}
*/

/* EX25
#include <stdio.h>

int main(void)
{
	printf("\"ASCII code\", \'A\', \'B\', \'C\'\n");
	printf("\\t \\a \\n");

	return 0;
}
*/