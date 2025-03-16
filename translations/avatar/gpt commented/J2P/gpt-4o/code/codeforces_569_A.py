# Import the sys module for user input
import sys

def main():
    # Read three integers from the input: T, S, and q
    T = int(sys.stdin.readline().strip())  # The upper limit
    S = int(sys.stdin.readline().strip())  # The starting value
    q = int(sys.stdin.readline().strip())  # The multiplier
    
    previous = S  # Initialize 'previous' with the starting value S
    answer = 0    # Initialize the answer counter
    
    # Loop until 'previous' is less than 'T'
    while previous < T:
        answer += 1  # Increment the answer counter
        previous *= q  # Multiply 'previous' by 'q' for the next iteration
    
    # Output the final count of how many times 'previous' was multiplied before reaching 'T'
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
