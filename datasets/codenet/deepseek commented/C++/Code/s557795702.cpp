#include<iostream> // Include the iostream library for input and output operations.
#include<algorithm> // Include the algorithm library for using the sort function.
#include <cstdlib> // Include the cstdlib library for standard C library functions.
#define INF 0x3f3f3f3f // Define a constant INF with the value 0x3f3f3f3f for initializing arrays.
using namespace std; // Use the standard namespace.
typedef long long LL; // Define a long long integer type for convenience.
const int MAXN = 2*1e5+10; // Define a constant MAXN for the maximum number of elements in the array.
int a[MAXN],n,L[MAXN/2],R[MAXN/2]; // Declare an array a to store the elements, an integer n for the number of elements, and two arrays L and R to temporarily store the left and right halves of the array during merge sort.

// Merge function: Merges two sorted halves of the array a from index left to right.
LL merge(int left,int mid,int right){
    int i,j,k;
    LL cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    for(i = 0; i < n1; ++i)	L[i] = a[left+i];
    for(i = 0; i < n2; ++i)	R[i] = a[mid+i];
    L[n1] = R[n2] = INF;
    i = j = 0;
    for(k = left; k < right; ++k){
        if(L[i] <= R[j]) a[k] = L[i++];
        else{
            a[k] = R[j++];
            cnt += n1-i;
        }
    }
    return cnt;
}

// Merge sort function: Recursively divides the array into halves and sorts them using merge sort.
LL mergesort(int left,int right){
    int mid;
    LL v1,v2,v3;
    if(left + 1 < right){
        mid = (left+right)/2;
        v1 = mergesort(left,mid);
        v2 = mergesort(mid,right);
        v3 = merge(left,mid,right);
        return v1+v2+v3;
    }
    return 0;
}

// Main function: Synchronizes the input/output streams, reads the number of elements and the elements themselves, calls the merge sort function to sort the array and compute the number of inversions, and prints the number of inversions.
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0; i < n; ++i) cin>>a[i];
    LL ans = mergesort(0,n);
    cout<<ans<<'\n';
    return 0;
}
