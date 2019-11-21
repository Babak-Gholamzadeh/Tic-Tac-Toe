#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int dooz[3][3];
int count = 9, u;
void display(void);
int test(void);
void ai(void);
int bestmove(int);
int main()
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			dooz[i][j] = 0;
	int p;
	cout << "1. X (First)\n2. O (Second)\nChoose of number:";
	cin >> u;
	display();
	while (1)
	{
		if (count % 2 == u % 2)
		{
			cout << "(Human) Enter the position: ";
			cin >> p;
			dooz [(p-1)/3][(p-1)%3] = -1;
			display();
			count--;
		}
		if (test() == 0)
		{
			if (count == 0)
				break;
		}
		else
			break;
		ai();
		display();
		count--;
		if (test() == 0)
		{
			if (count == 0)
				break;
		}
		else
			break;
	}//end of while(1)
	cout << "Finish game\n"
		<< (test() == 0 ? "=Mosavi=" : (test() == 1 ? "AI Win" : "Human Win"));
    return 0;
}
void ai()
{
	int a[9] = {0}, i;
	for (i=0; i<9; i++)
		if (dooz[i/3][i%3] == 0)
		{
			dooz[i/3][i%3] = (count % 2 == u % 2 ? -1 : 1);
			a[i] = bestmove(count-1);
			dooz[i/3][i%3] = 0;
		}
r:
	int max = a[0], p = 0;
	for (i=0; i<9; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			p = i;
		}
	}
	if (dooz[p/3][p%3] == 0)
		dooz[p/3][p%3] = 1;
	else
	{
		a[p] = -10000;
		goto r;
	}
}
int bestmove(int c)
{
	int sum = 0;
	for (int i=0; i<9; i++)
		if (dooz[i/3][i%3] == 0)
		{
			if (test() != 0)
				return test();
			else
			{
				if (c == 0)
					return 0;
				dooz[i/3][i%3] = (c % 2 == u % 2 ? -1 : 1);
				sum += bestmove(c-1);
				dooz[i/3][i%3] = 0;
			}
		}
	return sum;
}
void display()
{
	// clrscr();
    system("cls");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
			if (dooz[i][j] ==1)
				cout << (u == 1 ? 'O' : 'X') << '\t';
			else if (dooz[i][j] == -1)
				cout << (u == 1 ? 'X' : 'O') << '\t';
			else
				cout << (i*3+j+1) << '\t';
		cout << endl;
	}
}
int test()
{
	if (dooz[0][0] + dooz[0][1] + dooz[0][2] == 3 ||
		 dooz[1][0] + dooz[1][1] + dooz[1][2] == 3 ||
		 dooz[2][0] + dooz[2][1] + dooz[2][2] == 3 ||
		 dooz[0][0] + dooz[1][0] + dooz[2][0] == 3 ||
		 dooz[0][1] + dooz[1][1] + dooz[2][1] == 3 ||
		 dooz[0][2] + dooz[1][2] + dooz[2][2] == 3 ||
		 dooz[0][0] + dooz[1][1] + dooz[2][2] == 3 ||
		 dooz[0][2] + dooz[1][1] + dooz[2][0] == 3)
		return 1;
	if (dooz[0][0] + dooz[0][1] + dooz[0][2] == -3 ||
		 dooz[1][0] + dooz[1][1] + dooz[1][2] == -3 ||
		 dooz[2][0] + dooz[2][1] + dooz[2][2] == -3 ||
		 dooz[0][0] + dooz[1][0] + dooz[2][0] == -3 ||
		 dooz[0][1] + dooz[1][1] + dooz[2][1] == -3 ||
		 dooz[0][2] + dooz[1][2] + dooz[2][2] == -3 ||
		 dooz[0][0] + dooz[1][1] + dooz[2][2] == -3 ||
		 dooz[0][2] + dooz[1][1] + dooz[2][0] == -3)
		return -1;
	return 0;
}
