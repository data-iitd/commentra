
# Declare the main function
def main():
    # Declare an integer variable 'n' to read the number of elements in the vector 'a'
    n = int(input())

    # Declare a vector 'a' of size 'n' and initialize it with zeros
    a = [0] * n

    # Read the elements of the vector 'a' from the standard input
    for i in range(n):
        a[i] = int(input()) # Read the 'i'-th element of the vector 'a'

    # Create a copy of the vector 'a' named 'abs_a' to store the absolute values of its elements
    abs_a = a.copy()

    # Iterate through each element of the vector 'abs_a' and make it positive if it's negative
    for i in range(n):
        if abs_a[i] < 0: # Check if the current element is negative
            abs_a[i] = -abs_a[i] # Make it positive by negating it

    # Initialize the variables 'ans' and 'min' with zero and the first element of 'abs_a' respectively
    ans = 0
    min = abs_a[0]

    # Iterate through each element of the vector 'abs_a' and update the variables 'ans' and 'min' accordingly
    for e in abs_a:
        ans += e # Add the current element to the variable 'ans'
        if min > e: # Check if the current element is smaller than the current minimum
            min = e # Update the minimum if it is

    # Initialize the variable 'num_negative' with zero and count the number of negative elements in the vector 'a'
    num_negative = 0
    for e in a:
        if e < 0: # Check if the current element is negative
            num_negative += 1 # Increment the counter if it is

    # Check if the number of negative elements is odd or even and update the variable 'ans' accordingly
    if num_negative % 2:
        ans -= min * 2 # Subtract twice the minimum if the number of negative elements is odd

    # Print the final answer 'ans' to the standard output
    print(ans)

# Call the main function
main()

