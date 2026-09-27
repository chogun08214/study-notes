/*미로 탐색 프로그램*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h> //_getch()

#define STACK_SIZE 100 //stack의 크기 100
#define MAZE_SIZE 10 //미로의 크기 10x10

typedef struct stackobject { //stack 구조체 
	int r; //행
	int c; //열
}stackobject;

stackobject stack[STACK_SIZE]; //stack의 배열, 좌표 저장
int top = -1; //stack의 초기값
stackobject here = { 0,1 }, entry = { 0,1 }; //현재위치와 입구의 위치

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', 'e', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '1', '1', '1', '0', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
	{'1', '1', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '1', '0', '1', '1', '1', '1', '1'},
	{'1', '1', '0', '1', '0', '0', '0', '0', '1', '1'},
	{'1', '1', '0', '1', '1', '1', '1', '0', '1', '1'},
	{'1', '1', '1', '1', '1', '1', '1', 'x', '1', '1'}
};

int isEmpty() //스택이 비어있는지 확인
{
	return top == -1; //스택이 비어있음
}

void push(stackobject item) //stack에 좌표 저장
{
	if (top >= STACK_SIZE - 1) //stack 초과시
	{
		return;
	}
	else
	{
		stack[++top] = item; //stack에 좌표 추가
	}
}

stackobject pop() //stack에서 좌표 삭제
{
	if (isEmpty()) //stack이 비어있으면 종료
	{
		exit(1);
	}
	else
	{
		return stack[top--]; //stack에서 최근에 추가한 좌표 반환
	}
}

void pushLoc(int r, int c) //좌표를 stack에 push
{
	if (r < 0 || c < 0) //미로 바깥으로 나가면
	{
		return;
	}
	if (maze[r][c] != '1' && maze[r][c] != '.') //1 or .이면 stack에 추가x
	{
		stackobject tmp;
		tmp.r = r;
		tmp.c = c;
		push(tmp); //이동가능한 좌표 stack에 저장
	}
}

void printmaze(char maze[MAZE_SIZE][MAZE_SIZE]) //현재 미로 출력
{
	for (int r = 0; r < MAZE_SIZE; r++)
	{
		for (int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c ", maze[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void printstack() //현재 stack 출력
{
	int i;

	for (i = 9; i > top; i--)
	{
		printf("|      |\n");
	}

	for (i = top; i >= 0; i--)
	{
		printf("|(%01d, %01d)|\n", stack[i].r, stack[i].c);
	}

	printf("--------\n");
}

int main(void)
{
	int r, c;
	here = entry;
	printmaze(maze);
	printstack();

	while (maze[here.r][here.c] != 'x') //x를 찾을때까지 반복
	{
		printmaze(maze);

		r = here.r;
		c = here.c;

		maze[r][c] = '.';

		pushLoc(r - 1, c);
		pushLoc(r + 1, c);
		pushLoc(r, c - 1);
		pushLoc(r, c + 1);

		printstack();

		if (isEmpty())
		{
			printf("실패!\n");
			return;
		}
		else
		{
			here = pop();
			printmaze(maze);
			printstack();
			_getch();
		}
	}

	printf("성공!\n");
	return 0;
}