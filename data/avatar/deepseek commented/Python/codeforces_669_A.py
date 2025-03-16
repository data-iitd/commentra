
n = int(input())  # Take an integer input from the user
print((n * 2 + 1) // 3)  # Perform a calculation and print the result



def factorial(n):
    if n == 0:  # Base case: factorial of 0 is 1
        return 1
    else:
        return n * factorial(n - 1)  # Recursive case: n * factorial of (n - 1)

number = int(input())  # Take an integer input from the user
result = factorial(number)  # Calculate the factorial of the input number
print(result)  # Print the result






def fibonacci(n):
    if n <= 0:  # Return 0 for non-positive input
        return 0
    elif n == 1:  # Return 1 for input of 1
        return 1
    else:
        a, b = 0, 1  # Initialize the first two Fibonacci numbers
        for _ in range(2, n + 1):  # Loop from 2 to n
            a, b = b, a + b  # Update the values of a and b
        return b  # Return the nth Fibonacci number

index = int(input())  # Take an integer input from the user
print(fibonacci(index))  # Print the nth Fibonacci number