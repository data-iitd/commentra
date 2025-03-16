

import sys # Module for handling system-specific configurations and functions

def main():
    x = input() # Reading the input string
    s = [] # List to store characters
    c = 0 # Counter to store the number of pairs

    # Iterating through each character in the input string
    for i in range(len(x)):
        s.append(x[i]) # Appending the character to the list

        # Popping two characters from the list and checking for a pair
        while len(s) > 1:
            p = s.pop() # Popping the last character from the list
            q = s.pop() # Popping the second last character from the list

            # If the popped characters form a pair, increment the counter and continue
            if (p == '1' and q == '0') or (p == '0' and q == '1'):
                c += 1
                continue
            # If the characters don't form a pair, push them back onto the list and break
            s.append(q)
            s.append(p)
            break

    # Writing the output to the standard output
    print(c * 2)

if __name__ == "__main__":
    main() # Calling the main function

