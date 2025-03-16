# Import necessary modules
import sys

# Define the main function
def main():
    # Read the first integer n representing the size of the array
    n = int(input())
    
    # Create a list arr to store n integers
    arr = list(map(int, input().split()))
    
    # Initialize a variable ans with the first element of the array and add 1 to it
    ans = arr[0] + 1
    
    # Use a for loop to iterate through the remaining elements of the array arr
    for i in range(1, len(arr)):
        # Calculate the absolute difference between the current and previous elements and add it to the variable ans along with 2
        ans += abs(arr[i] - arr[i - 1]) + 2
    
    # Finally, print the value of ans to the standard output
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
