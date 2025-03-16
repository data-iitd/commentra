
N = int(input())  # Take an integer input N, representing the number of elements in the list A.
A = list(map(int, input().split()))  # Take a space-separated string of integers, convert them into a list of integers, and assign it to the variable A.
import functools  # Import the functools module.
import fractions  # Import the fractions module.
gcd = functools.reduce(fractions.gcd, A)  # Use the reduce function from functools and the gcd function from the fractions module to compute the greatest common divisor (GCD) of all elements in the list A.
print(gcd)  # Print the computed GCD.

