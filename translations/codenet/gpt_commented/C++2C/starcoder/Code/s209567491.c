#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <set>
using namespace std;
typedef long long ll;

int main(int argc, char *args[]) {
    // Declare variables for number of friends (N), days (D), and initial chocolates (X)
    int N, D, X;
    // Variable to store the total number of chocolates
    int num_of_chocolate;
    // Counter for the number of days
    int counter;
    // Variable to track days for each friend
    int days;
    // Array to hold the chocolate consumption rate for each friend
    int A[101];

    // Input the number of friends, days, and initial chocolates
    scanf("%d %d %d", &N, &D, &X);

    // Input the chocolate consumption rates for each friend
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Initialize the total number of chocolates with the initial amount
    num_of_chocolate = 0;

    // Loop through each friend to calculate the number of chocolates they will consume
    for (int i = 0; i < N; i++) {
        // Reset days and counter for each friend
        days = 0;
        counter = 0;

        // Calculate how many chocolates can be consumed within the given days
        for (int j = 0;; j++) {
            // Calculate the total days required to consume chocolates
            days = j * A[i] + 1;
            // If the calculated days are within the limit, increment the counter
            if (days <= D) {
                counter++;
            }
            // Break the loop if the days exceed the limit
            else {
                break;
            }
        }
        // Add the count of chocolates consumed by this friend to the total
        num_of_chocolate = num_of_chocolate + counter;
    }

    // Add the initial chocolates to the total count
    num_of_chocolate = num_of_chocolate + X;

    // Output the total number of chocolates
    printf("%d\n", num_of_chocolate);
}

