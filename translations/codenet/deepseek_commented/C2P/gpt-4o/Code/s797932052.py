# Declare two integer variables to store user input
a = int(input())  # Read an integer value from the user and store it in variable a
b = int(input())  # Read another integer value from the user and store it in variable b

# Check if the product of a and b is even or odd
if (a * b) % 2 == 0:
    print("Even")  # Print "Even" if the product is even
else:
    print("Odd")   # Print "Odd" if the product is odd

# Return 0 to indicate successful execution of the program
# In Python, we don't need to explicitly return from main
# <END-OF-CODE>
