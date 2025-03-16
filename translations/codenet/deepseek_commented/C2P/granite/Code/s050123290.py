
# Python code

# 1. Define the array and variables
su = [] # List to store the sequence of digits
susum = 0 # Variable to store the sum of the digits

while True:
    # 2. Read input and calculate sum
    su = input() # Read input as a string
    if su == '0': break # Break if the sequence starts with '0'
    for i in su:
        susum += int(i) # Convert character to integer and add to sum
    # 3. Print the sum
    print(susum) # Print the sum of the digits
    susum = 0 # Reset the sum for the next sequence

# 4. Check for termination condition
print("