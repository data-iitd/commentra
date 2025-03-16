
n = int(input())  # Take the number of elements as input
input_array = []  # Initialize an empty list to store tuples

# Loop to take inputs and append them as tuples to input_array
for i in range(n):
    S, R, H, C = map(int, input().split())  # Take four integers as input
    input_array.append((S, R, H, C))  # Append the tuple to input_array

outdated = []  # Initialize an empty list to store outdated elements

# Nested loop to compare each element in input_array with every other element
for i in range(n):
    for j in range(n):
        if (input_array[i][0] < input_array[j][0] and
            input_array[i][1] < input_array[j][1] and
            input_array[i][2] < input_array[j][2]):
            outdated.append(input_array[i])  # Append outdated elements to outdated list

outdated = set(outdated)  # Convert outdated list to a set to remove duplicates

minimum_cost = 100000  # Initialize minimum_cost to a large value
input_number = 0  # Initialize input_number to 0

# Iterate through input_array to find the item with the minimum cost that is not outdated
for i in range(n):
    current_item = input_array[i]
    cost = current_item[3]
    if (current_item not in outdated and cost < minimum_cost):
        minimum_cost = current_item[3]  # Update minimum_cost
        input_number = i + 1  # Update input_number

print(input_number)  # Print the input number of the item with the minimum cost that is not outdated

