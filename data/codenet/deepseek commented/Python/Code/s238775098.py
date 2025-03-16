
n=int(input())  # Read the number of transactions
res = 0  # Initialize the result variable to store the total amount
for _ in range(n):  # Loop through each transaction
    x, u = list(input().split())  # Read the amount and currency type
    if u == "BTC":  # Check if the currency is Bitcoin
        res += float(x) * 380000  # Convert Bitcoin to Yen and add to result
    else:
        res += int(x)  # Convert the amount to integer and add to result
print(res)  # Print the total amount after all transactions

