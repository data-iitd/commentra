# Import the necessary module
import sys

def main():
    # Declare variables for radius (r), distance (D), and initial value (x)
    r, D, x = map(int, sys.stdin.readline().split())
    
    # Loop to perform calculations and print results for 10 iterations
    for i in range(1, 11):
        # Calculate and print the result of the formula r*x - D
        print(r * x - D)
        
        # Update x for the next iteration using the formula r*x - D
        x = r * x - D

if __name__ == "__main__":
    main()

# <END-OF-CODE>
