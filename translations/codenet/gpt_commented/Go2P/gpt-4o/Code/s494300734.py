# Import the necessary module
import sys

def main():
    # Read a string input from the user
    s = input().strip()
    
    # Initialize the answer variable with "No"
    ans = "No"
    
    # Check if the first occurrence of 'C' is before the last occurrence of 'F'
    index_C = s.find("C")
    index_F = s.rfind("F")
    
    if index_C != -1 and index_C < index_F:
        # If true, set the answer to "Yes"
        ans = "Yes"
    
    # Check if 'C' does not exist in the string
    if index_C == -1:
        # If true, set the answer to "No"
        ans = "No"
    
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
