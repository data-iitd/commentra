import sys
input = sys.stdin.readline

def next_int():
    # Read an integer from the standard input and convert it to an integer
    return int(input().strip())

def main():
    # Read the number of elements n and m from the standard input
    n, m = map(int, input().split())

    # Initialize h array with n elements and good array with n boolean values
    h = [0] * n
    good = [True] * n

    # Read n integers from the standard input and initialize h and good arrays
    h = list(map(int, input().split()))

    # Process m queries
    for _ in range(m):
        # Read two integers ai and bi from the standard input
        ai, bi = map(int, input().split())
        ai -= 1
        bi -= 1

        # Compare the heights of h[ai] and h[bi]
        if h[ai] > h[bi]:
            # If h[ai] is greater than h[bi], mark good[bi] as False
            good[bi] = False
        elif h[ai] < h[bi]:
            # If h[ai] is less than h[bi], mark good[ai] as False
            good[ai] = False
        else:
            # If heights are equal, mark both good[ai] and good[bi] as False
            good[ai] = False
            good[bi] = False

    # Initialize answer variable ans to 0
    ans = 0

    # Count the number of good elements in the h array
    for i in range(n):
        if good[i]:
            # Increment ans if good[i] is True
            ans += 1

    # Print the answer
    print(ans)

main()
