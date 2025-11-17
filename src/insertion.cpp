#include <vector>
#include "utils.h"
using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparisons++;              
            if (arr[j] > key) {
                swaps++;                
                arr[j + 1] = arr[j];
                j--;
            } else break;
        }
        arr[j + 1] = key;
    }
}
