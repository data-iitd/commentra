#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

public class Main {
    public static void main(String[] args) {
        int n;
        cin >> n; // Read the number of test cases
        while (n--){
            int p, q;
            cin >> p >> q; // Read the values of p and q for each test case
            int l = sqrt(p*p + q*q); // Calculate the length of the hypotenuse
            boolean isprime = true; // Initialize a flag to check if the number is prime
            for (int i=0; i<l; ++i) { // Loop through all pairs (i, j) within the range of l
                for (int j=0; j<l; ++j) {
                    int x = i*i + j*j; // Calculate the sum of squares
                    if (x <= 1 || x >= p*p + q*q) continue; // Skip if x is out of range
                    if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) isprime = false; // Check the conditions
                }
            }
            cout << (isprime ? "P" : "C") << endl; // Print the result
        }
    }
}

