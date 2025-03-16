# Step 1: Define the main function which is the entry point of the program.
def main():
    # Step 2: Read the number of sheep and wolves from the user.
    sheep, wolf = map(int, input().split())  # Step 3: Use input and map to read and convert the input to integers.

    # Step 4: Check if the number of wolves is greater than or equal to the number of sheep.
    if wolf >= sheep:  # Step 5:
        print("unsafe")  # Step 6: If the condition is true, print "unsafe".
    else:
        print("safe")  # Step 7: Otherwise, print "safe".

# Step 8: Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
