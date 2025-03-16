# Import the necessary module
import sys

def main():
    # Read three integers from standard input
    in_numbers = list(map(int, sys.stdin.readline().split()))

    # Sort the integers in ascending order
    in_numbers.sort()

    # Calculate the result based on the sorted integers
    # The result is computed as: (largest number * 10) + (second largest number) + (smallest number)
    result = in_numbers[2] * 10 + in_numbers[1] + in_numbers[0]
    
    # Print the result
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
