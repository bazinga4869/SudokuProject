#include "stdafx.h"
#include<iostream>
#include<random>
#include<algorithm>
#include<functional>
#include<fstream>
#include "generator.h"
extern int tryarray[9];
extern int sudoku[9][9];

//检查填入的数字是否重复
bool check(int x, int y, int fillnum) {
	//检查当前行
	for (int i = 0; i < y; i++) {
		if (sudoku[x][i] == fillnum)
			return false;
	}
	//检查当前列
	for (int i = 0; i < x; i++) {
		if (sudoku[i][y] == fillnum)
			return false;
	}
	//检查当前九宫格
	int count = x % 3 * 3 + y % 3;
	while (count--)
	{
		if (sudoku[x - x % 3 + count / 3][y - y % 3 + count % 3] == fillnum)
			return false;
	}
	return true;
}

//递归按行逐个填充数独
bool fill(int r, int c, int* fillarray) {
	//填充至第9行结束
	if (r > 8)
		return true;
	//当前数字未重复时:
	if (check(r, c, *fillarray)) {
		sudoku[r][c] = *fillarray;
		//继续填充下一格
		if (fill(r + (c + 1) / 9, (c + 1) % 9, tryarray))
			return true;
	}
	sudoku[r][c] = 0;
	//用于测试的数组已遍历完
	if (fillarray - tryarray >= 8)
		return false;
	//当前数字重复时:
	if (fill(r, c, fillarray + 1))
		return true;
}
void generator::generate()
{
	for (int i = 0; i <9; i++)
	{
		sudoku[0][i] = tryarray[i];
	}
	fill(1, 0, tryarray);
}