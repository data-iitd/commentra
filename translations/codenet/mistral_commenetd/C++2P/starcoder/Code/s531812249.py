
#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++) // Macro for repetition of a loop n times
#include<set>

//---------------------------------------------

int main(void) // Main function
{
    int n,m; // Declare variables n and m of type int

    cin>>n>>m; // Read input values of n and m from standard input

    //n gu m ki

    int ans =0; // Initialize answer variable ans to 0

    // gu gu
    ans+= n*(n-1)/2; // Calculate the sum of numbers from 1 to n-1 and add it to the answer

    //kiki
    ans +=m*(m-1)/2; // Calculate the sum of numbers from 1 to m-1 and add it to the answer

    cout<<ans<<endl; // Print the answer to the standard output





}

