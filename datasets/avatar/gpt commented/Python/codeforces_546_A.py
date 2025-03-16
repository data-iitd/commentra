# Read input values for k (cost per banana), n (initial amount of money), and w (number of bananas)
k, n, w = input().split()

# Check if k is at least 1 and w is at most 1000
if 1 <= int(k) and int(w) <= 1000:
    # Initialize total cost to zero
    total = 0
    
    # Calculate the total cost of buying w bananas
    for i in range(1, int(w) + 1):
        total += i * int(k)  # Cost of each banana increases with its quantity (1*k, 2*k, ..., w*k)
    
    # Check if the total cost exceeds the initial amount of money n
    if total > int(n):
        # Print the amount of money needed to buy the bananas
        print(total - int(n))
    else:
        # Print 0 if the initial amount is sufficient to buy the bananas
        print(0)
