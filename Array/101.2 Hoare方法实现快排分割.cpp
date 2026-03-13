// TopK快排分割和大根堆小根堆
// 先看快排分割
// 如果利用 Hole方法，我们知道，每次函数调用循环结束后都可以返回一个位置：这个位置通常是本轮pivot应该在的正确位置；
// 再看Hoare方法，最终我们看right的时候，right左侧都是 <= pivot的元素，那么可以以right为参照么？理论上可以！待会先把Hole实现了再来尝试！
// 我们尝试一下 Hoare
#include<algorithm>
int Hoare(vector<int>& nums, int i, int j)
{
	int pivot = nums[i];
	int left = i - 1;
	int right = j + 1;
	while (true)
	{
		do { left++; } while (nums[left] < pivot);
		do { right--; } while (nums[right] > pivot);
		if (left >= right) {
			break;
		}
		swap(nums[left], nums[right]);
	}
	// 回到我们昨天分析的问题：
	// 只可能出现两种情况： 1. left == right  2. left == right + 1
	// 我们要分区，应该返回哪个值 -- 应该是right！因为right左侧的值一定 <= pivot, right <= pivot, left >= pivot;
	// -- 为什么不能选 left?
	// 因为一旦把left扔到左边区间，可能会出现问题！ left是一个>或者=pivot的值，一旦大于，会对原本有序的分区打乱！！
	return right;
}
void controller(vector<int>& nums, int i, int j, int k)
{
	int pos = Hoare(nums, i, j);
	if (pos == k - 1)
	{
		return;
	}
	else if (pos < k - 1)
	{
		controller(nums, pos + 1, j, k);
	}
	else
	{
		controller(nums, i, pos - 1, k);
	}
}
int main()
{
	srand(time(nullptr));
	vector<int>nums;
	for (int i = 0; i < 1000; i++)
	{
		nums.push_back(rand() % 1000 + 1);
	}
	const int k = 5;
	controller(nums, 0, nums.size() - 1, k);
	for (int i = 0; i < k; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	cout << "========================" << endl;
	sort(nums.begin(), nums.end());
	for (auto& u : nums)
	{
		cout << u << " ";
	}
	cout << endl;
	return 0;
}
