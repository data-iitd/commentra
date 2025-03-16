import sys

# Constants
initial_buf_size = 10000
max_buf_size = 1000000
mod = 10**9 + 7

# Main function to determine the number of days until Sunday for a given day.
def main():
    week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]
    s = get_string()  # Get the input day as a string.
    index = -1
    for i, day in enumerate(week):
        if s == day:
            index = i  # Set the index of the day found in the week array.
            break

    print(7 - index)  # Print the number of days until Sunday.

# Helper function to read a string from standard input.
def get_string():
    return sys.stdin.readline().strip()

# Function to return the absolute value of an integer.
def abs_value(a):
    return abs(a)

# Function to return the result of raising the first argument to the power of the second argument.
def pow_func(p, q):
    return p ** q

# Function to return the smallest integer from a list of integers.
def min_func(*nums):
    if len(nums) == 0:
        raise ValueError("function min_func() requires at least one argument.")
    return min(nums)

# Function to return the largest integer from a list of integers.
def max_func(*nums):
    if len(nums) == 0:
        raise ValueError("function max_func() requires at least one argument.")
    return max(nums)

# Function to check if a string is present in a list of strings.
def str_search(a, b):
    return b in a

# Function to print a list of integers in a specific format.
def print_int_array(array):
    print(", ".join(map(str, array)))

# Function to return the modulo of an integer with respect to mod.
def calc_mod(x):
    return x % mod

if __name__ == "__main__":
    main()

# <END-OF-CODE>
