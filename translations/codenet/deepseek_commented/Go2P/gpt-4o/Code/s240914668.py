import sys

def next_int():
    return int(next_token())

def next_ints(n):
    return [next_int() for _ in range(n)]

def next_token():
    return next(sys.stdin).strip()

def main():
    n = next_int()  # Read the number of elements n.
    a = next_ints(n)  # Read n integers into a list a.

    ans = 0  # Initialize ans to 0 to keep track of the number of segments.
    i = 0
    while i < n:
        l, r = i, i + 1  # Set l to i and r to i + 1.
        while r + 1 < n and (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0:
            r += 1  # Expand r as long as the condition holds.
        ans += 1  # Increment ans after finding the segment.
        i = r  # Update i to r.

    print(ans)  # Output the number of segments ans.

if __name__ == "__main__":
    main()

# <END-OF-CODE>
