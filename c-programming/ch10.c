/*ex1 score1
#include <stdio.h>

int main(void)
{
	int scores[5];

	scores[0] = 10;
	scores[1] = 20;
	scores[2] = 30;
	scores[3] = 40;
	scores[4] = 50;

	for (int i = 0; i < 5; i++)
	{
		printf("scores[%d]=%d\n", i, scores[i]);
	}

	return 0;
}
*/

/*ex2 scores2
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void)
{
	int scores[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		scores[i] = rand() % 100;
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("scores[%d]=%d\n", i, scores[i]);
	}

	return 0;
}
*/

/*ex3 scores4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STUDENTS 5

int main(void)
{
	int scores[STUDENTS];
	int sum = 0;
	int average;

	for (int i = 0; i < STUDENTS; i++)
	{
		printf("학생들의 성적을 입력하시오: ");
		scanf("%d", &scores[i]);
	}

	for (int i = 0; i < STUDENTS; i++)
	{
		sum = sum + scores[i];
	}

	average = sum / STUDENTS;
	printf("성적 평균 = %d", average);

	return 0;
}
*/

/*ex4 scores5
#include <stdio.h>

int main(void)
{
	int scores[5] = { 31, 63, 62, 87, 14 };

	for (int i = 0; i < 5; i++)
	{
		printf("scores[%d] = %d\n", i, scores[i]);
	}

	return 0;
}
*/

/*ex5 dice
#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int main(void)
{
	int freq[SIZE] = { 0 };

	for (int i = 0; i < 10000; i++)
	{
		++freq[rand() % 6];
	}

	srand((unsigned)time(NULL));

	printf("=================\n");
	printf("면      빈도\n");
	printf("=================\n");

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d       %d\n", i + 1, freq[i]);
	}

	return 0;
}
*/

/*ex6 theater
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SEAT 10

int main(void)
{
	char yes_no;
	int seats[SEAT] = { 0 };
	int number;

	while (1)
	{
		printf("좌석을 예약하시겠습니까?(y 또는 n) ");
		scanf("%c", &yes_no);

		if (yes_no == 'y')
		{
			printf("-----------------------\n");
			printf(" 1 2 3 4 5 6 7 8 9 10\n");
			printf("------------------------\n");

			for (int i = 0; i < SEAT; i++)
			{
				printf(" %d", seats[i]);
			}

			printf("\n");

			printf("몇번째 좌석을 예약하시겠습니까");
			scanf("%d", &number);

			if (seats[number - 1] == 0)
			{
				seats[number - 1] = 1;
				printf("예약되었습니다.\n");
			}
			else
			{
				printf("이미 예약된 자리입니다\n");
			}
		}
		else if (yes_no == 'n')
		{
			break;
		}

	}
	
	return 0;
}
*/

/*ex7 minimum
#include <stdio.h>
#include <stdlib.h>

#define SHOP 10

int main(void)
{

	int minimum;
	int prices[SHOP] = { 0 };

	srand((unsigned)time(NULL));

	printf("---------------------\n");
	printf("1 2 3 4 5 6 7 8 9 10\n");
	printf("---------------------\n");

	for (int i = 0; i < SHOP; i++)
	{
		prices[i] = rand() % 100 + 1;
		printf("%-3d", prices[i]);
	}

	printf("\n\n");

	minimum = prices[0];

	for (int i = 0; i < SHOP; i++)
	{
		if (prices[i] < minimum)
		{
			minimum = prices[i];
		}
	}

	printf("최소값은 %d입니다.", minimum);

	return 0;
}
*/

/*ex8 modify
#include <stdio.h>

#define SIZE 7

void modify_array(int a[], int size);
void print_array(int a[], int size);

int main(void)
{
	int list[SIZE] = { 1, 2, 3, 4, 5, 6, 7 };

	print_array(list, SIZE);
	modify_array(list, SIZE);
	print_array(list, SIZE);

	return 0;
}

void modify_array(int a[], int size)
{

	for (int i = 0; i < size; i++)
	{
		++a[i];
	}
}

void print_array(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}
*/

/*ex9 selection_sort
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int list[SIZE] = { 3, 2, 8, 7, 1, 4, 8, 0, 6, 5 };

	int temp, least;

	for (int i = 0; i < SIZE - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (list[j] < list[least])
			{
				least = j;
			}
		}
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	return 0;
}
*/

/*ex10 deq_search
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int key;
	int list[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &key);

	for (int i = 0; i < SIZE; i++)
	{
		if (list[i] == key)
		{
			printf("탐색 성공 인덱스 = %d\n", i);
		}
	}

	printf("탐색 종료\n");

	return 0;
}
*/

/*ex11 binary_search
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 16

int binary_search(int list[], int n, int key)
{
	int low, high, middle;

	low = 0;
	high = n - 1;

	while (low <= high)
	{
		printf("[%d %d]\n", low, high);
		middle = (low + high) / 2;
		if (key == list[middle])
		{
			return middle;
		}
		else if (key > list[middle])
		{
			low = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
	}
	return -1;
}

int main(void)
{
	int number;
	int grade[SIZE] = { 2, 6, 11, 13, 18, 20, 22, 27, 29, 30, 34, 38, 41, 42, 45, 47 };

	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &number);

	printf("탐색결과 = %d\n", binary_search(grade, SIZE, number));

	return 0;
}
*/

/*ex12 two_dim_array
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand((unsigned)time(NULL));

	int s[3][5];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			s[i][j] = rand() % 100;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%02d ", s[i][j]); //ex 5 -> 05
		}
		printf("\n");
	}

	return 0;
}
*/

/*ex13 two_dimen_array2
#include <stdio.h>

int main(void)
{
	double final_scores;

	int a[3][5] = {
		{87, 98, 80, 76, 3},
		{99, 89, 90, 90, 0},
		{65, 68, 50, 49, 0}
	};

	for (int i = 0; i < 3; i++)
	{
		final_scores = a[i][0] * 0.3 + a[i][1] * 0.4 + a[i][2] * 0.2 + a[i][3] * 0.1 - a[i][4];

		printf("학생 #%d의 최종성적= %10.2f\n", i + 1, final_scores);
	}


	return 0;
}
*/

/*ex14 matrix
#include <stdio.h>

int main(void)
{
	int A[3][3] = {
		{2, 3, 0},
		{8, 9, 1},
		{7, 0, 5}
	};

	int B[3][3] = {
		{1, 0, 0},
		{1, 0, 0},
		{1, 0, 0}
	};

	int C[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/

/*ex15 sales
#include <stdio.h>

#define YEARS 3
#define PRODUCT 5

int sum(int scores[YEARS][PRODUCT])
{
	int y, p;
	int total = 0;

	for (y = 0; y < YEARS; y++)
	{
		for (p = 0; p < PRODUCT; p++)
		{
			total = total + scores[y][p];
		}
	}

	return total;
}

int main(void)
{
	int sales[YEARS][PRODUCT] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int total_sales;

	total_sales = sum(sales);

	printf("총매출은 %d입니다.", total_sales);

	return 0;
}
*/

/*ex16 image_proc
#include <stdio.h>

void display(int image[8][16])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (image[i][j] == 0)
			{
				printf("*");
			}
			else
			{
				printf("_");
			}
		}
		printf("\n");
	}
}

void inverse(int image[8][16])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (image[i][j] == 0)
			{
				image[i][j] = 1;
			}
			else
			{
				image[i][j] = 0;
			}
		}

	}
}

int main(void)
{
	int image[8][16] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	printf("변환전 이미지\n");
	display(image);
	inverse(image);

	printf("\n\n변환후 이미지\n");
	display(image);

	return 0;
}
*/

/*ex17
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, k, i;
	char board[3][3];

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board[x][y] = ' ';
		}
	}

	for (int k = 0; k < 9; k++)
	{
		printf("(x, y) 좌표: ");
		scanf("%d %d", &x, &y);

		board[x][y] = (k % 2 == 0) ? 'X' : '0';

		for (int i = 0; i < 3; i++)
		{
			printf("---|---|---\n");
			printf("%c  | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		}
		printf("---|---|---\n");
	}

	return 0;
}
*/

/*test 1
#include <stdio.h>

int main(void)
{
	int days[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	printf("8월은 %d일까지 있습니다.\n", days[7]);
	printf("9월은 %d일까지 있습니다.\n", days[8]);
	printf("10월은 %d일까지 있습니다.\n", days[9]);
	printf("11월은 %d일까지 있습니다.\n", days[10]);
	printf("12월은 %d일까지 있습니다.\n", days[11]);
	
	return 0;
}
*/

/* test2
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand((unsigned)time(NULL));

	int number[10];

	int max = 0;
	int mini = 32768;

	for (int i = 0; i < 10; i++)
	{
		number[i] = rand();

		if (number[i] > max)
		{
			max = number[i];
		}
		else if (number[i] < mini)
		{
			mini = number[i];
		}
	}



	printf("최대값은 %d\n", max);
	printf("최소값은 %d\n", mini);

	return 0;
}
*/

/*test3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int array_equal(int a[], int b[], int size)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (a[i] == b[i])
		{
			return 1;
		}
		else if(a[i] != b[i])
		{
			return 0;
		}
	}
}

int main(void)
{
	int a[SIZE] = { 0 };
	int b[SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int j = 0; j < SIZE; j++)
	{
		scanf("%d", &b[j]);
	}

	if (array_equal(a, b, SIZE) == 1)
	{
		printf("2개의 배열은 같음\n");
	}
	else if (array_equal(a, b, SIZE) == 0)
	{
		printf("2개의 배열은 다름\n");
	}

	return 0;
}
*/

/*test4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void array_copy(int a[], int b[], int size)
{
	for (int i = 0; i < 10; i++)
	{
		b[i] = a[i];
	}
}

int main(void)
{
	int a[10] = { 1, 2, 3, 0, 0, 0, 0, 0, 0 ,0 };
	int b[10];

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	array_copy(a, b, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
	}

	return 0;
}
*/

/*test5
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand((unsigned)time(NULL));

	int max_number;
	int random[10] = { 0 };
	int find_max[1] = { 0 };

	for (int i = 0; i < 100; i++)
	{
			++random[rand() % 10];
	}

	for (int i = 0; i <= 9; i++)
	{
		if (random[i] < random[i + 1])
		{
			max_number = i + 1;
		}
	}

	printf("가장 많이 나온수=%d", max_number);

	return 0;
}
*/

/*test6
#include <stdio.h>

int main(void)
{
	int a[3][5] = {
		{12, 56, 32, 16, 98},
		{99, 56, 34, 41, 3},
		{65, 3, 87, 78, 21}
	};

	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sum = sum + a[i][j];
		}
		printf("%d행의 합계: %d\n", i, sum);
		sum = 0;
	}

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			sum = sum + a[i][j];
		}
		printf("%d열의 합계: %d\n", j, sum);
		sum = 0;
	}

	return 0;
}
*/

/*test7
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int array[10][3] = { 0 };
	int number;

	for (int i = 0; i < 10; i++)
	{
		array[i][0] = i;
		array[i][1] = i * i;
		array[i][2] = i * i * i;
	}

	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	for (int i = 0; i < 10; i++)
	{
		if (array[i][2] == number)
		{
			printf("%d의 세제곱근은 %d", number, array[i][0]);
		}
	}

	return 0;
}
*/

/*test8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int data[10];

	int sum = 0;
	double avg;

	int a = 0;;
	double v;

	for (int i = 0; i < 10; i++)
	{
		printf("데이터를 입력하시오: ");
		scanf("%d", &data[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		sum = sum + data[i];
	}

	avg = sum / 10;
	printf("평균값은 %lf\n", avg);

	for (int i = 0; i < 10; i++)
	{
		a += (data[i] - avg) * (data[i] - avg);
	}

	v = sqrt(a / 10);

	printf("표준편차값은 %lf", v);

	return 0;
}
*/

/*test9
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int score[10][3] = { 0 };

	int max_score;
	int mini_score;

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			score[i][j] = rand() % 101;
		}
	}

	max_score = score[0][0];
	for (int i = 0; i < 10; i++)
	{
		if (max_score < score[i][0])
		{
			max_score = score[i][0];
		}
	}
	printf("시험 #0의 최대점수=%d\n", max_score);
	max_score = 0;

	mini_score = score[0][0];
	for (int i = 0; i < 10; i++)
	{
		if (mini_score > score[i][0])
		{
			mini_score = score[i][0];
		}
	}
	printf("시험 #0의 최저점수=%d\n", mini_score);
	mini_score = 0;

	max_score = score[0][1];
	for (int i = 0; i < 10; i++)
	{
		if (max_score < score[i][1])
		{
			max_score = score[i][1];
		}
	}
	printf("시험 #1의 최대점수=%d\n", max_score);
	max_score = 0;

	mini_score = score[0][1];
	for (int i = 0; i < 10; i++)
	{
		if (mini_score > score[i][1])
		{
			mini_score = score[i][1];
		}
	}
	printf("시험 #1의 최저점수=%d\n", mini_score);
	mini_score = 0;

	max_score = score[0][2];
	for (int i = 0; i < 10; i++)
	{
		if (max_score < score[i][2])
		{
			max_score = score[i][2];
		}
	}
	printf("시험 #2의 최대점수=%d\n", max_score);
	max_score = 0;

	mini_score = score[0][2];
	for (int i = 0; i < 10; i++)
	{
		if (mini_score > score[i][2])
		{
			mini_score = score[i][2];
		}
	}
	printf("시험 #0의 최저점수=%d\n", mini_score);
	mini_score = 0;

	return 0;
}
*/

/*test 10-1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void vector_add(double x[], double y[], double z[])
{
	for (int i = 0; i < 3; i++)
	{
		 z[i] = x[i] + y[i];
	}
	return;
}

int main(void)
{
	double first_vector[3] = { 0.0 };
	double second_vector[3] = { 0.0 };
	double third_vector[3] = { 0.0 };

	for (int i = 0; i < 3; i++)
	{
		scanf("%lf", &first_vector[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		scanf("%lf", &second_vector[i]);
	}

	vector_add(first_vector, second_vector, third_vector);

	printf("\n벡터의 합 = [%lf %lf %lf]", third_vector[0], third_vector[1], third_vector[2]);

	return 0;
}
*/

/*test 10-2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void vector_dot_prob(double x[], double y[], double z[])
{
	for (int i = 0; i < 3; i++)
	{
		z[i] = x[i] * y[i];
	}
	return;
}

int main(void)
{
	double first_vector[3] = { 0.0 };
	double second_vector[3] = { 0.0 };
	double third_vector[3] = { 0.0 };

	for (int i = 0; i < 3; i++)
	{
		scanf("%lf", &first_vector[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		scanf("%lf", &second_vector[i]);
	}

	vector_dot_prob(first_vector, second_vector, third_vector);

	printf("\n벡터의 합 = [%lf %lf %lf]", third_vector[0], third_vector[1], third_vector[2]);

	return 0;
}
*/

/*test11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int product[10] = { 0 };

	int num;

	srand((unsigned)time(NULL));
	
	for (int i = 0; i < 5; i++)
	{
		product[i] = rand() % 5 + 1;
	}

	printf("상품 번호를 입력하시요: ");
	scanf("%d", &num);

	printf("상품 번호 %d의 위치는 %d입니다.", num, product[num - 1]);

	return 0;
}
*/

/*test12-1
#include <stdio.h>

void scalar_multi(int a[][3], int scalar)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = a[i][j] * scalar;
		}
	}
}

int main(void)
{

	int matrix[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	scalar_multi(matrix, 2);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/

/*12-2
#include <stdio.h>

void transpose(int a[][3], int b[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[j][i];
		}
	}
}

int main(void)
{
	int matrix1[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int matrix2[3][3];

	transpose(matrix1, matrix2);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", matrix2[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
*/

/*test13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int binary[32] = { 0 };
	int n;
	int count = 0;

	scanf("%d", &n);
	printf("%d-> ", n);

	for (int i = 0; i < 32 && n > 0; i++)
	{
		binary[i] = n % 2;
		n = n / 2;
		count++;
	}

	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}

	return 0;
}
*/

/*test14
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int tile[20][20] = { 0 };
	int n = 10, m = 10;

	tile[10][10] = 1;

	srand((unsigned)time(NULL));

	for (int i = 0; i < rand() % 8; i++) 
	{
		int number = rand() % 8;

		switch (number) {
		case 0:
			tile[n - 1][m] = 1;
			n = n - 1; break;
		case 1:
			tile[n - 1][m + 1] = 1;
			n = n - 1; m = m + 1; break;
		case 2:
			tile[n][m + 1] = 1;
			m = m + 1; break;
		case 3:
			tile[n + 1][m + 1] = 1;
			n = n + 1; m = m + 1; break;
		case 4:
			tile[n + 1][m] = 1;
			n = n + 1; break;
		case 5:
			tile[n + 1][m - 1] = 1;
			n = n + 1; m = m - 1; break;
		case 6:
			tile[n][m - 1] = 1;
			m = m - 1; break;
		case 7:
			tile[n - 1][m - 1] = 1;
			n = n - 1; m = m - 1; break;
		}
	}

	for (int i = 0; i < 20; i++) 
	{
		for (int j = 0; j < 20; j++)
		{
			if (tile[i][j] == 0) 
				printf(". ");
			else if (tile[i][j] == 1) 
				printf("* ");
		}
		printf("\n");
	}
	return 0;
}
*/

/*test15
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int map[10][10] = { 0 };

	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((rand() % 100) < 30)
			{
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 1)
			{
				printf("#");
			}
			else if (map[i][j] == 0)
			{
				printf(". ");
			}
		}
		printf("\n");
	}

	return 0;
}
*/


