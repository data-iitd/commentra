# Step 1: Import the sys module for input handling.
import sys

# Step 2: Define the main function.
def main():
    c = []  # Step 3: Initialize an empty list 'c' to store results.

    while True:  # Step 4: Start an infinite loop.
        # Step 5: Read three inputs: an integer 'a', a character 'm', and an integer 'b'.
        input_line = sys.stdin.readline().strip()
        if not input_line:  # Handle empty input to break the loop.
            break
        a, m, b = input_line.split()
        a = int(a)
        b = int(b)

        if m == '?':  # Step 6: Check if the character 'm' is '?'. If true, break the loop.
            break
        if m == '+':  # Step 7: Depending on the character 'm', perform the corresponding arithmetic operation and store the result in the list 'c'.
            c.append(a + b)
        elif m == '-':
            c.append(a - b)
        elif m == '*':
            c.append(a * b)
        elif m == '/':
            c.append(a // b)  # Use integer division for consistency with C.

    # Step 9: After the loop ends, print the results stored in the list 'c'.
    for result in c:  
        print(result)

# Step 10: Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
