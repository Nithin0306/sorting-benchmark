#include <vector>
#include "utils.h"
using namespace std;

void mergeArrays(vector<int> &arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        comparisons++;                  
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSortHelper(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSortHelper(arr, l, m);
    mergeSortHelper(arr, m + 1, r);
    mergeArrays(arr, l, m, r);
}

void mergeSort(vector<int> &arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}
