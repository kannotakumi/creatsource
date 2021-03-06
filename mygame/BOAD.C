#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#define LEN 9


#define EMPTY 0
#define OU 1
#define HU 2
#define KYOU 3
#define KEI 3
#define GIN 4
#define KIN 4
#define HISY 5
#define KAKU 5
#define E -1
#define EOU E*OU
#define EHU E*HU
#define EKYOU E*KYOU
#define EKEI E*KEI
#define EGIN E*GIN
#define EKIN E*KIN
#define EHISY E*HISY
#define EKAKU E*KAKU

void initField (char f[LEN][LEN]){
	int x, y;

	for (y = 0; y < LEN; y++){
		for (x = 0; x < LEN; x++) {
			f[y][x] = ' ';
		}
	}
	f[0][0] = f[0][8] = EKYOU;
	f[0][1] = f[0][7] = EKEI;
	f[0][2] = f[0][6] = EGIN;
	f[0][3] = f[0][5] = EKIN;
	f[0][4] = EOU;
	for (x = 0; x < LEN; x ++) {
		f[2][x] = EHU;
		f[6][x] = HU;
	}
	f[8][0] = f[8][8] = KYOU;
	f[8][1] = f[8][7] = KEI;
	f[8][2] = f[8][6] = GIN;
	f[8][3] = f[8][5] = KIN;
	f[8][4] = OU;
}
void printField(char f[LEN][LEN]){
	int x,y;
	for (x = 0; x < LEN; x++) printf(x ? "  %d " : "     %d ", x);
		printf("\n");
		printf("   +---+---+---+---+---+---+---+---+---+ \n");

		for (y = 0; y < LEN; y++){
			printf(" %d |", y);
			for (x = 0; x < LEN; x++){
				
				printf(x ? " %c  |" : " %c  |", f[y][x]);
			}
			
			printf("\n");
			printf("   +---+---+---+---+---+---+---+---+---+\n");
		}
/*	for (y = 0; y < LEN; y++){
		for(x = 0; x < LEN; x++){
		
		}
	}
		printf("\n");
		printf("%d",f[0][0]);*/
}
int main (void){
	int c;
	char field[LEN][LEN];

	initField(field);

	printField (field);

	c = getchar();
	putchar (c);
	return 0;
}

