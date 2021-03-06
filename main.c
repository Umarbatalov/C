#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define IN 1;
#define OUT 0;

int getMax(const int* arr)
{
    int res = 0;

    for (int i = 0; i < 2; i++) {
        if (arr[i] > res) {
            res = arr[i];
        }
    }

    return res;
}

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

    printf(
        "Space count: %d, tab count: %d, string end count: %d\n",
        spaceCount,
        tabCount,
        strEndCount
    );
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

// 1.13. Напишите программу для вывода гистограммы длин слов
// во входном потоке. Построить гистрограмму с горизонтальнами рядами довольно легко,
// а вот с вертикальными столбцами труднее.
void exercise_1_13()
{
    int c, count, current;

    int stats[2];

    count = 0;
    current = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (count > 0) {
                stats[current] = count;
            }

            ++current;
            count = 0;
        } else {
            ++count;
        }
    }

    int max = getMax(stats);
    int minNumber;

    if (stats[0] == max) {
        minNumber = stats[1];
    } else {
        minNumber = stats[0];
    }

    int maxPercent = (max * 100) / max;
    int minPercent = (minNumber * 100) / max;

    int firstCharCount = maxPercent / 10;
    int secondCharCount = minPercent / 10;

    char bufMin[256];
    char bufMax[256];

    strcpy(bufMin, "");
    strcpy(bufMax, "");

    for (int i = 0; i < firstCharCount; i++) {
        strcat(bufMax, "-");
    }

    for (int i = 0; i < secondCharCount; i++) {
        strcat(bufMin, "-");
    }

    puts(bufMin);
    puts(bufMax);
    printf("----%d----%d\n", max / 2, max);
}

int main()
{
    exercise_1_13();
    return 0;
}
