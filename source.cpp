#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
// Game Settings //
int isJumping = 0; // to check if the hero is jumping or not
int isClimbing = 0; // to check if the hero is climbing or not
int jumpdone; // to check if the jump is done or not
int pos; // save the position of the hero when he starts jumping
int velocety = 7; //controls jump height
int jumpLimit = 0;
char current_level = '1';

// Player Stats //
int health_hero = 100;
int heroDir = 1;

// Enemy Stats //
int Health_enemy = 100;
int enemyAlive = 1;
//Scrolling//
const int map_width = 500;
int camera_x = 0;
void display(char x[][map_width], int camera_x)
{
	system("cls");
	for (int r = 0; r < 35; r++)
	{
		for (int c = camera_x; c < camera_x + 118; c++)
		{
			cout << x[r][c];
		}
		cout << endl;
	}
}
void border(char x[][map_width])
{
	for (int r = 0; r < 35; r++)
	{
		for (int c = 0; c < map_width; c++)
		{
			x[r][c] = ' ';
		}
	}
	for (int r = 0; r < 35; r++)
	{
		x[r][0] = 186;
		x[r][119] = 186;
		x[9][119] = ' ';
		x[8][119] = ' ';
		x[7][119] = ' ';
		x[6][119] = ' ';
		x[5][119] = ' ';
		x[4][119] = ' ';
		x[3][119] = ' ';
	}
	x[3][55] = 'L';
	x[3][56] = 'E';
	x[3][57] = 'V';
	x[3][58] = 'E';
	x[3][59] = 'L';
	x[3][60] = ' ';
	x[3][61] = current_level;
	for (int c = 0; c < map_width; c++)
	{
		x[0][c] = 205;
		x[34][c] = 205;
	}
}
void ladder_level1(char x[][map_width])
{
	x[33][105] = 179;
	x[32][105] = 179;
	x[31][105] = 179;
	x[30][105] = 179;
	x[29][105] = 179;
	x[28][105] = 179;
	x[27][105] = 179;
	x[26][105] = 179;
	x[25][105] = 179;
	x[24][105] = 179;
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
	x[33][118] = 179;
	x[32][118] = 179;
	x[31][118] = 179;
	x[30][118] = 179;
	x[29][118] = 179;
	x[28][118] = 179;
	x[27][118] = 179;
	x[26][118] = 179;
	x[25][118] = 179;
	x[24][118] = 179;
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
	x[30][106] = 196;
	x[30][107] = 196;
	x[30][108] = 196;
	x[30][109] = 196;
	x[30][110] = 196;
	x[30][111] = 196;
	x[30][112] = 196;
	x[30][113] = 196;
	x[30][114] = 196;
	x[30][115] = 196;
	x[30][116] = 196;
	x[27][106] = 196;
	x[27][107] = 196;
	x[27][108] = 196;
	x[27][109] = 196;
	x[27][110] = 196;
	x[27][111] = 196;
	x[27][112] = 196;
	x[27][113] = 196;
	x[27][114] = 196;
	x[27][115] = 196;
	x[27][116] = 196;
	x[24][106] = 196;
	x[24][107] = 196;
	x[24][108] = 196;
	x[24][109] = 196;
	x[24][110] = 196;
	x[24][111] = 196;
	x[24][112] = 196;
	x[24][113] = 196;
	x[24][114] = 196;
	x[24][115] = 196;
	x[24][116] = 196;
	x[22][106] = 196;
	x[22][107] = 196;
	x[22][108] = 196;
	x[22][109] = 196;
	x[22][110] = 196;
	x[22][111] = 196;
	x[22][112] = 196;
	x[22][113] = 196;
	x[22][114] = 196;
	x[22][115] = 196;
	x[22][116] = 196;
	x[22][117] = 196;
	x[19][106] = 196;
	x[19][107] = 196;
	x[19][108] = 196;
	x[19][109] = 196;
	x[19][110] = 196;
	x[19][111] = 196;
	x[19][112] = 196;
	x[19][113] = 196;
	x[19][114] = 196;
	x[19][115] = 196;
	x[19][116] = 196;
	x[19][117] = 196;
	x[16][106] = 196;
	x[16][107] = 196;
	x[16][108] = 196;
	x[16][109] = 196;
	x[16][110] = 196;
	x[16][111] = 196;
	x[16][112] = 196;
	x[16][113] = 196;
	x[16][114] = 196;
	x[16][115] = 196;
	x[16][116] = 196;
	x[16][117] = 196;
	x[13][106] = 196;
	x[13][107] = 196;
	x[13][108] = 196;
	x[13][109] = 196;
	x[13][110] = 196;
	x[13][111] = 196;
	x[13][112] = 196;
	x[13][113] = 196;
	x[13][114] = 196;
	x[13][115] = 196;
	x[13][116] = 196;
	x[13][117] = 196;
	x[10][106] = 196;
	x[10][107] = 196;
	x[10][108] = 196;
	x[10][109] = 196;
	x[10][110] = 196;
	x[10][111] = 196;
	x[10][112] = 196;
	x[10][113] = 196;
	x[10][114] = 196;
	x[10][115] = 196;
	x[10][116] = 196;
	x[10][117] = 196;
}
void hero(char x[][map_width], int mr, int mc)
{
	if (health_hero > 1)
	{
		x[mr + 5][mc + 9] = '/';
		x[mr + 5][mc + 10] = '/';
		x[mr + 5][mc + 11] = '/';
		x[mr + 5][mc + 12] = '/';
		x[mr + 5][mc + 13] = '^';
		x[mr + 5][mc + 14] = '\\';
		x[mr + 5][mc + 15] = '\\';
		x[mr + 5][mc + 16] = '\\';
		x[mr + 5][mc + 17] = '\\';
		x[mr + 6][mc + 9] = '|';
		x[mr + 6][mc + 11] = '^';
		x[mr + 6][mc + 15] = '^';
		x[mr + 6][mc + 17] = '|';
		x[mr + 7][mc + 8] = '@';
		x[mr + 7][mc + 10] = '(';
		x[mr + 7][mc + 11] = 'o';
		x[mr + 7][mc + 11] = ')';
		x[mr + 7][mc + 14] = '(';
		x[mr + 7][mc + 15] = 'o';
		x[mr + 7][mc + 16] = ')';
		x[mr + 7][mc + 18] = '@';
		x[mr + 8][mc + 9] = '|';
		x[mr + 8][mc + 13] = '<';
		x[mr + 8][mc + 17] = '|';
		x[mr + 9][mc + 9] = '|';
		x[mr + 9][mc + 12] = '_';
		x[mr + 9][mc + 13] = '_';
		x[mr + 9][mc + 14] = '_';
		x[mr + 9][mc + 17] = '|';
		x[mr + 10][mc + 10] = '\\';
		x[mr + 10][mc + 11] = '_';
		x[mr + 10][mc + 12] = '_';
		x[mr + 10][mc + 13] = '_';
		x[mr + 10][mc + 14] = '_';
		x[mr + 10][mc + 15] = '_';
		x[mr + 10][mc + 16] = '/';
		x[mr + 11][mc + 8] = '_';
		x[mr + 11][mc + 9] = '_';
		x[mr + 11][mc + 10] = '_';
		x[mr + 11][mc + 11] = '_';
		x[mr + 11][mc + 12] = '|';
		x[mr + 11][mc + 15] = '|';
		x[mr + 11][mc + 16] = '_';
		x[mr + 11][mc + 17] = '_';
		x[mr + 11][mc + 18] = '_';
		x[mr + 11][mc + 19] = '_';
		x[mr + 12][mc + 7] = '/';
		x[mr + 12][mc + 12] = '\\';
		x[mr + 12][mc + 13] = '_';
		x[mr + 12][mc + 14] = '_';
		x[mr + 12][mc + 15] = '/';
		x[mr + 12][mc + 20] = '\\';
		x[mr + 13][mc + 6] = '/';
		x[mr + 13][mc + 21] = '\\';
		x[mr + 14][mc + 5] = '/';
		x[mr + 14][mc + 6] = '\\';
		x[mr + 14][mc + 7] = '_';
		x[mr + 14][mc + 8] = '/';
		x[mr + 14][mc + 9] = '|';
		x[mr + 14][mc + 18] = '|';
		x[mr + 14][mc + 19] = '\\';
		x[mr + 14][mc + 20] = '_';
		x[mr + 14][mc + 21] = '/';
		x[mr + 14][mc + 22] = '\\';
		x[mr + 15][mc + 4] = '/';
		x[mr + 15][mc + 6] = '/';
		x[mr + 15][mc + 9] = '|';
		x[mr + 15][mc + 18] = '|';
		x[mr + 15][mc + 21] = '\\';
		x[mr + 15][mc + 23] = '\\';
		x[mr + 16][mc + 3] = '(';
		x[mr + 16][mc + 5] = '<';
		x[mr + 16][mc + 9] = '|';
		x[mr + 16][mc + 18] = '|';
		x[mr + 16][mc + 22] = '>';
		x[mr + 16][mc + 24] = ')';
		x[mr + 17][mc + 4] = '\\';
		x[mr + 17][mc + 6] = '\\';
		x[mr + 17][mc + 9] = '|';
		x[mr + 17][mc + 18] = '|';
		x[mr + 17][mc + 21] = '/';
		x[mr + 17][mc + 23] = '/';
		x[mr + 18][mc + 5] = '\\';
		x[mr + 18][mc + 7] = '\\';
		x[mr + 18][mc + 9] = '|';
		x[mr + 18][mc + 10] = '_';
		x[mr + 18][mc + 11] = '_';
		x[mr + 18][mc + 12] = '_';
		x[mr + 18][mc + 13] = '_';
		x[mr + 18][mc + 14] = '_';
		x[mr + 18][mc + 15] = '_';
		x[mr + 18][mc + 16] = '_';
		x[mr + 18][mc + 17] = '_';
		x[mr + 18][mc + 18] = '|';
		x[mr + 18][mc + 20] = '/';
		x[mr + 18][mc + 22] = '/';
		x[mr + 19][mc + 6] = '\\';
		x[mr + 19][mc + 8] = '\\';
		x[mr + 19][mc + 9] = '|';
		x[mr + 19][mc + 10] = '<';
		x[mr + 19][mc + 11] = 'I';
		x[mr + 19][mc + 12] = '_';
		x[mr + 19][mc + 13] = 'D';
		x[mr + 19][mc + 14] = '_';
		x[mr + 19][mc + 15] = 'I';
		x[mr + 19][mc + 16] = '_';
		x[mr + 19][mc + 17] = '_';
		x[mr + 19][mc + 18] = '|';
		x[mr + 19][mc + 19] = '/';
		x[mr + 19][mc + 21] = '/';
		x[mr + 20][mc + 7] = '\\';
		x[mr + 20][mc + 9] = '\\';
		x[mr + 20][mc + 11] = '/';
		x[mr + 20][mc + 13] = 'I';
		x[mr + 20][mc + 16] = '\\';
		x[mr + 20][mc + 18] = '/';
		x[mr + 20][mc + 20] = '/';
		x[mr + 21][mc + 8] = '\\';
		x[mr + 21][mc + 10] = '/';
		x[mr + 21][mc + 13] = 'I';
		x[mr + 21][mc + 17] = '\\';
		x[mr + 21][mc + 19] = '/';
		x[mr + 22][mc + 8] = '|';
		x[mr + 22][mc + 18] = '|';
		x[mr + 23][mc + 8] = '|';
		x[mr + 23][mc + 13] = '|';
		x[mr + 23][mc + 18] = '|';
		x[mr + 24][mc + 8] = '|';
		x[mr + 24][mc + 13] = '|';
		x[mr + 24][mc + 18] = '|';
		x[mr + 25][mc + 8] = '|';
		x[mr + 25][mc + 13] = '|';
		x[mr + 25][mc + 18] = '|';
		x[mr + 26][mc + 8] = '|';
		x[mr + 26][mc + 13] = '|';
		x[mr + 26][mc + 18] = '|';
		x[mr + 27][mc + 8] = '|';
		x[mr + 27][mc + 10] = '#';
		x[mr + 27][mc + 11] = '#';
		x[mr + 27][mc + 13] = '|';
		x[mr + 27][mc + 15] = '#';
		x[mr + 27][mc + 16] = '#';
		x[mr + 27][mc + 18] = '|';
		x[mr + 28][mc + 8] = '|';
		x[mr + 28][mc + 13] = '|';
		x[mr + 28][mc + 18] = '|';
		x[mr + 29][mc + 8] = '|';
		x[mr + 29][mc + 13] = '|';
		x[mr + 29][mc + 18] = '|';
		x[mr + 30][mc + 8] = '|';
		x[mr + 30][mc + 9] = '_';
		x[mr + 30][mc + 10] = '_';
		x[mr + 30][mc + 11] = '_';
		x[mr + 30][mc + 12] = '_';
		x[mr + 30][mc + 13] = '|';
		x[mr + 30][mc + 14] = '_';
		x[mr + 30][mc + 15] = '_';
		x[mr + 30][mc + 16] = '_';
		x[mr + 30][mc + 17] = '_';
		x[mr + 30][mc + 18] = '|';
		x[mr + 31][mc + 8] = '(';
		x[mr + 31][mc + 9] = '_';
		x[mr + 31][mc + 10] = '_';
		x[mr + 31][mc + 11] = '_';
		x[mr + 31][mc + 12] = '_';
		x[mr + 31][mc + 13] = '(';
		x[mr + 31][mc + 14] = '_';
		x[mr + 31][mc + 15] = '_';
		x[mr + 31][mc + 16] = '_';
		x[mr + 31][mc + 17] = '_';
		x[mr + 31][mc + 18] = ')';
		x[mr + 32][mc + 9] = '_';
		x[mr + 32][mc + 10] = '|';
		x[mr + 32][mc + 12] = '|';
		x[mr + 32][mc + 14] = '_';
		x[mr + 32][mc + 18] = '|';
		x[mr + 32][mc + 17] = '|';
		x[mr + 33][mc + 5] = 'c';
		x[mr + 33][mc + 6] = 'c';
		x[mr + 33][mc + 7] = 'c';
		x[mr + 33][mc + 8] = 'C';
		x[mr + 33][mc + 9] = '_';
		x[mr + 33][mc + 10] = '_';
		x[mr + 33][mc + 11] = 'C';
		x[mr + 33][mc + 12] = 'c';
		x[mr + 33][mc + 13] = 'c';
		x[mr + 33][mc + 14] = 'c';
		x[mr + 33][mc + 15] = '_';
		x[mr + 33][mc + 16] = '_';
		x[mr + 33][mc + 17] = '_';
		x[mr + 33][mc + 18] = ')';
	}
}
void moveHero(int& mr, int& mc, char c)
{
	if (c == 'a' && mc > 1 && mr >= -2)
	{
		heroDir = -1;
		mc -= 3;
		if (mc >= 97)
		{
			mr += 2;
			mc -= 8;
		}
	}
	if (c == 'd' && mc < 97)
	{
		heroDir = 1;
		mc += 3;
		if (mc >= 97)
		{
			mr -= 2;
			mc += 8;
		}
	}
	if (c == 'd' && mc >= 103 && mr <= -14 && mc < 119)
	{
		mc++;
	}
	if (c == 'w')
	{
		jumpLimit++;
		if (jumpLimit <= 2 && mc < 97)
		{
			isJumping = 1;
			jumpdone = 0;
			pos = mr;
		}
		if (mc >= 97)
		{
			mr -= 3;
		}
		if (mr <= -15)
		{
			mr += 3;
		}
	}
	if (c == 's' && mc > 100)
	{
		mr += 3;
		if (mr >= 0)
		{
			mr -= 3;
		}
	}
}
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
void health_of_hero(char x[][map_width])
{
	if (health_hero == 100)
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
	else if (health_hero == 80)
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
	else if (health_hero == 60)
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
	else if (health_hero == 40)
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
	else if (health_hero == 20)
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
	else if (health_hero == 0)
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
			health_hero -= 20;
		}
	}
}
void enemy(char x[][map_width], int er, int ec, int dir)
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
	Sleep(80);
}
void health_enemy(char x[][map_width])
{
	if (Health_enemy == 100)
	{
		x[3][90] = 'E';
		x[3][91] = 'n';
		x[3][92] = 'e';
		x[3][93] = 'm';
		x[3][94] = 'y';
		x[3][95] = ':';
		x[3][96] = 221;
		x[3][97] = 221;
		x[3][98] = 221;
		x[3][99] = 221;
		x[3][100] = 221;
		x[3][101] = 221;
		x[3][102] = 221;
		x[3][103] = 221;
		x[3][104] = 221;
		x[3][105] = '1';
		x[3][106] = '0';
		x[3][107] = '0';
		x[3][108] = '%';
	}
	if (Health_enemy == 0)
	{
		x[3][90] = 'E';
		x[3][91] = 'n';
		x[3][92] = 'e';
		x[3][93] = 'm';
		x[3][94] = 'y';
		x[3][95] = ':';
		x[3][107] = '0';
		x[3][108] = '%';
	}
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
	if (enemyAlive == 0)
	{
		Health_enemy = 0;
	}
}
void checkLose()
{
	if (health_hero <= 0)
	{
		cout << "Game Over" << endl;
		exit(0);
	}
}
int main()
{
	char x[35][map_width];
	int mr = 0, mc = 0;
	int enemyr = 18, enemyc = 55; // enemy row and column
	int enemydir = 1; // enemy direction (1 for right, -1 for left)
	border(x);
	ladder_level1(x);
	hero(x, mr, mc);
	health_of_hero(x);
	display(x, camera_x);
	for (;;)
	{

		//while (1)
		//{
		//	while (!_kbhit())
			//{
				camera_x = mc - 60;
				if (camera_x < 0) camera_x = 0;
				if (camera_x > map_width - 120) camera_x = map_width - 120;
				border(x);
				ladder_level1(x);
				hero(x, mr, mc);
				jumpHero(mr, mc);
				//	enemy(x, enemyr, enemyc, enemydir);
					//damage(mr, mc, enemyc, enemyr);
				killEnemy(mr, mc, enemyc, enemyr);
				checkLose();
				health_of_hero(x);
				health_enemy(x);
				display(x, camera_x);
				moveEnemy(enemyc, enemydir);
		//	}
			char movement = _getch();
			moveHero(mr, mc, movement);
		//}
	}
	return 0;
}