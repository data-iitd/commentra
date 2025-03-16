import sys

# out is a utility function to print output to the console.
def out(*args):
    print(*args)

# getInt reads an integer from input and returns it.
def getInt():
    return int(sys.stdin.readline().strip())

# getString reads a string from input and returns it.
def getString():
    return sys.stdin.readline().strip()

# max returns the maximum of two integers.
def max(a, b):
    return a if a > b else b

# min returns the minimum of two integers.
def min(a, b):
    return a if a < b else b

# asub returns the absolute difference between two integers.
def asub(a, b):
    return abs(a - b)

# abs returns the absolute value of an integer.
def abs(a):
    return a if a >= 0 else -a

# shop represents a shop with a price (a) and available quantity (b).
class Shop:
    def __init__(self, a, b):
        self.a = a  # price
        self.b = b  # quantity

# main is the entry point of the program.
def main():
    # Read the number of shops (N) and the total quantity needed (M)
    N, M = map(int, getString().split())
    shops = []  # Create a list to hold the shops

    # Read the price and quantity for each shop
    for _ in range(N):
        a, b = map(int, getString().split())  # Read price (a) and quantity (b)
        shops.append(Shop(a, b))  # Store the shop information

    # Sort the shops by price
    shops.sort(key=lambda shop: shop.a)

    total = 0  # Initialize total cost
    # Calculate the total cost based on available quantities and prices
    for shop in shops:
        n = min(shop.b, M)  # Determine how much can be bought from this shop
        total += n * shop.a  # Add to total cost
        M -= n  # Decrease the remaining quantity needed
        if M == 0:
            break  # Stop if the required quantity is met

    out(total)  # Output the total cost

if __name__ == "__main__":
    main()

# <END-OF-CODE>
