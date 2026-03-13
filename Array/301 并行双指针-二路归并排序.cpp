// 二路归并
void merge(int nums[], int i, int mid, int j)
{
	// 本轮划分的子区间是 [i, i + 1,..., mid] && [mid + 1, mid + 2,..., j]; 
	vector<int>tmp;
	int idx1 = i;
	int idx2 = mid + 1;
	while (idx1 <= mid && idx2 <= j) {

		if (nums[idx1] <= nums[idx2])  // 保证稳定性，同样大小取左边数组部分元素
		{
			tmp.push_back(nums[idx1]);
			idx1++;
		}
		else
		{
			tmp.push_back(nums[idx2]);
			idx2++;
		}
	}
	while (idx1 <= mid)
	{
		tmp.push_back(nums[idx1]);
		idx1++;
	}
	while (idx2 <= j)
	{
		tmp.push_back(nums[idx2]);
		idx2++;
	}
	// 拷贝数组内容
	for (int k = 0; k < tmp.size(); k++)
	{
		nums[i + k] = tmp[k];
	}
}
void mergesort(int nums[], int i, int j)
{
	if (i >= j)  // 递归结束条件
	{
		return;
	}
	int mid = i + (j - i) / 2;
	// 先对左边右边排序，最后merge融合一下回溯给父级函数
	mergesort(nums, i, mid);
	mergesort(nums, mid + 1, j);
	// mergesort的作用就是划分子区间直至缩小到一个元素，方便处理子问题，最后merge向上回溯给父级对象，完成排序
	merge(nums, i, mid, j);
}
int main()
{
	int nums[] = { 3,3,5,7,2,1,5,7 };
	const int length = sizeof(nums) / sizeof(nums[0]);
	mergesort(nums, 0, length - 1);
	for (auto& i : nums) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

