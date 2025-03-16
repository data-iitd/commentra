# Step 1: Import the sys module for input handling.
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Read values for a, b, c, x, y from the user.
    a, b, c, x, y = map(int, sys.stdin.readline().split())
    
    # Step 4: Double the value of c.
    c *= 2
    
    # Step 5: Check if the sum of a and b is less than or equal to c.
    if a + b <= c:
        # Step 6: If true, print the product of a and x plus the product of b and y.
        print(a * x + b * y)
    else:
        # Step 7: If false, start the else block.
        if x <= y:
            # Step 8: Check if b is less than or equal to c.
            if b <= c:
                # Step 9: If true, print the product of c and x plus the product of (y-x) and b.
                print(c * x + (y - x) * b)
            else:
                # Step 10: If false, print the product of c and y.
                print(c * y)
        else:
            # Step 11: If x is greater than y, start the else block.
            if a <= c:
                # Step 12: If true, print the product of c and y plus the product of (x-y) and a.
                print(c * y + (x - y) * a)
            else:
                # Step 13: Print the product of c and x.
                print(c * x)

# Step 14: Call the main function.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
