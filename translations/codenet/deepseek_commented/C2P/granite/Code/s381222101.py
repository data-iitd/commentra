
# Step 1: Import the standard input/output library.
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Declare three integer variables a, b, and h.
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    h = int(sys.stdin.readline())
    
    # Step 4: Read three integer values from the user and store them in a, b, and h.
    
    # Step 5: Calculate the area of a trapezoid using the formula (a+b)*h/2.
    area = (a+b)*h/2
    
    # Step 6: Print the calculated area.
    print(area)
    
    # Step 7: End the main function.
    return 0

# Step 8: Call the main function.
if __name__ == "__main__":
    main()

# 