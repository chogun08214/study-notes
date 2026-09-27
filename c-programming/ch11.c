/*ex1 address_of
#include <stdio.h>

int main(void)
{
	int i = 10;
	char c = 69;
	double f = 12.3;

	printf("i의 주소: %u\n", &i);
	printf("c의 주소: %u\n", &c);
	printf("f의 주소: %u\n", &f);

	return 0;
}
*/

/*ex2 pointer_variable
#include <stdio.h>

int main(void)
{
	int i = 10;
	double f = 12.3;
	int* pi = NULL;
	double* pf = NULL;

	pi = &i;
	pf = &f;

	printf("%u %u\n", pi, i);
	printf("%u %u\n", pf, f);

	return 0;
}
*/

/*ex3 pointer 1
#include <stdio.h>

int main(void)
{
	int i = 3000;
	int* p = NULL;

	p = &i;

	printf("p = %u\n", p);
	printf("&i = %u\n\n", &i);

	printf("i = %d\n", i);
	printf("*p = %d\n", *p);

	return 0;
}
*/

/*ex4 pointer2
#include <stdio.h>

int main(void)
{
	int x = 10, y = 20;
	int* p;

	p = &x;
	printf("p = %d\n", p);
	printf("*p = %d\n\n", *p);

	p = &y;
	printf("p = %d\n", p);
	printf("*p = %d\n", *p);

	return 0;
}
*/

/*ex5 pointer 3
#include <stdio.h>

int main(void)
{
	int i = 10;
	int* p;

	p = &i;
	printf("i = %d\n", i);
	
	*p = 20;
	printf("i = %d\n", i);

	return 0;
}
*/

/*ex6 pointer_arith1
#include <stdio.h>

int main(void)
{
	char* pc;
	int* pi;
	double* pd;

	pc = (char*)10000;
	pi = (int*)10000;
	pd = (double*)10000;
	printf("증가 전 pc = %d, pi = %d, pd = %d\n", pc, pi, pd);

	pc++;
	pi++;
	pd++;
	printf("증가 후  pc = %d, pi = %d, pd = %d\n", pc, pi, pd);

	printf("pc + 2 = %d, pi + 2 = %d, pd + 2 = %d\n", pc + 2, pi + 2, pd + 2);

	return 0;
}
*/

/*ex7 pointer_arith2
#include <stdio.h>

int main(void)
{
	int i = 10;
	int* pi;

	pi = &i;
	printf("i = %d, pi = %d\n", i, pi);
	(*pi)++;
	printf("i = %d, pi = %d\n", i, pi);

	printf("i = %d, pi = %d\n", i, pi);
	*pi++;
	printf("i = %d, pi = %d\n", i, pi);

	return 0;
}
*/

/*ex8 pointer_arith3
#include <stdio.h>

int main(void)
{
	int data = 0x0A0B0C0D;
	char* pc;

	pc = (char*)&data;

	for (int i = 0; i < 4; i++)
	{
		printf("*(pc + %d) = %02X \n", i, *(pc + i));
	}

	return 0;
}
*/

/*ex9 swap1
#include <stdio.h>

void swap(int x, int y)
{
	int tmp;

	printf("x=%d y=%d\n", x, y);

	tmp = x;
	x = y;
	y = tmp;

	printf("x=%d y=%d\n", x, y);
}

int main(void)
{
	int a = 100, b = 200;

	printf("a=%d,b=%d\n", a, b);
	swap(a, b);
	printf("a=%d b=%d\n", a, b);

	return 0;
}
*/

/*ex10 swap2
#include <stdio.h>

void swap(int* px, int* py)
{
	int tmp;

	tmp = *px;
	*px = *py;
	*py = tmp;
}

int main(void)
{
	int a = 100, b = 200;

	printf("a=%d b=%d\n", a, b);
	swap(&a, &b);
	printf("a=%d,b=%d\n", a, b);

	return 0;
}
*/

/*ex11 slope
#include <stdio.h>

int get_line_parameter(int x1, int y1, int x2, int y2, float* slope, float* yintercept)
{
	if (x1 == x2)
	{
		return -1;
	}
	else
	{
		*slope = (float)(y2 - y1) / (float)(x2 - x1);
		*yintercept = y1 - (*slope) * x1;
		return 0;
	}
}

int main(void)
{
	float s, y;

	if (get_line_parameter(3, 3, 6, 6, &s, &y) == -1)
	{
		printf("에러\n");
	}
	else
	{
		printf("기울기는 %f, y절편은 %f\n", s, y);
	}

	return 0;
}
*/

/*ex12 p_array1
#include <stdio.h>

int main(void)
{
	int a[] = { 10, 20, 30, 40, 50 };

	printf("&a[0] = %u\n", &a[0]);
	printf("&a[1] = %u\n", &a[1]);
	printf("&a[2] = %u\n", &a[2]);

	printf("a = %u\n", a);

	return 0;
}
*/

/*ex13 p_array2
#include <stdio.h>

int main(void)
{
	int a[] = { 10, 20, 30, 40, 50 };

	printf("a = %u\n", a); //배열의 이름을 포인터처럼 사용 가능
	printf("a + 1 = %u\n", a + 1); //= a[1]의 주소
	printf("*a = %d\n", *a);
	printf("*(a+1) = %d", *(a+1));

	return 0;
}
*/

/*ex14 p_array3
#include <stdio.h>

int main(void)
{
	int a[] = { 10, 20, 30, 40, 50 };
	int* p;

	p = a; //배열의 첫번째 주소가 p에 대입
	printf("a[0]=%d a[1]=%d a[2]=%d\n", a[0], a[1], a[2]);
	printf("p[0]=%d p[1]=%d p[2]=%d\n", p[0], p[1], p[2]);

	p[0] = 60;
	p[1] = 70;
	p[2] = 80;

	printf("a[0]=%d a[1]=%d a[2]=%d\n", a[0], a[1], a[2]);
	printf("p[0]=%d p[1]=%d p[2]=%d\n", p[0], p[1], p[2]);

	return 0;
}
*/

/*ex15 p_func
#include <stdio.h>

void sub(int b[], int size)
{
	b[0] = 4;
	b[1] = 5;
	b[2] = 6;
}

int main(void)
{
	int a[3] = { 1, 2, 3 };

	printf("%d %d %d\n", a[0], a[1], a[2]);
	sub(a, 3);
	printf("%d %d %d\n", a[0], a[1], a[2]);

	return 0;
}
*/

/*ex16 imageprocessing
#include <stdio.h>
#define SIZE 5

void print_image(int image[SIZE][SIZE])
{
	int r, c;
	for (r = 0; r < SIZE; r++)
	{
		for (c = 0; c < SIZE; c++)
		{
			printf("%03d ", image[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void brighten_image(int image[SIZE][SIZE])
{
	int r, c;
	int* p;
	p = &image[0][0];
	for (r = 0; r < SIZE; r++)
	{
		for (c = 0; c < SIZE; c++)
		{
			*p += 10;
			p++;
		}
	}
}

int main(void)
{
	int image[SIZE][SIZE] = {
		{10, 20, 30, 40, 50},
		{10, 20, 30, 40, 50},
		{10, 20, 30, 40, 50},
		{10, 20, 30, 40, 50},
		{10, 20, 30, 40, 50},
	};

	print_image(image);
	brighten_image(image);
	print_image(image);

	return 0;
}
*/

/*ex17 simulation
#include <stdio.h>

void getSensorData(double* p)
{
	return;
}

int main(void)
{
	double sensorData[3];
	getSensorData(sensorData);

	printf("왼쪽 센서와 장애물과의 거리: %lf \n", sensorData[0]);
	printf("중간 센서와 장애물과의 거리: %lf \n", sensorData[1]);
	printf("오른쪽 센서와 장애물과의 거리: %lf \n", sensorData[2]);

	return 0;
}
*/

/*test1
#include <stdio.h>

int main(void)
{
	int x = 0x12345678;
	unsigned char* xp = (char*)&x;

	printf("바이트순서: %x %x %x %x\n", xp[0], xp[1], xp[2], xp[3]); //리틀 엔디언

	return 0;
}
*/

/*test2
#include <stdio.h>

void get_sum_diff(int x, int y, int* p_sum, int* p_diff)
{
	*p_sum = x + y;
	*p_diff = x - y;
}

int main(void)
{
	int sum;
	int diff;

	get_sum_diff(100, 200, &sum, &diff);


	printf("원소들의 합 = %d\n", sum);
	printf("원소들의 차 = %d", diff);

	return 0;
}
*/

/*test3
#include <stdio.h>
#include <stdlib.h>

void array_fill(int* A, int size)
{
	int i;
	for (int i = 0; i < size; i++)
	{
		A[i] = rand();
	}
}

void array_print(int* A, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}
}

int main(void)
{
	srand((unsigned)time(NULL));

	int A[10] = { 0 };

	array_fill(A, 10);
	array_print(A, 10);

	return 0;
}
*/

/*test4
#include <stdio.h>

void array_print(int* A, int size)
{
	int i;

	printf("A[] = { ");

	for (i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}

	printf("}\n");
}

int main(void)
{
	int A[10] = { 1, 2, 3, 4 };

	array_print(A, 10);

	return 0;
}
*/

/*test5
#include <stdio.h>

void convert(double* grades, double* scores, int size)
{
	int i;

	for (int i = 0; i < size; i++)
	{
		scores[i] = (grades[i] / 4.3) * 100;
	}
}

void print(double* scores, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%lf ", scores[i]);
	}
	printf("\n");
}

int main(void)
{
	double grades[10] = {1, 2, 3, 4, 3, 2, 1, 2, 3, 4};
	double scores[10] = { 0 };

	convert(grades, scores, 10);
	print(scores, 10);

	return 0;
}
*/

/*test6
#include <stdio.h>

void array_copy(int* A, int* B, int size)
{
	for (int i = 0; i < size; i++)
	{
		B[i] = A[i];
	}
}

void print_array(int* B, int size)
{
	printf("B[] = ");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", B[i]);
	}
}

int main(void)
{
	int A[10] = { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0 };
	int B[10] = { 0 };

	printf("A[] = ");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n");
	

	array_copy(A, B, 10);
	print_array(B, 10);

	return 0;
}
*/

/*test7
#include <stdio.h>

void array_add(int* A, int* B, int* C, int size)
{
	for (int i = 0; i < size; i++)
	{
		C[i] = A[i] + B[i];
	}
}

void array_print(int* C, int size)
{
	printf("C[] = ");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", C[i]);
	}
}

int main(void)
{
	int A[10] = { 1, 2, 3, 0, 0, 0, 0, 0, 0, 0 };
	int B[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int C[10] = { 0 };

	printf("A[] = ");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n");

	printf("B[] = ");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", B[i]);
	}

	printf("\n");

	array_add(A, B, C, 10);
	array_print(C, 10);

	return 0;
}
*/

/*test8
#include <stdio.h>

void array_sum(int* A, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum = sum + A[i];
	}

	printf("월급의 합 = %d", sum);
}

int main(void)
{
	int sum = 0;
	int A[10] = { 1, 2, 3 };

	printf("A[] = ");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", A[i]);
	}

	printf("\n");

	array_sum(A, 10);

	return 0;
}
*/

/*test9
#include <stdio.h>

int search(int* A, int size, int search_value)
{
	for (int i = 0; i < size; i++)
	{
		if (A[i] == search_value)
		{
			printf("월급이 200만원인 사람의 인덱스=%d", i);
		}
	}
}

int main(void)
{
	int money[5] = {210, 200, 190, 195, 210};

	int value_200 = 200;
	
	search(money, 5, value_200);

	return 0;
}
*/

/*test10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_lcm_gcd(int org_x, int org_y, int* p_lcm, int* p_gcd)
{
	int x = org_x;
	int y = org_y;
	int temp;
 
	while (y) {
		temp = x % y;
		x = y;
		y = temp;
	}
	*p_gcd = x;
	*p_lcm = org_x * org_y / *p_gcd;
}

int main(void)
{
	int num1, num2, l, g;

	printf("두 개의 정수를 입력하시오: ");
	scanf("%d %d", &num1, &num2);

	get_lcm_gcd(num1, num2, &l, &g);

	printf("최소공배수는 %d입니다.\n", l);
	printf("최대공약수는 %d입니다.\n", g);

	return 0;
}
*/

/*test11
#include <stdio.h>

void merge(int* A, int* B, int* C, int size)
{
	int i = 0, j = 0, k = 0;

	for (k = 0; k < size; k++) {
		if (i >= 4) 
		{
			C[k] = B[j];
			j++;
		}
		else if (j >= 4) 
		{
			C[k] = A[i];
			i++;
		}
		else if (A[i] < B[j]) 
		{
			C[k] = A[i];
			i++;
		}
		else if (A[i] > B[j]) 
		{
			C[k] = B[j];
			j++;
		}
	}
}

int main(void)
{
	int A[4] = { 2, 5, 7, 8 };
	int B[4] = { 1, 3, 4, 6 };
	int C[8] = { 0 };

	printf("A[] = ");

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	printf("B[] = ");

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", B[i]);
	}
	printf("\n");

	merge(A, B, C, 8);

	printf("C[] = ");

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", C[i]);
	}
	printf("\n");

	return 0;
}
*/

/*test 13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_int(int* px, int* py)
{
	printf("정수의 합은 %d", *px + *py);
}

int main(void)
{
	int num1, num2;

	printf("2개의 정수를 입력하시오(예: 10 20): ");
	scanf("%d %d", &num1, &num2);

	get_int(&num1, &num2);

	return 0;
}
*/

