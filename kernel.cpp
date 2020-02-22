#include "stdafx.h"
#include "kernel.h"
#include <iostream>
#include <fstream>
using namespace std;

kernel::kernel()
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			A[r][c] = 0;

			for (int n = 0; n <= 9; n++)
			{
				Table[r][c][n] = 1;
		}
	}
}
	
	
}


kernel::~kernel()
{
}

void kernel::read(char filename[])
{
	fstream f;
	f.open(filename, ios::in);
	
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			f >> Q[r][c];

		}
	}
	f.close();
}

void kernel::printQ()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Q[i][j]>0)
				cout << Q[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void kernel::printA()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (A[i][j]>0)
				cout << A[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}


void kernel::updateTable(int r, int c, int n)
{
	for (int i = 0; i < 9; i++)
	{
		Table[i][c][n] = 0;
		Table[r][i][n] = 0;
	}

	
	for (int i = r / 3 * 3; i <= r / 3 * 3 + 2; i++)
	{
		for (int j = c / 3 * 3; j <= c / 3 * 3 + 2; j++)
		{
			Table[i][j][n] = 0;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		Table[r][c][i] = 0;
	}

	Table[r][c][n] = 1;

}

bool kernel::checkTable(int r, int c, int n)
{
	int sumn=0, sumr=0, sumc=0, sum9=0;

	for (int i = 1; i <= 9; i++)
	{
		sumn += Table[r][c][i];  //n
	}

	for (int i = 0; i <= 8; i++)
	{
		sumr += Table[i][c][n];  //r
	}

	for (int i = 0; i <= 8; i++)
	{
		sumc += Table[r][i][n];  //c
	}

	for (int i = r / 3 * 3; i <= r / 3 * 3 + 2; i++)
	{
		for (int j = c / 3 * 3; j <= c / 3 * 3 + 2; j++)
		{
			sum9 += Table[i][j][n] ;  //9
		}
	}

	if ( (sumn == 1 || sumr == 1 || sumc == 1 || sum9 == 1) && Table[r][c][n] == 1)
	{
		return true;
	}
	else{
		return false;
	}
}

void kernel::solve()
{
	int count = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Q[i][j]>0){
				A[i][j] = Q[i][j];
				updateTable( i, j, Q[i][j] );
				count++;  //conut=81°±¤î
			}
		}
	}


	int r=0, c=0;
	while (count < 81)
	{
		if (A[r][c] == 0)
		{
			for (int i = 1; i <= 9; i++)
			{
				if (checkTable(r,c,i)==true)
				{ 
					A[r][c] = i;
					updateTable(r, c, i);
					count++;
					break;
				}
			}
		}
		if (r == 8 && c == 8)
		{
			r = 0;
			c = 0;
		}
		else if ( c == 8 )
		{
			r++;
			c = 0;
		}
		else
		{
			c++;
		}
	}



}

