# Read the number of items from user input
n = int(input())

# Initialize an empty list to store the input items
input_array = []

# Loop to read each item's attributes (S, R, H, C)
for i in range(n):
    # Read the attributes S, R, H, C and convert them to integers
    S, R, H, C = map(int, input().split())
    # Append the attributes as a tuple to the input_array
    input_array.append((S, R, H, C))

# Initialize a list to keep track of outdated items
outdated = []

# Compare each item with every other item to find outdated ones
for i in range(n):
    for j in range(n):
        # Check if item i is outdated compared to item j
        if (input_array[i][0] < input_array[j][0] and 
            input_array[i][1] < input_array[j][1] and 
            input_array[i][2] < input_array[j][2]):
            # If outdated, add item i to the outdated list
            outdated.append(input_array[i])

# Convert the outdated list to a set to remove duplicates
outdated = set(outdated)

# Initialize variables to track the minimum cost and corresponding item index
minimum_cost = 100000
input_number = 0

# Loop through the input items to find the one with the minimum cost that is not outdated
for i in range(n):
    current_item = input_array[i]
    cost = current_item[3]  # Get the cost of the current item
    # Check if the current item is not outdated and has a lower cost than the current minimum
    if (current_item not in outdated and cost < minimum_cost):
        minimum_cost = current_item[3]  # Update the minimum cost
        input_number = i + 1  # Store the index of the current item (1-based index)

# Print the index of the item with the minimum cost that is not outdated
print(input_number)
