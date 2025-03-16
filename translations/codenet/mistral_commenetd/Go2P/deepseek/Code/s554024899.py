import sys

def main():
    # Read the first two integers from the standard input
    x, y = map(int, sys.stdin.readline().split())

    # Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
    xt, yt = -1, -1

    # Define a 3x3 2D array a
    a = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

    # Iterate through each inner loop of the outer loop
    for i, t in enumerate(a):
        # Iterate through each element of the current inner loop
        for n in t:
            # Check if the current element is equal to x, if yes, store its index in xt
            if x == n:
                xt = i
            # Check if the current element is equal to y, if yes, store its index in yt
            if y == n:
                yt = i

    # Check if the indices xt and yt are equal, if yes, print "Yes"
    if xt == yt:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

