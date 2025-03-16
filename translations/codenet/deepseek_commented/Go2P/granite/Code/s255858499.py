
import sys

# nextLine reads the next line of input from the user
def nextLine():
    return sys.stdin.readline().strip()

if __name__ == '__main__':
    # Reading the first integer input
    a = int(nextLine())
    # Reading the second integer input
    b = int(nextLine())

    # Checking if the product of a and b is odd or even and printing the result
    if (a * b) % 2!= 0:
        print("Odd")
    else:
        print("Even")
