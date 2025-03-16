

import sys

# Import necessary modules for input/output operations and utility methods

def main():
    a = int(input())
    b = int(input())
    c = int(input())
    d = int(input())

    if c > b:
        print(0)
    elif a > d:
        print(0)
    elif a < c:
        print(min(b, d) - c)
    else:
        l = [a, b, c, d]
        l.sort()
        print(l[2] - l[1])

if __name__ == "__main__":
    main()

# Define a function called main() to read input from the standard input stream and print the result based on the conditions

# End of code