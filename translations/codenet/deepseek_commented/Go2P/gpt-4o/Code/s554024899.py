import sys

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Read two integers from the input
    x = next_int()
    y = next_int()
    
    # Define a list containing three groups of months with the same number of days
    a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]
    
    # Determine which group each of the integers belongs to
    xt = yt = -1
    for i, t in enumerate(a):
        if x in t:
            xt = i
        if y in t:
            yt = i
    
    # Compare the groups of x and y to determine if they belong to the same group
    if xt == yt:
        print("Yes")
    else:
        print("No")

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
