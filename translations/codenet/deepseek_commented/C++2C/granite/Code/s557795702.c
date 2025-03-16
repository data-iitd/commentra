
#include<stdio.h> // Include the standard input/output library for input and output operations.
#include<stdlib.h> // Include the standard library library for standard C library functions.
#define INF 0x3f3f3f3f // Define a constant INF with the value 0x3f3f3f3f for initializing arrays.
#define MAXN 2*1e5+10 // Define a constant MAXN for the maximum number of elements in the array.
int a[MAXN],n,L[MAXN/2],R[MAXN/2]; // Declare an array a to store the elements, an integer n for the number of elements, and two arrays L and R to temporarily store the left and right halves of the array during merge sort.

// Merge function: Merges two sorted halves of the array a from index left to right.
long long merge(int left,int mid,int right){
    int i,j,k;
    long long cnt = 0;
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
long long mergesort(int left,int right){
    int mid;
    long long v1,v2,v3;
    if(left + 1 < right){
        mid = (left+right)/2;
        v1 = mergesort(left,mid);
        v2 = mergesort(mid,right);
        v3 = merge(left,mid,right);
        return v1+v2+v3;
    }
    return 0;
}

// Main function: Reads the number of elements and the elements themselves, calls the merge sort function to sort the array and compute the number of inversions, and prints the number of inversions.
int main(){
    int i;
    scanf("%d",&n);
    for(i = 0; i < n; ++i) scanf("%d",&a[i]);
    long long ans = mergesort(0,n);
    printf("%lld\n",ans);
    return 0;
}
