#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    # Declare an integer to hold the number of elements
    n = int(input())

    # Read the number of elements from user input
    cin >> n;

    # Declare an integer to hold the number of largest elements to sum
    a = int(input())

    # Read the number of largest elements to sum from user input
    cin >> a;

    # Initialize a variable to hold the sum of the largest elements
    sum = 0

    # Declare an array to hold the elements
    s = [0] * n

    # Read the elements into the array from user input
    for i in range(n):
        s[i] = int(input())

    # Sort the array in non-decreasing order
    sort(s, s + n)

    # Sum the largest 'a' elements from the sorted array
    for i in range(n - 1, n - a - 1, -1):
        sum += s[i]

    # Output the calculated sum of the largest 'a' elements
    print(sum)

    # Return 0 to indicate successful completion of the program
    return 0
}

