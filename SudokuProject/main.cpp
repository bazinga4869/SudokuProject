
#include "stdafx.h"
#include<iostream>
#include<random>
#include<algorithm>
#include<functional>
#include<fstream>
#include "generator.h"

using namespace std;
int sudoku[9][9] = { 0 };
int tryarray[9] = {6,1,2,3,4,5,7,8,9};

int main(int arg, char* args[])
{
	int num;
	
	if (arg == 3)
	{
		if (strcmp(args[1], "-c")==0)
		{
			if (atoi(args[2]))
			{
				num = atoi(args[2]);
				//限定左上角第一个数字后第一行数字的全排列共8!种
				if (num > 0 && num <= 40320)
				{
					ofstream outfile("sudoku.txt");
					if (!outfile.is_open())
					{
						std::cout << " the file open fail" << endl;
						exit(1);
					}
					for (int i = 0; i < num; i++)
					{
						generator sudo;
						sudo.generate();
						for (int i = 0; i < 9; i++)
						{
							for (int j : sudoku[i])
							{
								outfile << j << " ";
							}
							outfile << "\n";
						}
						outfile << "\n";
						//更新第一行的全排列
						std::next_permutation(tryarray, tryarray + 8);
					}
					outfile.close();
				}
			}
			else {
				std::cout << "number non-integer or out of range";
				std::cout << endl;
			}
		}
		else {
			std::cout << "Illegal Input";
			std::cout << endl;
		}
	}
	else {
		std::cout << "Illegal Input";
		std::cout << endl;
	}
	system("pause");
	return 0;
}
