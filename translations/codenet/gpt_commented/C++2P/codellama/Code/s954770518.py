#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    # Declare an array to hold 10 integers
    s = [0] * 11

    # Input 10 integers from the user
    for i in range(0, 10):
        s[i] = int(input())

    # Sort the array of integers in ascending order
    s.sort()

    # Print the three largest integers from the sorted array
    for i in range(9, 6, -1):
        print(s[i])

    return 0 # Indicate that the program ended successfully
}
