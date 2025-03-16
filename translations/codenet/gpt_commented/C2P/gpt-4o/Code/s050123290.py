N = 1000  # Define a constant N to represent the maximum size of the input array

while True:
    su = input()  # Read a line of input from the user
    if su[0] == '0':  # Check if the first character is '0', which indicates the end of input
        break  # Exit the loop if the first character is '0'
    
    susum = sum(int(char) for char in su)  # Calculate the sum of the digits in the input
    print(susum)  # Print the sum of the digits read

# End of the program
# <END-OF-CODE>
