# Import the necessary module for reading input
import sys

def main():
    # Read three long integers from user input
    pandu = int(sys.stdin.readline().strip())
    vundu = int(sys.stdin.readline().strip())
    urdu = int(sys.stdin.readline().strip())
    
    c = 0  # Initialize the accumulation variable

    # The for loop iterates from 1 to urdu (inclusive)
    # In each iteration, it calculates the product of i and pandu and adds it to the variable c
    for i in range(1, urdu + 1):
        c += i * pandu

    # The if-else statement checks if the value of c is less than vundu
    # If it is, the program prints "0". Otherwise, it prints the difference between c and vundu
    if c < vundu:
        print("0")
    else:
        print(c - vundu)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
