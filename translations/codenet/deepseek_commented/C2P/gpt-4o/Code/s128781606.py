# Step 1: Import the sys module for input (optional, can use input() directly).
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Declare integer variables A, B, C, D, E, and max.
    A, B = map(int, input().split())  # Step 4: Read two integers A and B from the user.

    # Step 5: Calculate the sum of A and B, store it in C.
    C = A + B
    # Step 6: Calculate the difference between A and B, store it in D.
    D = A - B
    # Step 7: Calculate the product of A and B, store it in E.
    E = A * B

    # Step 8: Initialize max with the value of C.
    max_value = C

    # Step 9: Compare max with D and update max if D is greater.
    if max_value < D:
        max_value = D
    # Step 10: Compare max with E and update max if E is greater.
    if max_value < E:
        max_value = E

    # Step 11: Print the maximum value.
    print(max_value)

# Step 12: Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
