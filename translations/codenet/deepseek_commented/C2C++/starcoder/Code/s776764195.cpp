#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cctype>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
using namespace std;

#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define EPS 1e-10
#define MOD 1000000007
#define MAXN 10000010

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

int getNum() {
    int n = 0;
    while (*p >= '0' && *p <= '9') {
        n = n * 10 + (*p - '0'); // Convert character to integer
        ++p;
    }
    ++p; // Move past the space or newline
    return n;
}

void putNum(int n) {
    int d;
    if (n < 10) {
        printf("0%d", n); // Write single digit number
        return;
    }
    d = n / 10;
    if (d) putNum(d); // Recursively write higher digits
    printf("%d", n - (d * 10)); // Write the last digit
}

void CountingSort(int A[], int B[], int k, int len) {
    int C[MAXN] = { 0 }; // Initialize count array
    int i, j;
    for (j = 1; j <= len; ++j) {
        ++C[A[j]]; // Count occurrences of each element
    }
    for (i = 1; i <= k; ++i) {
        C[i] += C[i - 1]; // Calculate cumulative count
    }
    for (j = len; j > 0; --j) {
        B[C[A[j]]] = A[j]; // Place elements in sorted order
        --C[A[j]]; // Decrement count for the element
    }
}

int main() {
    register int i;
    int n;
    scanf("%s", str); // Read input into the buffer
    p = str; // Reset the pointer to the start of the buffer
    n = getNum(); // Get the number of elements
    for (i = 1; i <= n; ++i) {
        A[i] = getNum(); // Read each element into the array A
    }
    CountingSort(A, B, MAXN, n); // Sort the array A using Counting Sort
    p = str; // Reset the pointer to the start of the buffer
    --n; // Decrement n to exclude the last element from the output
    for (i = 1; i <= n; ++i) {
        putNum(B[i]); // Write each sorted element
        printf(" "); // Write a space between elements
    }
    putNum(B[i]); // Write the last element without a space
    printf("\n"); // Null-terminate the string
    return 0;
}

