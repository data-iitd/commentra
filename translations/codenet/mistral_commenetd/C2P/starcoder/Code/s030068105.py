#include <stdio.h>
#include <stdlib.h>

# The main function is the entry point of the program
def main():
    n = int(input("Enter the number of elements: "))

    data = [0] * n

    for i in range(n):
        data[i] = int(input("Enter element %d: " % (i+1)))

    max = 0
    index = 0

    for i in range(n):
        if data[i] > max:
            max = data[i]
            index = i

    a = 0

    for i in range(n):
        if i!= index:
            a += data[i]

    if a > max:
        print("Yes")
    else:
        print("No")

# 