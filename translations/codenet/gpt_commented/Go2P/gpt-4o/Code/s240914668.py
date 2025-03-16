import sys

def next_int():
    return int(sys.stdin.readline().strip())

def next_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def main():
    # Read the number of integers
    n = next_int()
    # Read the integers into a list
    a = next_ints(n)

    # Initialize the answer counter
    ans = 0

    # Iterate through the list of integers
    i = 0
    while i < n:
        # Set the left and right pointers for the current segment
        l, r = i, i + 1

        # Expand the right pointer while the conditions are met
        while r + 1 < n and (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0:
            r += 1

        # Increment the answer for each segment found
        ans += 1
        # Move the left pointer to the end of the current segment
        i = r

    # Output the final count of segments
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
