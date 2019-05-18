#include<stdlib.h>
#include<ncurses.h>
#include<locale.h>
#define LEN 9


#define EMPTY 0
#define OU 1
#define HU 2
#define KYOU 3
#define KEI 4
#define GIN 5
#define KIN 6
#define HISYA 8
#define KAKU 7
#define E -1
#define EOU E*OU
#define EHU E*HU
#define EKYOU E*KYOU
#define EKEI E*KEI
#define EGIN E*GIN
#define EKIN E*KIN
#define EHISYA E*HISYA
#define EKAKU E*KAKU
void initField (int f[LEN][LEN]){

	int x, y;

	for (y = 0; y < LEN; y++){
		for (x = 0; x < LEN; x++) {
			f[y][x] = EMPTY;
		}
	}
	f[0][0] = f[0][8] = EKYOU;
	f[0][1] = f[0][7] = EKEI;
	f[0][2] = f[0][6] = EGIN;
	f[0][3] = f[0][5] = EKIN;
	f[0][4] = EOU;
	f[1][1] = EHISYA;
	f[1][7] = EKAKU;
	for (x = 0; x < LEN; x ++) {
		f[2][x] = EHU;
		f[6][x] = HU;
	}
	f[8][0] = f[8][8] = KYOU;
	f[8][1] = f[8][7] = KEI;
	f[8][2] = f[8][6] = GIN;
	f[8][3] = f[8][5] = KIN;
	f[8][4] = OU;
	f[7][1] = KAKU;
	f[7][7] = HISYA;
}
void printField(int f[LEN][LEN]){
	int x,y;
	erase();
	for (x = 0; x < LEN; x++) printw(x ? "  %d " :"     %d "  ,x);

	printw("\n");
	printw("   +---+---+---+---+---+---+---+---+---+\n");
	for (y = 0; y < LEN; y++){
		printw(" %d |", y);
		for(x = 0; x < LEN; x++){
			switch(f[y][x]){
				case EMPTY:
					printw("   |");
					break;
				case EOU:
					printw("E王|");
					break;
				case EHU:
					printw("E歩|");
					break;
				case EKYOU:
					printw("E香|");
					break;
				case EKEI:
					printw("E桂|");
					break;
				case EGIN:
					printw("E銀|");
					break;
				case EKIN:
					printw("E金|");
					break;
				case EHISYA:
					printw("E飛|");
					break;
				case EKAKU:
					printw("E角|");
					break;
				case OU:
					printw(" 王|");
					break;
				case HU:
					printw(" 歩|");
					break;
				case KYOU:
					printw(" 香|");
					break;
				case KEI:
					printw(" 桂|");
					break;
				case GIN:
					printw(" 銀|");
					break;
				case KIN:
					printw(" 金|");
					break;
				case HISYA:
					printw(" 飛|");
					break;
				case KAKU:
					printw(" 角|");
					break;


			}
			//	printw(x ? " %d  |" : " %d  |", f[y][x]);

		}

		printw("\n");
		printw("   +---+---+---+---+---+---+---+---+---+\n");
	}
	refresh();
	/*for (y = 0; y < LEN; y++){
	  for(x = 0; x < LEN; x++){

	  }
	  }*/
	//	printf("\n");
	//	printf("%d",f[0][0]);
}
void mycontrol (int f[LEN][LEN]){
	int w,i;
	int x,y;	
	int o;
		printw("1Pのターンです\n")
		printw("動かしたい駒のy座標を選べ");
		scanw("%d",&y);
		printw("動かしたい駒のx座標を選べ");
		scanw("%d",&x);

		if (y < 0 || y > 8|| x < 0 || x > 0) {
			printw("そこは盤面の外です続けるなら'o'を押せ");
			scanw("%d", &o);
			printField(f);
			continue;
		}
		else if(f[y][x] == HU) {
			//clear();
			//printField(f);
			printw("移動させたいy座標を選べ");
			scanw("%d",&w);
			printw("移動させたいx座標を選べ");
			scanw("%d",&i);
			if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] > 0) f[w][i] = HU;
			
			else if (y-w == 1 && x-i == 0 && f[w][i] == 0) f[w][i] = HU;
			else if (f[w][i] > 0){
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d",&o);
				printField(f);
				continue;
			}
		}
		else if(f[y][x] == OU) {
			printw("移動させたいy座標を選べ");
			scanw("%d",&w);
			printw("移動させたいx座標を選べ");
			scanw("%d",&i);
			if (f[w][i] > 0){
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d", &o);
				printField(f);
				continue;
			}
			else if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;
			
			else if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] < 0) f[y][x] = 0;
			
			else if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] > 0) f[w][i] = OU;

			else if (y-w == 1 && x-i == 0 && f[w][i] == 0) f[w][i] = OU;
			
			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] =0;

			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] > 0) f[w][i]  = OU;
			
			else if (y-w == 1 && x-i == 1 && f[w][i] == 0) f[w][i] = OU;
		
			else if (y-w == 1 && x-i == -1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == 1 && x-i == -1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;
				
			else if (y-w == 1 && x-i == -1 && f[w][i] + f[y][x] > 0) f[w][i] = OU;

			else if (y-w == 1 && x-i == -1 && f[w][i] == 0) f[w][i] = OU;  
			
			else if (y-w == 0 && x-i == -1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == 0 && x-i == -1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == 0 && x-i == -1 && f[w][i] + f[y][x] > 0) f[w][i] =OU;

			else if (y-w == 0 && x-i == -1 && f[w][i] == 0) f[w][i] = OU;
			
			else if (y-w == 0 && x-i == 1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;
			
			else if (y-w == 0 && x-i == 1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == 0 && x-i == 1 && f[w][i] + f[y][x] > 0) f[w][i] = OU;

			else if (y-w == 0 && x-i == 1 && f[w][i] == 0) f[w][i] = OU; 
		
			else if (y-w == -1 && x-i == -1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == -1 && x-i == -1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;
			
			else if (y-w == -1 && x-i == -1 && f[w][i] + f[y][x] > 0) f[w][i] = OU;

			else if (y-w == -1 && x-i == -1 && f[w][i] == 0) f[w][i] = OU;
			
			else if (y-w == -1 && x-i == 1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == -1 && x-i == 1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == -1 && x-i == 1 && f[w][i] + f[y][x] > 0) f[w][i] = OU;

			else if (y-w == -1 && x-i == 1 && f[w][i] == 0) f[w][i] = OU;

			else if (y-w == -1 && x-i == 0 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;
			
			else if (y-w == -1 && x-i == 0 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == -1 && x-i == 0 && f[w][i] + f[y][x] > 0) f[w][i] = OU;

			else if (y-w == -1 && x-i == 0 && f[w][i] == 0) f[w][i] = OU;
		
			else  {
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d", &o);
				printField(f);
				continue;
			}


		}

		else if(f[y][x] == GIN){	
			printw("移動させたいy座標を選べ");
			scanw("%d",&w);
			printw("移動させたいx座標を選べ");
			scanw("%d",&i);
			
			if (f[w][i] > 0){
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d", &o);
				printField(f);
				continue;
			}
			else if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;
			
			else if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == 1 && x-i == 0 && f[w][i] + f[y][x] > 0) f[w][i] = GIN;

			else if (y-w == 1 && x-i == 0 && f[w][i] == 0) f[w][i] = GIN; 

			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] > 0) f[w][i] = GIN;

			else if (y-w == 1 && x-i == 1 && f[w][i] == 0) f[w][i] = GIN; 

			else if (y-w == 1 && x-i == -1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == 1 && x-i == -1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;
			
			else if (y-w == 1 && x-i == -1 && f[w][i] + f[y][x] > 0) f[w][i] = GIN;

			else if (y-w == 1 && x-i == -1 && f[w][i] == 0) f[w][i] = GIN;

			else if (y-w == -1 && x-i == -1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == -1 && x-i == -1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == -1 && x-i == -1 && f[w][i] + f[y][x] > 0) f[w][i] = GIN;
			
			else if (y-w == -1 && x-i == -1 && f[w][i] == 0) f[w][i] = GIN;
			
			else if (y-w == -1 && x-i == 1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;
			
			else if (y-w == -1 && x-i == 1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == -1 && x-i == 1 && f[w][i] + f[y][x] > 0) f[w][i] = GIN;

			else if (y-w == -1 && x-i == 1 && f[w][i] == 0) f[w][i] = GIN;

			else {
				printw("そこには置けません続けるなら'o'を押してください");
				scanw("%d", &o);
				printField(f);
				continue;
			}
		      	
			else if (f[w][i] > 0){
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d", &o);
				printField(f);
				continue;
			}	

		}
		else if(f[y][x] == KIN){
			printw("移動させたいy座標を選べ");
			scanw("%d", &w);
			printw("移動させたいx座標を選べ");
			scanw("%d", &i);
			if (f[w][i] > 0){
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d", &o);
				printField(f);
				continue;
			}
			else if (y-w == 1 && x-i == 0 && f[w][i] == 0) f[w][i] = KIN;

			else if(y-w == 1 && x-i == 0 && f[w][i] + f[y][x] == 0 ) f[w][i] = f[y][x] = 0;
			
			else if (y-x == 1 && x-i == 0 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-x == 1 && x-i == 0 && f[w][i] + f[y][x] > 0) f[w][i] = KIN;

			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == 1 && x-i == 1 && f[w][i] + f[y][x] > 0) f[w][i] = KIN;	

			else if (y-w == 1 && x-i == 1 && f[w][i] == 0) f[w][i] = KIN;

                        else if(y-w == 1 && x-i ==-1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;

			else if (y-w == 1 && x-i == -1 && f[w][i] + f[y][x] < 0) f[y][x] = 0; 

		        else if (y-w == 1 && x-i == -1 && f[w][i] + f[y][x] > 0) f[w][i] = KIN;
	 
	                else if (y-w == 1 && x-i == -1 && f[w][i] == 0) f[w][i] = KIN;

			else if (y-w == -1 && x-i == 0 && f[w][i] == 0) f[w][i] = KIN;
			
			else if (y-w == -1 && x-i == 0 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;
	
			else if (y-w == -1 && x-i == 0 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == -1 && x-i == 0 && f[w][i] + f[y][x] > 0 ) f[w][i] = KIN;
		}
		else if (f[y][x] == KEI){
			printw("移動させたいy座標を選べ");
			scanw("%d", &w);
			printw("移動させたいx座標を選べ");
			scanw("%d", &i);
			if (f[w][i] > 0){
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d", &o);
				printField(f);
				continue;
			}
			else if (y-w == 2 && x-i == -1 && f[w][i] == 0) f[w][i] = KEI;

			else if (y-w == 2 && x-i == -1 && f[w][i] + f[y][x] ==  0) f[w][i] = f[y][x] = 0;
	
			else if (y-w == 2 && x-i == -1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;

			else if (y-w == 2 && x-i == -1 && f[w][i] + f[y][x] > 0) f[w][i] = KEI;

			else if (y-w == 2 && x-i == 1 && f[w][i] == 0) f[w][i] = KEI;

			else if (y-w == 2 && x-i == 1 && f[w][i] + f[y][x] == 0) f[w][i] = f[y][x] = 0;
			
			else if (y-w == 2 && x-i == 1 && f[w][i] + f[y][x] < 0) f[y][x] = 0;
		
			else if (y-w == 2 && x-i == 1 && f[w][i] + f[y][x] > 0) f[w][i] = KEI;
		}
		else if (f[y][x] == KYOU){
				printw("移動させたいy座標を選べ");
				scanw("%d", &w);
				printw("移動させたいx座標を選べ");
				scanw("%d", &i);
			if (!x-i == 0){
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d", &o);
				printField(f);
				continue;
			}
			else if (f[w][i] > 0) {
				printw("そこには置けません続けるなら'o'を押せ");
				scanw("%d", &o);
				printField(f);
				continue;
			}
			for (y; y < w ; w++){
				if (f[y][x] == 0) continue;
				else if (f[y][x] > 0){
					printw("そこには置けません続けるなら'o'を押せ");
					scanw("%d", &o);
					break;
				}
			}
	
		}
		else if (f[y][x] == HISYA){

		}
		else if (f[y][x] == KAKU){

		}
		
	
	f[y][x] = 0;

	printField(f);
	
}
void enemycontrol(f[LEN][LEN]){

}


void GameEnd(int f[LEN][LEN]){
	int x,y;
	for (y = 0; y < LEN ; y++){
		for (x = 0; x < LEN; x++){
		if (!f[y][x] == 1) continue;
		else if (!f[y][x] == -1) continue;
		
		
	}
	}
	
}
int main (void){
	int c;
	int field[LEN][LEN];
	setlocale(LC_ALL, "");
	initscr();	// 端末制御を開始
	cbreak();	// 入力バッファは使うなよ
	curs_set(0);	// カーソルは表示するなよ
	timeout(-1);	// キー入力は来るまで待てよ

	initField(field);

	printField(field);	

	while {

	mycontrol(field);
	GameEnd(field);
	enemycontrol(field);
	GameEnd(field);
	}
	c = getchar();
	putchar (c);
	endwin();
	return 0;
}

