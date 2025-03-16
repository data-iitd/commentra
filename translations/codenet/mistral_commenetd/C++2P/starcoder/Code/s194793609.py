
# Declare the main function
def main():
    n = int(input()) # Read the number of elements in the vector 'a'

    a = [0] * n # Declare a vector 'a' of size 'n' and initialize it with zeros

    for i in range(n):
        a[i] = int(input()) # Read the 'i'-th element of the vector 'a'

    abs_a = a.copy() # Create a copy of the vector 'a' named 'abs_a' to store the absolute values of its elements

    for i in range(n):
        if abs_a[i] < 0: # Check if the current element is negative
            abs_a[i] = -abs_a[i] # Make it positive by negating it

    ans = 0 # Initialize the variable 'ans' with zero
    min = abs_a[0] # Initialize the variable'min' with the first element of 'abs_a'

    for e in abs_a:
        ans += e # Add the current element to the variable 'ans'
        if min > e: # Check if the current element is smaller than the current minimum
            min = e # Update the minimum if it is

    num_negative = 0 # Initialize the variable 'num_negative' with zero
    for e in a:
        if e < 0: # Check if the current element is negative
            num_negative += 1 # Increment the counter if it is

    if num_negative % 2:
        ans -= min * 2 # Subtract twice the minimum if the number of negative elements is odd

    print(ans) # Print the final answer 'ans' to the standard output

# Call the main function
if __name__ == "__main__":
    main()

