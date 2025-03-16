
# Importing the Scanner class to read input from the user
import java.util.Scanner;

# Creating a Scanner object to read input from the user
scanner = java.util.Scanner(System.in);

# Reading the first integer input from the user
a = scanner.nextInt();

# Reading the second integer input from the user
b = scanner.nextInt();

# Checking if the first number is positive
if (a > 0):
    print("Positive"); # Printing "Positive" if the first number is greater than 0

# Checking if the first number is zero or the second number is non-negative
elif (b >= 0):
    print("Zero"); # Printing "Zero" if the second number is non-negative

# Checking if the difference between b and a plus one is even
elif ((b - a + 1) % 2 == 0):
    print("Positive"); # Printing "Positive" if the difference is even

else:
    print("Negative"); # Printing "Negative" if none of the above conditions are met

# 