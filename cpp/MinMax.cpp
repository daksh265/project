#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int* findMinMax(vector<int>& arr, int low, int high, int result[]) {
    if (low == high) {
        result[0] = arr[low];
        result[1] = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result[0] = arr[low];
            result[1] = arr[high];
        } else {
            result[0] = arr[high];
            result[1] = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
    findMinMax(arr, low, mid, result);
    int leftMin = result[0], leftMax = result[1];

    findMinMax(arr, mid + 1, high, result);
    int rightMin = result[0], rightMax = result[1];

    result[0] = min(leftMin, rightMin);
    result[1] = max(leftMax, rightMax);

    return result;
}

int main() {
    vector<int> arr = {3, 5, 7, 2, 8, -1, 4, 10, 12};
    int result[2] = {INT_MAX, INT_MIN};

    findMinMax(arr, 0, arr.size() - 1, result);
    cout << "Minimum: " << result[0] << endl;
    cout << "Maximum: " << result[1] << endl;

    return 0;
}
