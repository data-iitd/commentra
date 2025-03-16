#include <string.h>  # Include string manipulation functions
#include <stdlib.h>  # Include memory allocation functions
#include <stdio.h>   # Include standard input/output functions

def main():
    t, h = [], []  # Declare lists for Tarō and Hanako's strings
    n = int(input())  # Read the number of rounds
    for i in range(n):  # Loop through each round
        t.append(input())  # Read Tarō's string
        h.append(input())  # Read Hanako's string
    taro, hanako = 0, 0  # Declare scores
    for i in range(n):  # Loop through each round
        if t[i] < h[i]:  # Compare and update Hanako's score
            hanako += 3
        if t[i] > h[i]:  # Compare and update Tarō's score
            taro += 3
        if t[i] == h[i]:  # If strings are equal
            taro += 1  # Increment Tarō's score by 1
            hanako += 1  # Increment Hanako's score by 1
    print(taro, hanako)  # Print the final scores


