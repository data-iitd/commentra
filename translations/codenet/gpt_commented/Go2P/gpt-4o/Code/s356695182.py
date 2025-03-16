import sys

# Function to read the next integer from standard input
def next_int():
    return int(sys.stdin.readline().strip())

# Function to read a specified number of integers from standard input and return them as a list
def scan_nums(length):
    nums = []
    for _ in range(length):
        num = next_int()  # Read an integer from standard input
        nums.append(num)  # Append the integer to the list
    return nums  # Return the list of integers

# Function to calculate a specific pattern based on the first five integers in the list
def pattern1(l):
    n = (l[0] * l[3]) + (l[1] * l[4])  # Calculate the result based on the formula
    return n  # Return the calculated value

# Function to calculate another pattern based on the maximum of the last two integers
def pattern2(l):
    n = 2 * l[2] * max(l[3], l[4])  # Calculate the result using the maximum value
    return n  # Return the calculated value

# Function to calculate a third pattern that combines the minimum value and a function call
def pattern3(l):
    n = 2 * l[2] * min(l[3], l[4]) + doch(l)  # Calculate the result using the minimum value and doch function
    return n  # Return the calculated value

# Function to return the minimum value from a variable number of integer arguments
def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("function min_value() requires at least one argument.")  # Raise error if no arguments are provided
    return min(nums)  # Return the minimum value

# Function to return the maximum value from a variable number of integer arguments
def max_value(*nums):
    if len(nums) == 0:
        raise ValueError("function max_value() requires at least one argument.")  # Raise error if no arguments are provided
    return max(nums)  # Return the maximum value

# Function to calculate a value based on the difference between the last two integers in the list
def doch(l):
    if l[3] > l[4]:
        return l[0] * (l[3] - l[4])  # Return the product if the fourth integer is greater
    else:
        return l[1] * (l[4] - l[3])  # Return the product if the fifth integer is greater

# Main function where the program execution begins
if __name__ == "__main__":
    length = 5  # Define the number of integers to read
    l = scan_nums(length)  # Read the integers into a list
    # Print the minimum value from the three calculated patterns
    print(min_value(pattern1(l), pattern2(l), pattern3(l)))

# <END-OF-CODE>
