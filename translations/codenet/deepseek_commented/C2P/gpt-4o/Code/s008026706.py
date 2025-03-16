# Step 1: Import the necessary module (not needed in this case, but included for completeness)
# import sys

# Step 2: Define the main function
def main():
    # Step 3: Read two integers from the user
    a, b = map(int, input().split())
    
    # Step 4: Calculate the perimeter of a rectangle using the formula 2*a + 2*b
    x = 2 * a + 2 * b
    
    # Step 5: Calculate the area of a rectangle using the formula a*b
    y = a * b
    
    # Step 6: Print the area and perimeter
    print(y, x)

# Step 7: Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
