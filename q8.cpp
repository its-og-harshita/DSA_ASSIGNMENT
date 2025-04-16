#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findTwoSum(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {-1, -1};

int main() {
    vector<int> nums = {1, 2, 3, 4, 6, 8, 10};
    int target = 10;

    pair<int, int> result = findTwoSum(nums, target);
    if (result.first != -1) {
        cout << "Pair found: " << result.first << ", " << result.second << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}