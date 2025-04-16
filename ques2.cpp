#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int totalSum = 0, leftSum = 0;

    for (int num : arr) {
        totalSum += num;
    }

    for (int i = 0; i < arr.size(); i++) {
        totalSum -= arr[i];

        if (leftSum == totalSum) {
            return i;
        }

        leftSum += arr[i];
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 2, 2};
    int equilibriumIndex = findEquilibriumIndex(arr);

    if (equilibriumIndex != -1) {
        cout << "Equilibrium index is: " << equilibriumIndex << endl;
    } else {
        cout << "No equilibrium index found." << endl;
    }

    return 0;
}
