#include <bits/stdc++.h>
#include "utils.h"
using namespace std;


void bubbleSort(vector<int>&);
void selectionSort(vector<int>&);
void insertionSort(vector<int>&);
void mergeSort(vector<int>&);
void quickSort(vector<int>&);

long long getTimeUs() {
    return chrono::duration_cast<chrono::microseconds>(
        chrono::high_resolution_clock::now().time_since_epoch()
    ).count();
}

void testSort(const string &algo, const string &caseType,
              vector<int> arr, void (*sortFunc)(vector<int>&),
              ofstream &csv)
{
    resetCounters();

    long long start = getTimeUs();
    sortFunc(arr);
    long long end = getTimeUs();

    csv << arr.size() << ","
        << caseType << ","
        << algo << ","
        << comparisons << ","
        << swaps << ","
        << (end - start) << "\n";
}

int main() {
    system("mkdir results >nul 2>nul");

    ofstream csv("results/results.csv", ios::out | ios::trunc);
    csv << "SIZE,CASE,ALGORITHM,COMPARISONS,SWAPS,TIME(us)\n";

    vector<int> sizes = {500, 1000, 2000, 3000, 5000};

    for (int n : sizes) {

        vector<int> best(n), worst(n), avg(n);
        iota(best.begin(), best.end(), 1);
        iota(worst.rbegin(), worst.rend(), 1);
        avg = best;
        shuffle(avg.begin(), avg.end(), mt19937(random_device{}()));

        testSort("BUBBLE", "BEST", best, bubbleSort, csv);
        testSort("SELECTION", "BEST", best, selectionSort, csv);
        testSort("INSERTION", "BEST", best, insertionSort, csv);
        testSort("MERGE", "BEST", best, mergeSort, csv);
        testSort("QUICK", "BEST", best, quickSort, csv);

        testSort("BUBBLE", "AVERAGE", avg, bubbleSort, csv);
        testSort("SELECTION", "AVERAGE", avg, selectionSort, csv);
        testSort("INSERTION", "AVERAGE", avg, insertionSort, csv);
        testSort("MERGE", "AVERAGE", avg, mergeSort, csv);
        testSort("QUICK", "AVERAGE", avg, quickSort, csv);

        testSort("BUBBLE", "WORST", worst, bubbleSort, csv);
        testSort("SELECTION", "WORST", worst, selectionSort, csv);
        testSort("INSERTION", "WORST", worst, insertionSort, csv);
        testSort("MERGE", "WORST", worst, mergeSort, csv);
        testSort("QUICK", "WORST", worst, quickSort, csv);
    }

    csv.close();
    cout << "CSV generated at: results/results.csv\n";
    return 0;
}
