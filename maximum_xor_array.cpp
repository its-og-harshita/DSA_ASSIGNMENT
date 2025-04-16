
#include <iostream>
#include <vector>
using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int maxXOR = 0, mask = 0;
    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);
        unordered_set<int> prefixes;
        for (int num : nums) {
            prefixes.insert(num & mask);
        }
        int temp = maxXOR | (1 << i);
        for (int prefix : prefixes) {
            if (prefixes.count(prefix ^ temp)) {
                maxXOR = temp;
                break;
            }
        }
    }
    return maxXOR;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR: " << findMaximumXOR(nums) << endl;
    return 0;
}
