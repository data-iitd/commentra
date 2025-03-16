import sys  # Importing sys for reading input

def main():
    n = int(sys.stdin.readline().strip())  # Reading an integer input from the user and storing it in variable n
    solve(n)  # Calling the solve function with the input value n

def solve(n):
    # Calculating the result based on the given logic
    print((n // 3) * 2 + (0 if n % 3 == 0 else 1))  # Printing the result to the console

if __name__ == "__main__":
    main()  # Running the main function

# <END-OF-CODE>
