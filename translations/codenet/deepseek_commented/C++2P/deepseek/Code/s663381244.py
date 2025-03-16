import sys

# Step 1: Setting up input and output streams
# The code starts by setting up the input and output streams to be as fast as possible.
# This is achieved by turning off synchronization between the C and C++ standard streams
# and setting the `cin` object to not buffer its input.

denominations = [10, 50, 100, 500]

# Step 2: Initializing a list to store denominations
# The code initializes a list `m` to store the denominations of the currency,
# which are 10, 50, 100, and 500.

for line in sys.stdin:
    # Step 3: Reading input and processing each transaction
    # The code enters a loop where it reads an integer `money` from the input.
    # If `money` is zero, the loop terminates. Otherwise, it processes the transaction.

    money = int(line.strip())
    if money == 0:
        break

    # Step 4: Checking if it's the first transaction and outputting a newline if necessary
    # The code checks if it's the first transaction. If not, it outputs a newline to separate the transactions.

    nums = list(map(int, sys.stdin.readline().split()))
    total_value = sum(num * denom for num, denom in zip(nums, denominations))

    # Step 5: Calculating the total value of the currency and the change to be given
    # The code initializes `sum` to zero and a list `num` to store the number of each denomination.
    # It then reads the number of each denomination and calculates the total value of the currency.

    change = total_value - money
    change_nums = [0] * 4
    for i in range(3, -1, -1):
        if change >= denominations[i]:
            change_nums[i] = change // denominations[i]
            change %= denominations[i]

    # Step 6: Calculating the change and updating the number of denominations
    # The code calculates the change by subtracting the input amount from the total value.
    # It then updates the number of each denomination to reflect the change.

    # Step 7: Outputting the denominations and their counts for the change
    # The code outputs the denominations and their counts for the change.

    for i in range(4):
        if change_nums[i] > 0:
            print(f"{denominations[i]} {change_nums[i]}")
    print()  # Output a newline to separate transactions

# Final Comment: The code runs until the input money is zero, processing each transaction
# to calculate and output the change based on the available denominations.
