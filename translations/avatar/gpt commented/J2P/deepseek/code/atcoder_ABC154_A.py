import sys

def main():
    # Read a line of input, split it by spaces, and store it in a list
    str = input().split()
    
    # Read the next line of input and use a StringTokenizer to split it by spaces
    a, b = map(int, input().split())
    
    # Read another line of input and store it in variable 'u'
    u = input()
    
    # Compare the string 'u' with the first element of the list 'str'
    # Print the result based on the comparison
    if u == str[0]:
        print(a - 1, b)
    else:
        print(a, b - 1)

if __name__ == "__main__":
    main()
