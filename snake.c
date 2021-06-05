#include <stdio.h>
#include <stdlib.h>
#include "head.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

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



int main(void)

{
	char key;
	Introduction();
	system("clear");
	load();
	length=5;
	//head.x=25;
	//head.y=20;
	//head.direction=RIGHT;
	Border();
	Food();
	//life = 3;
	//bend[0] = head;
	//Move();
	return 0;
}

