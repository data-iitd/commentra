# Step 1: Define a function named 'swap' that takes two integer references as arguments.
def swap(a, b):
    # Step 2: Inside the 'swap' function, declare a temporary variable 'tmp'.
    tmp = a  # Step 3: Assign the value of 'a' to 'tmp'.
    a = b    # Step 4: Assign the value of 'b' to 'a'.
    b = tmp  # Step 5: Assign the value stored in 'tmp' to 'b'.
    return a, b  # Step 6: Return the swapped values.

# Step 7: In the 'main' function, create an infinite loop using 'while True'.
while True:
    # Step 8: Use 'input' to read two integers from the user and store them in 'a' and 'b'.
    a, b = map(int, input("Enter two integers (0 0 to exit): ").split())
    # Step 9: Check if both 'a' and 'b' are zero. If true, break the loop.
    if a == 0 and b == 0:
        break
    # Step 10: Check if 'b' is less than 'a'. If true, call the 'swap' function to swap the values of 'a' and 'b'.
    if b < a:
        a, b = swap(a, b)
    # Step 11: Print the values of 'a' and 'b'.
    print(a, b)  # Step 12: Print the values of 'a' and 'b'.

# Step 13: End the program.
# <END-OF-CODE>
