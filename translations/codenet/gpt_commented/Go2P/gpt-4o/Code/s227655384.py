import sys

# ReadLongLines reads a specified number of long lines from standard input.
def read_long_lines(times):
    result = []  # Create a list to hold the lines read
    for _ in range(times):
        line = sys.stdin.readline().rstrip('\n')  # Read a line from input
        result.append(line)  # Store the line in the result
    return result  # Return the lines read

# PrintList prints a list of integers to the console
def print_list(lst):
    print(" ".join(map(str, lst)))  # Print the list as a space-separated string

# main function where the program execution begins
def main():
    m = set()  # Create a set to track unique integers
    lines = read_long_lines(4)  # Read 4 lines from input
    a = lines[1].split()  # Split the second line into individual strings

    # Convert strings to integers and store them in the set
    for num in a:
        n = int(num)  # Convert string to integer
        m.add(n)  # Add the integer to the set

    result = []  # List to hold the result integers
    b = lines[3].split()  # Split the fourth line into individual strings

    # Process the integers from the fourth line
    for num in b:
        n = int(num)  # Convert string to integer
        if n in m:  # Check if the integer exists in the set
            m.remove(n)  # Remove it from the set if it exists
        else:
            m.add(n)  # Add it to the set if it does not exist

    # Collect remaining integers from the set into the result list
    result.extend(m)

    # Sort the result list in ascending order
    result.sort()

    # Print the sorted result
    print_list(result)  # Print each integer in the result

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
