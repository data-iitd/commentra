import sys

def main():
    # Reading the prices of different quantities of the item from standard input
    Q = int(input())  # Price for 4 items
    H = int(input())  # Price for 2 items
    S = int(input())  # Price for 1 item
    D = int(input())  # Price for 1 item when bought in pairs
    N = int(input())  # Number of items to buy
    
    # Calculating the minimum price for a single item based on the given prices
    one_price = min(Q * 4, H * 2, S)
    
    # Checking if the price of one item is less than or equal to half the price of buying in pairs
    if one_price <= D / 2:
        # If true, calculate the total cost for N items at the price of one item
        print(N * one_price)
    else:
        # If false, calculate the total cost using the pair price and the remaining single item price if N is odd
        print((N // 2) * D + (N % 2) * one_price)

if __name__ == "__main__":
    main()
