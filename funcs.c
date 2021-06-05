#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global variables
int length;
int bend_no;
int len;
char key;
int life;

//User-defined variables
struct coordinate {
	int x;
	int y;
	int direction;
};
typedef struct coordinate coordinate;
coordinate head, food, bend[500], body[30];



//Introduction
void Introduction(void) {
	//GotoXY(10,12) //dont know yet
	printf("\t\tWELCOME to the Mini Snake Game !!\n");
	printf("\t\t\t\t\t\t(Press ENTER to continue)\n\n");
	getchar();
	//system("clear");
	printf("\tGame instructions:\n\n");
	printf("-> Use arrow keys to move the snake.\n\n");
	printf("-> You will be provided food at several coordinates of the screen which you have to eat.\n");
	printf("   Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n");
	printf("-> You are provided with three lives.\n");
	printf("   Your life will decrease as you hit the wall or snake's body.\n\n");
	printf("-> You can pause the game in its middle by pressing any key.\n");
	printf("   To continue the paused game press any other key once again.\n\n");
	printf("-> If you want to exit press esc.\n\n");
	printf("\n\nPress ENTER to play the game. GOOD LUCK :)\n");
	if(getchar()==27)
		exit(0);
}



//Change cursor position
void gotoxy(int x, int y) {
	printf("%c[%d;%df", 0x1B, y, x);
}



//Loading the game
void load(void) {
	int r,q;
	gotoxy(36,14);
	printf("loading...");
	gotoxy(30,15);
	for(r=1 ; r<=20 ; r++) {
		for(q=0 ; q<=100000000 ; q++);
		printf("%c", 177);
	}
	printf("\nClick ENTER to continue!!");
	getchar();
}



//Game area
void Border(void) {
	system("clear");
	int i,j,height = 40, width = 40;
	for(i=0 ; i<height ; i++) {
		for(j=0 ; j<width ; j++) {
			if(i==0 || i==width-1 || j==0 || j==height-1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}



//To create food
void Food(void) {
	if(head.x==food.x && head.y==food.y) {
		length++;
		time_t a;
		a = time(0);
		srand(a);
		food.x = rand()%70;
		if(food.x<=10)
			food.x += 11;
		food.y = rand()%30;
		if(food.y<=10)
			food.y += 11;
	}
	else if(food.x == 0) {
		food.x = rand()%70;
		if(food.x <= 10)
			food.x += 11;
		food.y = rand()%30;
		if(food.y <= 10)
			food.y += 11;
	}
}







/*void Move() {
	int a, i;
	do {
		Food();
		fflush(stdin);
		len = 0;
		for(i=0 ; i<30 ; i++) {
			body[i].x = 0;
			body[i].y = 0;
			if(i==length)
				break;          //-------
		}
		Delay(length);
		Boarder();
		if(head.direction==RIGHT)           // WORK
			Right();
		else if(head.direction==LEFT)
			Left();
		else if(head.direction==DOWN)
			Down();
		else if(head.direction==UP)                 // IN
			Up();
		ExitGame();
	}
	while(!kbhit());
	a = getchar();
	if(a==27) {
		system("clear");
		exit(0);
	}
	key = getchar();
	if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN)) {
		bend_no++;
		bend[bend_no] = head;
		head.direction = key;
		if(key==UP)
			head.y--;
		if(key==DOWN)
			head.y++;
		if(key==RIGHT)
			head.x++;
		if(key==LEFT)                                   // PROGRESS
			head.x--;
		Move();
	}
	else if(key==27) {
		system("clear");
		exit(0);                                                        // ------------
	}
	else {
		printf("\a");
		Move();
	}
}*/

/*void GotoXY(int x, int y) {
	HANDLE a;
	COORD b;
	fflush(stdout);          --------WORK IN PROGRESS------
	b.X = x;
	b.Y = y;
	a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a,b);
}*/

/*int Score(void) {
	int score;
	//GotoXY(20,8);
	score = length - 5;
	printf("SCORE : %d\n",(length - 5));      ------KINDA WORKS------
	score = length - 5;
	//GotoXY(50,8);
	printf("Life : %d\n", life);
	return score;
}*/
