#include <iostream>

using namespace std;

int main(void) {
    // Read the number of elements N
    int N;
    cin >> N;
    
    // Allocate an array mem to store the positions of elements
    // The size of the array is N + 1 to accommodate 1-based indexing
    int mem[N + 1];
    
    // Read the elements and store their positions in the array mem
    // The position is stored at the index corresponding to the element value
    for (int i = 1; i <= N; ++i) {
        int P;
        cin >> P;
        mem[P] = i;
    }

    // Initialize variables to keep track of the longest increasing subsequence
    int maxcnt = 1;
    int cnt = 1;
    
    // Iterate through the array to find the longest increasing subsequence
    for (int i = 1; i < N; ++i) {
        // Check if the current position is less than the next position
        if (mem[i] < mem[i + 1]) {
            // Increment the count of the increasing subsequence
            cnt++;
        } else {
            // Update the maximum count if the current count is greater
            maxcnt = max(maxcnt, cnt);
            // Reset the count for the next subsequence
            cnt = 1;
        }
        // Update the maximum count if the end of the array is reached
        if (i == N - 1) {
            maxcnt = max(maxcnt, cnt);
        }
    }

    // Uncommented part of the code
//    cnt = 1;
//    for (int i = N; i > 1; --i) {
//        if(mem[i] > mem[i-1]){
//            cnt++;
//        }
//    }

    // Output the result, which is the number of elements to remove
    // to make the sequence strictly decreasing
    cout << N - maxcnt << endl;
    return 0;
}