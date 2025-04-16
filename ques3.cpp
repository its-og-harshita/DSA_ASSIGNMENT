#include <iostream>
#include <vector>
using namespace std;

bool canSplitArray(const vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) {
        totalSum += num;
    }

    int prefixSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        int suffixSum = totalSum - prefixSum;
        if (prefixSum == suffixSum) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    if (canSplitArray(arr)) {
        cout << "The array can be split into two parts with equal sum." << endl;
    } else {
        cout << "The array cannot be split into two parts with equal sum." << endl;
    }
    return 0;
}