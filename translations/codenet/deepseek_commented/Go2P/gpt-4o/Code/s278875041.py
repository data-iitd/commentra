# Import the necessary module
import sys

def main():
    # Read input from the user and store it in `a`
    a = input().strip()
    
    # Replace all occurrences of "1" with "0" in the string `a`
    tmp = a.replace("1", "0")
    
    # Replace all occurrences of "9" with "1" in the string `tmp`
    b = tmp.replace("9", "1")
    
    # Replace all occurrences of "0" with "9" in the string `b`
    ans = b.replace("0", "9")
    
    # Print the final result to the console
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
