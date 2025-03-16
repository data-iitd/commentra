import math

# Function to find the greatest divisor of a given number
def div(n):
    # If the number is even, return 2 as the greatest divisor
    if n % 2 == 0:
        return 2
    # Calculate the square root of the number
    s = int(math.sqrt(n))
    # Check for divisibility by odd numbers from 3 to the square root
    for i in range(3, s + 1, 2):
        # If the number is divisible by the current odd number, return it as the greatest divisor
        if n % i == 0:
            return i
    # If no divisor is found, return the number itself
    return n

def main():
    # Declare and initialize a variable to store the input number
    num = int(input())
    # Print the input number
    print(f"{num}:", end="")
    
    # Continue the process until the number becomes 1
    while num != 1:
        # Print the greatest divisor of the current number
        greatest_divisor = div(num)
        print(f" {greatest_divisor}", end="")
        # Divide the current number by its greatest divisor
        num = num // greatest_divisor
    # Print a newline character to move the cursor to the next line
    print()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
