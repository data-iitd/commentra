# Import necessary modules
import sys

def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize a list to hold the input integers
    arr = list(map(int, input().split()))
    
    # Initialize the answer with the first element of the array plus one
    ans = arr[0] + 1
    
    # Calculate the total distance based on the differences between consecutive elements
    for i in range(1, len(arr)):
        # Add the absolute difference between the current and previous element, plus 2
        ans += abs(arr[i] - arr[i - 1]) + 2
    
    # Output the final calculated answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
