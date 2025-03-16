def twos_in_factorial(n):
    # Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
    return n - bin(n).count('1')

def parity_of_nCr(n, i):
    # Determine the parity (even or odd) of the binomial coefficient C(n, i)
    f = twos_in_factorial  # Reference to the function that calculates the number of factors of 2
    # The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
    return f(n) - f(n - i) - f(i) > 0

if __name__ == "__main__":
    # Read an integer n from input
    n = int(input())
    # Read a list of integers, subtracting 1 from each input value
    nums = list(map(lambda x: int(x) - 1, input().strip()))
    
    no_one = False  # Flag to check if there are no '1's in the input list
    if 1 not in nums:
        # If there are no '1's, divide each number in nums by 2
        nums = [num // 2 for num in nums]
        no_one = True  # Set the flag to True since there were no '1's

    is_odd = False  # Flag to track if the overall parity is odd
    for i, num in enumerate(nums):
        # Check the parity of C(n-1, i) and if num is odd
        if not parity_of_nCr(n - 1, i) and num & 1:
            is_odd ^= 1  # Toggle the is_odd flag if the conditions are met

    # Print the result based on the parity
    if not is_odd:
        print(0)  # If the overall parity is even, print 0
    else:
        print(1 << no_one)  # If odd, print 1 or 2 based on the no_one flag
