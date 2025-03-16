# Import the necessary module
import sys

def main():
    # Read three strings from standard input
    s1, s2, s3 = sys.stdin.read().split()
    
    # Get the first character of each string, convert to uppercase and concatenate them
    result = s1[0].upper() + s2[0].upper() + s3[0].upper()
    
    # Print the concatenated result
    print(result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
