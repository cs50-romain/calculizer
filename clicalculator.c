#include <curses.h>
#include <stdio.h>
#include <ncurses.h>

#define MIN_POSITION 1
#define MAX_POSITION 3

int multiply(int num1, int num2) {
	return num1 * num2;
}

int add(int num1, int num2) {
	return num1 * num2;
}

void pointArrow(int realposition, int position) {
	if (realposition == position) {
		printw(" ==> [X] ");
	} else {
		printw("     [ ] ");
	}
	refresh();
}

void menu() {
	//system("cls");
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

	int position = 1;
	int keypressed = 0;

	refresh();

	while (keypressed != 10) {
		clear();
		pointArrow(1, position); printw("Multiply\n");
		pointArrow(2, position); printw("Add\n");
		pointArrow(3, position); printw("Substract\n");

		//keypressed = getch();
		keypressed = getch();

		if (keypressed == KEY_UP && position > MIN_POSITION) {
			position--;
		} else if (keypressed == KEY_DOWN && position < MAX_POSITION) {
			position++;
		} else {
			position = position;
		}
		refresh();
	}
	endwin();
}

int main(void) {
	printf("HERE\n");
	menu();
	printf("DONE\n");
	return 0;
}

/*
*	int operation, num1, num2;
	printf("Select operation (0=* or 1=+ or 2=-): ");
	scanf("%d", &operation);
	printf("Number 1: ");
	scanf("%d", &num1);
	printf("Number 2: ");
	scanf("%d", &num2);

	int result;
	if (operation == 0 ) {
		result = multiply(num1, num2);
	} else if (operation == 1) {
		result = add(num1, num2);
	} else {
		result = num1 - num2;
	}
	printf("Result = %d\n", result);

*/
