# Step 1: Take the first input from the user
first_input = input()

# Step 2: Multiply the first input by 2
s = first_input * 2

# Step 3: Take the second input from the user
second_input = input()

# Step 4: Check if the second input is in the list created by multiplying the first input by 2
if second_input in s:
    # Step 5: Print 'Yes' if the second input is in the list
    print('Yes')
else:
    # Step 6: Print 'No' if the second input is not in the list
    print('No')
