import sys

# Constants for modulus
MOD = 10**9 + 7

def main():
    # Array representing the days of the week
    week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
    
    # Get the input day as a string
    s = input().strip()
    index = -1  # Initialize index to -1 to indicate not found

    # Search for the input day in the week array
    for i, day in enumerate(week):
        if s == day:
            index = i  # Update index if the day is found
            break

    # Calculate and print the number of days until the next Sunday
    print(7 - index)

# Function to read an integer from input
def get_int():
    return int(input().strip())

# Function to read a string from input
def get_string():
    return input().strip()

# Function to compute the absolute value of an integer
def abs_value(a):
    return abs(a)

# Function to compute p raised to the power of q
def pow_func(p, q):
    return p ** q

# Function to find the minimum value among given integers
def min_value(*nums):
    if len(nums) == 0:
        raise ValueError("function min_value() requires at least one argument.")
    return min(nums)

# Function to find the maximum value among given integers
def max_value(*nums):
    if len(nums) == 0:
        raise ValueError("function max_value() requires at least one argument.")
    return max(nums)

# Function to check if a string exists in a list of strings
def str_search(a, b):
    return b in a

# Function to print a list of integers
def print_int_array(array):
    print(" ".join(map(str, array)))

# Function to calculate the modulus of x with respect to the defined mod
def calc_mod(x):
    return x % MOD

if __name__ == "__main__":
    main()

# <END-OF-CODE>
