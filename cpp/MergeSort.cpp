#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& merged, vector<int>& left, vector<int>& right) {
    int i = 0, j = 0, k = 0;

    while (j < left.size() && k < right.size()) {
        if (left[j] <= right[k]) {
            merged[i++] = left[j++];
        } else {
            merged[i++] = right[k++];
        }
    }

    while (j < left.size()) {
        merged[i++] = left[j++];
    }

    while (k < right.size()) {
        merged[i++] = right[k++];
    }
}

void mergeSort(vector<int>& nums) {
    if (nums.size() <= 1) {
        return;
    }

    int mid = nums.size() / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid, nums.end());

    mergeSort(left);
    mergeSort(right);

    merge(nums, left, right);
}

int main() {
    vector<int> nums = {3, 1, 7, 5, 11, 9, 432, 564, 12, 1123, 153};

    mergeSort(nums);

    cout << "Sorted Array: ";
    for (int element : nums) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
