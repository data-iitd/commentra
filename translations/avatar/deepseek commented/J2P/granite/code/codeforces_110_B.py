
n = int(input()) # Read the size of the array from the user
c = [chr(97+i//4) for i in range(n)] # Initialize the character array of size n
print(''.join(c)) # Print the character array to the console
