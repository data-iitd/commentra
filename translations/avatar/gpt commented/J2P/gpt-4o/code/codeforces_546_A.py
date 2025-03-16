# Importing the sys module for user input
import sys

def main():
    # Declaring variables to hold input values and a counter
    pandu = int(sys.stdin.readline().strip())  # The first input value
    vundu = int(sys.stdin.readline().strip())  # The second input value
    urdu = int(sys.stdin.readline().strip())   # The third input value
    
    # Initializing the counter
    c = 0
    
    # Calculating the cumulative sum of 'pandu' multiplied by each integer from 1 to 'urdu'
    for i in range(1, urdu + 1):
        c += i * pandu  # Incrementing 'c' by the product of 'i' and 'pandu'
    
    # Checking if the calculated sum 'c' is less than 'vundu'
    if c < vundu:
        print("0")  # If true, print "0"
    else:
        # If 'c' is greater than or equal to 'vundu', print the difference
        print(c - vundu)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
