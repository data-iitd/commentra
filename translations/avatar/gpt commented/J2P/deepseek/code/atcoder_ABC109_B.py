from collections import defaultdict
import sys

def main():
    # Read the number of strings to be processed
    N = int(input().strip())
    
    # Initialize a defaultdict to store the strings with their corresponding indices
    map_dict = defaultdict(str)
    
    # Read N strings from the input and store them in the map
    for i in range(N):
        map_dict[i] = input().strip()
    
    # Initialize a boolean variable to track if the conditions are met
    ans = True
    
    # Initialize a defaultdict to keep track of previously seen strings
    past_dict = defaultdict(str)
    
    # Variable to hold the last character of the previous string
    next_char = ""
    
    # Iterate through the strings to check the conditions
    for i in range(N):
        # Check if the current string has already been seen
        if list(past_dict.values()).count(map_dict[i]) > 0:
            ans = False  # Set answer to false if a duplicate is found
            break
        
        # Store the current string in the past map
        past_dict[i] = map_dict[i]
        
        # Check if this is not the first string
        if i != 0:
            # Check if the first character of the current string matches the last character of the previous string
            if next_char != map_dict[i][0]:
                ans = False  # Set answer to false if the characters do not match
                break
        
        # Update 'next_char' to the last character of the current string
        next_char = map_dict[i][-1]
    
    # Output the result based on the value of ans
    if ans:
        print("Yes")  # Print "Yes" if all conditions are satisfied
    else:
        print("No")  # Print "No" if any condition fails

if __name__ == "__main__":
    main()
