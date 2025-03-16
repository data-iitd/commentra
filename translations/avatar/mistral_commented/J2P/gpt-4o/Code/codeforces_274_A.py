# Importing the necessary libraries
import sys

def main():
    # Reading the first integer value n from the standard input
    n = int(sys.stdin.readline().strip())
    # Reading the long integer value k from the standard input
    k = int(sys.stdin.readline().strip())

    # Creating a list named arr to store long integer values
    arr = list(map(int, sys.stdin.readline().strip().split()))
    # Creating an empty set named set to store unique long integer values
    unique_values = set()

    # Sorting the arr list in ascending order
    arr.sort()

    # Initializing the count variable to 0
    count = 0

    # Iterating through the sorted arr list
    for value in arr:
        # Checking if the value is not divisible by k
        if value % k != 0:
            count += 1  # Incrementing the count variable
            unique_values.add(value)  # Adding the value to the set
        # Checking if the value is divisible by k and if its quotient is not present in the set
        elif (value // k) not in unique_values:
            count += 1  # Incrementing the count variable
            unique_values.add(value)  # Adding the value to the set

    # Printing the count value to the standard output
    print(count)

# Calling the main function to execute the code
if __name__ == "__main__":
    main()

# <END-OF-CODE>
