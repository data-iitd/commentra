# Take an integer input from the user representing the number of transactions
n = int(input())

# Initialize an accumulator variable to store the total sum of the transactions
res = 0

# Iterate through each transaction in the given number of transactions
for _ in range(n):
    # Get the transaction details as a list from the user input
    x, u = list(input().split())

    # Check if the transaction is related to Bitcoin
    if u == "BTC":
        # If yes, calculate the transaction amount in USD by multiplying the transaction amount with the current BTC to USD exchange rate
        res += float(x) * 380000
    else:
        # If not, calculate the transaction amount in USD by converting the transaction amount from the input to USD directly
        res += int(x)

# Print the total sum of all the transactions in USD
print(res)
