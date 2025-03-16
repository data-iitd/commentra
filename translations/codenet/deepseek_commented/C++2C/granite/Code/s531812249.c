
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 0x3f3f3f3f
#define eps 1e-8
const int mod=1e9+7;
typedef pair<int,int> P;

int main(void)
{
    // Include necessary libraries for input/output operations, mathematical functions, and data structures
    // Define a type alias for long long integers
    // Define a macro for a loop that iterates n times
    // Include additional libraries for sets

    int n, m;

    // Read two integers n and m from the standard input
    scanf("%d%d",&n,&m);

    // n represents the number of items, m represents the number of items

    int ans = 0;
    // Initialize a variable to store the result, which will be the sum of combinations

    // Calculate the number of ways to choose 2 items from n items (n choose 2)
    ans += n * (n - 1) / 2;

    // The formula for n choose 2 is n * (n - 1) / 2
    // Add this value to the answer

    // Calculate the number of ways to choose 2 items from m items (m choose 2)
    ans += m * (m - 1) / 2;

    // The formula for m choose 2 is m * (m - 1) / 2
    // Add this value to the answer

    // Output the final answer, which is the sum of combinations from n and m
    printf("%d\n",ans);
}

