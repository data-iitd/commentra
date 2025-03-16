def main():
    # Declare variables for input and a map to store string entries
    n = int(input())  # Number of commands to process
    T = {}  # Dictionary to track the presence of strings (True if present)

    # Loop through each command
    for _ in range(n):
        # Read the command and the associated string
        com, str = input().split()
        
        # Check if the command is 'insert' (indicated by the first character being 'i')
        if com == 'insert':
            # Insert the string into the map with a value of True
            T[str] = True
        else:
            # If the command is not 'insert', check if the string exists in the map
            if T.get(str, False):
                # If the string exists, print "yes"
                print("yes")
            else:
                # If the string does not exist, print "no"
                print("no")

# Call the main function
main()

