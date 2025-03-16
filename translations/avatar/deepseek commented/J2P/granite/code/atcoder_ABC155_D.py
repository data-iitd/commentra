
import sys
import math
import bisect

def main():
    n = int(input()) # Read the size of the array.
    k = int(input()) # Read the target value.
    a = list(map(int, input().split())) # Read the elements of the array.
    
    a.sort() # Sort the array.
    
    l = -10**18 - 1 # Initialize the left boundary of the search.
    r = 10**18 + 1 # Initialize the right boundary of the search.
    
    while l + 1 < r: # Perform binary search.
        c = (l + r) // 2 # Calculate the middle point.
        if check(c):
            l = c # Adjust the left boundary.
        else:
            r = c # Adjust the right boundary.
    
    print(l) # Print the result.

def check(x):
    tot = 0 # Initialize the total count.
    
    for i in range(n):
        now = a[i] # Get the current element.
        l = 0 # Initialize the left boundary for binary search.
        r = n # Initialize the right boundary for binary search.
        
        if now >= 0: # If the current element is non-negative.
            while l < r: # Perform binary search.
                c = (l + r) // 2
                if now * a[c] < x:
                    l = c + 1 # Adjust the left boundary.
                else:
                    r = c # Adjust the right boundary.
            tot += l # Add the result to the total.
        else: # If the current element is negative.
            while l < r: # Perform binary search.
                c = (l + r) // 2
                if now * a[c] >= x:
                    l = c + 1 # Adjust the left boundary.
                else:
                    r = c # Adjust the right boundary.
            tot += (n - l) # Add the result to the total.
        
        if now * now < x:
            tot -= 1 # Adjust the total if necessary.
    
    if tot // 2 < k:
        return True # Return true if the count is less than k.
    else:
        return False # Return false otherwise.

main() # Call the main function.

