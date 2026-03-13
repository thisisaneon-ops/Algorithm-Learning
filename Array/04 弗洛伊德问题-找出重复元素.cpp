// 弗洛伊德问题的数组版本
/*
给定一个包含 n + 1 个整数的数组 nums，其所有数字都在 [1, n] 范围内（包括 1 和 n）。根据抽屉原理（鸽巢原理），可知至少存在一个重复的整数。假设 nums 中只有一个重复的整数，但这个重复的数可能出现多次。需要你找出这个重复的数，并且在不修改原数组、且只使用常量级额外空间的前提下完成
*/

int arr[] = { 1,3,4,2,2 };
const int length = sizeof(arr) / sizeof(arr[0]);
int Floyd()
{
	int fast = 0;
	int slow = 0;
	do
	{
		fast = arr[arr[fast]];
		slow = arr[slow];
	} while (fast != slow);
	fast = 0;
	do {
		fast = arr[fast];
		slow = arr[slow];
	} while (fast != slow);
	return fast;
}
int main()
{
	cout << Floyd();
	return 0;
}


int arr[] = { 1,3,4,2,2 };
const int length = sizeof(arr) / sizeof(arr[0]);
int Floyd()
{
	int fast = arr[0];
	int slow = arr[arr[0]];
	while (fast != slow)
	{
		fast = arr[arr[fast]];
		slow = arr[slow];
	}
	fast = 0;
	slow = arr[slow];
	while (fast != slow)
	{
		fast = arr[fast];
		slow = arr[slow];
	}
	return fast;
}
int main()
{
	cout << Floyd();
	return 0;
}

