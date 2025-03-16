import sys

# Function to read the next line of input as a string
def next():
    return sys.stdin.readline().strip()  # Read a line from standard input and strip whitespace

# Function to read the next line of input as an integer
def next_int():
    return int(next())  # Convert the next input to an integer

# Function to read 'n' integers from input and return them as a list
def next_ints(n):
    return [next_int() for _ in range(n)]  # Read 'n' integers into a list

def main():
    # Read two integers from input: n (number of elements) and k (some parameter)
    n, k = next_int(), next_int()
    
    # Read 'n' integers into list 'a'
    a = next_ints(n)
    
    # Avoid unused variable error by assigning a value to the first element of 'a'
    a[0] = 0

    # Initialize sum with the value of k and set ans to 1
    sum_value = k
    ans = 1
    
    # Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
    while sum_value < n:
        sum_value = sum_value - 1 + k  # Update sum by subtracting 1 and adding k
        ans += 1  # Increment the answer counter
    
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
