# Declare variables to store loop index, transaction type, and number of items
i = 0
t = 0
n = 0

# Loop through four transactions
while i < 4:
    # Read the transaction type and number of items from standard input
    t, n = map(int, input().split())

    # Check the transaction type and calculate the total cost
    if t == 1:
        print(6000 * n) # If transaction type is 1, calculate cost for 6000 per item
    elif t == 2:
        print(4000 * n) # If transaction type is 2, calculate cost for 4000 per item
    elif t == 3:
        print(3000 * n) # If transaction type is 3, calculate cost for 3000 per item
    elif t == 4:
        print(2000 * n) # If transaction type is 4, calculate cost for 2000 per item

    # Increment loop index
    i += 1

# 