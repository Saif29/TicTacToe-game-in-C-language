#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>

void table1_();
void table2_();
int start_();
char choice_();
void Single_Player(char);
void Multi_Player();
void gotoxy(int, int);
void p1_turn();
void p2_turn();
void p1t();
void p2t();
void compt();
int win_(int[]);
int comp_turn(int[], int[]);
int strong_AI(int[], int[], int);
/*
#define sizex 80
#define sizey 40
#define row (sizey + 1)
#define col (sizex + 1)
*/
int main()
{
	char stop = 'a';
	while (stop != 'x' && stop != 'X')
	{
		system("cls");
		fflush(stdin);
		stop = 'a';
		char b, c;
		while(1)	
		{	
			start_();
			b = choice_();
			system("cls");
			if (b == '1')
			{
				system("cls");
				while(1)	
				{
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEnter Difficulty level\n\t\t\t\t\t\t\t1. Easy\n\t\t\t\t\t\t\t2. Hard");
					c = choice_();
					system("cls");
					if (c == '1')
					{
						break;
					}
					else if(c == '2')
					{
						break;
					}
					else
						continue;
				}
				Single_Player(c);
				break;
			}
			else if (b == '2')
			{
				Multi_Player();
				break;
			}
			else
				continue;
		}
		fflush(stdin);
		printf("\n\n\n\n\n\n\n\nEnter X or x to exit or anything else to play another game!\n");
		stop = getch();
	}
	return 0;
}

int start_()
{
	printf("\n\t\t      __      __  __        __    _____  __     _____    __    _____  __   __    _____  __   __");
	printf("\n\t\t|  | |__ |   |   |  | |\\/| |__      |   |  |      |   | |        |   |__| |        |   |  | |__");
	printf("\n\t\t|/\\| |__ |__ |__ |__| |  | |__      |   |__|      |   | |__      |   |  | |__      |   |__| |__");
	printf("\n\n\t\t\t\t\t\tPROGRAMMED BY SAIF UR REHMAN");
	printf("\n\n\t\t\t\t\t              _____        _ _     _");
	printf("\n\t\t\t\t\t |\\      /|  |       |\\   |  |     |");
	printf("\n\t\t\t\t\t | \\    / |  |_____  | \\  |  |     |");
	printf("\n\t\t\t\t\t |  \\  /  |  |       |  \\ |  |     |");
	printf("\n\t\t\t\t\t_|   \\/   |_ |_____ _|   \\|  |_____|\n");
	printf("\n\n\n\t\t\t\t\t\t1. Single Player\n\t\t\t\t\t\t2. Multi Player\n\n");
}

void table1_()
{
	printf("\n\n\t\t\t\t\t\t _________________\n\t\t\t\t\t\t|1    |2    |3    |\n\t\t\t\t\t\t|     |     |     |\n\t\t\t\t\t\t|_____|_____|_____|\n");
	printf("\t\t\t\t\t\t|4    |5    |6    |\n\t\t\t\t\t\t|     |     |     |\n\t\t\t\t\t\t|_____|_____|_____|\n");
	printf("\t\t\t\t\t\t|7    |8    |9    |\n\t\t\t\t\t\t|     |     |     |\n\t\t\t\t\t\t|_____|_____|_____|\n");
}

void table2_()
{
	printf("\n\t\t\t\t\t\t _________________\n\t\t\t\t\t\t|1    |2    |3    |\n\t\t\t\t\t\t|     |     |     |\n\t\t\t\t\t\t|_____|_____|_____|\n");
	printf("\t\t\t\t\t\t|4    |5    |6    |\n\t\t\t\t\t\t|     |     |     |\n\t\t\t\t\t\t|_____|_____|_____|\n");
	printf("\t\t\t\t\t\t|7    |8    |9    |\n\t\t\t\t\t\t|     |     |     |\n\t\t\t\t\t\t|_____|_____|_____|\n");
}

char choice_()
{
	int a;
	a = getch();
	return a;
}

void Multi_Player()
{
	int win = 0, count = 0;
	int save1[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int save2[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	char p1[20], p2[20], mark;
	printf("\n\n\t\t\t\t\t\t\t\tEnter Names:");
	fflush(stdin);
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//	First save the current color information
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	printf("\n\t\t\t\t\t\tPlayer 1:\t");
	fgets(p1, sizeof(p1), stdin);
//  Set the new color information
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
	fflush(stdin);
	printf("\n\t\t\t\t\t\tPlayer 2:\t");
	fgets(p2, sizeof(p2), stdin);
//	Restore the original colors
	SetConsoleTextAttribute ( h, wOldColorAttrs);
	system("cls");
	gotoxy(4, 1);
	printf("Enter number (1-9) to mark or 'q' to exit.");
	table2_();
	p1t();
	while (win != 1)
	{
		while(1)
		{
			mark = getch();
			if(mark == '1' && (save1[0] == 1 || save2[0] == 1))
			{
				continue;
			}
			if(mark == '2' && (save1[1] == 1 || save2[1] == 1))
			{
				continue;
			}
			if(mark == '3' && (save1[2] == 1 || save2[2] == 1))
			{
				continue;
			}
			if(mark == '4' && (save1[3] == 1 || save2[3] == 1))
			{
				continue;
			}
			if(mark == '5' && (save1[4] == 1 || save2[4] == 1))
			{
				continue;
			}
			if(mark == '6' && (save1[5] == 1 || save2[5] == 1))
			{
				continue;
			}
			if(mark == '7' && (save1[6] == 1 || save2[6] == 1))
			{
				continue;
			}
			if(mark == '8' && (save1[7] == 1 || save2[7] == 1))
			{
				continue;
			}
			if(mark == '9' && (save1[8] == 1 || save2[8] == 1))
			{
				continue;
			}
			else if(mark == '1' || mark == '2' || mark == '3' || mark == '4' || mark == '5' || mark == '6' || mark == '7' || mark == '8' || mark == '9' || mark == 'q')
			{
				break;
			}
		}
		count++;
		switch(mark)
		{
			case '1':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(51, 4);
					p2_turn();
					save2[0] = 1;
					win = win_(save2);
				}
				else
				{	
					p2t();
					gotoxy(51, 4);
					p1_turn();
					save1[0] = 1;
					win = win_(save1);
				}
				break;
			case '2':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(57, 4);
					p2_turn();
					save2[1] = 1;
					win = win_(save2);
				}
				else
				{
					p2t();
					gotoxy(57, 4);
					p1_turn();
					save1[1] = 1;
					win = win_(save1);
				}
				break;
			case '3':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(63, 4);
					p2_turn();
					save2[2] = 1;
					win = win_(save2);
				}
				else
				{
					p2t();
					gotoxy(63, 4);
					p1_turn();
					save1[2] = 1;
					win = win_(save1);
				}
				break;
			case '4':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(51, 7);
					p2_turn();
					save2[3] = 1;
					win = win_(save2);
				}
				else
				{
					p2t();
					gotoxy(51, 7);
					p1_turn();
					save1[3] = 1;
					win = win_(save1);
				}
				break;
			case '5':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(57, 7);
					p2_turn();
					save2[4] = 1;
					win = win_(save2);
				}
				else
				{
					p2t();
					gotoxy(57, 7);
					p1_turn();
					save1[4] = 1;
					win = win_(save1);
				}
				break;
			case '6':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(63, 7);
					p2_turn();
					save2[5] = 1;
					win = win_(save2);
				}
				else
				{
					p2t();
					gotoxy(63, 7);
					p1_turn();
					save1[5] = 1;
					win = win_(save1);
				}
				break;
			case '7':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(51, 10);
					p2_turn();
					save2[6] = 1;
					win = win_(save2);
				}
				else
				{
					p2t();
					gotoxy(51, 10);
					p1_turn();
					save1[6] = 1;
					win = win_(save1);
				}
				break;
			case '8':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(57, 10);
					p2_turn();
					save2[7] = 1;
					win = win_(save2);
				}
				else
				{
					p2t();
					gotoxy(57, 10);
					p1_turn();
					save1[7] = 1;
					win = win_(save1);
				}
				break;
			case '9':
				if (count % 2 == 0)
				{
					p1t();
					gotoxy(63, 10);
					p2_turn();
					save2[8] = 1;
					win = win_(save2);
				}
				else
				{
					p2t();
					gotoxy(63, 10);
					p1_turn();
					save1[8] = 1;
					win = win_(save1);
				}
				break;
		}
		if (count == 9 && win != 1)
		{
			gotoxy(55, 15);
			printf("DRAW GAME!");
			return;
		}
		if (win == 1)
		{
			gotoxy(55, 15);
			if (count % 2 == 0)
				printf("PLAYER 2 --> %s\t\t\t\t\t\t\t\t WINS\n\n\n\n\n\n", p2);
			else
				printf("PLAYER 1 --> %s\t\t\t\t\t\t\t\t WINS\n\n\n\n\n\n", p1);
		}
		if(mark == 'q')
		{
			printf("\n\n\n\n\n\nGame Quited!\n");
			break;
		}
	}
}

void Single_Player(char diff)
{
	int win = 0, count = 0, s;
	int save1[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int save2[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	char p1[20], mark;
	printf("\n\n\t\t\t\t\t\t\t\tEnter Name:");
	fflush(stdin);
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//	First save the current color information
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	printf("\t");
	fgets(p1, sizeof(p1), stdin);
//	Restore the original colors
	SetConsoleTextAttribute ( h, wOldColorAttrs);
	system("cls");
	table1_();
	gotoxy(4, 1);
	printf("Enter number (1-9) to mark or 'q' to exit.");
	while (win != 1)	
	{
		while(1)	
		{
			mark = getch();
			if(mark == '1' && (save1[0] == 1 || save2[0] == 1))
			{
				continue;
			}
			if(mark == '2' && (save1[1] == 1 || save2[1] == 1))
			{
				continue;
			}
			if(mark == '3' && (save1[2] == 1 || save2[2] == 1))
			{
				continue;
			}
			if(mark == '4' && (save1[3] == 1 || save2[3] == 1))
			{
				continue;
			}
			if(mark == '5' && (save1[4] == 1 || save2[4] == 1))
			{
				continue;
			}
			if(mark == '6' && (save1[5] == 1 || save2[5] == 1))
			{
				continue;
			}
			if(mark == '7' && (save1[6] == 1 || save2[6] == 1))
			{
				continue;
			}
			if(mark == '8' && (save1[7] == 1 || save2[7] == 1))
			{
				continue;
			}
			if(mark == '9' && (save1[8] == 1 || save2[8] == 1))
			{
				continue;
			}
			else if(mark == '1' || mark == '2' || mark == '3' || mark == '4' || mark == '5' || mark == '6' || mark == '7' || mark == '8' || mark == '9' || mark == 'q')
			{
				break;
			}
		}
		count++;
		switch(mark)
		{
			case '1':
				gotoxy(51, 4);
				p1_turn();
				save1[0] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);
				break;
			case '2':
				gotoxy(57, 4);
				p1_turn();
				save1[1] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);
				break;
			case '3':
				gotoxy(63, 4);
				p1_turn();
				save1[2] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);
				break;
			case '4':
				gotoxy(51, 7);
				p1_turn();
				save1[3] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);
				break;
			case '5':
				gotoxy(57, 7);
				p1_turn();
				save1[4] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);
				break;
			case '6':
				gotoxy(63, 7);
				p1_turn();
				save1[5] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);
				break;
			case '7':
				gotoxy(51, 10);
				p1_turn();
				save1[6] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);
				break;
			case '8':
				gotoxy(57, 10);
				p1_turn();
				save1[7] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);	
				break;
			case '9':
				gotoxy(63, 10);
				p1_turn();
				save1[8] = 1;
				win = win_(save1);
				if (win == 1 || count == 9)
					break;
				if (diff == '1' || count > 4)
				{
					s = comp_turn(save1, save2);
				}
				else
				{
					s = strong_AI(save1, save2, count);
				}
				count++;
				save2[s] = 1;
				win = win_(save2);
				break;
		}
		if (count == 9 && win != 1)
		{
			gotoxy(55, 15);
			printf("DRAW GAME!");
			return;
		}
		if (win == 1)
		{
			gotoxy(55, 15);
			if (count % 2 == 0)
				printf("YOU LOSE!\n\n\n\n\n\n");
			else
				printf("YOU WIN!\n\n\n\n\n\n");
		}
		if(mark == 'q')
			break;
	}
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void p1_turn()
{
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//	First save the current color information
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	printf("X");
	SetConsoleTextAttribute ( h, wOldColorAttrs);
}

void p2_turn()
{
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//	First save the current color information
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
	printf("O");
	SetConsoleTextAttribute ( h, wOldColorAttrs);
}

int win_(int a[])
{
	if (a[0] == 1 && a[1] == 1 && a[2] == 1)
		return 1;
	else if (a[3] == 1 && a[4] == 1 && a[5] == 1)
		return 1;
	else if (a[6] == 1 && a[7] == 1 && a[8] == 1)
		return 1;
	else if (a[0] == 1 && a[3] == 1 && a[6] == 1)
		return 1;
	else if (a[1] == 1 && a[4] == 1 && a[7] == 1)
		return 1;
	else if (a[2] == 1 && a[5] == 1 && a[8] == 1)
		return 1;
	else if (a[0] == 1 && a[4] == 1 && a[8] == 1)
		return 1;
	else if (a[2] == 1 && a[4] == 1 && a[6] == 1)
		return 1;
	else
		return 0;
}

int comp_turn(int a[], int b[])
{
	int k = 0, end = 0;
	if (b[0] == 1 && b[1] == 1 && a[2] != 1)
	{
		gotoxy(63, 4);
		p2_turn();
		return 2;
	}
	else if (b[0] == 1 && b[2] == 1 && a[1] != 1)
	{
		gotoxy(57, 4);
		p2_turn();
		return 1;
	}
	else if (b[1] == 1 && b[2] == 1 && a[0] != 1)
	{
		gotoxy(51, 4);
		p2_turn();
		return 0;
	}
	//________________________________________	
	else if (b[3] == 1 && b[4] == 1 && a[5] != 1)
	{
		gotoxy(63, 7);
		p2_turn();
		return 5;
	}
	else if (b[3] == 1 && b[5] == 1 && a[4] != 1)
	{
		gotoxy(57, 7);
		p2_turn();
		return 4;
	}
	else if (b[4] == 1 && b[5] == 1 && a[3] != 1)
	{
		gotoxy(51, 7);
		p2_turn();
		return 3;
	}
	//__________________________________________
	else if (b[6] == 1 && b[7] == 1 && a[8] != 1)
	{
		gotoxy(63, 10);
		p2_turn();
		return 8;
	}
	else if (b[6] == 1 && b[8] == 1 && a[7] != 1)
	{
		gotoxy(57, 10);
		p2_turn();
		return 7;
	}
	else if (b[7] == 1 && b[8] == 1 && a[6] != 1)
	{
		gotoxy(51, 10);
		p2_turn();
		return 6;
	}
	//____________________________________________
	else if (b[0] == 1 && b[3] == 1 && a[6] != 1)
	{
		gotoxy(51, 10);
		p2_turn();
		return 6;
	}
	else if (b[0] == 1 && b[6] == 1 && a[3] != 1)
	{
		gotoxy(51, 7);
		p2_turn();
		return 3;
	}
	else if (b[3] == 1 && b[6] == 1 && a[0] != 1)
	{
		gotoxy(51, 4);
		p2_turn();
		return 0;
	}
	//______________________________________________	
	else if (b[1] == 1 && b[4] == 1 && a[7] != 1)
	{
		gotoxy(57, 10);
		p2_turn();
		return 7;
	}
	else if (b[1] == 1 && b[7] == 1 && a[4] != 1)
	{
		gotoxy(57, 7);
		p2_turn();
		return 4;
	}
	else if (b[4] == 1 && b[7] == 1 && a[1] != 1)
	{
		gotoxy(57, 4);
		p2_turn();
		return 1;
	}
	//____________________________________________	
	else if (b[2] == 1 && b[5] == 1 && a[8] != 1)
	{
		gotoxy(63, 10);
		p2_turn();
		return 8;
	}
	else if (b[2] == 1 && b[8] == 1 && a[5] != 1)
	{
		gotoxy(63, 7);
		p2_turn();
		return 5;
	}
	else if (b[5] == 1 && b[8] == 1 && a[2] != 1)
	{
		gotoxy(63, 4);
		p2_turn();
		return 2;
	}
	//_____________________________________________	
	else if (b[0] == 1 && b[4] == 1 && a[8] != 1)
	{
		gotoxy(63, 10);
		p2_turn();
		return 8;
	}
	else if (b[0] == 1 && b[8] == 1 && a[4] != 1)
	{
		gotoxy(57, 7);
		p2_turn();
		return 4;
	}
	else if (b[4] == 1 && b[8] == 1 && a[0] != 1)
	{
		gotoxy(51, 4);
		p2_turn();
		return 0;
	}
	//____________________________________________
	else if (b[2] == 1 && b[4] == 1 && a[6] != 1)
	{
		gotoxy(51, 10);
		p2_turn();
		return 6;
	}
	else if (b[2] == 1 && b[6] == 1 && a[4] != 1)
	{
		gotoxy(57, 7);
		p2_turn();
		return 4;
	}
	else if (b[4] == 1 && b[6] == 1 && a[2] != 1)
	{
		gotoxy(63, 4);
		p2_turn();
		return 2;
	}
	//==========================================================================
	else if (a[0] == 1 && a[1] == 1 && b[2] != 1)
	{
		gotoxy(63, 4);
		p2_turn();
		return 2;
	}
	else if (a[0] == 1 && a[2] == 1 && b[1] != 1)
	{
		gotoxy(57, 4);
		p2_turn();
		return 1;
	}
	else if (a[1] == 1 && a[2] == 1 && b[0] != 1)
	{
		gotoxy(51, 4);
		p2_turn();
		return 0;
	}
	//________________________________________	
	else if (a[3] == 1 && a[4] == 1 && b[5] != 1)
	{
		gotoxy(63, 7);
		p2_turn();
		return 5;
	}
	else if (a[3] == 1 && a[5] == 1 && b[4] != 1)
	{
		gotoxy(57, 7);
		p2_turn();
		return 4;
	}
	else if (a[4] == 1 && a[5] == 1 && b[3] != 1)
	{
		gotoxy(51, 7);
		p2_turn();
		return 3;
	}
	//__________________________________________
	else if (a[6] == 1 && a[7] == 1 && b[8] != 1)
	{
		gotoxy(63, 10);
		p2_turn();
		return 8;
	}
	else if (a[6] == 1 && a[8] == 1 && b[7] != 1)
	{
		gotoxy(57, 10);
		p2_turn();
		return 7;
	}
	else if (a[7] == 1 && a[8] == 1 && b[6] != 1)
	{
		gotoxy(51, 10);
		p2_turn();
		return 6;
	}
	//____________________________________________
	else if (a[0] == 1 && a[3] == 1 && b[6] != 1)
	{
		gotoxy(51, 10);
		p2_turn();
		return 6;
	}
	else if (a[0] == 1 && a[6] == 1 && b[3] != 1)
	{
		gotoxy(51, 7);
		p2_turn();
		return 3;
	}
	else if (a[3] == 1 && a[6] == 1 && b[0] != 1)
	{
		gotoxy(51, 4);
		p2_turn();
		return 0;
	}
	//______________________________________________	
	else if (a[1] == 1 && a[4] == 1 && b[7] != 1)
	{
		gotoxy(57, 10);
		p2_turn();
		return 7;
	}
	else if (a[1] == 1 && a[7] == 1 && b[4] != 1)
	{
		gotoxy(57, 7);
		p2_turn();
		return 4;
	}
	else if (a[4] == 1 && a[7] == 1 && b[1] != 1)
	{
		gotoxy(57, 4);
		p2_turn();
		return 1;
	}
	//____________________________________________	
	else if (a[2] == 1 && a[5] == 1 && b[8] != 1)
	{
		gotoxy(63, 10);
		p2_turn();
		return 8;
	}
	else if (a[2] == 1 && a[8] == 1 && b[5] != 1)
	{
		gotoxy(63, 7);
		p2_turn();
		return 5;
	}
	else if (a[5] == 1 && a[8] == 1 && b[2] != 1)
	{
		gotoxy(63, 4);
		p2_turn();
		return 2;
	}
	//_____________________________________________	
	else if (a[0] == 1 && a[4] == 1 && b[8] != 1)
	{
		gotoxy(63, 10);
		p2_turn();
		return 8;
	}
	else if (a[0] == 1 && a[8] == 1 && b[4] != 1)
	{
		gotoxy(57, 7);
		p2_turn();
		return 4;
	}
	else if (a[4] == 1 && a[8] == 1 && b[0] != 1)
	{
		gotoxy(51, 4);
		p2_turn();
		return 0;
	}
	//____________________________________________
	else if (a[2] == 1 && a[4] == 1 && b[6] != 1)
	{
		gotoxy(51, 10);
		p2_turn();
		return 6;
	}
	else if (a[2] == 1 && a[6] == 1 && b[4] != 1)
	{
		gotoxy(57, 7);
		p2_turn();
		return 4;
	}
	else if (a[4] == 1 && a[6] == 1 && b[2] != 1)
	{
		gotoxy(63, 4);
		p2_turn();
		return 2;
	}
	else if (a[1] == 1 && a[3] == 1 && b[0] != 1 && a[0] != 1)
	{
		gotoxy(51, 4);
		p2_turn();
		return 0;
	}
	else if (a[1] == 1 && a[5] == 1 && b[2] != 1 && a[2] != 1)
	{
		gotoxy(63, 4);
		p2_turn();
		return 2;
	}
	else if (a[5] == 1 && a[7] == 1 && b[8] != 1 && a[8] != 1)
	{
		gotoxy(63, 10);
		p2_turn();
		return 8;
	}
	else if (a[3] == 1 && a[7] == 1 && b[6] != 1 && a[6] != 1)
	{
		gotoxy(51, 10);
		p2_turn();
		return 6;
	}
	//================================================================
	else
	{
		srand(time(0));
		while (end != 1)
		{
			k = 1 + rand() % 9;
			if (k == 1)
			{
				if (a[0] == 1 || b[0] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(51, 4);
					p2_turn();
					end = 1;
					return 0;
				}
			}
			if (k == 2)
			{
				if (a[1] == 1 || b[1] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(57, 4);
					p2_turn();
					end = 1;
					return 1;
				}
			}
			if (k == 3)	
			{
				if (a[2] == 1 || b[2] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(63, 4);
					p2_turn();
					end = 1;
					return 2;
				}
			}
			if (k == 4)
			{
				if (a[3] == 1 || b[3] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(51, 7);
					p2_turn();
					end = 1;
					return 3;
				}
			}
			if (k == 5)
			{
				if (a[4] == 1 || b[4] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(57, 7);
					p2_turn();
					end = 1;
					return 4;
				}
			}
			if (k == 6)
			{
				if (a[5] == 1 || b[5] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(63, 7);
					p2_turn();
					end = 1;
					return 5;
				}
			}
			if (k == 7)
			{			
				if (a[6] == 1 || b[6] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(51, 10);
					p2_turn();
					end = 1;
					return 6;
				}
			}
			if (k == 8)
			{	
				if (a[7] == 1 || b[7] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(57, 10);
					p2_turn();
					end = 1;
					return 7;
				}
			}
			if (k == 9)
			{
				if (a[8] == 1 || b[8] == 1)
				{
					continue;
				}
				else 
				{
					gotoxy(63, 10);
					p2_turn();
					end = 1;
					return 8;
				}
			}
		}
	}
}

void p1t()
{
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//	First save the current color information
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	gotoxy(57, 1);
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	printf("Player1's Turn");
	SetConsoleTextAttribute ( h, wOldColorAttrs);
}

void p2t()
{
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
//	First save the current color information
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	gotoxy(57, 1);
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
	printf("Player2's Turn");
	SetConsoleTextAttribute ( h, wOldColorAttrs);
}

int strong_AI(int a[], int b[], int k)
{
	if (k < 3)
	{
		if (a[0] == 1)
		{
			gotoxy(57, 7);
			p2_turn();
			return 4;
		}
		else if (a[2] == 1)
		{
			gotoxy(57, 7);
			p2_turn();
			return 4;
		}
		else if (a[4] == 1)
		{
			gotoxy(63, 4);
			p2_turn();
			return 2;
		}
		else if (a[6] == 1)
		{
			gotoxy(57, 7);
			p2_turn();
			return 4;
		}
		else if (a[8] == 1)
		{
			gotoxy(57, 7);
			p2_turn();
			return 4;
		}
		else
		{
			gotoxy(57, 7);
			p2_turn();
			return 4;
		}
	}
	else if (k == 3)
	{
		if (a[0] == 1)
		{
			if (a[8] == 1)
			{
				gotoxy(57, 4);
				p2_turn();
				return 1;
			}
			else
			{
				comp_turn(a, b);
			}
		}
		else if (a[2] == 1)
		{
			if (a[6] == 1)
			{
				gotoxy(57, 4);
				p2_turn();
				return 1;
			}
			else
			{
				comp_turn(a, b);
			}
		}
		else if (a[6] == 1)
		{
			if (a[2] == 1)
			{
				gotoxy(57, 4);
				p2_turn();
				return 1;
			}
			else
			{
				comp_turn(a, b);
			}
		}
		else if (a[8] == 1)
		{
			if (a[0] == 1)
			{
				gotoxy(57, 4);
				p2_turn();
				return 1;
			}
			else
			{
				comp_turn(a, b);
			}
		}
		else
			comp_turn(a, b);
	}
	else
	{
		if (a[1] != 1)
		{
			gotoxy(57, 4);
			p2_turn();
			return 1;
		}
		else if (a[7] != 1)
		{
			gotoxy(57, 10);
			p2_turn();
			return 1;
		}
		else if (a[5] != 1)
		{
			gotoxy(63, 7);
			p2_turn();
			return 1;
		}
		else if (a[3] != 1)
		{
			gotoxy(51, 7);
			p2_turn();
			return 1;
		}
		else
			comp_turn(a, b );
	}
}
