#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    // Read an integer input N, which represents the number of elements in the list
    int N;
    cin >> N;

    // Read a line of input, split it into individual string elements, convert them to integers,
    // and store them in a list A
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // Calculate the GCD of all elements in the list A using functools.reduce and fractions.gcd
    int gcd = accumulate(A.begin(), A.end(), 0, [](int a, int b) { return __gcd(a, b); });

    // Print the calculated GCD
    cout << gcd << endl;

    // End with comment "