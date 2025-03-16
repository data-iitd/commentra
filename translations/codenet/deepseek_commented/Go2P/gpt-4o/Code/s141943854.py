import sys  # For system-related functions

# Function to check for errors and exit if any occur
def check(e):
    if e:
        print(f"error: {e}", file=sys.stderr)
        sys.exit(1)

def main():
    sage = input()  # Read input from standard input

    if sage == "1":
        print("Hello World")  # Print "Hello World" if input is "1"
    elif sage == "2":
        total = 0  # Declare total variable to store the sum of two integers
        for _ in range(2):
            try:
                num = int(input())  # Read input and convert to integer
            except ValueError as e:
                check(e)  # Check for errors during conversion
            total += num  # Add the integer to the total
        print(total)  # Print the sum of the two integers

if __name__ == "__main__":
    main()

# <END-OF-CODE>
