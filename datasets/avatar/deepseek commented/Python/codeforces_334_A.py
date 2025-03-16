
n = int(input())  # Taking an integer input from the user
i, j = 1, n * n   # Initializing variables i and j

# Starting a while loop that continues as long as i is less than j
while i < j:
    print(i, j)  # Printing the current values of i and j
    i += 1       # Incrementing i by 1
    j -= 1       # Decrementing j by 1


