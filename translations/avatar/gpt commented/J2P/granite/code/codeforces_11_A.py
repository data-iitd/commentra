
import sys

def main():
    # Reading the number of elements (n) and the divisor (d) from user input
    n, d = map(int, sys.stdin.readline().split())
    
    # Reading n integers from user input and storing them in the nums array
    nums = list(map(int, sys.stdin.readline().split()))
    
    # Initializing result variable to count the total adjustments made
    result = 0
    a = 0 # Variable to hold the difference between consecutive elements
    
    # Looping through the nums array starting from the second element
    for i in range(1, n):
        # Calculating the difference between the previous and current element
        a = (nums[i - 1] - nums[i])
        
        # If the difference is non-negative, adjustments are needed
        if a >= 0:
            # Calculating how many times we can adjust the current element
            result += a // d + 1 
            
            # Adjusting the current element to maintain the required condition
            nums[i] += (a // d + 1) * d; 
    
    # Printing the total number of adjustments made
    print(result)

if __name__ == "__main__":
    main()

