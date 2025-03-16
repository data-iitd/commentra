#include <cstdio>
#include <algorithm> # We include the algorithm library to use std::min later

def main(): # The entry point of the program
    n, m, x = map(int, input().split()) # Read three integers from the standard input

    a = [0] * 105 # Declare and initialize an array a of size 105 with zeros

    for i in range(m): # Iterate through m times
        temp = int(input()) # Read an integer from the standard input and store it in temp
        a[temp] = 1 # Set the value of the array element at index temp to 1

    ansl = 0 # Declare and initialize three integer variables: ansl, ansr, and i
    ansr = 0
    i = 0

    for i in range(x, n+1): # Iterate through the range from x to n
        ansr += a[i] # Add the value of the array element at index i to the variable ansr

    for i in range(x, -1, -1): # Iterate through the range from x to 0
        ansl += a[i] # Add the value of the array element at index i to the variable ansl

    print(min(ansl, ansr)) # Print the minimum value between ansl and ansr
    return 0 # Indicate successful termination of the program

