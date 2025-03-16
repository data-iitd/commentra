# Import necessary modules
import sys

def main():
    N = int(input())  # Read the number of elements N from the user
    x = []  # Initialize the list to store the values
    u = []  # Initialize the list to store the currencies

    # Read the values into the lists x and u
    for _ in range(N):
        value, currency = input().split()  # Read a line of input
        x.append(float(value))  # Append the value as a float
        u.append(currency)  # Append the currency

    # Call the solve function and print the result
    print(solve(x, u))

def solve(x, u):
    # Calculate the total value based on the currency
    return sum(value * (1 if currency == "JPY" else 380000) for value, currency in zip(x, u))

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
