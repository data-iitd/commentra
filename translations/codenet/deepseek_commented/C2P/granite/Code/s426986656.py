
A, B = map(int, input().split())  # Read input values for A and B
flag = False  # Initialize flag to False

# Loop through numbers 1 to 3 to check if the product of A, B, and i is odd
for i in range(1, 4):
    if (A*B*i) % 2 == 1:  # Check if the product is odd
        flag = True  # Set flag to True if an odd product is found
        break  # Break out of the loop

if flag: print("Yes")  # Print "Yes" if an odd product was found
else: print("No")  # Print "No" if no odd product was found

