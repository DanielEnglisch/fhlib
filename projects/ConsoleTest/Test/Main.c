#include <stdio.h>
#include "consolelib.h"

void main()
{
	setcolor(YELLOW);
	cursoroff();

	for (int i = 0; i < 20; i++)
		printf("*");
	printf("\n");
	for (int i = 1; i < 4; i++)
	{
		printf("*");
		gotoxy(20, i);
		printf("*");
		printf("\n");
	}
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy (5, 2);
	setcolor(LIGHTGREEN);
	printf("Hello World");
	getchar();
}

