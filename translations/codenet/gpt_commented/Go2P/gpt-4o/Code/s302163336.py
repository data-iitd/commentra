import sys

# Initialize a scanner to read input from standard input
input = sys.stdin.read
data = input().split()

def main():
    # Read the number of elements (n) and the number of comparisons (m)
    n = int(data[0])
    m = int(data[1])

    # Create a list to hold the heights and a list to track which elements are "good"
    h = [0] * n
    good = [True] * n

    # Read the heights
    for i in range(n):
        h[i] = int(data[i + 2])  # Read height for each element

    # Process each comparison
    index = n + 2
    for _ in range(m):
        ai = int(data[index]) - 1  # Read the first index (0-based)
        bi = int(data[index + 1]) - 1  # Read the second index (0-based)
        index += 2

        # Compare the heights and update the good list accordingly
        if h[ai] > h[bi]:
            good[bi] = False  # If ai is taller, bi is not "good"
        elif h[ai] < h[bi]:
            good[ai] = False  # If bi is taller, ai is not "good"
        else:
            # If heights are equal, mark both as not "good"
            good[ai] = False
            good[bi] = False

    # Count the number of "good" elements
    ans = sum(good)  # Count True values in good list

    # Print the result: the number of "good" elements
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
