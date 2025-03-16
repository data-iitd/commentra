import math  # Importing the math module for mathematical operations

def main():
    N = int(input())  # Reading the first integer `N` from the standard input
    A = int(input())  # Reading the second integer `A` from the standard input
    B = int(input())  # Reading the third integer `B` from the standard input

    k = 0  # Initializing a variable `k` with the value 0

    if is_valid_input(N, A, B):  # Checking if the input values are valid
        if A + B <= N:  # Checking if the sum of `A` and `B` is less than or equal to `N`
            k = calculate_k(N, A, B)  # Calculating the number of times `A + B` can be added to `N` and storing the result in `k'

            if remaining_part_greater_than_A(N, k, A, B):  # Checking if the remaining part of `N` after subtracting `k * (A + B)` is greater than `A`
                print_result(N, k, A, B)  # Printing the result of the expression
            else:
                print_result(N, k, A, B)  # Printing the result of the expression
        elif A + B > N and A <= N:  # Checking if the sum of `A` and `B` is greater than `N`, but `A` is less than or equal to `N`
            print_A(A)  # Printing the value of `A`
        else:  # If neither of the above conditions is true
            print_N(N)  # Printing the value of `N`

def is_valid_input(n, a, b):
    return (1 <= n <= 10**18 and 0 <= a and 0 <= b and 0 < a + b and a + b <= 10**18)

def calculate_k(n, a, b):
    return n // (a + b)

def remaining_part_greater_than_A(n, k, a, b):
    return (n - k * (a + b)) > a

def print_result(n, k, a, b):
    if remaining_part_greater_than_A(n, k, a, b):
        result = a * k + (n - k * (a + b)) - (n - (k * (a + b) + a))
    else:
        result = a * k + (n - k * (a + b))
    print(result)

def print_A(a):
    print(a)

def print_N(n):
    print(n)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
