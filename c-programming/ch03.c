/* EX1
#include <stdio.h>

int main(void)
{
	int x; //첫 번째 정수를 저장할 변수
	int y; //두 번째 정수를 저장할 변수
	int sum; //두 정수의 합을 저장하는 변수

	x = 100;
	y = 200;

	sum = x + y;
	printf("두수의 합: %d", sum);

	return 0;
}
*/

/* EX2
#include <stdio.h>

int main(void)
{
	int x = 20;
	int y = 10;
	int a, b, c, d;

	a = x + y;
	b = x - y;
	c = x * y;
	d = x / y;

	printf("두수의 합: %d\n", a);
	printf("두수의 차: %d\n", b);
	printf("두수의 곱: %d\n", c);
	printf("두수의 몫: %d\n", d);

	return 0;
}
*/

/* EX3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, sum; //첫번째 정수, 두번째 정수, 2개의 정수의 합을 저장할 변수

	printf("첫번쨰 숫자를 입력하시오: ");
	scanf("%d", &x); //하나의 정수를 받아서 x에 저장

	printf("두번째 숫자를 입력하시오: ");
	scanf("%d", &y); //하나의 정수를 받아서 y에 저장

	sum = x + y;

	printf("두수의 합: %d", sum);

	return 0;
}
*/

/* EX4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b;

	printf("연봉을 입력하시오(단위: 만원): ");
	scanf("%d", &a);

	b = a / 12;
	printf("월수령액(단위: 만원): %d", b);

	return 0;
}
*/

/* EX5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float r, s;

	printf("반지름을 입력하시오: ");
	scanf("%f", &r);

	s = r * r * 3.14;
	printf("원의 면적: %f", s);

	return 0;

}
*/

/* EX6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b;
	int c;

	printf("환율을 입력하시오: ");
	scanf("%lf", &a);

	printf("원화 금액을 입력하시오: ");
	scanf("%d", &c);

	b = c / a;

	printf("원화 %d원은 %lf달러입니다.", c, b);

	return 0;
}
*/

/* EX7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double w, h, a, p;

	w = 10.0;
	h = 5.0;
	a = w * h;
	printf("사각형의 넓이: %lf\n", a);

	p = 2 * (w + h);
	printf("사각형의 둘레: %lf", p);
	
	return 0;
}
*/

/* EX8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b, c, d, e;

	printf("실수를 입력하시오: ");
	scanf("%lf", &a);

	printf("실수를 입력하시오: ");
	scanf("%lf", &b);

	printf("실수를 입력하시오: ");
	scanf("%lf", &c);
	
	d = a + b + c;
	e = d / 3;

	printf("합은 %lf이고 평균은 %lf입니다.", d, e);

	return 0;
}
*/

/* EX9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b;

	printf("마일을 입력하시오: ");
	scanf("%lf", &a);

	b = a * 1609.0;

	printf("%lf마일은 %lf미터입니다.", a, b);

	return 0;
}
*/

/* EX10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b, c;

	printf("삼각형의 밑변: ");
	scanf("%lf", &a);

	printf("삼각형의 높이: ");
	scanf("%lf", &b);

	c = 0.5 * a * b;

	printf("삼각형의 넓이: %lf", c);

	return 0;
}
*/

/* EX11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b;

	printf("화씨값을 입력하시오: ");
	scanf("%lf", &a);

	b = (5.0 / 9.0) * (a - 32.0);
	printf("섭씨값은 %f도입니다.", b);

	return 0;
}
*/

/* EX12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b;

	printf("실수를 입력하세요: ");
	scanf("%lf", &a);

	b = (3 * a * a) + (7 * a) + 11;

	printf("다항식의 값은 %f", b);

	return 0;
}
*/

/* EX13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b;

	printf("몸무게를 입력하세요(단위: kg): ");
	scanf("%lf", &a);

	b = a * 0.17;

	printf("달에서의 몸무게는 %fkg 입니다.", b);

	return 0;
}
*/

