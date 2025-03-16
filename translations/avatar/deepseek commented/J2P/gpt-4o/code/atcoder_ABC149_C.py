import math  # Importing the math module for mathematical operations

def main():
    x = int(input())  # Reading an integer input from the user

    # Step 2: Check if the input is not equal to 2 and is even. If so, increment the input by 1.
    if x != 2 and x % 2 == 0:
        x += 1

    # Step 3: Enter a loop where it checks if the number is a prime number.
    while True:
        sqrt_num = math.sqrt(x)  # Calculate the square root of the number

        # Step 4: Check for factors from 3 up to the square root of the number, incrementing by 2 (only odd numbers)
        for i in range(3, int(sqrt_num) + 1, 2):
            if x % i == 0:
                break  # If a factor is found, break out of the loop
        else:
            # Step 5: If no factors are found and i is greater than the square root, the number is prime
            break  # Exit the loop once a prime number is found

        # If the number is not prime, increment by 2 and check again
        x += 2

    # Step 5: Print the prime number found
    print(x)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
