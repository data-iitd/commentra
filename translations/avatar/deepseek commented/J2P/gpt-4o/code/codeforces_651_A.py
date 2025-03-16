import sys

def main():
    a = int(input())  # Read first integer input
    b = int(input())  # Read second integer input
    c = 0  # Initialize counter

    if a == 1 and b == 1:  # Check if both a and b are 1
        print(0)  # Print 0 if true
    else:
        while a >= 1 or b >= 1:  # Continue until a or b is less than or equal to 0
            if a >= b:  # If a is greater than or equal to b
                b += 1  # Increment b
                a -= 2  # Decrement a by 2
            else:  # If b is greater than a
                a += 1  # Increment a
                b -= 2  # Decrement b by 2
            if a <= 0 or b <= 0:  # Check if either a or b is less than or equal to 0
                c += 1  # Increment counter and break the loop
                break
            c += 1  # Increment counter in each iteration
        print(c)  # Print the final value of counter

if __name__ == "__main__":
    main()

# <END-OF-CODE>
