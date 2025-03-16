import math

# Function main is the entry point of the program
def main():
    # Declare and initialize two integer variables n and m using input
    n, m = map(int, input().split())

    # Calculate the value of x using the given formula
    x = m * 1900 + (n - m) * 100

    # Print the result
    print(x * int(math.pow(2, m)))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
