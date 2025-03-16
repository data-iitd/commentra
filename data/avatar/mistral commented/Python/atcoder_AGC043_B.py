# Define a helper function 'twos_in_factorial' to count the number of twos in the factorial of a given number
def twos_in_factorial(n):
    # Calculate the number of twos in the factorial of 'n' using the number of '1' bits in the binary representation of 'n'
    return n - bin(n).count('1')

# Define a helper function 'parity_of_nCr' to check if the index 'i' has odd parity in the combination 'nCr'
def parity_of_nCr(n, i):
    # Use the 'twos_in_factorial' function to calculate the number of twos in 'n', 'n-i', and 'i'
    f = twos_in_factorial
    # Return True if the difference between the number of twos in 'n' and the sum of twos in 'n-i' and 'i' is greater than zero
    return f(n) - f(n - i) - f(i) > 0

# Check if the input is valid and process the given problem
if __name__ == "__main__":
    # Read the input values from the standard input
    n = int(input())
    nums = list(map(lambda x: int(x) - 1, input().strip().split()))
    
    # Initialize a flag to indicate if there is no '1' in the list of numbers
    no_one = False
    
    # If there is no '1' in the list of numbers, then replace each number by half of it
    if 1 not in nums:
        nums = [num // 2 for num in nums]
        no_one = True
    
    # Initialize a flag to indicate if the result is odd
    is_odd = False
    
    # Iterate through each number in the list and check if it satisfies the given condition
    for i, num in enumerate(nums):
        # Skip the number if it doesn't satisfy the parity condition
        if not parity_of_nCr(n - 1, i) and num & 1:
            # Toggle the 'is_odd' flag
            is_odd ^= 1
    
    # Print the result based on the value of the 'is_odd' flag
    if not is_odd:
        print(0)
    else:
        # If there is no '1' in the list of numbers, then print the result with the 'no_one' flag shifted to the left
        print(1 << no_one)
