# Start an infinite loop to continuously accept input until a break condition is met
while True:
    # Read an integer input from the user
    n = int(input())
    
    # Check if the input is zero; if so, exit the loop
    if n == 0:
        break
    
    # Initialize the result variable to a very small number
    res = -1111111111
    # Initialize the sum variable to zero
    s = 0
    
    # Loop through the range of n to read n integers
    for i in range(n):
        # Read the next integer input from the user
        a = int(input())
        # Update the sum s to be the maximum of (current sum + new number) or the new number itself
        s = max(s + a, a)
        # Update the result res to be the maximum of the current sum or the previous result
        res = max(s, res)
    
    # Print the maximum subarray sum found for the current set of inputs
    print(res)
