# Step 1: Import the sys module for input/output operations.
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Read three integer values from the user and store them in a, b, and h.
    a, b, h = map(int, sys.stdin.readline().split())
    
    # Step 4: Calculate the area of a trapezoid using the formula (a+b)*h/2.
    area = (a + b) * h // 2
    
    # Step 5: Print the area.
    print(area)

# Step 6: Call the main function.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
