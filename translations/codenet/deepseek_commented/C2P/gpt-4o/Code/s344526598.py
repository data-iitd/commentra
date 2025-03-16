# Step 1: Import the sys module for input handling.
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Declare an integer list x with a size of 10000.
    x = [0] * 10000
    
    i = 0  # Step 4: Initialize i to 0.
    x[i] = int(input())  # Step 5: Read an integer from the input and store it in x[0].
    
    # Step 6: Use a while loop to read integers into the list x until a zero is entered.
    while x[i] != 0:
        i += 1
        x[i] = int(input())
    
    # Step 7: Use a for loop to print the integers stored in the list x.
    for j in range(i):
        print(f"Case {j + 1}: {x[j]}")
    
# Step 8: Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
