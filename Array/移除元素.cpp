#include <iostream>
#include <vector>
using namespace std;

/*
 * 删除数组中所有等于 target 的元素，并返回新长度（允许改变元素顺序）
 * 左右指针法实现
 */
int removeTarget_LR(vector<int>& nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j)
    {
        while (i <= j && nums[i] != target) i++;
        while (i <= j && nums[j] == target) j--;
        if (i < j)
        {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    return j + 1; // 返回新长度
}

/*
 * 删除数组中所有等于 target 的元素，并返回新长度（保持原顺序）
 * 快慢指针法实现
 */
int removeTarget_FS(vector<int>& nums, int target)
{
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++)
    {
        if (nums[fast] != target)
        {
            nums[slow++] = nums[fast];
        }
    }
    return slow; // 返回新长度
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 3, 4, 3};
    vector<int> nums2 = nums1; // 复制一份用于另一种方法

    int target = 3;

    // 左右指针法(不稳定，类似于快速排序，维护两个反向指针难度大)
    int newLength1 = removeTarget_LR(nums1, target);
    cout << "左右指针法结果: ";
    for (int i = 0; i < newLength1; i++)
        cout << nums1[i] << " ";
    cout << " 新长度: " << newLength1 << endl;

    // 快慢指针法(稳定)
    int newLength2 = removeTarget_FS(nums2, target);
    cout << "快慢指针法结果: ";
    for (int i = 0; i < newLength2; i++)
        cout << nums2[i] << " ";
    cout << " 新长度: " << newLength2 << endl;

    return 0;
}
