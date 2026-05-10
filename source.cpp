#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Game Settings //
int isJumping = 0; // to check if the hero is jumping or not
int isClimbing = 0; // to check if the hero is climbing or not
int jumpdone; // to check if the jump is done or not
int pos; // save the position of the hero when he starts jumping
int velocety = 6; //controls jump height
int jumpLimit = 0;
char current_level = '1';

// Player Stats //
int health_hero = 100;
int heroDir = 1;

// Enemy Stats //
int Health_enemy = 100;
int enemyAlive = 1;

// Scrolling //
const int map_width = 500;
int camera_x = 0;
// key //
int key = 0;
void display(char x[][map_width], int camera_x)
{
	system("cls");
	for (int r = 0; r < 50; r++)
	{
		for (int c = camera_x; c < camera_x + 120; c++)
		{
			cout << x[r][c];
		}
		cout << endl;
	}
}
void border(char x[][map_width])
{
	for (int r = 0; r < 50; r++)
	{
		for (int c = 0; c < map_width; c++)
		{
			x[r][c] = ' ';
		}
	}
	for (int r = 0; r < 50; r++)
	{
		x[r][0] = 186;
		x[r][119] = 186;
		x[34][119] = ' ';
		x[33][119] = ' ';
		x[32][119] = ' ';
		x[31][119] = ' ';
		x[30][119] = ' ';
		x[29][119] = ' ';
		x[28][119] = ' ';
		x[r][119] = 186;
		x[r][240] = 186;
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
		x[49][c] = 205;
	}

}
void ladder_level1(char x[][map_width])
{
	x[48][105] = 179;
	x[47][105] = 179;
	x[46][105] = 179;
	x[45][105] = 179;
	x[44][105] = 179;
	x[43][105] = 179;
	x[42][105] = 179;
	x[41][105] = 179;
	x[40][105] = 179;
	x[39][105] = 179;
	x[38][105] = 179;
	x[37][105] = 179;
	x[36][105] = 179;
	x[35][105] = 179;
	x[48][118] = 179;
	x[47][118] = 179;
	x[46][118] = 179;
	x[45][118] = 179;
	x[44][118] = 179;
	x[43][118] = 179;
	x[42][118] = 179;
	x[41][118] = 179;
	x[40][118] = 179;
	x[39][118] = 179;
	x[38][118] = 179;
	x[37][118] = 179;
	x[36][118] = 179;
	x[35][118] = 179;
	x[47][106] = '-';
	x[47][107] = '-';
	x[47][108] = '-';
	x[47][109] = '-';
	x[47][110] = '-';
	x[47][111] = '-';
	x[47][112] = '-';
	x[47][113] = '-';
	x[47][114] = '-';
	x[47][115] = '-';
	x[47][116] = '-';
	x[47][117] = '-';
	x[44][106] = '-';
	x[44][107] = '-';
	x[44][108] = '-';
	x[44][109] = '-';
	x[44][110] = '-';
	x[44][111] = '-';
	x[44][112] = '-';
	x[44][113] = '-';
	x[44][114] = '-';
	x[44][115] = '-';
	x[44][116] = '-';
	x[44][117] = '-';
	x[41][106] = '-';
	x[41][107] = '-';
	x[41][108] = '-';
	x[41][109] = '-';
	x[41][110] = '-';
	x[41][111] = '-';
	x[41][112] = '-';
	x[41][113] = '-';
	x[41][114] = '-';
	x[41][115] = '-';
	x[41][116] = '-';
	x[41][117] = '-';
	x[38][106] = '-';
	x[38][107] = '-';
	x[38][108] = '-';
	x[38][109] = '-';
	x[38][110] = '-';
	x[38][111] = '-';
	x[38][112] = '-';
	x[38][113] = '-';
	x[38][114] = '-';
	x[38][115] = '-';
	x[38][116] = '-';
	x[38][117] = '-';
	x[35][106] = '-';
	x[35][107] = '-';
	x[35][108] = '-';
	x[35][109] = '-';
	x[35][110] = '-';
	x[35][111] = '-';
	x[35][112] = '-';
	x[35][113] = '-';
	x[35][114] = '-';
	x[35][115] = '-';
	x[35][116] = '-';
	x[35][117] = '-';
}
void hero(char x[][map_width], int mr, int mc)
{
	if (health_hero > 1)
	{
		x[46 + mr][3 + mc] = 223;
		x[47 + mr][3 + mc] = 219;
		x[48 + mr][4 + mc] = 221;
		x[48 + mr][2 + mc] = 221;
	}
}
void moveHero(int& mr, int& mc, char c)
{
	if (mc >= 99 && mc <= 116)
	{
		isClimbing = 1;
	}
	else
	{
		isClimbing = 0;
	}
	if (c == 'a' && (mc > 1 || mc > 120))
	{
		heroDir = -1;
		mc -= 3;
		if (mc >= 97 && mc <= 116)
		{
			mr += 2;
			mc -= 8;
		}
	}
	if (c == 'd' && (mc < 97 || mc>120))
	{
		heroDir = 1;
		mc += 3;
		if (mc >= 97 && mc <= 116)
		{
			mr -= 2;
			mc += 8;
		}
	}
	if (c == 'd')
	{
		mc++;
	}
	if (c == 'w')
	{
		jumpLimit++;
		if (jumpLimit <= 2 && mc < 97 && mc <= 116 || mc>120)
		{
			isJumping = 1;
			jumpdone = 0;
			pos = mr;
		}
		if (mc >= 97)
		{
			mr -= 3;
			isJumping = 0;
		}
		if (mr < -14) // limit to the top of the ladder
		{
			mr = -14;
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
		if (mr == 0 && jumpdone == 1)
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

void health_of_hero(char x[][map_width], int cam)
{
	if (health_hero == 100)
	{
		x[3][cam+2] = 'H';
		x[3][cam+3] = 'E';
		x[3][cam+4] = 'A';
		x[3][cam+5] = 'L';
		x[3][cam+6] = 'T';
		x[3][cam+7] = 'H';
		x[3][cam+8] = ':';
		x[3][cam+9] = 221;
		x[3][cam+10] = 221;
		x[3][cam+11] = 221;
		x[3][cam+12] = 221;
		x[3][cam+13] = 221;
		x[3][cam+14] = 221;
		x[3][cam+15] = 221;
		x[3][cam+16] = 221;
		x[3][cam+17] = 221;
		x[3][cam+18] = 221;
		x[3][cam+19] = '1';
		x[3][cam+20] = '0';
		x[3][cam+21] = '0';
		x[3][cam+22] = '%';
	}
	else if (health_hero == 80)
	{
		x[3][cam+2] = 'H';
		x[3][cam+3] = 'E';
		x[3][cam+4] = 'A';
		x[3][cam+5] = 'L';
		x[3][cam+6] = 'T';
		x[3][cam+7] = 'H';
		x[3][cam+8] = ':';
		x[3][cam+9] = 221;
		x[3][cam+10] = 221;
		x[3][cam+11] = 221;
		x[3][cam+12] = 221;
		x[3][cam+13] = 221;
		x[3][cam+14] = 221;
		x[3][cam+15] = 221;
		x[3][cam+16] = 221;
		x[3][cam+19] = '8';
		x[3][cam+20] = '0';
		x[3][cam+21] = '%';
	}
	else if (health_hero == 60)
	{
		x[3][cam+2] = 'H';
		x[3][cam+3] = 'E';
		x[3][cam+4] = 'A';
		x[3][cam+5] = 'L';
		x[3][cam+6] = 'T';
		x[3][cam+7] = 'H';
		x[3][cam+8] = ':';
		x[3][cam+9] = 221;
		x[3][cam+10] = 221;
		x[3][cam+11] = 221;
		x[3][cam+12] = 221;
		x[3][cam+13] = 221;
		x[3][cam+14] = 221;
		x[3][cam+19] = '6';
		x[3][cam+20] = '0';
		x[3][cam+21] = '%';
	}
	else if (health_hero == 40)
	{
		x[3][cam + 2] = 'H';
		x[3][cam + 3] = 'E';
		x[3][cam + 4] = 'A';
		x[3][cam + 5] = 'L';
		x[3][cam + 6] = 'T';
		x[3][cam + 7] = 'H';
		x[3][cam + 8] = ':';
		x[3][cam + 9] = 221;
		x[3][cam + 10] = 221;
		x[3][cam + 11] = 221;
		x[3][cam + 12] = 221;
		x[3][19] = '4';
		x[3][20] = '0';
		x[3][21] = '%';
	}
	else if (health_hero == 20)
	{
		x[3][cam + 2] = 'H';
		x[3][cam + 3] = 'E';
		x[3][cam + 4] = 'A';
		x[3][cam + 5] = 'L';
		x[3][cam + 6] = 'T';
		x[3][cam + 7] = 'H';
		x[3][cam + 8] = ':';
		x[3][cam + 9] = 221;
		x[3][cam + 10] = 221;
		x[3][cam+19] = '2';
		x[3][cam+20] = '0';
		x[3][cam+21] = '%';
	}
	else if (health_hero == 0)
	{
		x[3][cam + 2] = 'H';
		x[3][cam + 3] = 'E';
		x[3][cam + 4] = 'A';
		x[3][cam + 5] = 'L';
		x[3][cam + 6] = 'T';
		x[3][cam + 7] = 'H';
		x[3][cam + 8] = ':';
		x[3][cam+19] = '0';
		x[3][cam+20] = '%';
	}

}
void damage(int& mr, int& mc, int& enemyc, int& enemyr)
{
	if (enemyAlive == 1)
	{
		if ((48 + mr) >= (enemyr) && (45 + mr) <= (5 + enemyr) && (4 + mc) >= (enemyc) && (2 + mc) <= (18 + enemyc))
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

void checkgravity(int& mr)
{
	if (mr != 0 && isJumping == 0 && isClimbing == 0)
	{
		mr++;
	}
}
void keyhero(char x[][map_width], int& key, int& health_enemy, int cam)
{
	if (key == 0)
	{
		x[4][cam + 4] = 'K';
		x[4][cam + 5] = 'E';
		x[4][cam + 6] = 'Y';
		x[4][cam + 7] = ':';
		x[4][cam + 8] = '0';
	}
	if (key == 1)
	{
		x[4][cam + 4] = 'K';
		x[4][cam + 5] = 'E';
		x[4][cam + 6] = 'Y';
		x[4][cam + 7] = ':';
		x[4][cam + 8] = '1';
	}
	if (key == 2)
	{
		x[4][cam + 4] = 'K';
		x[4][cam + 5] = 'E';
		x[4][cam + 6] = 'Y';
		x[4][cam + 7] = ':';
		x[4][cam + 8] = '2';
	}
	if (key == 3)
	{
		x[4][cam + 4] = 'K';
		x[4][cam + 5] = 'E';
		x[4][cam + 6] = 'Y';
		x[4][cam + 7] = ':';
		x[4][cam + 8] = '3';
	}
	if (Health_enemy == 0)
	{
		key = 1;
	}
}
void health_enemy(char x[][map_width], int cam)
{
	if (Health_enemy == 100)
	{
		x[3][cam + 90] = 'E';
		x[3][cam + 91] = 'n';
		x[3][cam + 92] = 'e';
		x[3][cam + 93] = 'm';
		x[3][cam + 94] = 'y';
		x[3][cam + 95] = ':';
		x[3][cam + 96] = 221;
		x[3][cam + 97] = 221;
		x[3][cam + 98] = 221;
		x[3][cam + 99] = 221;
		x[3][cam + 100] = 221;
		x[3][cam + 101] = 221;
		x[3][cam + 102] = 221;
		x[3][cam + 103] = 221;
		x[3][cam + 104] = 221;
		x[3][cam + 105] = '1';
		x[3][cam + 106] = '0';
		x[3][cam + 107] = '0';
		x[3][cam + 108] = '%';
	}
	if (Health_enemy == 0)
	{
		x[3][cam + 90] = 'E';
		x[3][cam + 91] = 'n';
		x[3][cam + 92] = 'e';
		x[3][cam + 93] = 'm';
		x[3][cam + 94] = 'y';
		x[3][cam + 95] = ':';
		x[3][cam + 107] = '0';
		x[3][cam + 108] = '%';
	}
}
void killEnemy(int& mr, int& mc, int enemyc, int enemyr)
{
	int heroPos = 48 + mr;
	int sameCol = 0; // flag to check if hero at the same column as enemy

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

void resetGame(char x[][map_width], int& camera_x, int& mr, int& mc, int& enemyr, int& enemyc, int& enemydir)
{
	system("cls");
	cout << "Game Over. Press 'R' to restart or 'Q' to quit." << endl;
	char ch = 0;
	for (;;)
	{
		ch = _getch();
		if (ch == 'r' || ch == 'R')
			break;
		if (ch == 'q' || ch == 'Q')
			exit(0);
	}

	// Reset globals
	isJumping = 0;
	isClimbing = 0;
	jumpdone = 0;
	pos = 0;
	velocety = 6;
	jumpLimit = 0;
	current_level = '1';

	health_hero = 100;
	heroDir = 1;

	Health_enemy = 100;
	enemyAlive = 1;

	camera_x = 0;

	// Reset positions
	mr = 0;
	mc = 0;
	enemyr = 43;
	enemyc = 55;
	enemydir = 1;

	// Rebuild map
	border(x);
	ladder_level1(x);
	health_of_hero(x, camera_x);
	health_enemy(x, camera_x);
}
void checkLose(char x[][map_width], int& camera_x, int& mr, int& mc, int& enemyr, int& enemyc, int& enemydir)
{
	if (health_hero <= 0)
	{
		resetGame(x, camera_x, mr, mc, enemyr, enemyc, enemydir);
	}
}

int main()
{
	char x[50][map_width];
	int mr = 0, mc = 0;
	int enemyr = 43, enemyc = 55; // enemy row and column
	int enemydir = 1; // enemy direction (1 for right, -1 for left)
	border(x);
	ladder_level1(x);
	hero(x, mr, mc);
	health_of_hero(x, camera_x);
	display(x, camera_x);
	while (1)
	{
		while (!_kbhit())
		{
			camera_x = mc - 90;
			if (camera_x < 0) camera_x = 0;
			if (camera_x > map_width - 120) camera_x = map_width - 120;
			border(x);
			keyhero(x, key, Health_enemy, camera_x);
			ladder_level1(x);
			hero(x, mr, mc);
			jumpHero(mr, mc);
			enemy(x, enemyr, enemyc, enemydir);
			damage(mr, mc, enemyc, enemyr);
			killEnemy(mr, mc, enemyc, enemyr);
			checkLose(x, camera_x, mr, mc, enemyr, enemyc, enemydir);
			health_of_hero(x, camera_x);
			health_enemy(x, camera_x);
			checkgravity(mr);
			display(x, camera_x);
			moveEnemy(enemyc, enemydir);
		}
		char movement = _getch();
		moveHero(mr, mc, movement);
	}
	return 0;
}