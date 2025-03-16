#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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

def main(argc, args):
    # Declare variables for number of friends (N), days (D), and initial chocolates (X)
    N = 0
    D = 0
    X = 0
    # Variable to store the total number of chocolates
    num_of_chocolate = 0
    # Counter for the number of days
    days = 0
    # Variable to track days for each friend
    counter = 0
    # Array to hold the chocolate consumption rate for each friend
    A = [0] * 101

    # Input the number of friends, days, and initial chocolates
    N, D, X = map(int, input().split())

    # Input the chocolate consumption rates for each friend
    for i in range(N):
        A[i] = int(input())

    # Initialize the total number of chocolates with the initial amount
    num_of_chocolate = 0

    # Loop through each friend to calculate the number of chocolates they will consume
    for i in range(N):
        # Reset days and counter for each friend
        days = 0
        counter = 0

        # Calculate how many chocolates can be consumed within the given days
        for j in range(101):
            # Calculate the total days required to consume chocolates
            days = j * A[i] + 1
            # If the calculated days are within the limit, increment the counter
            if days <= D:
                counter += 1
            # Break the loop if the days exceed the limit
            else:
                break
        # Add the count of chocolates consumed by this friend to the total
        num_of_chocolate += counter

    # Add the initial chocolates to the total count
    num_of_chocolate += X

    # Output the total number of chocolates
    print(num_of_chocolate)


