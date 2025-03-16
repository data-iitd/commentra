# Import necessary modules
import sys

# Function to read input and check for duplicates
def main():
    # Read the number of elements
    n = int(sys.stdin.readline().strip())
    
    # Initialize a list to store the elements and read them from input
    a = list(map(int, sys.stdin.readline().strip().split()))
    
    # Sort the list to facilitate duplicate checking
    a.sort()
    
    # Check for duplicates in the sorted list
    for i in range(n - 1):
        if a[i] == a[i + 1]:
            # If a duplicate is found, print "NO" and exit
            print("NO")
            return
    
    # If no duplicates are found, print "YES"
    print("YES")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
