# Importing necessary libraries
import sys

def main():
    N = int(input())  # Reading the number of elements from user input

    x = []  # List to store the double values
    u = []  # List to store the currency strings

    # Reading the double values and currency strings from user input
    for _ in range(N):
        value, currency = input().split()  # Read a line and split into value and currency
        x.append(float(value))  # Append the float value to the list
        u.append(currency)  # Append the currency string to the list

    # Calling the 'solve' function to find the sum of products of double values and their respective currency conversion factors
    print(solve(x, u))

def solve(x, u):
    # Calculating the sum of products using a list comprehension
    return sum(x[i] * (1 if u[i] == "JPY" else 380000) for i in range(len(x)))

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
