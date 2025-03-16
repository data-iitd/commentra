def main():
    import sys

    # Initialize a 3x3 list to hold the input values
    c = [[0] * 3 for _ in range(3)]
    # Initialize lists to hold differences for calculations
    a = [0] * 3
    b = [0] * 3

    # Read 3x3 integers from input and populate the list 'c'
    for i in range(3):
        line = sys.stdin.readline().strip().split()
        for j in range(3):
            c[i][j] = int(line[j])  # Convert the word to an integer and store it in 'c'

    # Calculate the first differences based on the first row of 'c'
    b[0] = c[0][0] - a[0]
    b[1] = c[0][1] - a[0]
    b[2] = c[0][2] - a[0]

    # Calculate the differences for the second and third rows based on the first row
    a[1] = c[1][0] - c[0][0]
    a[2] = c[2][0] - c[0][0]

    # Check if the calculated differences are consistent across the matrix
    if (a[1] == c[1][1] - c[0][1] and a[1] == c[1][2] - c[0][2] and
            a[2] == c[2][1] - c[0][1] and a[2] == c[2][2] - c[0][2]):
        # If the conditions are met, print "Yes"
        print("Yes")
    else:
        # If the conditions are not met, print "No"
        print("No")

if __name__ == "__main__":
    main()
# <END-OF-CODE>
