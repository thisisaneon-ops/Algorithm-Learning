#include <iostream>
#include <vector>
using namespace std;

// 奇数放奇数位，偶数放偶数位
void arrangeOddEven(vector<int>& nums)
{
    int n = nums.size();
    int i = 0; // 偶数索引
    int j = 1; // 奇数索引

    while (i < n && j < n)
    {
        // 找到偶数位上不该放的偶数
        while (i < n && nums[i] % 2 == 0) i += 2;
        // 找到奇数位上不该放的奇数
        while (j < n && nums[j] % 2 == 1) j += 2;

        if (i < n && j < n)
        {
            swap(nums[i], nums[j]);
            i += 2;
            j += 2;
        }
    }
}

int main()
{
    vector<int> nums = {5, 2, 7, 8, 3, 1, 4, 6, 9, 10};
    arrangeOddEven(nums);

    for (auto& u : nums)
        cout << u << " ";
    cout << endl;

    return 0;
}
