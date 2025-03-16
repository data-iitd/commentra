# Import necessary modules
from collections import defaultdict

def main():
    # Create a dictionary to store the strings with their corresponding indices
    map = {}
    
    # Read the number of strings to be processed
    N = int(input())
    
    # Read N strings from the input and store them in the map
    for i in range(N):
        map[i] = input().strip()
    
    # Initialize a boolean variable to track if the conditions are met
    ans = True
    
    # Initialize a set to keep track of previously seen strings
    past = set()
    
    # Variable to hold the last character of the previous string
    next_char = ""
    
    # Iterate through the strings to check the conditions
    for i in range(N):
        # Check if the current string has already been seen
        if map[i] in past:
            ans = False  # Set answer to false if a duplicate is found
            break
        
        # Store the current string in the past set
        past.add(map[i])
        
        # Check if this is not the first string
        if i != 0:
            # Check if the first character of the current string matches the last character of the previous string
            if next_char != map[i][0]:
                ans = False  # Set answer to false if the characters do not match
                break
        
        # Update 'next_char' to the last character of the current string
        next_char = map[i][-1]
    
    # Output the result based on the value of ans
    if ans:
        print("Yes")  # Print "Yes" if all conditions are satisfied
    else:
        print("No")  # Print "No" if any condition fails

if __name__ == "__main__":
    main()

# <END-OF-CODE>
