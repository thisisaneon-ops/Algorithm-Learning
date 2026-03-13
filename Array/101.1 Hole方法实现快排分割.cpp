// TopK快排分割和大根堆小根堆
// 先看快排分割
// 如果利用 Hole方法，我们知道，每次函数调用循环结束后都可以返回一个位置：这个位置通常是本轮pivot应该在的正确位置；
// 再看Hoare方法，最终我们看right的时候，right左侧都是 <= pivot的元素，那么可以以right为参照么？理论上可以！待会先把Hole实现了再来尝试！
#include<iostream>
using namespace std;

int partition(vector<int>& nums, int left, int right)
{
	int pivot = nums[left];  // 这里就不三数取中了
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && nums[j] >= pivot)
		{
			j--;
		}
		if (i < j)
		{
			nums[i] = nums[j];
			i++;
		}
		while (i < j && nums[i] <= pivot)
		{
			i++;
		}
		if (i < j)
		{
			nums[j] = nums[i];
			j--;
		}
	}
	nums[j] = pivot;
	return j;
}

void controller(int k, vector<int>& nums, int i, int j)
{
	int pos = partition(nums, i, j);
	if (pos == k - 1)
	{
		return;
	}
	else if (pos < k - 1)  // 说明需要往右边走
	{
		controller(k, nums, pos + 1, j);
	}
	else
	{
		controller(k, nums, i, pos - 1);
	}
}

int main()
{
	srand(time(nullptr));
	vector<int>v;
	for (int i = 0; i < 500; i++)
	{
		v.push_back(rand() % 500 + 1);
	}
	const int k = 10;  // 找前10小元素；即Top10元素(大完全一样，就是把idx反过来减一下就可以)
	controller(k, v, 0, v.size() - 1);
	for (int i = 0; i < k; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
