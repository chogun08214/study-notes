/*ex1 student1
#include <stdio.h>

struct studentex1 {
	int id;
	char name[10];
	double grade;
};

int main(void)
{
	struct studentex1 s1;

	s1.id = 20190001;
	strcpy(s1.name, "홀길동");
	s1.grade = 3.4;

	printf("학번: %d\n", s1.id);
	printf("이름: %s\n", s1.name);
	printf("학점: %lf\n", s1.grade);

	return 0;
}
*/

/*ex2 student2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	int id;
	char name[10];
	double grade;
};

int main(void)
{
	struct student s1;

	printf("학번을 입력하시오: ");
	scanf("%d", &s1.id);

	printf("이름을 입력하시오: ");
	scanf("%s", s1.name);

	printf("학점을 입력하시오: ");
	scanf("%lf", &s1.grade);

	printf("학번: %d\n", s1.id);
	printf("이름: %s\n", s1.name);
	printf("학점: %lf\n", s1.grade);

	return 0;

}
*/

/*ex3 point
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
};

int main(void)
{
	struct point p1;
	struct point p2;

	double dist;

	printf("점의 좌표를 입력하시오(x y): ");
	scanf("%d %d", &p1.x, &p1.y);

	printf("점의 좌표를 입력하시오(x y): ");
	scanf("%d %d", &p2.x, &p2.y);

	dist = sqrt((double)((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));

	printf("거리는 %lf입니다.\n", dist);

	return 0;
}
*/

/*ex3 nested_struct
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct point {
	int x;
	int y;
};

struct rect {
	struct point p1;
	struct point p2;
};

int main(void)
{
	struct rect r;
	int area;
	int peri;
	int w, h;

	printf("왼쪽 하단의 좌표를 입력하시오: ");
	scanf("%d %d", &r.p1.x, &r.p1.y);

	printf("오른쪽 상단의 좌표를 입력하시오: ");
	scanf("%d %d", &r.p2.x, &r.p2.y);

	w = r.p2.x - r.p1.x;
	h = r.p2.y - r.p1.x;

	area = w * h;
	peri = 2 * (w + h);

	printf("면적은 %d이고 둘레는 %d입니다.", area, peri);

	return 0;
}
*/

/*ex4 array_of_struct
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student {
	int id;
	char name[10];
	double grade;
};

int main(void)
{
	struct student s[3];

	for (int i = 0; i < 3; i++)
	{
		printf("학번을 입력하시오: ");
		scanf("%d", &s[i].id);

		printf("이름을 입력하시오: ");
		scanf("%s", s[i].name);

		printf("학점을 입력하시오: ");
		scanf("%lf", &s[i].grade);
	}

	for (int j = 0; j < 3; j++)
	{
		printf("이름: %s, 학점: %lf\n", s[j].name, s[j].grade);
	}

	return 0;
}
*/

/*ex5 pointer_to_st
#include <stdio.h>

struct student {
	int id;
	char name[10];
	double grade;
};

int main(void)
{
	struct student s = {20190001, "홍길동", 4.3};
	struct student* p;

	p = &s;

	printf("학번=%d 이름 =%s 학점 %lf\n", s.id, s.name, s.grade);
	printf("학번=%d 이름 =%s 학점 %lf\n", (*p).id, (*p).name, (*p).grade);
	printf("학번=%d 이름 =%s 학점 %lf\n", p->id, p->name, p->grade);

	return 0;
}
*/

/*ex6 st_pointer
#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};

struct student {
	int id;
	char name[10];
	double grade;
	struct date *dob;
};

int main(void)
{
	struct date d = {1990, 3, 20};
	struct student s = {20190001,"Kim", 4.3};

	s.dob = &d;

	printf("학번: %d\n", s.id);
	printf("이름: %s\n", s.name);
	printf("학점: %lf\n", s.grade);
	printf("생년월일: %d년 %d월 %d일\n", s.dob->year, s.dob->month, s.dob->day);

	return 0;
}
*/

#include <stdio.h>

struct vector {
	float x;
	float y;
};

struct vector get_vector_sum(struct vector a, struct vector b)
{
	struct vector result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;

	return result;
}

int main(void)
{

	struct vector a = {2.0, 3.0};
	struct vector b = { 5.0, 6.0 };
	struct vector sum;

	sum = get_vector_sum(a, b);
	printf("벡터의 합은 (%lf, %lf)입니다.\n", sum.x, sum.y);

	return 0;
}



