# Import the necessary module
import sys

def main():
    # Read input from the user
    a = input().strip()
    
    # Replace all occurrences of '1' with '0' in the input string
    tmp = a.replace("1", "0")
    
    # Replace all occurrences of '9' with '1' in the modified string
    b = tmp.replace("9", "1")
    
    # Replace all occurrences of '0' with '9' in the second modified string
    ans = b.replace("0", "9")
    
    # Print the final transformed string
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
