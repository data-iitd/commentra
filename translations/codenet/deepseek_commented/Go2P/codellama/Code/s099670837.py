
# Go:
package main

import "fmt"

var n, ans int # Declare variables n and ans to store the size of the array and the result respectively.

const arraySize = 101 # Define a constant arraySize to set the size of the 2D array.

var a = [arraySize][arraySize]int{} # Declare a 2D array a with dimensions [arraySize][arraySize].

# findAns is a recursive function that explores all possible paths from the top-left to the bottom-right corner of the array.
def findAns(i, j, sum):
    if i == 1 and j == n-1 and sum+a[i][j] > ans: # Check if the current position is the bottom-right corner and if the current sum plus the value at a[i][j] is greater than the current ans.
        ans = sum + a[i][j] # Update ans if the condition is met.
        return # Return to stop further recursion.
    if i == 0: # If the current row is the first row, move to the next row.
        findAns(i+1, j, sum+a[i][j]) # Recursively call findAns with the next row.
    if j+1 < n: # If the current column is within bounds, move to the next column.
        findAns(i, j+1, sum+a[i][j]) # Recursively call findAns with the next column.

# main function to execute the program.
def main():
    fmt.Scanf("%d", &n) # Read the value of n from the input.
    for i in range(0, 2): # Loop through the first two rows of the array.
        for j in range(0, n): # Loop through each column of the current row.
            fmt.Scanf("%d", &a[i][j]) # Read the value into the array a from the input.
    findAns(0, 0, 0) # Call the findAns function with initial parameters (0, 0, 0).
    fmt.Println(ans) # Print the final value of ans.

