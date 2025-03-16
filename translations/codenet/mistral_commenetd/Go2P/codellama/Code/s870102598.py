
# Define the main function as the entry point of our program
def main():
    # Declare and initialize three integer variables "a", "b", and "c"
    a, b, c = input(), input(), input()

    # Check if the value of "c" is within the range of "a" and "b"
    if c >= a and c <= b:
        # If the condition is true, print the string "Yes" to the standard output
        print("Yes")
    else:
        # If the condition is false, print the string "No" to the standard output
        print("No")

# Call the main function
main()

