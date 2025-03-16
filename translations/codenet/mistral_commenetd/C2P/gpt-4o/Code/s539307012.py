# Including the standard input/output library

def main():  # The main function, which is the starting point of the program
    n, x, min_val = map(int, input().split())  # Reading three integers from the standard input and storing them in the variables n, x, and min

    x -= min_val  # Subtracting the minimum value from x

    for i in range(1, n):  # Starting a for loop that iterates from 1 to n-1
        m = int(input())  # Reading an integer from the standard input and storing it in the variable m

        x -= m  # Subtracting the current number from x

        if min_val > m:  # Checking if the current number is smaller than the current minimum
            min_val = m  # Updating the minimum if it is

    print(n + x // min_val)  # Printing the final result, which is the number of elements plus the quotient of the remaining difference and the minimum number

if __name__ == "__main__":
    main()  # Indicating that the program has ended successfully

# <END-OF-CODE>
