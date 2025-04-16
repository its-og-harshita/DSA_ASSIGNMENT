#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumSubarrayOfSizeK(const vector<int>& arr, int k) {
    if (arr.size() < k) {
        cerr << "Array size is smaller than subarray size K." << endl;
        return -1;
    }

    int maxSum = INT_MIN, currentSum = 0;

    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }
    maxSum = currentSum;

    for (int i = k; i < arr.size(); i++) {
        currentSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int result = maxSumSubarrayOfSizeK(arr, k);
    if (result != -1) {
        cout << "Maximum sum of any subarray of size " << k << " is: " << result << endl;
    }

    return 0;
}
