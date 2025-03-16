# Step 1: Use the input function to read values from the user.
# Step 2: Define the main function where the execution of the program begins.
def main():
    # Step 3: Read four integers from the user and store them in variables a, b, c, and d.
    a, b, c, d = map(int, input().split())
    
    # Step 4: Compare the sum of a and b with the sum of c and d.
    if a + b > c + d:  # Step 5
        print("Left")   # Step 6
    elif a + b < c + d:  # Step 7
        print("Right")  # Step 8
    else:  # Step 9
        print("Balanced")

# Step 10: Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
