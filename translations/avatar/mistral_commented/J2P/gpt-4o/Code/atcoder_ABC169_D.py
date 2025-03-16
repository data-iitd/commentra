import math  # Importing math module for mathematical functions

def main():  # Defining the main function
    try:  # Starting a try block for handling exceptions
        n = int(input("Enter a long integer: "))  # Reading a long integer value from user input

        # Calculating the square root of the given number
        sqrt = int(math.sqrt(n))

        # Initializing the answer variable to 0
        answer = 0

        # Checking for prime factors of the given number
        for i in range(2, sqrt + 1):  # Starting a for loop to check for prime factors
            count = 0  # Initializing a counter variable to count the number of occurrences of a prime factor
            while n % i == 0:  # Checking if the given number is divisible by the current prime factor
                n //= i  # Dividing the given number by the current prime factor
                count += 1  # Incrementing the counter variable

            # Calculating the contribution of the current prime factor to the answer
            for j in range(1, count + 1):
                count -= j
                answer += 1

        # Checking for the remaining prime factor (if any)
        if n > 1:
            answer += 1

        # Printing the result
        print(answer)

    except Exception as e:  # Catching any exceptions that might occur during the execution
        print("Error:", str(e))
        
if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
