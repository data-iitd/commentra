
import sys

# Initialize a scanner to read input from standard input
sc = bufio.Scanner(sys.stdin)

def main():
    # Set the scanner to split input by whitespace
    sc.whitespace = " "

    # Read the number of elements (n) and the number of comparisons (m)
    n = int(sc.next())
    m = int(sc.next())

    # Create a list to hold the heights and a list to track which elements are "good"
    h = [0] * n
    good = [True] * n

    # Read the heights and initialize the good list to True
    for i in range(n):
        h[i] = int(sc.next()) # Read height for each element
        good[i] = True   # Initially, all elements are considered "good"

    # Process each comparison
    for i in range(m):
        ai = int(sc.next()) - 1 # Read the first index (0-based)
        bi = int(sc.next()) - 1 # Read the second index (0-based)

        # Compare the heights and update the good list accordingly
        if h[ai] > h[bi]:
            good[bi] = False # If ai is taller, bi is not "good"
        elif h[ai] < h[bi]:
            good[ai] = False # If bi is taller, ai is not "good"
        else:
            # If heights are equal, mark both as not "good"
            good[ai] = False
            good[bi] = False

    # Count the number of "good" elements
    ans = 0
    for i in range(n):
        if good[i]:
            ans += 1 # Increment count for each "good" element

    # Print the result: the number of "good" elements
    print(ans)

# Call the main function
main()

