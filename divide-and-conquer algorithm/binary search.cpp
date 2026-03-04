#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

bool binarySearch(vector<int>v, int i, int j, int target)
{
	if (i > j)
	{
		return false;
	}
	int mid = (i + j) / 2;
	if (v[mid] == target)
	{
		return true;
	}
	else if (v[mid] > target)
	{
		return binarySearch(v, i, mid - 1, target);
	}
	else
	{
		return binarySearch(v, mid + 1, j, target);
	}
}

int main()
{
	srand(time(nullptr));
	vector<int>vec;
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(rand() % 1000);
	}
	sort(vec.begin(), vec.end());
	int cnt = 0;
	for (auto& i : vec)
	{
		if (cnt != 0 && cnt % 10 == 0)
		{
			cout << endl;
		}
		cout << setw(5) << i;
		cnt++;
	}
	cout << endl;
	cout << "输入你想查找的元素：";
	int a;
	cin >> a;
	cout << "待查找：" << a << endl;
	if (binarySearch(vec, 0, vec.size() - 1, a))
	{
		cout << "该元素存在" << endl;
	}
	else
	{
		cout << "该元素不存在" << endl;
	}
	return 0;
}
