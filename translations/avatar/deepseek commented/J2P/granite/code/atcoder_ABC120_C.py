
import sys

def main():
    # Read the input string
    x = input()
    # Initialize a stack to keep track of characters
    s = []
    # Initialize a counter to count balanced pairs
    c = 0
    # Iterate through each character in the input string
    for i in range(len(x)):
        # Push the current character onto the stack
        s.append(x[i])
        # While the stack has more than one element, check for balanced pairs
        while len(s) > 1:
            # Pop the top two elements from the stack
            p = s.pop()
            q = s.pop()
            # Check if they form a balanced pair
            if (p == '1' and q == '0') or (p == '0' and q == '1'):
                # Increment the counter if a balanced pair is found
                c += 1
                continue
            else:
                # If not a balanced pair, push the popped elements back onto the stack
                s.append(q)
                s.append(p)
                break
    # Output the result, which is twice the counter value
    print(c * 2)

if __name__ == "__main__":
    main()

