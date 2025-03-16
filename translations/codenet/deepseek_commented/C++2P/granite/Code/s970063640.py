
n = int(input()) # Read the value of n from the standard input
a = int(input()) # Read the value of a from the standard input
s = [] # Initialize an empty list to store the elements
for i in range(n): # Loop to read 'n' elements into the list's'
    s.append(int(input())) # Read the elements from the standard input and append them to the list
s.sort() # Sort the list's' in ascending order
sum = sum(s[-a:]) # Calculate the sum of the last 'a' elements using the built-in'sum' function and list slicing
print(sum) # Print the calculated sum to the standard output
