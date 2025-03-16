# Include the necessary library for input/output operations
import sys

def main():  # Beginning of the main function
    for line in sys.stdin:  # Read input line by line
        m, f, r = map(int, line.split())  # Split the line into integers m, f, and r

        if m == -1 or f == -1:  # Check if m or f is -1
            print("F")  # If so, print "F" and move on to the next input
            continue

        if m + f >= 80:  # Check if the sum of m and f is greater than or equal to 80
            print("A")  # If so, print "A" and move on to the next input
            continue

        if m + f >= 65:  # Check if the sum of m and f is greater than or equal to 65
            print("B")  # If so, print "B" and move on to the next input
            continue

        if m + f >= 50 or r >= 50:  # Check if the sum of m and f is greater than or equal to 50
                                      # or if r is greater than or equal to 50
            print("C")  # If so, print "C" and move on to the next input
            continue

        if m + f >= 30:  # Check if the sum of m and f is greater than or equal to 30
            print("D")  # If so, print "D" and move on to the next input
            continue

        print("F")  # If none of the above conditions are met, print "F" and move on to the next input

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
