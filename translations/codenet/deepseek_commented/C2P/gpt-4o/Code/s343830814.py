# Import necessary modules
import sys

def main():
    # Step 3: Read input from stdin
    buf = sys.stdin.readline()  # Read a line of input

    # Step 4: Calculate the length of the input
    length = len(buf)

    # Step 5: Print the first character, the length minus 3, and the second last character of the input
    print(f"{buf[0]}{length - 3}{buf[-2]}")

# Step 6: Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
