# Take an integer `N` as input from the user
N = int(input())

# Create a list `capacity_list` of size 5, where each element is an integer input from the user
capacity_list = [int(input()) for _ in range(5)]

# Sort the list `capacity_list` in ascending order
capacity_list.sort()

# Assign the first element of the sorted list to a variable `bottle_neck`
bottle_neck = capacity_list[0]

# Calculate and print the number of bottles needed to fill `N` liters using the bottle with the smallest capacity as the bottle
print(4 + int(N / bottle_neck))
