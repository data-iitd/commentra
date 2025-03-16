#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007; // Constants definition

int main(){
    freopen("input.txt","r",stdin); // Open input file
    freopen("output.txt","w",stdout); // Open output file

    // Input section
    LL n,c; // Declare variables n and c for number of elements and capacity
    scanf("%lld %lld",&n,&c); // Read input values for n and c from standard input

    LL *x = (LL*)calloc(n+1,sizeof(LL)); // Declare and initialize two vectors x and v of size n+1 with zero values
    LL *v = (LL*)calloc(n+1,sizeof(LL));

    for(int i = 1; i < n+1; i++){ // Loop through each element in the array
        scanf("%lld %lld",&x[i],&v[i]); // Read input values for x[i] and v[i] from standard input
    }

    // Calculate left prefix sums
    LL *lefttotal = (LL*)calloc(n+1,sizeof(LL));
    LL *maxlefttotal = (LL*)calloc(n+1,sizeof(LL));
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i]; // Calculate prefix sums of vector v
        maxlefttotal[i] = max(maxlefttotal[i-1],lefttotal[i]-x[i]); // Calculate maximum prefix sums excluding current element
    }

    // Calculate right prefix sums
    LL *righttotal = (LL*)calloc(n+1,sizeof(LL));
    LL *maxrighttotal = (LL*)calloc(n+1,sizeof(LL));
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1]; // Calculate prefix sums of reversed vector v
        maxrighttotal[i] = max(maxrighttotal[i-1],righttotal[i] -(c - x[n+1-i])); // Calculate maximum prefix sums excluding current element
    }

    // Calculate answer
    LL ans = 0;
    for(int i = 1; i < n+1; i++){
        ans = max(ans,lefttotal[i]-x[i]); // Calculate maximum sum by including current element in left sum
        ans = max(ans,lefttotal[i]-2*x[i]+maxrighttotal[n-i]); // Calculate maximum sum by excluding current element in left sum and including it in right sum
        ans = max(ans,righttotal[i]-(c -x[n+1-i])); // Calculate maximum sum by including current element in right sum
        ans = max(ans,righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]); // Calculate maximum sum by excluding current element in right sum and including it in left sum
    }

    // Output answer
    printf("%lld\n",ans);

    return 0;
}
