#include "stdafx.h"
#include<iostream>
#include<random>
#include<algorithm>
#include<functional>
#include<fstream>
#include "generator.h"
extern int tryarray[9];
extern int sudoku[9][9];

//�������������Ƿ��ظ�
bool check(int x, int y, int fillnum) {
	//��鵱ǰ��
	for (int i = 0; i < y; i++) {
		if (sudoku[x][i] == fillnum)
			return false;
	}
	//��鵱ǰ��
	for (int i = 0; i < x; i++) {
		if (sudoku[i][y] == fillnum)
			return false;
	}
	//��鵱ǰ�Ź���
	int count = x % 3 * 3 + y % 3;
	while (count--)
	{
		if (sudoku[x - x % 3 + count / 3][y - y % 3 + count % 3] == fillnum)
			return false;
	}
	return true;
}

//�ݹ鰴������������
bool fill(int r, int c, int* fillarray) {
	//�������9�н���
	if (r > 8)
		return true;
	//��ǰ����δ�ظ�ʱ:
	if (check(r, c, *fillarray)) {
		sudoku[r][c] = *fillarray;
		//���������һ��
		if (fill(r + (c + 1) / 9, (c + 1) % 9, tryarray))
			return true;
	}
	sudoku[r][c] = 0;
	//���ڲ��Ե������ѱ�����
	if (fillarray - tryarray >= 8)
		return false;
	//��ǰ�����ظ�ʱ:
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