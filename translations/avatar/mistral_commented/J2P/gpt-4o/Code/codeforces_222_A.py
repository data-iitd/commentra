# Importing the necessary library for input
import sys

def main():
    # Reading the first two integers from the input
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())
    
    l = 0  # Initializing the previous integer variable
    c = 1  # Initializing the counter variable

    for _ in range(n):  # Starting a loop that iterates n times
        a = int(sys.stdin.readline().strip())  # Reading the next integer from the input

        if a == l:  # If the current integer is equal to the previous one
            c += 1  # Increment the counter
        else:
            c = 1  # Otherwise, reset the counter to 1

        l = a  # Assigning the current integer to the previous integer variable

    if c + k > n:  # Checking if the sum of counter c and integer k is greater than n
        print(n - c)  # If true, print the difference between n and c
    else:
        print(-1)  # If false, print -1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
