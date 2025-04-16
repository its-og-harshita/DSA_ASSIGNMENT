
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return {left, right};
        else if (sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 6};
    int target = 6;
    auto result = twoSum(nums, target);
    cout << "Indices: " << result.first << ", " << result.second << endl;
    return 0;
}
