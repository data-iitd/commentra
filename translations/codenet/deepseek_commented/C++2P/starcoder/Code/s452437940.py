# Python 3 program to count multiples of x
# between a and b (both inclusive)

# Function to count multiples of x
# between a and b (both inclusive)
def countMultiples(a, b, x):
    # Count of multiples of x
    # between a and b (both inclusive)
    s = (b // x - a // x)
    
    # Check if a is a multiple of x
    # and adjust the count accordingly
    if (a % x == 0):
        s += 1
    
    return s

# Driver Code
if __name__ == '__main__':
    # Read three long long integers from standard input
    a, b, x = map(int, input().split())
    
    # Calculate the number of multiples of x
    # between a and b (both inclusive)
    s = countMultiples(a, b, x)
    
    # Print the result
    print(s)

