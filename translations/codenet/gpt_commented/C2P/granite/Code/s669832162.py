
import sys

def main():
    # Read input values for the two dates (month and day) from the command line arguments
    m1, d1, m2, d2 = map(int, sys.argv[1:])

    # Compare the months of the two dates
    if m1!= m2: 
        # If the months are different, print "1"
        print(1)
    else: 
        # If the months are the same, print "0"
        print(0)

if __name__ == "__main__":
    main()

