#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& nums, int low, int high) {
    if (low >= high) {
        return;
    }
    int start = low;
    int end = high;
    int middle = (start + end) / 2;
    int pivot = nums[middle];

    while (start <= end) {
        while (nums[start] < pivot) {
            start++;
        }
        while (nums[end] > pivot) {
            end--;
        }
        if (start <= end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    quickSort(nums, low, end);
    quickSort(nums, start, high);
}

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    quickSort(nums, 0, nums.size() - 1);

    for (int element : nums) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
