import sys

# Function to compute the minimum total distance to a median value
def solve():
    # Read the number of elements
    n = get_int()
    # Read the integer list of size n
    as_ = get_int_list(n)

    # Create a new list to store adjusted values
    xs = [a - i + 1 for i, a in enumerate(as_)]
    # Sort the adjusted values
    xs.sort()

    # Find the median value from the sorted list
    b = xs[n // 2]
    ans = 0
    # Calculate the total distance from each element to the median
    for x in xs:
        ans += abs(x - b)
    
    # Output the result
    print(ans)

# Function to return the absolute value of an integer
def abs(n):
    return -n if n < 0 else n

# Function to read an integer from input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a list of integers from input
def get_int_list(n):
    return list(map(int, sys.stdin.readline().strip().split()))[:n]

# Main function to initialize input/output and call the solve function
if __name__ == "__main__":
    solve()

# <END-OF-CODE>
