# Import the sys module and assign the stdin.readline() function to a variable named input()
import sys

# Read an integer n from the standard input
n = int(input())

# Create a list a of size n by reading n integers from the standard input and applying the map() function to convert each input integer to an integer
a = list(map(int, input().split()))

# Initialize two variables, pre and ans, to float('inf') and 0, respectively
pre = float('inf')
ans = 0

# Sort the list a in descending order using the sort() method
a.sort(reverse=True)

# Iterate through the list a using a for loop
for j in range(n):
    # Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
    ans += max(0, min(pre - 1, a[j]))
    
    # Update the value of pre to be the minimum of pre - 1 and a[j].
    pre = min(pre - 1, a[j])

# After the loop, print the value of ans.
print(ans)
