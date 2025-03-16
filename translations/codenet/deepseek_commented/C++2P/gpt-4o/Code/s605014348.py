import math

# Function to find the smallest divisor of a number
def div(n):
    if n % 2 == 0:
        return 2  # Check if the number is even and return 2
    s = int(math.sqrt(n))
    for i in range(3, s + 1, 2):  # Check for divisors starting from 3 up to the square root
        if n % i == 0:
            return i  # Return the first divisor found
    return n  # If no divisor is found, return the number itself

def main():
    num = int(input())  # Read an integer from the user
    print(f"{num}:", end="")

    while num != 1:
        smallest_divisor = div(num)
        print(f" {smallest_divisor}", end="")  # Print the smallest divisor
        num //= smallest_divisor  # Divide the number by its smallest divisor
    print()  # Print a newline at the end

if __name__ == "__main__":
    main()

# <END-OF-CODE>
