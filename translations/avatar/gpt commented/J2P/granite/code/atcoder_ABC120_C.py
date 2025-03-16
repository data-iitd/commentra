
import sys

def main():
    # Read the input string
    x = input()
    s = [] # Stack to store characters
    c = 0 # Counter for pairs of '0' and '1'
    
    # Iterate through each character in the input string
    for i in range(len(x)):
        # Push the current character onto the stack
        s.append(x[i])
        
        # Process the stack while there are at least two characters
        while len(s) > 1:
            p = s.pop() # Pop the top character
            q = s.pop() # Pop the next character
            
            # Check if the characters form a pair of '0' and '1'
            if (p == '1' and q == '0') or (p == '0' and q == '1'):
                c += 1 # Increment the counter for valid pairs
                continue # Continue to check for more pairs
            else:
                # If not a valid pair, push the characters back onto the stack
                s.append(q)
                s.append(p)
                break # Exit the while loop
                
    # Output the result, which is twice the count of pairs found
    print(c * 2)

if __name__ == "__main__":
    main()

