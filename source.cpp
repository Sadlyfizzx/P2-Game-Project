#include <iostream>
#include <conio.h>
using namespace std;

// Game Settings //
int isJumping = 0; // to check if the hero is jumping or not
int jumpdone; // to check if the jump is done or not
int pos; // save the position of the hero when he starts jumping
int velocety = 3; //controls jump height
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
//editor fares
void border(char x[][120])//frame
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
//editor fares
void ladder_level1(char x[][120])//selm
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
//editor fares
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
//editor fares
void moveHero(int& mr, int& mc, char c)//move left,right ,upper,lower
{
	if (c == 'a' && mc > 1)//left
	{
		mc -= 3;
		if (mr < 0 && mc < 105)//If he reaches the ladder, he won't move.
		{
			mc += 3;
		}
	}
	if (c == 'd' && mc < 111)//right
	{
		mc += 3;
		if (mc >= 104 && mc <= 106)//The first thing he does when he reaches the stairs is take the first step.
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

	if (c == 'w')	//upper
	{
		isJumping = 1;
		jumpdone = 0;
		pos = mr;
		if (mr < 16&&mc>104)//climb the stairs
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
		mr +=2;
	}
	}
}
//editor fares&&zeyad
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
//editor zeyad
void enemy(char x[][120], int er, int ec)
{
	x[22 + er][3 + ec] = '[';
	x[22 + er][4 + ec] = 'O';
	x[22 + er][5 + ec] = ']';

	x[23 + er][3 + ec] = '/';
	x[23 + er][5 + ec] = '\\';
}
//editor zeyad
// Move the enemy, we can control the range of moving by edit 50 and 60
void moveEnemy(int& enec, int& enedir)
{
	if (enedir == 1 && enec == 60)
		enedir = -1;
	if (enedir == -1 && enec == 50)
		enedir = 1;
	enec += enedir;
}
//editor zeyad
int main()
{
	char x[25][120];
	int mr = 0, mc = 0;
	int enemyr = 0, enemyc = 55; // enemy row and column
	int enemydir = 1; // enemy direction (1 for right, -1 for left)
	border(x);
	ladder_level1(x);
	hero(x, mr, mc);
	display(x);
	for (;;)
	{
		while (1)
		{
			//Game loop while not pressing any keys 
			while (!_kbhit())
				{
					border(x);
					ladder_level1(x);
					hero(x, mr, mc);
					jumpHero(mr);
					enemy(x, enemyr, enemyc);
					if ((23 + mr) >= (22 + enemyr) && (20 + mr) <= (23 + enemyr) && (4 + mc) >= (3 + enemyc) && (2 + mc) <= (5 + enemyc))
					{
						cout << "Game Over" << endl;
					}
					display(x);
					moveEnemy(enemyc, enemydir);
			}
			char movement = _getch();
			moveHero(mr, mc, movement);
		}
	
	}
	return 0;
}
