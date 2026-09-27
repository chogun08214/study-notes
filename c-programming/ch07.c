/* EX1 gugu
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int i=1;

	printf("출력하고 싶은 단: ");
	scanf("%d", &n);

	while (i<10)
	{
		printf("%d * %d = %d\n", n, i, n*i);
		i++;
	}

}
*/

/* EX2 square
#include <stdio.h>

int main(void)
{
	printf("===============================\n");
	printf("       n         n의 제곱      \n");
	printf("===============================\n");

	int n = 1;

	while (n < 11)
	{
		printf("       %d           %d       \n", n, n*n);
		n++;
	}
	return 0;
}
*/

/* EX3 sum
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;
	int i = 1;
	int sum = 0;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	while (i <= number)
	{
		sum = sum + i;
		i++;
	}
	printf("1부터 %d까지의 합은 %d입니다.", number, sum);

	return 0;
}
*/

/* EX4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;
	int i = 0;
	int sum = 0;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	while (i<=number)
	{
		sum += i;
		i = i + 2;
	}
	printf("1부터 %d까지의 합은 %d입니다.", number, sum);
	return 0;
}
*/

/* EX5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i=0;
	int num;
	int sum = 0;

	while (i<5)
	{
		printf("값을 입력하시오: ");
		scanf("%d", &num);
		sum += num;
		i++;
	}

	printf("합계는 %d입니다.", sum);

	return 0;
}
*/

/* EX6 average
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int grade=0;
	double sum=0, average;
	int n = 0;

	printf("종료하려면 음수를 입력하시오\n");

	while (grade >= 0)
	{
		printf("성적을 입력하시오: ");
		scanf("%d", &grade);
		sum += grade;
		n++;
	}

	sum = sum - grade;
		n--;

	average = sum / n;
	printf("성적의 평균은 %f입니다.", average);

	return 0;
}
*/

/* EX7 gcd
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, r;

	printf("두개의 정수를 입력하시오(큰수, 작은수): ");
	scanf("%d %d", &x, &y);

	while (y!=0)
	{
		r = x % y;
		x = y;
		y = r;
	}

	printf("최대 공약수는 %d입니다.", x);

	return 0;
}
*/

/* EX8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int half, year; //반감기, 시간
	double initial, current; //초기값, 현재값

	printf("반감기를 입력하시오(년): "); //반감기 입력
	scanf("%d", &half);

	initial = 100.0; //초기 방사능 원소 = 100
	current = initial; // 현재값=초기값
	year = 0; //초기화

	while (current > initial*0.1) //최근값이 초기값의 1/10보다 크면 계속 진행
	{
		year += half; //시간 = 시간 + 반감기
		current = current / 2.0; // 최근값은 반감한 값
		printf("%d년 남은 양 = %f\n", year, current);
	}

	printf("1/10이하로 되기까지 걸린 시간 = %d년", year);
	return 0;
}
*/

/* EX9 sum
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number, sum=0;

	do
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &number);
		sum += number;
	} while (number != 0);

	printf("숫자들의 합: %d", sum);

	return 0;
}
*/

/* EX10 menu
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int menu;

	do
	{
		printf("1---새로만들기\n");
		printf("2---파일열기\n");
		printf("3---파일닫기\n");
		printf("하나를 선택하시오: ");
		scanf("%d", &menu);
	} while (1 < menu || 3 < menu);

	printf("선택된 메뉴=%d", menu);

	return 0;
}
*/

/* EX11 game
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number, try = 0;
	int answer = 59;

	do
	{
		printf("정답을 추측하여 보시오: ");
		scanf("%d", &number);
		try++;

		if (number < answer)
			printf("제시한 정수가 낮습니다.\n");
		if(number > answer)
			printf("제시한 정수가 높습니다.\n");

	} while (number != answer);

	printf("축하합니다. 시도횟수=%d", try);

	return 0;
}
*/

/* EX12 for
#include <stdio.h>

int main(void)
{
	int i;

	for (i = 0; i < 5; i++) {
		printf("Hello World!\n");
	}
	return 0;
}
*/

/* EX13 sum_for
#include <stdio.h>

int main(void)
{
	int sum = 0;
	for (int i = 1; i < 11; i++) {
		sum += i;
	}
	printf("1부터 10까지의 정수의 합: %d", sum);

	return 0;
}
*/

/* EX14 cubing
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number, num3;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	printf("==============================\n");
	printf("    i        i의 세제곱       \n");
	printf("==============================\n");

	for (int i = 1; i <= number; i++) {
		num3 = i * i * i;
		printf("     %d            %d       \n", i, num3);
	}

	return 0;
}
*/

/*EX15 draw_box
#include <stdio.h>

int main(void)
{
	printf("**********\n");

	for (int i = 0; i < 5; i++)
	   printf("*        *\n");

	printf("**********\n");

	return 0;
}
*/

/*EX16
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int fact = 1;

	printf("정수를 입력하시요: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		fact = i * fact;

	printf("%d!는 %d입니다.\n", n, fact);

	return 0;
}
*/

/*EX17
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int fact = 1;
	int i = 1;

	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	while (i <= n)
	{
		fact = fact * i;
		i++;
	}

	printf("%d!은 %d입니다.\n", n, fact);

	return 0;
}
*/

/*EX18
#include <stdio.h>

int main(void)
{
	int x;
	int y;

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x<10; x++)
			printf("*");

		printf("\n");
		
	}

	return 0;
}
*/

/*EX19
#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");

		printf("\n");
	}

	return 0;
}
*/

/*EX20
#include <stdio.h>

int main(void)
{
	for (int a = 1; a <= 100; a++)
	{
		for (int b = 1; b <= 100; b++)
		{
			for (int c = 1; c <= 100; c++)
			{
				if (a* a + b * b == c * c)
					printf("%d %d %d\n", a, b, c);
			}
		}
	}

	return 0;
}
*/

/*EX21
#include <stdio.h>
#define SEED_MONEY 1000000

int main(void)
{
	int money = SEED_MONEY;
	int year = 0;;

	while (1)
	{				
		money += money * 0.3;
		year++;

		if (money >= 10 * SEED_MONEY)
			break;
	}

	printf("%d년\n", year);

	return 0;
}
*/

/*EX22
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{

	double num;

	while (1)
	{
		printf("실수값을 입력하시오: ");
		scanf("%lf", &num);

		if (num < 0.0)
		{
			break;
		}

		printf("%lf의 제곱근은 %lf입니다.\n", num, sqrt(num));

	}

	return 0;
}
*/

/*EX23
#include <stdio.h>

int main(void)
{
	int x, y;
	
	for (y = 1; y < 10000; y++)
	{
		for (x = 1; x < 50; x++)
		{
			if (_kbhit() ) //키가 눌려지면 
				goto OUT;
			printf("*");
		}
		printf("\n");
	}
OUT:
	return 0;
}
*/

/*EX24
#include <stdio.h>

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 == 0)
			continue;

		printf("%d ", i);
	}

	return 0;
}
*/

/*EX25
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char word;

	while (1)
	{
		printf("소문자를 입력하시오: ");
		scanf("%c", &word);

		if (word == 'Q')
			break;

		if (word < 'a' || word > 'z')
			continue;

		word -= 32;
		printf("변환된 대문자는 %c입니다.\n", word);
	}

	return 0;
}
*/

/*EX26
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define RATE 0.07
#define INVESTMENT 10000000
#define YEARS 10

int main(void)
{
	double total = INVESTMENT;

	printf("=================\n");
	printf("연도   원리금    \n");
	printf("=================\n");

	for (int i = 1; i <= YEARS; i++)
	{
		total = total * (1 + RATE);
		printf("%2d %10.1f\n", i, total);
	}
	return 0;

}
*/

/*EX27
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int result, x, y;

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		x = rand() % 10;
		y = rand() % 10;

		printf("%d + %d = ", x, y);
		scanf("%d", &result);

		if (result == x + y)
		{
			printf("맞았습니다.\n");
		}
		else
		{
			printf("틀렸습니다.\n");
		}
	}

	return 0;
}
*/

/*EX28
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int initial_money = 50;
	int goal_money = 250;
	int wins = 0;

	for (int i = 0; i < 100; i++)
	{
		int cash = initial_money;
		
		while (cash > 0 && cash < goal_money)
		{
			if ((double)rand() / RAND_MAX < 0.5) cash++;
			else cash--;
		}
		if (cash == goal_money) wins++;
	}

	printf("초기 금액 $%d\n", initial_money);
	printf("목표 금액 $%d\n", goal_money);
	printf("100번 중에서 %d번 성공\n", wins);

	return 0;
}
*/

/*EX29
#include <stdio.h>
#include <windows.h>

int main(void)
{
	HDC hdc = GetWindowDC(GetForegroundWindow());

	for (int i = 0; i < 100; i++)
	{
		int x = rand() % 500;
		int y = rand() % 300;
		int w = rand() % 100;
		int h = rand() % 100;
		Rectangle(hdc, x, y, x + w, y + h);
		Sleep(100);
	}
	return 0;

}
*/

/*EX30
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int count;
	double pi = 0.0;
	double a = 4.0;
	double b = 1.0;

	printf("반복횟수: ");
	scanf("%d", &count);

	while (count > 0)
	{
		pi = pi + a / b;
		a = -1.0 * a;
		b = b + 2.0;
		--count;
	}

	printf("pi = %f", pi);
	
	return 0;
}
*/

/*test 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int count;

	printf("카운터의 초기값을 입력하시오: ");
	scanf("%d", &count);

	for (int i = count; i >= 1; i--)
	{
		printf("%d ", i);
	}

	printf("\a");

	return 0;
}
*/

/*test2
#include <stdio.h>

int main(void)
{
	int sum = 0;

	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			sum += i;
		}
	}

	printf("1부터 100 사이의 모든 3의 배수의 합은 %d입니다.", sum);

	return 0;
}
*/

/*test3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	printf("약수: ");

	for (int i = 1; i <= number; i++)
	{
		if (number % i == 0)
		{
			printf("%d ", i);
		}
	}

	return 0;
}
*/

/*test4
#include <stdio.h>

int main(void)
{
	int i, j;

	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7 - i; j++)
		{
			printf(" ");
		}
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
			printf("\n");
	}

	return 0;
}
*/

/*test5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;
	int i, j;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d ", j);
		}

		printf("\n");
	}

	return 0;
}
*/

/*test6
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char op;

	int num1;
	int num2;

	printf("*****************\n");
	printf("A---- Add\n");
	printf("S---- Subtract\n");
	printf("M---- Multiply\n");
	printf("D---- Divide\n");
	printf("Q---- Quit\n");
	printf("*****************\n");

	do {
		printf("연산을 선택하시오: ");
		scanf("%c", &op);

		if (op == 'Q')
		{
			break;
		}

		printf("두수를 공백으로 분리하여 입력하시오: ");
		scanf("%d %d", &num1, &num2);

		if (op == 'A')
		{
			printf("%d\n", num1 + num2);
			continue;
		}

		else if (op == 'S')
		{
			printf("%d\n", num1 - num2);
			continue;
		}

		else if (op == 'M')
		{
			printf("%d\n", num1 * num2);
			continue;
		}

		else if(op == 'D')
		{
			printf("%d\n", num1 / num2);
			continue;
		}

	} while (1);

	return 0;
}
*/

/*test7
#include <stdio.h>

int main(void)
{

	int i, j;

	for ( i = 2; i <= 100; i++)
	{
		for ( j = 2; j <= i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
*/

/*test8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int height;

	for (int i = 1; i <= 50; i++)
	{
		printf("막대의 높이(종료: -1): ");
		scanf("%d", &height);

		for (int j = 1; j <= height; j++)
		{
			printf("*");
		}
		
		printf("\n");

	}

	return 0;
}
*/

/*test9
#include <stdio.h>

int main(void)
{
	int i = 0;
	int sum = 0;

	while (1)
	{
		sum += i;

		if (sum > 10000)
		{
			break;
		}

		i++;
	}

	printf("1부터 %d까지의 합이 %d입니다.", i - 1, sum - i);

	return 0;
}
*/

/*test10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double r;
	int n;
	double result = 1.0;

	printf("실수의 값을 입력하시오: ");
	scanf("%lf", &r);

	printf("거듭제곱횟수를 입력하시오: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		result = result * r;
	}

	printf("결과값은 %lf", result);

	return 0;
}
*/

/*test11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int number;
	int result = 0;

	printf("n의 값을 입력하시오: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		number = i * i;
		
		result = result + number;
	}

	printf("계산값은 %d입니다.", result);

	return 0;
}
*/

/*test12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 1;
	int c;
	int number;

	printf("몇번째 항까지 구할까요? ");
	scanf("%d", &number);

	for (int i = 0; i <= number; i++)
	{
		printf("%d, ", a);

		c = a + b;
		a = b;
		b = c;
	}
	return 0;
}
*/

/*test13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	int r;
	int result = 1;;

	printf("n의 값:  ");
	scanf("%d", &n);

	printf("r의 값:  ");
	scanf("%d", &r);

	for (int i = n; i >= (n-r+1); i--)
	{
		result = result * i;
	}

	printf("순열의 값은 %d입니다.", result);

	return 0;
}
*/

/*test14
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int number;
	int result;

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	do
	{
		result = number % 10;
		number /= 10;
		printf("%d", result);
	} while (number != 0);

	return 0;
}
*/



