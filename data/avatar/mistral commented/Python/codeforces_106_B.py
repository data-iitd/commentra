# Define the number of items in the input array
n = int(input())

# Initialize an empty list to store the input data
input_array = []

# Read n items from the standard input and append them to the input_array
for i in range(n):
    S, R, H, C = map(int, input().split())
    input_array.append((S, R, H, C))

# Initialize an empty list to store the outdated items
outdated = []

# Check for outdated items in the input array
for i in range(n):
    for j in range(n):
        # Check if the current item is older and smaller than the next one
        if (input_array[i][0] < input_array[j][0] and
            input_array[i][1] < input_array[j][1] and
            input_array[i][2] < input_array[j][2]):
            # Append the current item to the outdated list
            outdated.append(input_array[i])

# Convert the outdated list to a set to remove duplicates
outdated = set(outdated)

# Initialize minimum_cost and input_number to large initial values
minimum_cost = 100000
input_number = 0

# Find the item with the minimum cost that is not outdated
for i in range(n):
    current_item = input_array[i]
    cost = current_item[3]
    # Check if the current item is not outdated and has a smaller cost than minimum_cost
    if (current_item not in outdated and cost < minimum_cost):
        # Update minimum_cost and input_number
        minimum_cost = current_item[3]
        input_number = i + 1

# Print the index of the item with the minimum cost that is not outdated
print(input_number)
