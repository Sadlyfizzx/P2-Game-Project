#include <iostream>
#include <conio.h>
using namespace std;

// Game Settings - Editor Zeyad //
int isJumping = 0; // to check if the hero is jumping or not
int jumpdone; // to check if the jump is done or not
int pos; // save the position of the hero when he starts jumping
int velocety = 3; //controls jump height

// Player Stats //
int health = 100;

void display(char x[][120])
{
	system("cls");
	for (int r = 0; r < 25; r++)
	{
		for (int c = 0; c < 120; c++)
		{
			cout << x[r][c];
		}
		cout << endl;
	}
}

// editor fares
void border(char x[][120]) // frame
{
	for (int r = 0; r < 25; r++)
	{
		for (int c = 0; c < 120; c++)
		{
			x[r][c] = ' ';
		}
	}
	for (int r = 0; r < 25; r++)
	{
		x[r][0] = 186;
		x[r][119] = 186;
	}
	x[3][55] = 'L';
	x[3][56] = 'E';
	x[3][57] = 'V';
	x[3][58] = 'E';
	x[3][59] = 'L';
	x[3][60] = ' ';
	x[3][61] = '1';
	for (int c = 0; c < 120; c++)
	{
		x[0][c] = 205;
		x[24][c] = 205;
	}
}

// editor fares
void ladder_level1(char x[][120]) //selm
{
	x[23][109] = 179;
	x[22][109] = 179;
	x[21][109] = 179;
	x[20][109] = 179;
	x[19][109] = 179;
	x[18][109] = 179;
	x[17][109] = 179;
	x[16][109] = 179;
	x[23][113] = 179;
	x[22][113] = 179;
	x[21][113] = 179;
	x[20][113] = 179;
	x[19][113] = 179;
	x[18][113] = 179;
	x[17][113] = 179;
	x[16][113] = 179;
	x[22][111] = '-';
	x[22][110] = '-';
	x[22][112] = '-';
	x[20][111] = '-';
	x[20][110] = '-';
	x[20][112] = '-';
	x[18][111] = '-';
	x[18][110] = '-';
	x[18][112] = '-';
	x[16][111] = '-';
	x[16][110] = '-';
	x[16][112] = '-';
	x[15][114] = '-';
	x[15][115] = '-';
	x[15][116] = '-';
	x[15][117] = '-';
	x[15][118] = '-';
}

// editor fares
void hero(char x[][120], int mr, int mc)
{
	x[20 + mr][3 + mc] = 153;
	x[21 + mr][3 + mc] = 186;
	x[21 + mr][4 + mc] = '\\';
	x[21 + mr][2 + mc] = '/';
	x[22 + mr][3 + mc] = 186;
	x[23 + mr][4 + mc] = '\\';
	x[23 + mr][2 + mc] = '/';
}

// editor zeyad & fares
void moveHero(int& mr, int& mc, char c) // move left, right, upper, and lower
{
	if (c == 'a' && mc > 1) //left
	{
		mc -= 3;
		if (mr < 0 && mc < 105) // If hero reaches the ladder, he won't move.
		{
			mc += 3;
		}
	}
	if (c == 'd' && mc < 111) // right
	{
		mc += 3;
		if (mc >= 104 && mc <= 106) // The first thing he does when he reaches the stairs is take the first step.
		{

			mr -= 2;
			mc += 3;

		}
		else if (mc > 106 && mr > -10)
		{
			mr -= 1;
			mc += 2;
		}
	}

	if (c == 'w') // upper
	{
		isJumping = 1;
		jumpdone = 0;
		pos = mr;

		if (mr < 16 && mc > 104) // climb the stairs
		{
			mr -= 2;
			isJumping = 0;
			jumpdone = 0;
		}
	}

	if (mc > 104)
	{
		if (c == 's' && mc >= 108)
		{
			mr += 2;
		}
	}
}

// editor fares & zeyad
void jumpHero(int& mr)
{
	if (isJumping == 1)
	{
		if (pos - velocety != mr && jumpdone == 0)
		{
			mr--;
		}
		if (pos - velocety == mr)
		{
			jumpdone = 1;
		}
		if (jumpdone == 1)
		{
			if (mr != 0)
			{
				mr++;
			}
		}
		if (pos == mr && mr == 0)
		{
			jumpdone = 0;
			isJumping = 0;
		}
	}
}

//editor fares & zeyad
void health_of_hero(char x[][120])
{
	if (health == 100)
	{

		x[3][2] = 'H';
		x[3][3] = 'E';
		x[3][4] = 'A';
		x[3][5] = 'L';
		x[3][6] = 'T';
		x[3][7] = 'H';
		x[3][8] = ':';
		x[3][9] = 221;
		x[3][10] = 221;
		x[3][11] = 221;
		x[3][12] = 221;
		x[3][13] = 221;
		x[3][14] = 221;
		x[3][15] = 221;
		x[3][16] = 221;
		x[3][17] = 221;
		x[3][18] = 221;
		x[3][19] = '1';
		x[3][20] = '0';
		x[3][21] = '0';
		x[3][22] = '%';
	}
	else if (health == 80)
	{
		x[3][2] = 'H';
		x[3][3] = 'E';
		x[3][4] = 'A';
		x[3][5] = 'L';
		x[3][6] = 'T';
		x[3][7] = 'H';
		x[3][8] = ':';
		x[3][9] = 221;
		x[3][10] = 221;
		x[3][11] = 221;
		x[3][12] = 221;
		x[3][13] = 221;
		x[3][14] = 221;
		x[3][15] = 221;
		x[3][16] = 221;
		x[3][19] = '8';
		x[3][20] = '0';
		x[3][21] = '%';
	}
	else if (health == 60)
	{
		x[3][2] = 'H';
		x[3][3] = 'E';
		x[3][4] = 'A';
		x[3][5] = 'L';
		x[3][6] = 'T';
		x[3][7] = 'H';
		x[3][8] = ':';
		x[3][9] = 221;
		x[3][10] = 221;
		x[3][11] = 221;
		x[3][12] = 221;
		x[3][13] = 221;
		x[3][14] = 221;
		x[3][19] = '6';
		x[3][20] = '0';
		x[3][21] = '%';
	}
	else if (health == 40)
	{
		x[3][2] = 'H';
		x[3][3] = 'E';
		x[3][4] = 'A';
		x[3][5] = 'L';
		x[3][6] = 'T';
		x[3][7] = 'H';
		x[3][8] = ':';
		x[3][9] = 221;
		x[3][10] = 221;
		x[3][11] = 221;
		x[3][12] = 221;
		x[3][19] = '4';
		x[3][20] = '0';
		x[3][21] = '%';
	}
	else if (health == 20)
	{
		x[3][2] = 'H';
		x[3][3] = 'E';
		x[3][4] = 'A';
		x[3][5] = 'L';
		x[3][6] = 'T';
		x[3][7] = 'H';
		x[3][8] = ':';
		x[3][9] = 221;
		x[3][10] = 221;
		x[3][19] = '2';
		x[3][20] = '0';
		x[3][21] = '%';
	}
	else if (health == 0)
	{
		x[3][2] = 'H';
		x[3][3] = 'E';
		x[3][4] = 'A';
		x[3][5] = 'L';
		x[3][6] = 'T';
		x[3][7] = 'H';
		x[3][8] = ':';
		x[3][19] = '0';
		x[3][20] = '%';
	}
}

// editor zeyad
void damage(int& mr, int& mc, int& enemyc, int& enemyr)
{
	if ((23 + mr) >= (22 + enemyr) && (20 + mr) <= (23 + enemyr) && (4 + mc) >= (3 + enemyc) && (2 + mc) <= (5 + enemyc))
	{
		health -= 20;
	}
}

//editor zeyad
void enemy(char x[][120], int er, int ec)
{
	x[22 + er][3 + ec] = '[';
	x[22 + er][4 + ec] = 'O';
	x[22 + er][5 + ec] = ']';

	x[23 + er][3 + ec] = '/';
	x[23 + er][5 + ec] = '\\';
}

// editor zeyad
// Move the enemy, we can control the range of moving by edit 50 and 60
void moveEnemy(int& enec, int& enedir)
{
	if (enedir == 1 && enec == 60)
		enedir = -1;
	if (enedir == -1 && enec == 50)
		enedir = 1;
	enec += enedir;
}

// editor zeyad
void checkLose()
{
	if (health < 0)
	{
		cout << "Game Over" << endl;
		exit(0);
	}
}

// editor zeyad
int main()
{
	char x[25][120];
	int mr = 0, mc = 0;
	int enemyr = 0, enemyc = 55; // enemy row and column
	int enemydir = 1; // enemy direction (1 for right, -1 for left)
	border(x);
	ladder_level1(x);
	hero(x, mr, mc);
	health_of_hero(x);
	display(x);
	for (;;)
	{
		while (1)
		{
			// Game loop while not pressing any keys 
			while (!_kbhit())
			{
				border(x);
				ladder_level1(x);
				hero(x, mr, mc);
				jumpHero(mr);
				enemy(x, enemyr, enemyc);
				damage(mr, mc, enemyc, enemyr);
				checkLose();
				health_of_hero(x);
				display(x);
				moveEnemy(enemyc, enemydir);
			}
			char movement = _getch();
			moveHero(mr, mc, movement);
		}

	}
	return 0;
}
