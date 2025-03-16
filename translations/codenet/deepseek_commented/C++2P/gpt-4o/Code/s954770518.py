# Include necessary libraries
import sys

def main():
    s = []  # Declare a list to store the input numbers

    # Step 3: Read input numbers into the list
    for _ in range(10):
        s.append(int(sys.stdin.readline().strip()))  # Read input and store it in the list

    # Step 4: Sort the list
    s.sort()  # Sort the list in ascending order

    # Step 5: Print the last four numbers of the sorted list
    for i in range(9, 6, -1):
        print(s[i])  # Print the last four numbers

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
