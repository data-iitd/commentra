# Declare a map to store the minimum price for each weight
m = {}

# Iterate over possible quantities of items weighing 200 units
for i in range(5001):
    # Iterate over possible quantities of items weighing 300 units
    for j in range(5001):
        # Iterate over possible quantities of items weighing 500 units
        for k in range(5001):
            # Calculate the total weight based on the quantities of items
            w = i*200 + j*300 + k*500

            # Calculate the price based on the quantities of items
            p = i/5*5*380*0.8 + i%5*380
              + j/4*4*550*0.85 + j%4*550
              + k/3*3*850*0.88 + k%3*850

            # Update the map with the minimum price for the calculated weight
            if w in m:
                m[w] = min(m[w], p) # If weight already exists, take the minimum price
            else:
                m[w] = p # If weight does not exist, set the price

# Read input weights and output the corresponding minimum prices
n = int(input())
while n:
    print(m[n]) # Output the minimum price for the given weight
    n = int(input())

