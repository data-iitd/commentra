
import sys

def main():
    # Read the first input as an integer
    n = int(input())

    # Check if the input is 1
    if n == 1:
        # If the input is 1, print "Hello World"
        print("Hello World")
    else:
        # If the input is not 1, read two more strings
        strs = sys.stdin.readlines()
        # Parse the two strings as integers and print their sum
        print(int(strs[0]) + int(strs[1]))

if __name__ == "__main__":
    main()

