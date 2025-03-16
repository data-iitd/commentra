import sys

# Helper function to print output.
def out(*args):
    print(*args)

# Function to read an integer from input.
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from input.
def get_string():
    return sys.stdin.readline().strip()

# Function to return the maximum of two integers.
def max_val(a, b):
    return a if a > b else b

# Function to return the minimum of two integers.
def min_val(a, b):
    return a if a < b else b

# Struct to represent a shop with its price and stock.
class Shop:
    def __init__(self, price, stock):
        self.price = price
        self.stock = stock

# Main function to execute the program logic.
def main():
    # Read the number of shops and the amount of items to buy.
    N, M = map(int, get_string().split())

    # Create a list of shops and read each shop's price and stock.
    shops = []
    for _ in range(N):
        a, b = map(int, get_string().split())
        shops.append(Shop(a, b))

    # Sort the shops by price.
    shops.sort(key=lambda shop: shop.price)

    # Calculate the total cost of buying the required number of items.
    total = 0
    for shop in shops:
        # Determine the number of items to buy from the current shop.
        n = min_val(shop.stock, M)
        # Update the total cost and the remaining items to buy.
        total += n * shop.price
        M -= n
        # Break if all items are bought.
        if M == 0:
            break

    # Print the total cost.
    out(total)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
