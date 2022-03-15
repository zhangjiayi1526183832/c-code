// 最大子列和问题
#include <iostream>
using namespace std;
int f1(int array[], int size);
int f2(int array[], int size);
int f3(int array[], int size);
int main()
{
	int array[] = { 1,2,-4,3,-9,8,10,1,-3,1,2,6,-3 };
	cout << f1(array, size(array)) << endl;
	cout << f2(array, size(array)) << endl;
	cout << f3(array, size(array)) << endl;
}


int f1(int array[], int size)//复杂度 n*n*n
{
	int thisSum = 0;
	int maxSum = 0;
	for (int i = 0; i < size; i++)//i子列左边
	{
		for (int j = i; j < size; j++)//j子列右边
		{
			thisSum = 0;
			for (int k = i; k <= j; k++)
			{
				thisSum = thisSum + array[k];
				if (thisSum > maxSum)
					maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

int f2(int array[], int size)//复杂度n*n
{
	int thisSum = 0;
	int maxSum = 0;
	for (int i = 0; i < size; i++)//i子列左边
	{
		thisSum = 0;
		for (int j = i; j < size; j++)//j子列右边
		{
			thisSum = thisSum + array[j];
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

int f3(int array[], int size)//在线处理 复杂度n
{
	int thisSum = 0;
	int maxSum = 0;
	for (int i = 0; i < size; i++)//i子列左边
	{
		thisSum = thisSum + array[i];
		if (thisSum > maxSum)
		{
			maxSum = thisSum;
		}
		else if (thisSum < 0)
		{
			thisSum = 0;//当前子列和如果不能使后面的子列和变大，则舍去
		}
	}
	return maxSum;
}
