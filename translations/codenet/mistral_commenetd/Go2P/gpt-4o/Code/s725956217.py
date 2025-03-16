# Import necessary modules
import sys

# Function to read an integer from standard input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from standard input
def get_string():
    return sys.stdin.readline().strip()

# Function to return the maximum of two integers
def max(a, b):
    return a if a > b else b

# Function to return the minimum of two integers
def min(a, b):
    return a if a < b else b

# Function to return the absolute difference between two integers
def asub(a, b):
    return a - b if a > b else b - a

# Function to return the absolute value of an integer
def abs(a):
    return a if a >= 0 else -a

# Function to find the lower bound index
def lower_bound(a, x):
    left, right = 0, len(a)
    while left < right:
        mid = (left + right) // 2
        if a[mid] >= x:
            right = mid
        else:
            left = mid + 1
    return left

# Function to find the upper bound index
def upper_bound(a, x):
    left, right = 0, len(a)
    while left < right:
        mid = (left + right) // 2
        if a[mid] > x:
            right = mid
        else:
            left = mid + 1
    return left

# Class to represent a shop with capacity and demand
class Shop:
    def __init__(self, a, b):
        self.a = a  # capacity
        self.b = b  # demand

# Main function
def main():
    # Read the number of shops N and the number of customers M
    N = get_int()
    M = get_int()
    
    # Initialize a list of shops
    shops = []
    
    # Read the capacity and demand for each shop
    for _ in range(N):
        a, b = map(int, get_string().split())
        shops.append(Shop(a, b))
    
    # Sort the shops based on their capacity
    shops.sort(key=lambda shop: shop.a)

    # Initialize total capacity used
    total = 0
    
    # Calculate the total capacity used by the shops
    for shop in shops:
        n = min(shop.b, M)  # Minimum of shop's demand and remaining customers
        total += n * shop.a  # Add to total capacity
        M -= n  # Decrease remaining customers
        if M == 0:  # If no customers left, break
            break
    
    # Print the total capacity used
    print(total)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
