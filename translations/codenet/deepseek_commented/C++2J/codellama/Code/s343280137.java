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

public class Main {
    public static void main(String[] args) {
        // Step 1: Input Reading
        long long n, c;
        Scanner sc = new Scanner(System.in);
        n = sc.nextLong();
        c = sc.nextLong();

        // Step 2: Vector Initialization
        long long[] x = new long long[n+1];
        long long[] v = new long long[n+1];

        // Step 3: Reading Positions and Values
        for(int i = 1; i < n+1; i++){
            x[i] = sc.nextLong();
            v[i] = sc.nextLong();
        }

        // Step 4: Calculate Total Value Moving Left
        long long[] lefttotal = new long long[n+1];
        long long[] maxlefttotal = new long long[n+1];
        for(int i = 1; i < n+1; i++){
            lefttotal[i] = lefttotal[i-1] + v[i];
        }

        // Step 5: Calculate Maximum Value Left
        for(int i = 1; i < n+1; i++){
            maxlefttotal[i] = Math.max(maxlefttotal[i-1], lefttotal[i] - x[i]);
        }

        // Step 6: Calculate Total Value Moving Right
        long long[] righttotal = new long long[n+1];
        long long[] maxrighttotal = new long long[n+1];
        for(int i = 1; i < n+1; i++){
            righttotal[i] = righttotal[i-1] + v[n-i+1];
        }

        // Step 7: Calculate Maximum Value Right
        for(int i = 1; i < n+1; i++){
            maxrighttotal[i] = Math.max(maxrighttotal[i-1], righttotal[i] - (c - x[n+1-i]));
        }

        // Step 8: Calculate the Maximum Value
        long long ans = 0;
        for(int i = 1; i < n+1; i++){
            ans = Math.max(ans, lefttotal[i] - x[i]);
            ans = Math.max(ans, lefttotal[i] - 2*x[i] + maxrighttotal[n-i]);
            ans = Math.max(ans, righttotal[i] - (c - x[n+1-i]));
            ans = Math.max(ans, righttotal[i] - 2*(c - x[n+1-i]) + maxlefttotal[n-i]);
        }

        // Step 9: Output the Result
        System.out.println(ans);
    }
}

