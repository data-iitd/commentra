import sys

# Disable synchronization with C I/O for faster input/output
sys.stdin.readline = lambda: sys.stdin.readline().strip()

# Initialize a list to hold the denominations of money
m = [10, 50, 100, 500]

# Read money input until EOF or invalid input
for line in sys.stdin:
    if not line:
        break

    # Convert the input to an integer
    money = int(line)
    if not money:
        break

    # Print a newline before the output of subsequent transactions
    if not first:
        print()

    first = False
    sum_ = 0
    num = [0, 0, 0, 0]  # List to hold the number of each denomination

    # Read the number of coins for each denomination and calculate the total sum
    for i in range(4):
        num[i] = int(sys.stdin.readline())  # Input the number of coins for the current denomination
        sum_ += num[i] * m[i]  # Update the total sum

    # Calculate the change to be returned
    change = sum_ - money

    # Calculate how many coins of each denomination to return as change
    for i in range(3, -1, -1):
        if change // m[i]:  # Check if the current denomination can be used for change
            num[i] -= change // m[i]  # Reduce the number of coins of this denomination
            change %= m[i]  # Update the remaining change to be returned

    # Output the remaining coins of each denomination that are greater than zero
    for i in range(4):
        if num[i] > 0:  # Only print denominations that still have coins left
            print(f"{m[i]} {num[i]}")  # Print denomination and count

print("<END-OF-CODE>")