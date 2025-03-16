import sys

# Initialize input reader
input = sys.stdin.read
data = input().split()

def next_int():
    return int(data.pop(0))

def main():
    # Read the number of elements n and m from the standard input
    n = next_int()
    m = next_int()

    # Initialize h list with n elements and good list with n boolean values
    h = [0] * n
    good = [True] * n

    # Read n integers from the standard input and initialize h and good lists
    for i in range(n):
        h[i] = next_int()

    # Process m queries
    for _ in range(m):
        # Read two integers ai and bi from the standard input
        ai = next_int() - 1
        bi = next_int() - 1

        # Compare the heights of h[ai] and h[bi]
        if h[ai] > h[bi]:
            # If h[ai] is greater than h[bi], mark good[bi] as false
            good[bi] = False
        elif h[ai] < h[bi]:
            # If h[ai] is less than h[bi], mark good[ai] as false
            good[ai] = False
        else:
            # If heights are equal, mark both good[ai] and good[bi] as false
            good[ai] = False
            good[bi] = False

    # Initialize answer variable ans to 0
    ans = 0

    # Count the number of good elements in the h list
    for i in range(n):
        if good[i]:
            # Increment ans if good[i] is true
            ans += 1

    # Print the answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
