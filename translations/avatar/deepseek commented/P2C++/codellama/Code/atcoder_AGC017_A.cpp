#include <iostream>
using namespace std;

// Define a function to calculate the binomial coefficient
int combi(int N, int K)
{
    int a = 1;
    // Calculate the product part of the binomial coefficient
    for (int i = 0; i < K; i++)
    {
        a *= N - i;
    }
    // Calculate the division part of the binomial coefficient
    for (int j = 0; j < K; j++)
    {
        a /= j + 1;
    }
    return a;
}

int main()
{
    // Read the values of N and P from input
    int N, P;
    cin >> N >> P;

    // Read a list of integers from input
    int ans = 0;
    int lis[N];
    for (int i = 0; i < N; i++)
    {
        cin >> lis[i];
    }

    // Create a new list where each element is the remainder when divided by 2
    int ls[N];
    for (int i = 0; i < N; i++)
    {
        ls[i] = lis[i] % 2;
    }

    // Count the number of 1s and 0s in the list
    int one = 0, zero = 0;
    for (int i = 0; i < N; i++)
    {
        if (ls[i] == 1)
        {
            one++;
        }
        else
        {
            zero++;
        }
    }

    // Initialize variables to store the number of patterns
    int pattern_a = 0, pattern_b = 0;

    // Calculate the number of patterns with `j` zeros using the combi function
    for (int j = 0; j <= zero; j++)
    {
        pattern_b += combi(zero, j);
    }

    // Initialize time to 0 for the while loop
    int time = 0;

    // Calculate the number of patterns with `time` ones, considering the parity with P
    while (time <= one)
    {
        if (time % 2 == P)
        {
            pattern_a += combi(one, time);
        }
        time++;
    }

    // Print the result as an integer by multiplying pattern_a and pattern_b
    cout << pattern_a * pattern_b << endl;

    return 0;
}

