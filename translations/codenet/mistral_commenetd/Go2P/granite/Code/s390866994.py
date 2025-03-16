

import sys
from bisect import bisect_left

def main():
    # Initialize input reader
    input = sys.stdin.readline

    # Read input: N, C, K
    N, C, K = map(int, input().split())

    # Initialize array t of size N
    t = [0] * N

    # Read input: t[i] for i from 0 to N-1
    for i in range(N):
        t[i] = int(input())

    # Sort array t in ascending order
    t.sort()

    # Initialize variables: answer counter ans, counter cnt, and end index end
    ans = 1
    cnt = 1
    end = t[0] + K

    # Iterate through array t from index 1 to N-1
    for i in range(1, N):
        # If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
        if cnt < C and t[i] <= end:
            cnt += 1
        else:
            # Reset counter cnt and update end index end to the current element t[i] plus K
            cnt = 1
            end = t[i] + K
            # Increment answer counter ans
            ans += 1

    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

