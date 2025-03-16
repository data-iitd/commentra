

import sys
from collections import Counter

def main():
 n = int(input()) # Read the number of elements 'n'
 a = list(map(int, input().split())) # Read the elements of the array 'a'
 ng = 0 # Initialize the lower bound of the search range
 ok = n # Initialize the upper bound of the search range

 while ok - ng > 1: # Run the while loop until the search range is narrowed down to a single element
 k = (ng + ok) // 2 # Calculate the middle index of the search range
 if is_possible(k, a): # If the middle index 'k' is a valid solution, update the upper bound
 ok = k
 else: # Otherwise, update the lower bound
 ng = k
 print(ok) # Print the solution

def is_possible(k, a):
 s = Counter() # Initialize an empty Counter's'
 current = 0 # Initialize the current index in the array 'a'

 for ai in a: # Iterate through each element in the array 'a'
 if ai <= current: # If the current element is smaller than or equal to the previous one, check if the condition 'k' is valid
 if k == 1: return False # If 'k' is 1, return false as there is no possible solution

 while s and s.most_common()[-1][0] >= ai: # If there is an element greater than or equal to 'ai' in the Counter, remove it
 s.pop(ai)

 p = ai - 1 # Calculate the previous index 'p'
 while True: # Find the previous index 'p' with the count 'k' in the Counter
 if p < 0: return False # If 'p' is out of the array bounds, return false

 s[p] = s.get(p, 0) + 1 # Update the count of 'p' in the Counter
 if s[p] == k: # If the count of 'p' is equal to 'k', remove it and move to the previous index
 s.pop(p)
 p -= 1
 else: # Otherwise, break the loop
 break
 current = ai # Update the current index
 return True # If all elements in the array 'a' are processed, return true as a valid solution is found

print(main()) # Call the main function to find the solution and print it

These comments should provide a clear understanding of the code logic and flow. Let me know if you need any further assistance.