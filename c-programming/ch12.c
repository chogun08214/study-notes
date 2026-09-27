/*ex1 string1
#include <stdio.h>

int main(void)
{
	int i = 0;
	char str[4];

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';

	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i++;
	}

	return 0;
}
*/

/*ex2 string2
#include <stdio.h>

int main(void)
{
	char str1[16] = "Seoul";
	char str2[3] = { 'i', 's', '\0' };
	char str3[] = "the capital city of Korea.";

	printf("%s %s %s", str1, str2, str3);

	return 0;
}
*/

/*ex3 string3
#include <stdio.h>

int main(void)
{
	int i;

	char src[] = "The worst things to eat before you sleep";
	char dst[100];

	printf("원본 문자열=%s\n", src);

	for (i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
	}

	dst[i] = '\0'; //마지막에 NULL문자를 넣어준다

	printf("복사된 문자열=%s", dst);

	return 0;
}
*/

/*ex4 sting4
#include <stdio.h>

int main(void)
{
	char str[30] = "C language is easy";
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	printf("문자열 \"%s\"의 길이는 %d입니다.", str, i);

	return 0;
}
*/

/*ex5 stringconst
#include <stdio.h>

int main(void)
{
	char* p = "HelloWorld";
	printf("%s \n", p);

	p = "Welcome to C World!";
	printf("%s \n", p);

	p = "Goodbye";
	printf("%s \n", p);

	return 0;
}
*/

/*ex6 getchar
#include <stdio.h>

int main(void)
{
	int ch;

	while ( (ch = getchar()) != EOF)
	{
		putchar(ch);
	}

	return 0;
}
*/

/*ex7 getch
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int ch;

	while ( ( ch = _getch()) != 'q')
	{
		_putch(ch);
	}

	return 0;
}
*/

/*ex8 scanf_printf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char name[100];
	char address[100];

	printf("이름을 입력하시오: ");
	scanf("%s", name);
	printf("현재 거주하는 주소를 입력하시오: ");
	scanf("%s", address);

	printf("이름: %s\n", name);
	printf("주소: %s\n", address);

	return 0;
}
*/

/*ex9 gets
#include <stdio.h>

int main(void)
{
	char name[100];
	char address[100];

	printf("이름을 입력하시오: ");
	gets_s(name, 100);

	printf("현재 거주하는 주소를 입력하시오: ");
	gets_s(address, 100);

	puts(name);
	puts(address);

	return 0;
}
*/

/*ex10
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (islower(c))
		{
			c = toupper(c);
		}

		putchar(c);
	}
}
*/

/*ex11
#include <stdio.h>
#include <ctype.h>

int count_word(char* s)
{
	int word = 0, waiting = 1;

	for (int i = 0; s[i] != NULL; i++)
	{
		if (isalpha(s[i]))
		{
			if (waiting)
			{
				word++;
				waiting = 0;
			}
		}
		else
		{
			waiting = 1;
		}
	}

	return word;
}

int main(void)
{
	int word = count_word("the c book...");
	printf("단어의 개수: %d\n", word);

	return 0;
}
*/

/*ex12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[80];

	strcpy(string, "Hello world from ");
	strcat(string, "strcpy ");
	strcat(string, "and ");
	strcat(string, "strcat!");

	printf("string = %s", string);

	return 0;
}
*/

/*ex13
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80];
	char str2[80];
	int result;

	printf("첫번째 단어를 입력하시오: ");
	scanf("%s", str1);

	printf("두번째 단어를 입력하시오: ");
	scanf("%s", str2);

	result = strcmp(str1, str2);

	if (result < 0)
	{
		printf("%s가 %s보다 앞에있습니다.\n", str1, str2);
	}
	else if (result == 0)
	{
		printf("%s가 %s롸 같습니다.\n", str1, str2);
	}
	else if (result > 0)
	{
		printf("%s가 %s보다 뒤에 있습니다.\n", str1, str2);
	}

	return 0;
}
*/

/*ex14 strstr
#include <stdio.h>
#include <string.h>

int main(void)
{
	char sentence[] = "A joy that's shared is a joy made double";
	char search[] = "joy";

	char* p;
	int location;

	p = strstr(sentence, search);

	location = (int)(p - sentence);

	if (p != NULL)
	{
		printf("%s에서 첫번째 %s가 %d에서 발견되었음\n", sentence, search, location);
	}
	else
	{
		printf("%s가 발견되지 않았음\n", search);
	}

	return 0;
}
*/

/*ex15 strtok
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[] = "Man is immortal, because he has a soul";
char seps[] = " ,\t\n";
char* token;

int main(void)
{
	token = strtok(s, seps);

	while (token != NULL)
	{
		printf("토큰: %s\n", token);
		token = strtok(NULL, seps);
	}

	return 0;
}
*/

/*16 sscanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char s[] = "100";
	int value;

	sscanf(s, "%d", &value);
	printf("%d \n", value);
	value++;

	sprintf(s, "%d", value);
	printf("%s \n", s);
	return 0;
}
*/

/*ex17 sprintf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char filename[100];
	char s[100];
	int i;

	for (int i = 0; i < 6; i++)
	{
		strcpy(filename, "image");
		sprintf(s, "%d", i);
		strcat(filename, s);
		strcat(filename, ".jpg");
		printf("%s \n", filename);
	}

	return 0;
}
*/

/*ex18 atoi
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char s1[] = "100";
	char s2[] = "12.93";
	char buffer[100];

	int i;
	double d;
	double result;

	i = atoi(s1);
	d = atof(s2);

	result = i + d;

	sprintf(buffer, "%f", result);
	printf("연산 결과는 %s입니다.\n", buffer);

	return 0;
}
*/

/**ex19 stringarray1
#include <stdio.h>

int main(void)
{
	char menu[5][10] = {
		"init",
		"open",
		"close",
		"read",
		"write"
	};

	for (int i = 0; i < 5; i++)
	{
		printf("%d 번째 메뉴: %s \n", i, menu[i]);
	}

	return 0;
}
*/

/*ex20 stringarray2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int fruits[3][20];

	for (int i = 0; i < 3; i++)
	{
		printf("과일 이름을 입력하시오: ");
		scanf("%s", fruits[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 과일: %s\n", i, fruits[i]);
	}

	return 0;
}
*/

/*ex21 dic
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define WORD 5

int main(void)
{
	int index;

	char dic[WORD][2][30] = {
		{"book", '책'},
		{"boy", "소년"},
		{"computer", "컴퓨터"},
		{"language", "언어"},
		{"rain", "비"}
	};

	char word[30];

	printf("단어를 입력하시오: ");
	scanf("%s", word);

	index = 0;

	for (int i = 0; i < WORD; i++)
	{
		if (strcmp(dic[index][0], word) == 0)
		{
			printf("%s: %s\n", word, dic[index][1]);
			return 0;
		}
		index++;
	}

	printf("사전에서 발견되지 않았습니다.\n");

	return 0;
}
*/

/*ex22 encrypt
#include <stdio.h>

void encrypt(char cipher[], int shift)
{
	int i = 0;

	while (cipher[i] != '\0')
	{
		if (cipher[i] >= 'A' && cipher[i] <= 'z')
		{
			cipher[i] += shift;

			if (cipher[i] > 'z')
			{
				cipher[i] -= 26;
			}
		}
		i++;
	}
	printf("암호화된 문자열: %s \n", cipher);
}

int main(void)
{
	char cipher[50];
	int shift = 3;

	printf("문자열을 입력하시오: ");
	gets_s(cipher, 50);
	encrypt(cipher, shift);

	return 0;
}
*/

/*ex23 hangman
#include <stdio.h>
#include <string.h>

int check(char s[], char a[], char ch)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ch)
		{
			a[i] = ch;
		}
	}

	if (strcmp(s, a) == 0) return 1;
	else return 0;
}

int main(void)
{
	char solution[100] = "meet at midnight";
	char answer[100] = "____ __ ________";
	char ch;

	while (1)
	{
		printf("문자열을 입력하시오: %s \n", answer);
		printf("글자를 추측하시오: ");
		ch = getchar();

		if (check(solution, answer, ch) == 1)
		{
			break;
		}
		getchar();
	}

	return 0;
}
*/

/*test1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char word;

	printf("문자를 입력하시오: ");
	scanf("%c", &word);

	printf("아스키 코드값 = %d", word);

	return 0;
}
*/

/*test2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void space_delete(char* str)
{
	for (int i = 0; str[i] != NULL; i++)
	{
		if (str[i] != ' ')
		{
			printf("%c", str[i]);
		}
		else if (str[i] == ' ')
		{
			continue;
		}
	}
	return;
}

int main(void)
{
	char str[100];

	printf("공백 문자가 있는 문자열을 입력하시오: ");
	gets_s(str, 100);

	space_delete(str);

	return 0;
}
*/

/*test3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int str_chr(char* s, int c)
{
	int count = 0;

	for (int i = 0; s[i] != NULL; i++)
	{
		if (s[i] == c)
		{
			count++;
		}
	}

	return count;
}

int main(void)
{
	char str[100];
	char word;
	int count;

	printf("문자열을 입력하시오: ");
	gets_s(str, 100);

	printf("개수를 셀 문자를 입력하시오: ");
	scanf("%c", &word);

	printf("%c의 개수: %d", word, str_chr(str, (int)word));

	return 0;
}
*/

/*test4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int str_chr(char* s, int c)
{
	int count = 0;

	for (int i = 0; s[i] != NULL; i++)
	{
		if (s[i] == c)
		{
			count++;
		}
	}

	return count;
}

void count_str(char *str)
{
	for (int i = 'a'; i <= 'z'; i++)
	{
		printf("%c: %d\n", i, str_chr(str, i));
	}
}

int main(void)
{
	char str[100];

	printf("문자열을 입력하시오: ");
	gets_s(str, 100);

	count_str(str);

	return 0;
}
*/

/*test5
#include <stdio.h>

int main(void)
{
	char ch = 0;

	while (ch != '.')
	{

		printf("문자를 입력하시오: ");
		
		ch = getchar();

		if (islower(ch) != 0)
		{
			ch = toupper(ch);
		}
		else if (isupper(ch) != 0)
		{
			ch = tolower(ch);
		}

		putchar(ch);

		printf("\n");
	}

	return 0;
}
*/

/*test6
#include <stdio.h>

void str_upper(char* str)
{
	for (int i = 0; str[i] != NULL; i++)
	{
		str[i] = toupper(str[i]);
	}
}

int main(void)
{
	char str[100];

	printf("문자열을 입력하시오: ");
	gets_s(str, 100);;

	str_upper(str);

	printf("변환된 문자열: ");
	puts(str);


	return 0;
}
*/

/*test7
#include <stdio.h>
#include <string.h>
#include <string.h>

int get_response(char* prompt)
{
	char* y[2] = { "yes", "ok" };

	tolower(prompt);

	for (int i = 0; i < 2; i++)
	{
		if (strcmp(prompt, y[i]) == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int main(void)
{
	char answer[100];

	printf("게임을 하시겠습니까");
	gets_s(answer, 100);

	if (get_response(answer) == 1)
	{
		printf("긍정적인 답변");
	}
	else if(get_response(answer) == 0)
	{
		printf("부정적인 답변");
	}

	return 0;
}
*/

/*test8
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	int count = 0;

	printf("문자열을 입력하시오: ");
	gets_s(str, 100);

	char* token = strtok(str, " ");

	while (token != NULL)
	{
		count++;

		token = strtok(NULL, " ");
	}

	printf("단어의 수는 %d입니다.", count);

	return 0;
}
*/

/*test9
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	char ch[100];

	printf("텍스트를 입력하세요: ");
	gets_s(ch, 100);

	if (ch[0] >= 'a' && ch[0] <= 'z')
	{
		ch[0] = ch[0] - 32;
	}
		

	if (ch[strlen(ch) - 1] != '.')
	{
		ch[strlen(ch) + 1] = NULL;
		ch[strlen(ch)] = '.';
	}


	printf("수정된 텍스트: ");
	puts(ch);

	return 0;
}
*/

/*ㅅㄷㄴㅅ10
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str[100];

	printf("문자열을 입력하시오: ");
	gets_s(str, 100);

	int length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		str[i] = tolower(str);
	}

	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (str[i] == str[length - 1])
		{
			count++;
		}
	}

	if (count == length)
	{
		printf("회문입니다.");
	}
	else
	{
		printf("회문이 아닙니다.");
	}

	return 0;
}
*/

/*test 11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	int count = 1;
	char* copy[10];

	printf("문자열을 입력하시오: ");
	gets_s(str, 100);

	char* p = strtok(str, " ");
	copy[count - 1] = p;

	while (p != NULL)
	{
		p = strtok(NULL, " ");
		count++;
		copy[count - 1] = p;
	}

	for (int i = count - 1; i > 0; i--)
	{
		printf("%s ", copy[i - 1]);
	}

	return 0;
}
*/

/*test12
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
	char name[100];
	int count = 1;
	char *copy[10];

	printf("성과 이름을 대문자로 입력하시오: ");
	gets_s(name, 100);

	for (int i = 0; name[i] != NULL; i++)
	{
		name[i] = tolower(name[i]);
	}

	char* token = strtok(name, " ");
	copy[count - 1] = token;

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		count++;
		copy[count - 1] = token;
	}

	for (int i = count - 1; i > 0; i--)
	{
		printf("%s ", copy[i - 1]);
	}

	return 0;
}
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	int count = 0;

	printf("문자열을 입력하시오: ");
	gets_s(str, 100);

	char* token = strtok(str, ".,");

	while (token != NULL)
	{
		token = strtok(NULL, ",.");
		count++;
	}

	printf("구두점의 개수는  %d입니다", count);

	return 0;
}
*/

/*test14
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[80];
	char str1[10];
	char str2[10];
	char* result[10];
	
	int n = 0;

	printf("문자열을 입력하시오: ");
	gets_s(str, 80);

	printf("찾을 문자열: ");
	gets_s(str1, 10);

	printf("바꿀 문자열: ");
	gets_s(str2, 10);

	char* p = strtok(str, " ");
	result[n] = p;

	while (p != NULL)
	{
		n++;
		p = strtok(NULL, " ");
		result[n] = p;
	}

	for (int i = 0; i < n; i++)
	{
		if (strcmp(str1, result[i]) == 0)
		{
			result[i] = str2;
		}
	}

	printf("수정된 문자열: ");

	for (int i = 0; i < n; i++)
	{
		printf("%s ", result[i]);
	}
	

	return 0;
}
*/

/*test15
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[10];
	int a = 0, b = 0;

	int add;
	int minus;
	int multi;
	int divide;

	printf("연산을 입력하시오: ");
	scanf("%s %d %d", str, &a, &b);

	if (strcmp(str, "add") == 0)
	{
		add = a + b;
		printf("연산의 결과: %d", add);
	}
	else if (strcmp(str, "sub") == 0)
	{
		minus = a - b;
		printf("연산의 결과: %d", minus);
	}
	else if (strcmp(str, "mul") == 0)
	{
		multi = a * b;
		printf("연산의 결과: %d", multi);
	}
	else if (strcmp(str, "div") == 0)
	{
		divide = a / b;
		printf("연산의 결과: %d", divide);
	}


	return 0;
}
*/

/*test16
#include <stdio.h>

int main(void)
{
	char str[100];
	char* p;

	printf("광고하고 싶은 텍스트를 입력하시오: ");
	gets_s(str, 100);

	p = str;

	puts(str);
	puts(str + 1);
	puts(str + 2);

	return 0;
}
*/


