
import sys
from bisect import bisect_left

# Helper function to print output.
def out(*args):
    print(*args)

# Function to read an integer from input.
def getInt():
    return int(input())

# Function to read a string from input.
def getString():
    return input()

# Function to return the maximum of two integers.
def max(a, b):
    return a if a > b else b

# Function to return the minimum of two integers.
def min(a, b):
    return a if a < b else b

# Function to return the absolute difference between two integers.
def a_sub(a, b):
    return a - b if a > b else b - a

# Function to return the absolute value of an integer.
def abs(a):
    return a if a >= 0 else -a

# Function to find the lower bound index of a value in a sorted array.
def lower_bound(a, x):
    idx = bisect_left(a, x)
    return idx

# Function to find the upper bound index of a value in a sorted array.
def upper_bound(a, x):
    idx = bisect_left(a, x + 1)
    return idx

# Struct to represent a shop with its price and stock.
class Shop:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Main function to execute the program logic.
def main():
    # Read the number of shops and the amount of items to buy.
    N, M = getInt(), getInt()

    # Create a list of shops and read each shop's price and stock.
    shops = []
    for _ in range(N):
        a, b = getInt(), getInt()
        shops.append(Shop(a, b))

    # Sort the shops by price.
    shops.sort(key=lambda x: x.a)

    # Calculate the total cost of buying the required number of items.
    total = 0
    for shop in shops:
        # Determine the number of items to buy from the current shop.
        n = min(shop.b, M)
        # Update the total cost and the remaining items to buy.
        total += n * shop.a
        M -= n
        # Break if all items are bought.
        if M == 0:
            break

    # Print the total cost.
    out(total)

if __name__ == "__main__":
    main()

