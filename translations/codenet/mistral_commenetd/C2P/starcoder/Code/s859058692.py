# The main function is the entry point of the program
def main():
    sum = 0 # Initialize sum to 0
    n = int(input()) # Read the number of integers to be input from the user
    for i in range(n):
        m = int(input()) # Read an integer input and assign it to m
        sum += m # Add the current integer input to the sum
        if min > m:
            min = m # Set min to the current input if it's smaller
        if max < m:
            max = m # Set max to the current input if it's larger
    print(min, max, sum) # Print the minimum value, maximum value, and sum of the input integers

