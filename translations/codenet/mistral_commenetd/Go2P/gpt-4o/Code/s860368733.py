# main function is the entry point of the program
def main():
    # Initialize variables
    n, m = map(int, input().split())
    # Allocate memory for h array
    h = list(map(int, input().split()))
    # Initialize counter set
    counter = set()
    # Read m query pairs from standard input
    for _ in range(m):
        a, b = map(int, input().split())
        # Check the condition for a and b
        if h[a - 1] < h[b - 1]:
            # Add a to the counter set if h[a-1] is smaller than h[b-1]
            counter.add(a)
        elif h[a - 1] > h[b - 1]:
            # Add b to the counter set if h[a-1] is greater than h[b-1]
            counter.add(b)
        else:
            # Add both a and b to the counter set if h[a-1] is equal to h[b-1]
            counter.add(a)
            counter.add(b)
        # Comment for the loop that processes m query pairs
    # Print the result
    print(n - len(counter))
    # Comment for the final print statement

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
