import sys

# Define a constant for the maximum number of elements
NUM = int(1e5 + 2)

# Define a function to read input
def read_input():
    # Read the number of elements
    N = int(input())
    
    # Initialize a list to store the numbers
    nums = []
    
    # Read N numbers from input
    for i in range(N):
        nums.append(int(input()))
    
    # Return the list of numbers
    return nums

# Define a function to calculate the answer
def calculate_answer(nums):
    # Initialize variables to track the binary state and the difference count
    bin = 0
    diff = 0
    
    # Process the numbers in sorted order
    for num in sorted(nums):
        # Check if the parity of the current index and the binary state differ
        if (bin % 2)!= (num % 2):
            diff += 1 # Increment the difference count if they differ
        
        # Update the binary state
        bin += 1
        bin %= 2 # Toggle between 0 and 1
    
    # Calculate the final answer as half of the difference count
    ans = (diff / 2)
    
    # Return the final answer
    return ans

# Define a function to print the answer
def print_answer(ans):
    # Output the result
    print(ans)

# Define a function to run the program
def run():
    # Read the list of numbers
    nums = read_input()
    
    # Calculate the answer
    ans = calculate_answer(nums)
    
    # Print the answer
    print_answer(ans)

# Run the program
run()

