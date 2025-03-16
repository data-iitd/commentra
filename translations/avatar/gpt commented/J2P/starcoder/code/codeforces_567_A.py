import sys; # Importing sys module for reading input from the user

# Reading the number of elements to be inputted
a = int(sys.stdin.readline());

# Initializing an array to hold the input integers
ar = [0] * a;

# Variables to hold the maximum and minimum differences
max = 0;
min = 0;

# Loop to read integers into the array
for i in range(0, a):
    ar[i] = int(sys.stdin.readline()); # Reading each integer into the array

# Loop to calculate and print the min and max differences for each element
for i in range(0, a):
    # Calculating the maximum difference from the first and last elements
    max = max(ar[i] - ar[0], ar[a - 1] - ar[i]);
    
    # Calculating the minimum difference based on the position of the current element
    if (i == 0):
        # If it's the first element, compare with the second element
        min = ar[i + 1] - ar[i];
    elif (i == a - 1):
        # If it's the last element, compare with the second last element
        min = ar[i] - ar[i - 1];
    else:
        # For middle elements, compare with both neighbors
        min = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]);
    
    # Printing the minimum and maximum differences for the current element
    print(min, max);

# Closing the scanner to prevent resource leaks
s.close();

