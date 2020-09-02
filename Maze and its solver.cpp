#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
char maze[12][12] = { '#','#', '#','#','#','#','#','#','#','#','#','#',
'#',' .',' .',' .','#','.','.','.','.' ,'.', '.', '#',
'.','.','#', '.','#', '.' ,'#', '#','#', '#', '.' ,'#',
'#', '#', '#', '.', '#' ,'.' ,'.' ,'.' ,'.' ,'#' ,'.' ,'#',
'#', '.' ,'.' ,'.' ,'.' ,'#','#', '#' ,'.' ,'#' ,'.' ,'.',
'#' ,'#', '#', '#' ,'.', '#', '.', '#', '.', '#','.' ,'#',
'#', '.' ,'.', '#' ,'.', '#', '.', '#', '.' ,'#' ,'.', '#',
'#', '#', '.', '#','.' ,'#', '.', '#', '.', '#', '.', '#',
'#', '.' ,'.', '.', '.', '.', '.', '.', '.', '#' ,'.', '#',
'#', '#', '#' ,'#' ,'#', '#', '.', '#' ,'#' ,'#', '.', '#',
'#' ,'.' ,'.', '.' ,'.' ,'.' ,'.' ,'#' ,'.' ,'.', '.', '#',
'#' ,'#' ,'#' ,'#' ,'#', '#', '#' ,'#', '#' ,'#', '#', '#' };
int horimoves[4] = { 1,-1,0,0 };
int vertmoves[4] = { 0,0,1,-1 };
int startrow = 0, startcol = 0, endrow = 0, endcol = 0;

void findstart(int &row, int &col);
int issafe(int row, int col);
void findend(int& row, int& col);
int findpath(int startrow, int starcol, int endrow, int endcol);
int main(void)
{
	findstart(startrow, startcol);
	findend(endrow, endcol);	
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
			cout<<maze[i][j] << ' ';
		cout << endl;
	}
	cout << endl << endl;
	maze[startrow][startcol] = '_';
	findpath(startrow, startcol, endrow, endcol);
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
			cout<<maze[i][j]<<' ';
		cout << endl;
	}
}

void findstart(int &row,int &col)
{
	for ( row ; row < 12; row++)
		if (maze[row][col] == '.')
			return;
	row--;
	for (col; col < 12; col++)
		if (maze[row][col]=='.')
			return;
	col--;
	for (row; row >= 0; row--)
	{
		if (maze[row][col] == '.')
			return;
	}
	row++;
	for (col; col >=0; col--)
		if (maze[row][col] == '.')
			return;
	col++;
}
int issafe(int row, int col)
{
	if (row < 12 && row >= 0 && col >= 0 && col < 12 && maze[row][col] == '.')
		return 1;
	else return 0;
}
void findend(int& row, int& col)
{
	for (col; col < 12; col++)
		if (maze[row][col] == '.')
			return;
	col--;
	for (row; row < 12; row++)
		if (maze[row][col] == '.')
			return;
	row--;
	for (col; col >= 0; col--)
		if (maze[row][col] == '.')
			return;
	col++;
	for (row; row >= 0; row--)
	{
		if (maze[row][col] == '.')
			return;
	}row++;
}

int findpath(int startroww, int startcoll, int endroww, int endcoll)
{
	int nextx, nexty;
	if (startroww == endroww && startcoll == endcoll)
	{
		return 1;
	}
	
	for (int i=0; i < 4; i++)
	{
		nextx = startcoll + horimoves[i];
		nexty = startroww+ vertmoves[i];
		if (issafe(nexty, nextx))
		{
			maze[nexty][nextx] = '_';
			if (findpath(nexty, nextx, endroww, endcoll) == 1)
			{
				return 1;
			}
			else
			{
				maze[nexty][nextx] = '.';
			}
		}
	}
	return 0;

}



















