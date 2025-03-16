
import sys
import math

# Method to calculate a specific value based on the input string and character
def cal(s, c):
    n = len(s) # Get the length of the string
    m = n - 1 # Calculate the last index of the string
    ans = 0 # Initialize the answer variable
    
    # Iterate through each character in the string
    for i in range(n):
        # Check if the current character matches 'c' and if the bitwise AND of m and i equals i
        if s[i] == c and (m & i) == i:
            ans ^= 1 # Toggle the answer using XOR operation
    return ans # Return the final calculated answer

# Main logic to solve the problem
def solve():
    n = int(sys.stdin.readline()) # Read the integer input for the length of the string
    s = sys.stdin.readline().strip() # Read the string input
    sb = [] # Initialize a list to build the new string
    
    # Build a new string based on the absolute differences between adjacent characters
    for i in range(1, n):
        sb.append(abs(ord(s[i]) - ord(s[i - 1]))) # Append the absolute difference
    
    # Special case when the length of the string is 2
    if n == 2:
        print(sb[0]) # Print the first character of the new string
        return # Exit the method
    
    # Convert the list to a string
    s = ''.join(map(chr, sb))
    
    # Check if the new string contains the character '1'
    if '1' in s:
        print(cal(s, '1')) # Calculate and print the result for character '1'
    else:
        print(cal(s, '2') * 2) # Calculate and print the result for character '2', multiplied by 2

# Main method to execute the program
if __name__ == "__main__":
    solve() # Call the solve method

