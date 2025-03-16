import sys

def main():
    # Read the first line of input, split by spaces, and store in a list
    str_list = sys.stdin.readline().strip().split()
    
    # Read the second line of input and parse the integers
    a, b = map(int, sys.stdin.readline().strip().split())
    
    # Read another string from the input
    u = sys.stdin.readline().strip()
    
    # Check if the read string is equal to the first element of the list and print accordingly
    if u == str_list[0]:
        print(a - 1, b)
    else:
        print(a, b - 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
