import sys

# next() reads a single line of input as a string
def next():
    return sys.stdin.readline().strip()

# nextInt() reads a single line of input as an integer
def nextInt():
    return int(next())

def main():
    # Reading three integers and checking if their sum is greater than or equal to the third integer
    if nextInt() + nextInt() >= nextInt():
        print("Yes")  # Printing "Yes" if the condition is true
    else:
        print("No")   # Printing "No" if the condition is false

if __name__ == "__main__":
    main()

# <END-OF-CODE>
