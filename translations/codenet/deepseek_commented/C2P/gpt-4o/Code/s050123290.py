# Define the maximum length for the input
N = 1000 

while True:
    # 1. Read input
    su = input()  # Read the entire line of input
    if su[0] == '0':  # Break if the sequence starts with '0'
        break
    
    # 2. Calculate the sum of the digits
    susum = sum(int(char) for char in su)  # Convert each character to integer and sum them
    
    # 3. Print the sum
    print(susum)  # Print the sum of the digits

# 4. Check for termination condition
# The loop will terminate when the input starts with '0'
# <END-OF-CODE>
