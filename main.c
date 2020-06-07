#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void die(char* message)
{
	printf("%s\n", message);
	exit(0);
}

void dieNum(int message)
{
	printf("%d\n", message);
	exit(0);
}

// 1.8. Напишите программу для подсчетов пробелов, знаков табуляции и символов
// конца строки.
void exercise_1_8()
{
	int c;

	int spaceCount = 0;
	int tabCount = 0;
	int strEndCount = 0;

	while ((c = getchar()) != EOF) {
		switch (c) {
			case ' ':
				spaceCount++;
				break;
			case '\t':
				tabCount++;
				break;
			case '\n':
				strEndCount++;
				break;
			default:
				break;
		}
	}

	printf("Space count: %d, tab count: %d, string end count: %d\n", spaceCount,
		tabCount, strEndCount);
}

// 1.9. Напишите программу для копирования входного потока в выходной
// с заменой каждой строки, состоящей из одного или нескольких пробелов, одним
// пробелом.
void exercise_1_9()
{
	int c;
	int spaceCount = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			spaceCount++;
			continue;
		}

		if (spaceCount > 0) {
			putchar(' ');
			spaceCount = 0;
		}

		putchar(c);
	}
}

// 1.10. Напишите программу для копирования входного потока в выходной
// с заменой знаков табуляции на \t, символов возрата назад (Backspace) на \b, а
// обратных косых черт - на \\. Это сделается табуляции и символы возарата легко
// читаемыми в потоке.
void exercise_1_10()
{
	int c;

	while ((c = getchar()) != EOF) {
		switch (c) {
			case '\t':
				putchar('\\');
				putchar('t');
				break;
			case '\\':
				putchar(c);
				putchar(c);
				break;
			case '\b':
				putchar('\\');
				putchar('b');
				break;
			default:
				putchar(c);
				break;
		}
	}
}

int main()
{
	exercise_1_10();
	return 0;
}
