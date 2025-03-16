
k, n, w = input().split() # Taking three integers as input from the user

if 1 <= int(k) and int(w) <= 1000: # Input validation
    total = 0 # Initializing the variable 'total' to zero
    for i in range(1, int(w) + 1): # Iterating from 1 to w (inclusive)
        total += i * int(k) # Adding the product of k and the current index to the total variable

    if total > int(n): # Checking if the total is greater than n or not
        print(total - int(n)) # If yes, printing the difference between total and n
    else:
        print(0) # If no, printing zero