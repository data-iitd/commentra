#include <bits/stdc++.h>
using namespace std;

// Function to calculate the least common multiple of two numbers a and b.
int lcm(int a, int b)
{
    // Return the product of a and b divided by their greatest common divisor.
    return a * b / __gcd(a, b);
}

// Function to calculate the sum of the list A.
int sum(vector<int> &A)
{
    // Initializing the variable _sum to 0.
    int _sum = 0;
    // Iterating through each number a in the list A and updating the value of _sum.
    for (int a : A)
    {
        // Update the value of _sum.
        _sum += a;
    }
    // Return the value of _sum.
    return _sum;
}

// Function to calculate the answer using the formula _lcm * sum ( [ pow ( s, MOD - 2, MOD ) for s in A ] ) % MOD.
int answer(vector<int> &A)
{
    // Initializing the variable _lcm to 1.
    int _lcm = 1;
    // Iterating through each number a in the list A and updating the value of _lcm using the lcm function.
    for (int a : A)
    {
        // Update the value of _lcm using the lcm function.
        _lcm = lcm(_lcm, a);
    }
    // Return the answer using the formula _lcm * sum ( [ pow ( s, MOD - 2, MOD ) for s in A ] ) % MOD.
    return _lcm * sum([pow(s, MOD - 2, MOD) for s in A]) % MOD;
}

// Main function.
int main()
{
    // Reading the input N and storing the list A of N integers.
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    // Printing the final answer.
    cout << answer(A) << endl;
    return 0;
}

