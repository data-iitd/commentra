
#include<stdio.h>
#define N 2000
int num1,math[N+1];

// Initialize variables
int a, num2, ans, sum = 0;
int i, j;

// Initialize math array with first element as 1
math[0] = 1;

// Read the number of integers to be input
print("Enter the number of integers to be input:")
num1 = int(input())

// Read each integer and calculate its sum
for i in range(num1):
    print("Enter an integer:")
    a = int(input())
    sum += a

    // Mark all the previous numbers as visited
    for j in range(sum-a, -1, -1):
        if math[j] == 1:
            math[j+a] = 1

// Read the number of integers to be checked
print("Enter the number of integers to be checked:")
num2 = int(input())

// Check each integer and print the result
for i in range(num2):
    print("Enter an integer to check:")
    ans = int(input())
    if math[ans] == 1:
        print("yes")
    else:
        print("no")

# 