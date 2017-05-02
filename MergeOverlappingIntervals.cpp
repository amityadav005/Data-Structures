// C++ program to merge overlapping Intervals in
// O(n Log n) time and O(1) extra space.
#include<bits/stdc++.h>

using namespace std;

// An Interval
struct Interval {
    int s, e;
};

// Function used in sort
bool mycomp(Interval a, Interval b) { return a.s < b.s; }

void mergeIntervals(Interval arr[], int n) {
    // Sort Intervals in decreasing order of
    // start time
    sort(arr, arr + n, mycomp);

    int index = 0;

    for (int i = 1; i < n; i++) {

        if (arr[i].s <= arr[index].e) {

            // Merge previous and current Intervals
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].s, arr[i].s);


        } else {
            index++;
            arr[index] = arr[i];
        }


    }

    cout << "\n The Merged Intervals are: ";
    for (int i = 0; i <= index; i++)
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}

// Driver program
int main() {
    Interval arr[] = {{6, 8},
                      {1, 9},
                      {2, 4},
                      {5, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
