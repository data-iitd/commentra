# Step 1: Import the sys module for input/output (not necessary for this simple case).
# Step 2: Define the main function.
def main():
    # Step 3: Declare integer variables a and b.
    a, b = map(int, input().split())  # Step 4: Read two integers from the user.
    ar = a * b  # Step 5: Calculate the area of a rectangle (ar) by multiplying a and b.
    le = 2 * (a + b)  # Step 6: Calculate the perimeter of a rectangle (le) by doubling the sum of a and b.
    print(ar, le)  # Step 7: Print the area and perimeter.

# Step 8: Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
