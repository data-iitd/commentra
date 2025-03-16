#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const long long unko = 1e12;

// Function to merge two subarrays and count inversions
long long sort(vector<long long>& a, int left, int middle, int right){
    vector<long long> l_arr(middle-left+1), r_arr(right-middle+1);
    long long cnt = 0;
    // Copy elements into temporary arrays
    for(int i=0;i<middle-left;i++) l_arr[i] = a[i+left];
    for(int i=0;i<right-middle;i++) r_arr[i] = a[i+middle];
    // Sentinel values to simplify merging
    l_arr[middle-left] = unko;
    r_arr[right-middle] = unko;
    int l=0, r=0;
    // Merge the two subarrays while counting inversions
    for(int i=0;i<right-left;i++){
        if(l_arr[l]<=r_arr[r]){
            a[left+i] = l_arr[l++];
        }
        else{
            a[left+i] = r_arr[r++];
            cnt += middle-left-l;
        }
    }
    return cnt;
}

// Recursive function to count inversions in the array
long long merge(vector<long long>& a, int left, int right){
    if(left+1<right){
        int middle = (left+right)/2;
        // Recursively count inversions in the left and right halves
        long long x1 = merge(a, left, middle);
        long long x2 = merge(a, middle, right);
        // Merge the two halves and count inversions in the merge step
        long long x3 = sort(a, left, middle, right);
        return x1+x2+x3;
    }
    else{
        return 0;
    }
}

// Main function to read input, count inversions, and print the result
int main(void){
    int n;
    cin >> n; // Read the size of the array
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i]; // Read the elements of the array
    cout << merge(a, 0, n) << endl; // Count and print the number of inversions
    return 0;
}
