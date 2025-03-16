# <START-OF-CODE>

# solution function takes an integer n and a slice of integers a.
# It calculates the maximum frequency of any number or its two consecutive successors in the array.
def solution(n, a):
        # Create a memoization array to count occurrences of numbers and their successors.
        memo = [0] * (100000 + 2)
        
        # Iterate through each number in the input array.
        for num in a:
                # Increment the count for the current number and its two successors.
                memo[num] += 1
                memo[num + 1] += 1
                memo[num + 2] += 1
        
        # Initialize the output variable to track the maximum frequency found.
        out = 0
        
        # Iterate through the memoization array to find the maximum frequency.
        for num in memo:
                # Update the output if the current count is greater than the current maximum.
                if num > 0:
                        out = max(out, num)
        
        # Return the maximum frequency found.
        return out

# max function returns the greater of two integers x and y.
def max(x, y):
        if x > y:
                return x
        return y

# main function is the entry point of the program.
def main():
        # Declare a variable to hold the number of elements.
        n = 0
        
        # Read the number of elements from standard input.
        n = int(raw_input())
        
        # Create a slice to hold the input integers.
        a = [0] * n
        
        # Read each integer into the slice.
        for i in range(n):
                a[i] = int(raw_input())
        
        # Call the solution function and print the result.
        print solution(n, a)

# 