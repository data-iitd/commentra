import sys

def main():
    # Read the first two integers from the standard input
    x = next_int()
    y = next_int()

    # Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
    xt, yt = -1, -1

    # Define a 3x3 2D array a
    a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

    # Iterate through each inner list of the outer list
    for i, t in enumerate(a):
        # Check if x or y is in the current inner list
        if x in t:
            xt = i
        if y in t:
            yt = i

    # Check if the indices xt and yt are equal, if yes, print "Yes"
    if xt == yt:
        print("Yes")
    else:
        print("No")

# Function to read an integer from the input
def next_int():
    return int(sys.stdin.readline().strip())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
