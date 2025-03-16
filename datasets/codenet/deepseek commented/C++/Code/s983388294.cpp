#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

/*
 * Step 1: Include necessary headers
 * The code starts by including several headers. These headers provide various functionalities such as input/output operations, string manipulation, mathematical operations, and more.
 */

int main(int argc, char* argv[])
{
    /*
     * Step 2: Define main function
     * The main function is the entry point of the program. It initializes variables and processes the input.
     */
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    int i;
    for(i=0; i<n; i++) {
        /*
         * Step 3: Read input
         * The program reads an integer `n` which represents the number of elements in the array.
         * It then reads `n` integers and stores them in a vector `a`.
         */
        scanf("%d", &a[i]);
    }
    int curr=0;
    for(i=0; i<n; i++) {
        /*
         * Step 4: Process the array
         * The program initializes a variable `curr` to 0.
         * It iterates through the array `a` and updates `curr` based on the condition `a[i] == curr + 1`.
         */
        if(a[i]==curr+1) curr++;
    }
    if(curr>0) {
        /*
         * Step 5: Output the result
         * If `curr` is greater than 0, it prints the number of elements that need to be removed to make the sequence continuous, which is `n - curr`.
         * If `curr` is 0, it prints `-1` indicating that it's not possible to make the sequence continuous.
         */
        printf("%d\n", n-curr);
    }
    else {
        printf("-1\n");
    }

    /*
     * Step 6: Return 0
     * The main function returns 0 to indicate successful execution.
     */
    return 0;
}
