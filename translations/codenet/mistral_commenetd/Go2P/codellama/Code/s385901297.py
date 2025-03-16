
# Initialize a new scanner to read input from standard input
scanner = input()

# Read the first line of input containing 4 integers and store them in ns slice
ns = list(map(int, scanner.split()))

# Sort the ns slice in ascending order
ns.sort()

# Check if the sorted ns slice matches the specific condition (1, 4, 7, 9)
if ns[0] == 1 and ns[1] == 4 and ns[2] == 7 and ns[3] == 9:
    print("YES")
else:
    print("NO")

# 