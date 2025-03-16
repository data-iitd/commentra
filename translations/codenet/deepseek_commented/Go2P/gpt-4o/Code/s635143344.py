# Step 3: Create a list of integers with a length of 3
in_list = [0] * 3

# Step 4: Prompt the user to input three integers
in_list[0], in_list[1], in_list[2] = map(int, input("Enter three integers: ").split())

# Step 5: Sort the list of integers in ascending order
in_list.sort()

# Step 6: Perform a calculation using the sorted integers and print the result
print(in_list[2] * 10 + in_list[1] + in_list[0])

# <END-OF-CODE>
