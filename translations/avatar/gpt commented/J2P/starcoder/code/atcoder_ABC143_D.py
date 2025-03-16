
# <START-OF-CODE>

# Create a scanner object to read input from the console
scanner = input()

# Read the number of integers to be processed
N = int(scanner.next())

# Initialize a list to store the integers
L = []

# Read N integers from input and add them to the list
for i in range(N):
    L.append(int(scanner.next()))

# Sort the list of integers in ascending order
L.sort()

# Initialize a counter to keep track of valid pairs
count = 0

# Iterate through each pair of integers in the sorted list
for i in range(N):
    for j in range(i + 1, N):
        # Get the current pair of integers
        a = L[i]
        b = L[j]

        # Find the number of integers that can form a valid triplet with a and b
        res = find(L, j + 1, a + b)

        # Increment the count by the number of valid triplets found
        count = count + res

# Output the total count of valid triplets
print(count)

# Method to find the count of integers in the list that can form a valid triplet
def find(li, from, target):
    low = from
    upp = len(li) - 1

    # Calculate the mid index based on the current low and upper bounds
    mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2

    # Base cases for the search
    if (upp - low < 0):
        return 0
    elif (li[from] >= target):
        return 0
    elif (li[upp] < target):
        return upp - low + 1

    # Perform binary search to find the count of valid integers
    while (upp - low > 1):
        if (li[mid] >= target):
            upp = mid
        else:
            low = mid
        # Update mid index after adjusting low and upp
        mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2

    # Return the count of valid integers found
    return low - from + 1

# 