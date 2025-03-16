
# Step 3: Create a list of integers with a length of 3
in = [0] * 3

# Step 4: Prompt the user to input three integers
in[0] = int(input())
in[1] = int(input())
in[2] = int(input())

# Step 5: Sort the list of integers in ascending order
in.sort()

# Step 6: Perform a calculation using the sorted integers and print the result
print(in[2]*10 + in[1] + in[0])

