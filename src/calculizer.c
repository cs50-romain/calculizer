#include <curses.h>
#include <stdio.h>
#include <ncurses.h>

#define MIN_DOWN_POSITION 0 
#define MAX_UP_POSITION 12

// A string is defined as *char. A char pointer to the beginning character of the string.
// That means you can create an array of char pointers for strings
char *options[] = {"Multiply", "Add\t", "Substract", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
#define OPTIONS_SIZE ((int) (sizeof(options) / sizeof(options[0])))

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
		
		for (int i = 0; i < 3;i++) {
			pointArrow(i, position); printw("%s\t", options[i]);
			pointArrow(i + 3, position); printw("%s\t", options[i+3]);
			pointArrow(i + 6, position); printw("%s\t", options[i+6]);
			pointArrow(i + 9, position); printw("%s\n", options[i+9]);
		}

		// Currently for number 0, as it is in an odd position.
		printw("\t\t\t\t\t"); pointArrow(12, position); printw("%s\n", options[OPTIONS_SIZE - 1]);

		keypressed = getch();

		if (keypressed == KEY_UP && position > MIN_DOWN_POSITION) {
			position--;
		} else if (keypressed == KEY_DOWN && position < MAX_UP_POSITION) {
			position++;
		} else if (keypressed == KEY_RIGHT && position + 3 <= MAX_UP_POSITION) {
			position+=3;
		} else if (keypressed == KEY_LEFT && position - 3 >= MIN_DOWN_POSITION) {
			position = position - 3;
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
