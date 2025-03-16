# Import the necessary module
import sys

def main():
    # Read an integer K from the user
    K = int(input())
    
    # Read a string S from the user
    S = input()
    
    # Check if the length of the string S is less than or equal to K
    if len(S) <= K:
        # If true, print the string S as it is
        print(S)
    else:
        # If false, truncate the string to the first K characters and append "..."
        print(S[:K] + "...")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
