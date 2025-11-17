#include <vector>
#include "utils.h"
using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;              
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            swaps++;                    
            swap(arr[i], arr[minIdx]);
        }
    }
}
