#include <iostream>
#include <vector>
using namespace std;

vector<int> createPrefixSumArray(const vector<int>& arr) {
    vector<int> prefixSum(arr.size());
    prefixSum[0] = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    return prefixSum;
}

int rangeSum(const vector<int>& prefixSum, int L, int R) {
    if (L == 0) {
        return prefixSum[R];
    }
    return prefixSum[R] - prefixSum[L - 1];
}

int main() {
    int n, L, R;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> prefixSum = createPrefixSumArray(arr);

    cout << "Enter the range [L, R] (0-based index): ";
    cin >> L >> R;

    if (L < 0 || R >= n || L > R) {
        cout << "Invalid range!" << endl;
    } else {
        cout << "Sum of elements in the range [" << L << ", " << R << "] is: "
             << rangeSum(prefixSum, L, R) << endl;
    }

    return 0;
}
