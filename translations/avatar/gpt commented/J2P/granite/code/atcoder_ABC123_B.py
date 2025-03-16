
import sys
from collections import defaultdict

def main():
    # Create a defaultdict to store the required values for adjustment
    map = defaultdict(int)
    
    # Read 5 integers from the user and calculate their remainders
    for i in range(5):
        a = int(input())
        r = a % 10
        
        # If the remainder is not zero, calculate the adjustment needed to make it a multiple of 10
        if r!= 0:
            b = 10 - r
            # Store the adjustment and the original value in the defaultdict
            map[b] += a
    
    # Initialize the answer variable to accumulate the result
    ans = 0
    
    # If no adjustments are needed (map is empty), sum all input values
    if len(map) == 0:
        for i in range(5):
            ans += int(input())
        print(ans)
        return
    
    # Get the last key (largest adjustment) from the defaultdict
    last = max(map.keys())
    idx = 0
    
    # Find the index of the last value in the original array
    for i in range(5):
        if map[last] == int(input()):
            idx = i
    
    # Calculate the final answer by adding values, adjusting as necessary
    for i in range(5):
        if i!= idx:
            if int(input()) % 10 == 0:
                ans += int(input())
            else:
                ans += int(input()) + (10 - int(input()) % 10)
    
    # Add the last value to the answer
    ans += int(input())
    
    # Print the final calculated answer
    print(ans)

if __name__ == "__main__":
    main()

