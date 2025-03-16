
# Function to find the maximum number of occurrences of a number in the array
def solution(n, a):
        # Initialize a memo table to store the number of occurrences of each number
        memo = [0] * (100000 + 2)

        # Iterate through the array and update the memo table
        for num in a:
                # Increment the memo table for the current number and the next two numbers
                memo[num] += 1
                memo[num + 1] += 1
                memo[num + 2] += 1

        # Initialize output variable to store the maximum number of occurrences found
        out = 0

        # Iterate through the memo table and update the output variable if a larger number is found
        for num in memo:
                if num > 0:
                        # Update the output variable with the maximum number found so far
                        out = max(out, num)

        # Return the maximum number of occurrences found
        return out

# Function to find the maximum of two numbers
def max(x, y):
        # Return the larger number between x and y
        if x > y:
                return x
        return y

# Main function to read input and call the solution function
def main():
        # Read the size of the array from the standard input
        n = int(raw_input())

        # Allocate memory for the array and read its elements from the standard input
        a = [0] * n
        for i in range(n):
                a[i] = int(raw_input())

        # Call the solution function and print the result
        print solution(n, a)

# 