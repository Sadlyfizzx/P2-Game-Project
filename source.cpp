#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Game Settings - Editor Zeyad //
int isJumping = 0; // to check if the hero is jumping or not
int isClimbing = 0; // to check if the hero is climbing or not
int jumpdone; // to check if the jump is done or not
int pos; // save the position of the hero when he starts jumping
int velocety = 4; //controls jump height
int jumpLimit = 0;
char current_level = '1';

// Player Stats //
int health = 100;
int heroDir = 1;

// Enemy Stats //
int enemyAlive = 1;

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
	x[3][61] = current_level;
	for (int c = 0; c < 120; c++)
	{
		x[0][c] = 205;
		x[24][c] = 205;
	}
}

// editor fares
void ladder_level1(char x[][120]) //selm
{
	x[23][105] = 179;
	x[22][105] = 179;
	x[21][105] = 179;
	x[20][105] = 179;
	x[19][105] = 179;
	x[18][105] = 179;
	x[17][105] = 179;
	x[16][105] = 179;
	x[15][105] = 179;
	x[14][105] = 179;
	x[13][105] = 179;
	x[12][105] = 179;
	x[11][105] = 179;
	x[10][105] = 179;
	x[23][118] = 179;
	x[22][118] = 179;
	x[21][118] = 179;
	x[20][118] = 179;
	x[19][118] = 179;
	x[18][118] = 179;
	x[17][118] = 179;
	x[16][118] = 179;
	x[15][118] = 179;
	x[14][118] = 179;
	x[13][118] = 179;
	x[12][118] = 179;
	x[11][118] = 179;
	x[10][118] = 179;
	x[22][106] = '-';
	x[22][107] = '-';
	x[22][108] = '-';
	x[22][109] = '-';
	x[22][110] = '-';
	x[22][111] = '-';
	x[22][112] = '-';
	x[22][113] = '-';
	x[22][114] = '-';
	x[22][115] = '-';
	x[22][116] = '-';
	x[22][117] = '-';	
	x[19][106] = '-';
	x[19][107] = '-';
	x[19][108] = '-';
	x[19][109] = '-';
	x[19][110] = '-';
	x[19][111] = '-';
	x[19][112] = '-';
	x[19][113] = '-';
	x[19][114] = '-';
	x[19][115] = '-';
	x[19][116] = '-';
	x[19][117] = '-';
	x[16][106] = '-';
	x[16][107] = '-';
	x[16][108] = '-';
	x[16][109] = '-';
	x[16][110] = '-';
	x[16][111] = '-';
	x[16][112] = '-';
	x[16][113] = '-';
	x[16][114] = '-';
	x[16][115] = '-';
	x[16][116] = '-';
	x[16][117] = '-';
	x[13][106] = '-';
	x[13][107] = '-';
	x[13][108] = '-';
	x[13][109] = '-';
	x[13][110] = '-';
	x[13][111] = '-';
	x[13][112] = '-';
	x[13][113] = '-';
	x[13][114] = '-';
	x[13][115] = '-';
	x[13][116] = '-';
	x[13][117] = '-';
	x[10][106] = '-';
	x[10][107] = '-';
	x[10][108] = '-';
	x[10][109] = '-';
	x[10][110] = '-';
	x[10][111] = '-';
	x[10][112] = '-';
	x[10][113] = '-';
	x[10][114] = '-';
	x[10][115] = '-';
	x[10][116] = '-';
	x[10][117] = '-';
}
void hero(char x[][120], int mr, int mc)
{
	if (health > 1)
	{
		x[20 + mr][3 + mc] = 153;
		x[21 + mr][3 + mc] = 186;
		x[21 + mr][4 + mc] = '\\';
		x[21 + mr][2 + mc] = '/';
		x[22 + mr][3 + mc] = 186;
		x[23 + mr][4 + mc] = '\\';
		x[23 + mr][2 + mc] = '/';
	}
}
void moveHero(int& mr, int& mc, char c) // move left, right, upper, and lower
{
	if (c == 'a' && mc > 1) //left
	{
		heroDir = -1;
		mc -= 3;
		if (mr < 0 && mc < 105) // If hero reaches the ladder, he won't move.
		{
			mc += 3;
		}
	}
	if (c == 'd' && mc < 111) // right
	{
		heroDir = 1;
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
		jumpLimit++;
		if (jumpLimit <= 2)
		{
			isJumping = 1;
			jumpdone = 0;
			pos = mr;
		}

		if (mc >= 106 && mc <= 110)
		{
			isClimbing = 1;
			isJumping = 0;
			jumpdone = 0;
		}

		if (isClimbing == 1)
		{
			mr--;

			if (mr <= 15)
			{
				isClimbing = 0; // STOP climbing
			}

			if (mc < 106 || mc > 110)
			{
				isClimbing = 0;
			}
		}
	}

	if (mc > 104)
	{
		if (c == 's' && 3 + mc >= 108)
		{
			mr += 2;
		}
	}
}

// editor fares & zeyad
void jumpHero(int& mr, int& mc)
{
	if (isJumping == 1)
	{
		if (pos - velocety != mr && jumpdone == 0)
		{
			mr--;
			if (heroDir == -1)
			{
				mc--;
			}
			if (heroDir == 1)
			{
				mc++;
			}
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
				if (heroDir == -1)
				{
					mc--;
				}
				if (heroDir == 1)
				{
					mc++;
				}
			}
		}
		if (pos == mr && mr == 0)
		{
			jumpdone = 0;
			isJumping = 0;
		}
	}
	if (mr == 0)
	{
		jumpLimit = 0;
	}
}
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
void damage(int& mr, int& mc, int& enemyc, int& enemyr)
{
	if (enemyAlive == 1)
	{
		if ((23 + mr) >= (enemyr) && (20 + mr) <= (5 + enemyr) && (4 + mc) >= (enemyc) && (2 + mc) <= (18 + enemyc))
		{
			health -= 20;
		}
	}
}
void enemy(char x[][120], int er, int ec, int dir)
{
	if (enemyAlive == 1)
	{
		if (dir == 1) // facing right
		{
			x[er + 0][ec + 11] = '_';
			x[er + 0][ec + 12] = '_';
			x[er + 0][ec + 13] = 'n';
			x[er + 0][ec + 14] = '_';
			x[er + 0][ec + 15] = '_';
			x[er + 0][ec + 16] = 'n';
			x[er + 0][ec + 17] = '_';
			x[er + 0][ec + 18] = '_';

			x[er + 1][ec + 4] = '.';
			x[er + 1][ec + 5] = '-';
			x[er + 1][ec + 6] = '-';
			x[er + 1][ec + 7] = '-';
			x[er + 1][ec + 8] = '-';
			x[er + 1][ec + 9] = '-';
			x[er + 1][ec + 10] = '-';
			x[er + 1][ec + 11] = '`';
			x[er + 1][ec + 12] = '-';
			x[er + 1][ec + 13] = '\\';
			x[er + 1][ec + 14] = '0';
			x[er + 1][ec + 15] = '0';
			x[er + 1][ec + 16] = '/';
			x[er + 1][ec + 17] = '-';
			x[er + 1][ec + 18] = '\'';

			x[er + 2][ec + 3] = '/';
			x[er + 2][ec + 6] = '#';
			x[er + 2][ec + 7] = '#';
			x[er + 2][ec + 10] = '#';
			x[er + 2][ec + 11] = '#';
			x[er + 2][ec + 13] = '(';
			x[er + 2][ec + 14] = 'o';
			x[er + 2][ec + 15] = 'o';
			x[er + 2][ec + 16] = ')';

			x[er + 3][ec + 2] = '/';
			x[er + 3][ec + 4] = '\\';
			x[er + 3][ec + 5] = '#';
			x[er + 3][ec + 6] = '#';
			x[er + 3][ec + 8] = '_';
			x[er + 3][ec + 9] = '_';
			x[er + 3][ec + 13] = '.';
			x[er + 3][ec + 14] = '/';

			x[er + 4][ec + 5] = '|';
			x[er + 4][ec + 6] = '/';
			x[er + 4][ec + 7] = '/';
			x[er + 4][ec + 8] = 'Y';
			x[er + 4][ec + 9] = 'Y';
			x[er + 4][ec + 11] = '\\';
			x[er + 4][ec + 12] = '|';
			x[er + 4][ec + 13] = '/';

			x[er + 5][ec + 5] = '|';
			x[er + 5][ec + 6] = '|';
			x[er + 5][ec + 7] = '|';
			x[er + 5][ec + 11] = '|';
			x[er + 5][ec + 12] = '|';
			x[er + 5][ec + 13] = '|';
		}
		else // facing left
		{
			x[er + 0][ec + 0] = '_';
			x[er + 0][ec + 1] = '_';
			x[er + 0][ec + 2] = 'n';
			x[er + 0][ec + 3] = '_';
			x[er + 0][ec + 4] = '_';
			x[er + 0][ec + 5] = 'n';
			x[er + 0][ec + 6] = '_';
			x[er + 0][ec + 7] = '_';

			x[er + 1][ec + 0] = '\'';
			x[er + 1][ec + 1] = '-';
			x[er + 1][ec + 2] = '\\';
			x[er + 1][ec + 3] = '0';
			x[er + 1][ec + 4] = '0';
			x[er + 1][ec + 5] = '/';
			x[er + 1][ec + 6] = '-';
			x[er + 1][ec + 7] = '`';
			x[er + 1][ec + 8] = '-';
			x[er + 1][ec + 9] = '-';
			x[er + 1][ec + 10] = '-';
			x[er + 1][ec + 11] = '-';
			x[er + 1][ec + 12] = '-';
			x[er + 1][ec + 13] = '-';
			x[er + 1][ec + 14] = '.';

			x[er + 2][ec + 2] = '(';
			x[er + 2][ec + 3] = 'o';
			x[er + 2][ec + 4] = 'o';
			x[er + 2][ec + 5] = ')';
			x[er + 2][ec + 7] = '#';
			x[er + 2][ec + 8] = '#';
			x[er + 2][ec + 11] = '#';
			x[er + 2][ec + 12] = '#';
			x[er + 2][ec + 15] = '\\';

			x[er + 3][ec + 4] = '\\';
			x[er + 3][ec + 5] = '.';
			x[er + 3][ec + 9] = '_';
			x[er + 3][ec + 10] = '_';
			x[er + 3][ec + 12] = '#';
			x[er + 3][ec + 13] = '#';
			x[er + 3][ec + 14] = '/';
			x[er + 3][ec + 16] = '\\';

			x[er + 4][ec + 5] = '\\';
			x[er + 4][ec + 6] = '|';
			x[er + 4][ec + 7] = '/';
			x[er + 4][ec + 9] = 'Y';
			x[er + 4][ec + 10] = 'Y';
			x[er + 4][ec + 11] = '\\';
			x[er + 4][ec + 12] = '\\';
			x[er + 4][ec + 13] = '|';

			x[er + 5][ec + 5] = '|';
			x[er + 5][ec + 6] = '|';
			x[er + 5][ec + 7] = '|';
			x[er + 5][ec + 11] = '|';
			x[er + 5][ec + 12] = '|';
			x[er + 5][ec + 13] = '|';
		}
	}
}
// Move the enemy, we can control the range of moving by edit 50 and 60
void moveEnemy(int& enec, int& enedir)
{
	if (enedir == 1 && enec == 60)
		enedir = -1;
	if (enedir == -1 && enec == 50)
		enedir = 1;
	enec += enedir;
	Sleep(120);
}

void killEnemy(int& mr, int& mc, int enemyc, int enemyr)
{
	int heroPos = 23 + mr;

	int sameCol = 0; // check if hero at the same column as enemy
	if (4 + mc >= enemyc && 2 + mc <= enemyc + 18)
	{
		sameCol = 1;
	}

	int falling = 0; // check if hero was jumping
	if (jumpdone == 1)
	{
		falling = 1;
	}

	if (falling == 1 && sameCol == 1 && heroPos == enemyr && enemyAlive == 1)
	{
		enemyAlive = 0; // kill the enemy

		// make the player bounch after killing enemy //
		mr -= 2;

		isJumping = 1;
		jumpdone = 0;
		pos = mr;
	}
}
void checkLose()
{
	if (health <= 0)
	{
		cout << "Game Over" << endl;
		exit(0);
	}
}
int main()
{
	char x[25][120];
	int mr = 0, mc = 0;
	int enemyr = 18, enemyc = 55; // enemy row and column
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
				jumpHero(mr, mc);
				enemy(x, enemyr, enemyc, enemydir);
				damage(mr, mc, enemyc, enemyr);
				killEnemy(mr, mc, enemyc, enemyr);
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