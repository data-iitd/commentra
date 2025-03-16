# We include the standard input/output library

def main():  # The main function is the entry point of the program
    n = int(input())  # We read the first number 'n' from the standard input
    c = 0  # We initialize the variable 'c' to zero
    m = float('inf')  # We initialize 'm' to a very large positive number
    M = float('-inf')  # We initialize 'M' to a very large negative number

    for i in range(n):  # We start a for loop that iterates 'n' times
        a = int(input())  # We read the current number 'a' from the standard input

        # If the current number 'a' is greater than the current maximum number 'M', we update 'M' with 'a'
        if a > M:
            M = a

        # If the current number 'a' is smaller than the current minimum number 'm', we update 'm' with 'a'
        if a < m:
            m = a

        # We add the current number 'a' to the variable 'c'
        c += a

    # We print the minimum number 'm', the maximum number 'M', and the sum 'c' to the standard output
    print(m, M, c)

# The main function returns zero to indicate successful execution
if __name__ == "__main__":
    main()

# <END-OF-CODE>
