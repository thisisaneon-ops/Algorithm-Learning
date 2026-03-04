#include<iostream>
using namespace std;

void func(int arr[], int i, int len, int x[])
{
	if (i == len)  // 递归结束的条件  防止StackOverFlow
	{
		bool isexist = false;
		for (int j = 0; j < len; ++j)
		{
			if(x[j] != 0)
			{
				isexist = true;
				cout << arr[j] << " ";
			}
		}
		if (!isexist)
		{
			cout << "null";
		}
		cout << endl;
	}
	else
	{
		x[i] = 1;  // 选择i节点
		func(arr, i + 1, len, x);  // i节点用完，需要丢弃
		x[i] = 0;  // 不选择i节点
		func(arr, i + 1, len, x);
		// 问题：会打印多少次 1 2 3? 8次 = 2^(3-0);

	}
}

int main()
{
	int arr[] = { 1,2,3 };  // subset 1 2 3 12 13 23 123
	int x[3] = { 0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	func(arr, 0, len, x);
	return 0;
}
