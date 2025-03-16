from collections import defaultdict

m = defaultdict(int)

for i in range(5001 // 200 + 1):  # Loop through possible values of i
    for j in range(5001 // 300 + 1):  # Loop through possible values of j
        for k in range(5001 // 500 + 1):  # Loop through possible values of k
            w = i * 200 + j * 300 + k * 500  # Calculate the weight
            p = (i // 5 * 5 * 380 * 0.8 + i % 5 * 380 +  # Calculate the price for i
                 j // 4 * 4 * 550 * 0.85 + j % 4 * 550 +  # Calculate the price for j
                 k // 3 * 3 * 850 * 0.88 + k % 3 * 850)  # Calculate the price for k
            if w in m:
                m[w] = min(m[w], p)  # Update the map with the minimum price
            else:
                m[w] = p  # Add new weight and price to the map

while True:
    n = int(input())  # Read input
    if n == 0:  # Break if zero is entered
        break
    print(m[n])  # Output the minimum price for the given weight

# <END-OF-CODE>
