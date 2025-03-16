# Python 3.6.2
# Author: <NAME>
# Date: 2018-02-12

# Define the input function
# The input function is used to read input from stdin
# The first parameter is the type of the input required
# The second parameter is the name of the variable that stores the input
# The input is stored as a string
# The input is stripped of leading and trailing whitespace
# The input is then converted to the specified type and stored in the variable
# The input is then returned
# The program will crash if the input cannot be converted to the specified type
def input_func(type, name):
    val = input()
    val = val.strip()
    val = type(val)
    return val

# Define the output function
# The output function is used to print output to stdout
# The first parameter is the value to be printed
# The value is converted to a string using the str() function
# The string is then stripped of leading and trailing whitespace
# The string is then printed to stdout
# The program will crash if the value cannot be converted to a string
def output_func(val):
    val = str(val)
    val = val.strip()
    print(val)

# Define the main function
# The main function is the entry point of the program
# The main function is always named main
# The main function can have parameters
# The main function can return a value
def main():
    # Read the number of elements (N) and the number of steps (K)
    N = input_func(int, 'N')
    K = input_func(int, 'K')

    # Read the elements into array A
    A = [0] * (N + 1)
    REP(i, N):
        A[i + 1] = input_func(int, 'A[i + 1]')

    # Initialize array B to -1 to indicate unvisited positions
    B = [-1] * (200100)

    # Mark the starting position as visited at step 0
    B[1] = 0

    # Traverse the positions based on the values in A
    now = 1
    for j in range(1, K + 1):
        now = A[now]

        # Check if the current position has been visited before
        if B[now] == -1:
            B[now] = j
        else:
            # If the position has been visited, calculate the cycle length
            cnt = j
            break

    # If we did not reach the maximum steps K
    if j < K:
        # Calculate how many additional steps to take within the cycle
        tmp = (K - B[now]) % (cnt - B[now])

        # Move to the final position after the calculated additional steps
        for j in range(0, tmp):
            now = A[now]

    # Output the final position after all movements
    output_func(now)

# Call the main function
main()

# 