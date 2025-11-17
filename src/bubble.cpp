#include <vector>
#include "utils.h"
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            comparisons++;              
            if (arr[j] > arr[j + 1]) {
                swaps++;                
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
