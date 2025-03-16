import sys

# Function to read a single word as a string from the input
def next():
    return sys.stdin.readline().strip()

# Function to read an integer from the input
def next_int():
    return int(next())

# Function to read a float from the input
def next_float():
    return float(next())

# Function to read n integers from the input and return as a list
def next_ints(n):
    return [next_int() for _ in range(n)]

# Main function
if __name__ == "__main__":
    # Read the first three integers from the input
    a = next_int()
    b = next_int()
    c = next_int()

    # Check if the condition is true
    if a + b >= c:
        # If true, print "Yes" to the output
        print("Yes")
    else:
        # If false, print "No" to the output
        print("No")

# <END-OF-CODE>
