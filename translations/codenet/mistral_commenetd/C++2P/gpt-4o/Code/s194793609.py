# Declare the main function
def main():
    n = int(input())  # Read the number of elements 'n' from the standard input

    # Declare a list 'a' of size 'n' and initialize it with zeros
    a = [0] * n

    # Read the elements of the list 'a' from the standard input
    for i in range(n):
        a[i] = int(input())  # Read the 'i'-th element of the list 'a'

    # Create a copy of the list 'a' named 'abs_a' to store the absolute values of its elements
    abs_a = a.copy()

    # Iterate through each element of the list 'abs_a' and make it positive if it's negative
    for i in range(n):
        if abs_a[i] < 0:  # Check if the current element is negative
            abs_a[i] = -abs_a[i]  # Make it positive by negating it

    # Initialize the variables 'ans' and 'min' with zero and the first element of 'abs_a' respectively
    ans = 0
    min_val = abs_a[0]

    # Iterate through each element of the list 'abs_a' and update the variables 'ans' and 'min' accordingly
    for e in abs_a:
        ans += e  # Add the current element to the variable 'ans'
        if min_val > e:  # Check if the current element is smaller than the current minimum
            min_val = e  # Update the minimum if it is

    # Initialize the variable 'num_negative' with zero and count the number of negative elements in the list 'a'
    num_negative = 0
    for e in a:
        if e < 0:  # Check if the current element is negative
            num_negative += 1  # Increment the counter if it is

    # Check if the number of negative elements is odd or even and update the variable 'ans' accordingly
    if num_negative % 2:  # If the number of negative elements is odd
        ans -= min_val * 2  # Subtract twice the minimum if the number of negative elements is odd

    # Print the final answer 'ans' to the standard output
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
