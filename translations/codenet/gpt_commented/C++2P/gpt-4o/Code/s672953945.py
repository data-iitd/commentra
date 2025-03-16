# Include necessary libraries
from typing import List

def main():
    # Declare a list to store strings
    v: List[str] = []
    
    # Read the number of strings (N) and the length of strings (L)
    N, L = map(int, input().split())
    
    # Input N strings from the user and store them in the list
    for _ in range(N):
        s = input()
        v.append(s)  # Add the string to the list
    
    # Sort the list of strings in lexicographical order
    v.sort()
    
    # Output the sorted strings
    for string in v:
        print(string, end='')  # Print each string in the sorted order
    print()  # Print a newline at the end

if __name__ == "__main__":
    main()

# <END-OF-CODE>
