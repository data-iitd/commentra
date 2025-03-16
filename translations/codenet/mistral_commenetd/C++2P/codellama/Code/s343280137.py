#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007; // Constants definition

int main(){
    cin.tie(0); // Tie input and output streams to prevent buffer flush
    ios::sync_with_stdio(false); // Synchronize input and output streams

    // Input section
    LL n,c; // Declare variables n and c for number of elements and capacity
    cin >> n >> c; // Read input values for n and c from standard input

    vector<LL> x(n+1,0),v(n+1,0); // Declare and initialize two vectors x and v of size n+1 with zero values

    for(int i = 1; i < n+1; i++){ // Loop through each element in the array
        cin >> x[i] >> v[i]; // Read input values for x[i] and v[i] from standard input
    }

    # <START-OF-CODE>
    # Calculate left prefix sums
    lefttotal = [0]*(n+1)
    maxlefttotal = [0]*(n+1)
    for i in range(1,n+1):
        lefttotal[i] = lefttotal[i-1] + v[i] # Calculate prefix sums of vector v
        maxlefttotal[i] = max(maxlefttotal[i-1],lefttotal[i]-x[i]) # Calculate maximum prefix sums excluding current element

    # Calculate right prefix sums
    righttotal = [0]*(n+1)
    maxrighttotal = [0]*(n+1)
    for i in range(1,n+1):
        righttotal[i] = righttotal[i-1] + v[n-i+1] # Calculate prefix sums of reversed vector v
        maxrighttotal[i] = max(maxrighttotal[i-1],righttotal[i] -(c - x[n+1-i])) # Calculate maximum prefix sums excluding current element

    # Calculate answer
    ans = 0
    for i in range(1,n+1):
        ans = max(ans,lefttotal[i]-x[i]) # Calculate maximum sum by including current element in left sum
        ans = max(ans,lefttotal[i]-2*x[i]+maxrighttotal[n-i]) # Calculate maximum sum by excluding current element in left sum and including it in right sum
        ans = max(ans,righttotal[i]-(c -x[n+1-i])) # Calculate maximum sum by including current element in right sum
        ans = max(ans,righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]) # Calculate maximum sum by excluding current element in right sum and including it in left sum
    # 