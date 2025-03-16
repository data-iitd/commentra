# Read the number of transactions from user input
n = int(input())

# Initialize the result variable to accumulate the total value
res = 0

# Loop through each transaction
for _ in range(n):
    # Read the transaction amount and currency type from user input
    x, u = list(input().split())
    
    # Check if the currency is Bitcoin (BTC)
    if u == "BTC": 
        # Convert the Bitcoin amount to its equivalent in the local currency (assuming 1 BTC = 380000)
        res += float(x) * 380000
    else:
        # If the currency is not Bitcoin, add the amount directly to the result
        res += int(x)

# Print the total value of all transactions
print(res)
