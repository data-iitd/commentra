

import sys

def main():
    str = input() # Step 1: Read input from the user
    c = list(str) # Step 2: Read the input string
    k = int(input()) # Step 3: Read the value of k
    n = len(str) # Step 4: Initialize the length of the string
    
    for i in range(k): # Step 5: Loop through the character array k times
        if c[i] == '1': # Step 6: Check if the character at the current index is '1'
            if i == k - 1: # Step 7: Check if the current index is the last index
                print(1) # Step 8: Print '1' and return
                return # Step 9: Return from the function
        else: # Step 10: If it is not '1'
            print(c[i]) # Step 11: Print the character and return
            return # Step 12: Return from the function

if __name__ == "__main__":
    main()

