/*ex1
#include <stdio.h>

int main(void)
{

	for (int i = 0; i < 5; i++)
	{
		int temp = 1;
		printf("temp = %d\n", temp);
		temp++;
	}

	return 0;
}
*/

/*ex2
#include <stdio.h>

void inc(int counter);

int main(void)
{
	int i = 10;

	printf("함수 호출전 i = %d\n", i);
	inc(i);
	printf("함수 호출후 i = %d\n", i);

	return 0;
}

void inc(int counter)
{
	counter++;
}
*/

/*ex3 global
#include <stdio.h>

int A;
int B;

int add()
{
	return A + B;
}

int main()
{
	int answer;
	
	A = 5;
	B = 7;

	answer = add();

	printf("%d + %d = %d\n", A, B, answer);

	return 0;
}
*/

/*ex4
#include <stdio.h>

int sum = 1;

int main(void)
{
	int sum = 0;

	printf("sum = %d\n", sum);

	return 0;
}
*/

/*ex5 static
#include <stdio.h>

void sub()
{
	static int scount = 0;
	int account = 0;
	printf("scount = %d\t", scount);
	printf("account = %d\n", account);

	scount++;
	account++;

}

int main(void)
{
	sub();
	sub();
	sub();

	return 0;
}
*/

/*ex6 saving
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int save(int amount)
{
	static long balance = 0;

	if (amount >= 0)
	{
		printf("%d \t\t", amount);
	}
	else
	{
		printf("\t %d \t", -amount);
	}

	balance += amount;
	printf("%d \n", balance);
}

int main(void)
{
	printf("===================================\n");
	printf(" 입금          출금           잔고 \n");
	printf("===================================\n");
	save(10000);
	save(50000);
	save(-10000);
	save(30000);
	printf("===================================\n");

	return 0;
}
*/

/*ex7 inited
#include <stdio.h>
#include <stdlib.h>

void init();

int main(void)
{
	init();
	init();
	init();

	return 0;
}

void init()
{
	static int inited = 0;
	
	if (inited == 0)
	{
		printf("init(): 네트워크 장치를 초기화합니다. \n");
		inited = 1;
	}
	else
	{
		printf("init(): 이미 초기화되었으므로 초기화하지 않습니다 \n");
	}
}
*/

/*ex8 random, main
#define SEED 17

int MULT = 25173;
int INC = 13849;
int MOD = 665536;

static unsigned int seed = SEED;

unsigned random_i(void)
{
	seed = (MULT * seed + INC) % MOD;
	return seed;
}

double random_f(void)
{
	seed = (MULT * seed + INC) % MOD;
	return seed / (double)MOD;
}

#include <stdio.h>

extern unsigned random_i(void);
extern double random_f(void);

extern int MOD;

int main(void)
{
	int i;

	MOD = 10;
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", random_i());
	}

	return 0;
}
*/

/*ex9 stdarg
#include <stdio.h>
#include <stdarg.h>

int sum(int, ...);

int main(void)
{
	int answer = sum(4, 4, 3, 2, 1);
	printf("합은 %d입니다.\n", answer);

	return (0);
}

int sum(int num, ...)
{
	int answer = 0;
	va_list argptr;

	va_start(argptr, num);

	for (; num > 0; num--)
	{
		answer += va_arg(argptr, int);

		va_end(argptr);
		return(answer);
	}
}
*/


/*ex10 factorial
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long factorial(int n)
{
	printf("factorial(%d)\n", n);

	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}

int main(void)
{
	int n;
	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	printf("%d!은 %d입니다. \n", n, factorial(n));

	return (0);
}
*/

/*ex11 print_binary
#include <stdio.h>

void print_binary(int x);

int main(void)
{
	print_binary(9);
	printf("\n");
	return 0;
}

void print_binary(int x)
{
	if (x > 0)
	{
		print_binary(x / 2);
		printf("%d", x % 2);
	}
}
*/

/*ex12 gcd
#include <stdio.h>

int gcd(int x, int y);

int main(void)
{
	printf("%d\n", gcd(30. 20));
}

int gcd(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x % y);
	}
}
*/

/*ex13 hanoi_tower
#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to);

int main(void)
{
	hanoi_tower(4, 'A', 'B', 'C');
}

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)
	{
		printf("판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	}
	else
	{
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옯긴다.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
*/

/*test1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num1, num2;
char c;

void plus()
{
	static int count = 1;
	
	printf("덧셈은 총 %d번 실행되었습니다.\n", count);
	printf("연산 결과: %d", num1 + num2);

	count++;
}

void sub()
{
	static int count = 1;

	printf("뺄샘은 총 %d번 실행되었습니다.\n", count);
	printf("연산 결과: %d", num1 - num2);

	count++;
}

void mul()
{
	static int count = 1;

	printf("곱셈은 총 %d번 실행되었습니다.\n", count);
	printf("연산 결과: %d", num1 * num2);

	count++;
}

void div()
{
	static int count = 1;

	printf("나눗은 총 %d번 실행되었습니다.\n", count);
	printf("연산 결과: %d", num1 / num2);

	count++;
}

int main(void)
{
	while (1)
	{
		printf("연산을 입력하시오: ");
		scanf("%d%c%d", &num1, &c, &num2);

		switch (c)
		{
		case '+':
			plus();
			break;
		case '-':
			sub();
			break;
		case '*':
			mul();
			break;
		case '/':
			div();
			break;
		
		}
	}
	return 0;
}
*/

/*test2
#include <stdio.h>
#include <stdlib.h>

void get_dice_face()
{
	static int a0, a1, a2, a3, a4, a5;
	int num;

	for (int i = 0; i < 100; i++)
	{
		num = rand() % 6 + 1;

		if (num == 1)
		{
			a0++;
		}
		else if (num == 2)
		{
			a1++;
		}
		else if (num == 3)
		{
			a2++;
		}
		else if (num == 4)
		{
			a3++;
		}
		else if (num == 5)
		{
			a4++;
		}
		else if (num == 6)
		{
			a5++;
		}
	}

	printf("1->%d\n", a0);
	printf("2->%d\n", a1);
	printf("3->%d\n", a2);
	printf("4->%d\n", a3);
	printf("5->%d\n", a4);
	printf("6->%d\n", a5);
}

int main(void)
{
	srand((unsigned)time(NULL));
	get_dice_face();

	return 0;
}
*/

/*test3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define password 1234

int check()
{
	static int try = 0;
	int input;

	if (try == 3)
	{
		printf("로그인 시도횟수 초과\n");
		return 0;
	}

	printf("비밀번호: ");
	scanf("%d", &input);

	if (input == password)
	{
		printf("로그인 성공");

		return 1;
	}
	else
	{
		try++;
	}
	return 0;
}

int main(void)
{
	for (int i = 1; i <= 4; i++)
	{
		if (check() == 1)
		{
			break;
		}
	}

	return 0;
}
*/

/*test4
#include <stdio.h>
#include <stdlib.h>

void get_random()
{
	static int inited = 0;

	if (inited == 0)
	{
		srand((unsigned)time(NULL));
		printf("초기화 실행\n");
		inited = 1;
	}
	else
	{
		printf("%d\n", rand());
	}
}

int main(void)
{
	get_random();
	get_random();
	get_random();
	get_random();

	return 0;
}
*/

/*test5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int number)
{
	if (number != 0)
	{
		return number + sum(number - 1);
	}
	else
	{
		return number;
	}
}

int main(void)
{
	int number, result;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	result = sum(number);

	printf("1부터 %d까지의 합=%d", number, result);

	return 0;
}
*/

/*test6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int base, int power_raised)
{
	if (power_raised != 1)
	{
		return base * power(base, power_raised - 1);
	}
	else
	{
		return base;
	}
	
}

int main(void)
{
	int b, p;
	int result;

	printf("밑수: ");
	scanf("%d", &b);

	printf("지수: ");
	scanf("%d", &p);

	result = power(b, p);

	printf("%d^%d = %d", b, p, result);

	return 0;
}
*/

/*test7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int show_digit(int x)
{
	if (x / 10 > 0)
	{
		show_digit(x / 10);
	}
	printf("%d ", x % 10);
}

int main(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	show_digit(number);

	return 0;
}
*/

/*test8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count_number(int n)
{
	static int count = 0;

	if (n == 0)
	{
		return count;
	}
	n /= 10; count++;
	return count_number(n);

}

int main(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	printf("자리수의 개수: %d", count_number(number));

	return 0;
}
*/

/*test9
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_digit_sum(int n)
{
	if (n / 10 == 0) return n;
	return (n % 10) + get_digit_sum(n / 10);
}

int main(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	printf("자리수의 합: %d", get_digit_sum(number));

	return 0;
}
*/


/*test10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double recursive(double x)
{
	if (x != 1)
	{
		return 1.0 / x + recursive(x - 1);
	}
	else
	{
		return (x);
	}

}

int main(void)
{
	double num;
	scanf("%lf", &num);
	
	printf("%f", recursive(num));

	return 0;
}
*/

/*test11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recursive(int n, int k)
{
	if (n == k || k == 0) return 1;
	return recursive(n - 1, k - 1) + recursive(n - 1, k);
}

int main(void)
{
	int n, k;
	printf("n=");
	scanf("%d", &n);
	printf("k=");
	scanf("%d", &k);

	printf("%d", recursive(n, k));

	return 0;
}
*/

/*test12
#include <stdio.h>

int fib(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return fib(n - 2) + fib(n - 1);
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		printf("fib(%d) = %d\n", i, fib(i));
	}

	return 0;
}
*/

