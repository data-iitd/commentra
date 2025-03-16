# Read the total number of items (N) to be processed
N = int(input())

# Initialize a list to store the capacities of 5 different containers
capacity_list = [int(input()) for _ in range(5)]

# Sort the list of capacities in ascending order
capacity_list.sort()

# Identify the smallest capacity (bottle neck) from the sorted list
bottle_neck = capacity_list[0]

# Calculate and print the total number of trips required
# The formula accounts for the number of items and the capacity of the smallest container
# Adding 4 accounts for the initial trips before the last trip
print(4 + int((N + bottle_neck - 1) / bottle_neck))
