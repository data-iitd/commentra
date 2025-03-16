# Importing necessary modules
import sys

def main():
    n = int(input())  # Read the size of the array
    arr = list(map(int, input().split()))  # Read n integers into the array
    
    # Initialize ans with the value of the first element plus 1
    ans = arr[0] + 1
    
    # Iterate through the array and update ans
    for i in range(1, len(arr)):
        ans += abs(arr[i] - arr[i - 1]) + 2
    
    # Print the final value of ans
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
