# Import necessary libraries
import sys

# Main function starts here
def main():
    # Initialize variables for number of students and classes
    n, m = map(int, input().split())

    # Initialize lists 's' and 'c' for storing student numbers and classes respectively
    s = []
    c = []

    # Read student numbers and classes from the standard input stream
    for _ in range(m):
        student, class_num = map(int, input().split())
        s.append(student - 1)  # Decrement student numbers by 1 as they are 1-indexed
        c.append(class_num)

    # Check all strings of length 'n' for a valid combination of student numbers and classes
    for i in range(1000):
        # Convert the current number to a string
        st = str(i)

        # Check if the length of the string is equal to 'n'
        if len(st) != n:
            continue

        # Initialize a flag 'f' to check if the current combination is valid
        f = True

        # Check each combination of student number and class
        for j in range(m):
            # Check if the current character in the string matches the expected class
            if st[s[j]] == str(c[j]):
                # If yes, continue to the next check
                continue
            else:
                # If no, set the flag 'f' to False and break the loop
                f = False
                break

        # If all checks passed, print the current number and exit the program
        if f:
            print(i)
            return

    # If no valid combination was found, print -1
    print(-1)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
