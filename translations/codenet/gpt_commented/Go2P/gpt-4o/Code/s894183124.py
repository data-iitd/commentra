# Import the necessary module
import sys

def main():
    # Read an integer from standard input
    n = int(sys.stdin.readline().strip())
    
    # Read a string from standard input
    s = sys.stdin.readline().strip()
    
    # Count the occurrences of the substring "ABC" in the input string
    # and print the result
    print(s.count("ABC"))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
