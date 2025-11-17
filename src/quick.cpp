#include <vector>
#include "utils.h"
using namespace std;

int partitionArr(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;                  
        if (arr[j] < pivot) {
            swaps++;                    
            swap(arr[i + 1], arr[j]);
            i++;
        }
    }

    swaps++;                            
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int> &arr, int low, int high) {
    if (low < high) {
        int p = partitionArr(arr, low, high);
        quickSortHelper(arr, low, p - 1);
        quickSortHelper(arr, p + 1, high);
    }
}

void quickSort(vector<int> &arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}
