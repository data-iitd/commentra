
import sys

# Step 1: Setting up input and output streams
# The code starts by setting up the input and output streams to be as fast as possible.
# This is achieved by setting the buffering mode to unbuffered and disabling automatic flushing.

sys.stdin = open(0, 'r', buffering=1)
sys.stdout = open(1, 'w', buffering=1)
sys.stderr = open(2, 'w', buffering=1)

m = [10, 50, 100, 500]

# Step 2: Initializing a list to store denominations
# The code initializes a list `m` to store the denominations of the currency,
# which are 10, 50, 100, and 500.

first = True
for money in iter(int, 0):
    # Step 3: Reading input and processing each transaction
    # The code enters a loop where it reads an integer `money` from the input.
    # If `money` is zero, the loop terminates. Otherwise, it processes the transaction.

    if not first:
        print()

    # Step 4: Checking if it's the first transaction and outputting a newline if necessary
    # The code checks if it's the first transaction. If not, it outputs a newline to separate the transactions.

    first = False
    sum = 0
    num = [0] * 4
    for i in range(4):
        num[i] = int(input())
        sum += num[i] * m[i]

    # Step 5: Calculating the total value of the currency and the change to be given
    # The code initializes `sum` to zero and a list `num` to store the number of each denomination.
    # It then reads the number of each denomination and calculates the total value of the currency.

    change = sum - money
    for i in range(3, -1, -1):
        if change >= m[i]:
            num[i] = num[i] - change // m[i]
            change %= m[i]

    # Step 6: Calculating the change and updating the number of denominations
    # The code calculates the change by subtracting the input amount from the total value.
    # It then updates the number of each denomination to reflect the change.

    for i in range(4):
        if num[i] > 0:
            print(m[i], num[i])

    # Step 7: Outputting the denominations and their counts for the change
    # The code outputs the denominations and their counts for the change.

# Final Comment: The code runs until the input money is zero, processing each transaction
# to calculate and output the change based on the available denominations.

