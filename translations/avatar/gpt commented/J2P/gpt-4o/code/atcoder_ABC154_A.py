import sys

def main():
    # Read a line of input, split it by spaces, and store it in a list
    str_input = sys.stdin.readline().strip().split()
    
    # Read the next line of input and split it into tokens
    a, b = map(int, sys.stdin.readline().strip().split())
    
    # Read another line of input and store it in variable 'u'
    u = sys.stdin.readline().strip()
    
    # Compare the string 'u' with the first element of the list 'str_input'
    # Print the result based on the comparison
    if u == str_input[0]:
        print(a - 1, b)
    else:
        print(a, b - 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
