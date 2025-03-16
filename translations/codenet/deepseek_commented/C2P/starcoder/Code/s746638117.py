# Step 1: Include the standard input/output library.
import sys

# Step 2: Define the main function.
def main():
        # Step 3: Declare integer variables a, b, ar, and le.
        a = 0
        b = 0
        ar = 0
        le = 0

        # Step 4: Read two integers from the user.
        a = int(raw_input("Enter a: "))
        b = int(raw_input("Enter b: "))

        # Step 5: Calculate the area of a rectangle (ar) by multiplying a and b.
        ar = a * b

        # Step 6: Calculate the perimeter of a rectangle (le) by doubling the sum of a and b.
        le = 2 * (a + b)

        # Step 7: Print the area and perimeter.
        print ar, le

        # Step 8: Return 0 to indicate successful execution.
        return 0

# Step 9: Call the main function.
if __name__ == "__main__":
        main()

# 