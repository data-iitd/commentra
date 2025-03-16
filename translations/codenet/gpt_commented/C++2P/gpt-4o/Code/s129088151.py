# Import necessary modules
from collections import defaultdict

def main():
    # Declare a variable for the number of commands to process
    n = int(input())  # Read the number of commands from input
    T = defaultdict(bool)  # Dictionary to track the presence of strings (default to False)

    # Loop through each command
    for _ in range(n):
        com, str_input = input().split()  # Read the command and the associated string
        
        # Check if the command is 'insert'
        if com[0] == 'i':
            # Insert the string into the dictionary with a value of True
            T[str_input] = True
        else:
            # If the command is not 'insert', check if the string exists in the dictionary
            if T[str_input]:
                # If the string exists, print "yes"
                print("yes")
            else:
                # If the string does not exist, print "no"
                print("no")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
