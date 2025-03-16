# Define the main function as the entry point of our program
def main():
    # Declare and initialize three integer variables "a", "b", and "c"
    a, b, c = map(int, input().split())

    # Check if the value of "c" is within the range of "a" and "b"
    if a <= c <= b:
        # If the condition is true, print "Yes"
        print("Yes")
    else:
        # If the condition is false, print "No"
        print("No")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
