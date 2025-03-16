import sys  # Import sys for standard input and output

def main():
    try:
        # Read the number of elements in the list from the user input
        n = int(input().strip())

        # Create a set to store the unique elements
        a = set()
        for _ in range(n):  # Iterate through the input elements
            value = int(input().strip())  # Read the next input value
            a.add(value)  # Add the value to the set

        # Convert the set to a sorted list
        a = sorted(a)

        # Check if there exists a sequence of three consecutive elements with a difference of 1
        found = False
        for i in range(len(a) - 2):  # Iterate through the list elements
            if a[i] + 1 == a[i + 1] and a[i + 1] + 1 == a[i + 2]:  # Check if the difference is 1
                found = True  # Set the found flag if a sequence is found
                break  # Exit the loop if a sequence is found

        # Write the output to the console
        print("YES" if found else "NO")

    except Exception as e:
        print(f"An error occurred: {e}", file=sys.stderr)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
