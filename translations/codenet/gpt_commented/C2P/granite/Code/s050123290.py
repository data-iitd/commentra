
# Python code to read input from the user and calculate the sum of the digits

while True:
    su = input()  # Read input from the user
    if su == '0': break  # Exit the loop if the input is '0'
    susum = sum(int(digit) for digit in su)  # Calculate the sum of the digits in the input
    print(susum)  # Print the sum of the digits

