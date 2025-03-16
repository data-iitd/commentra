# Importing required packages
import sys

# Function to read a line text from stdin and return its string
def next_line():
    # Returning the scanned line text
    return sys.stdin.readline().strip()

# Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
# And then returns integers list
def next_ints_line():
    # Reading a line text from stdin and converting it to a list of integers
    return list(map(int, next_line().split()))

# Function to find the maximum integer among input integers
def max_value(*integers):
    # Returning the maximum integer
    return max(integers)

# Function to find the minimum integer among input integers
def min_value(*integers):
    # Returning the minimum integer
    return min(integers)

# Function to calculate integer power
def pow_int(a, e):
    # Checking for negative integers
    if a < 0 or e < 0:
        raise ValueError("[argument error]: pow_int does not accept negative integers")
    # Calculating the power
    return a ** e

# Function to calculate absolute value of an integer
def abs_int(a):
    # Returning the absolute value
    return abs(a)

# Function to delete an element from a list
def delete_element(lst, i):
    # Checking for negative index or empty list
    if i < 0 or len(lst) <= i:
        raise IndexError("[index error]")
    # Returning a new list without the element at index i
    return lst[:i] + lst[i+1:]

# Function to concatenate two lists
def concat(s, t):
    # Returning a new list that is the concatenation of s and t
    return s + t

# Variable declaration and initialization
x = 0

# Main function
def main():
    global x
    # Reading integers from stdin as a line text
    tmp = next_ints_line()
    # Assigning the first integer to variable x
    x = tmp[0]
    # Initializing sum variable as zero
    sum_value = 0
    # Initializing index variable as one
    i = 1
    # Looping until the sum is greater than or equal to x
    while True:
        # Adding current index to sum
        sum_value += i
        # Checking if sum is greater than or equal to x
        if sum_value >= x:
            # Breaking the loop
            break
        # Incrementing index
        i += 1
    # Printing the index
    print(i)

# Running the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
