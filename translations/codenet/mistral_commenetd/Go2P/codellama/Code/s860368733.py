
# main function is the entry point of the program
def main():
    # Initialize variables
    n, m = map(int, input().split())
    # Allocate memory for h array
    h = [0] * n
    # Read h array elements from standard input
    for i in range(n):
        h[i] = int(input())
        # Comment for the loop that reads h array elements
        # from standard input
        # and stores them in the h array
    # Initialize counter map
    counter = {}
    # Read m query pairs from standard input
    for i in range(m):
        a, b = map(int, input().split())
        # Check the condition for a and b
        if h[a-1] < h[b-1]:
            # Add a to the counter map if h[a-1] is smaller than h[b-1]
            counter[a] = 1
        elif h[a-1] > h[b-1]:
            # Add b to the counter map if h[a-1] is greater than h[b-1]
            counter[b] = 1
        else:
            # Add both a and b to the counter map if h[a-1] is equal to h[b-1]
            counter[a] = 1
            counter[b] = 1
        # Comment for the loop that processes m query pairs
    # Print the result
    print(n - len(counter))
    # Comment for the final print statement



