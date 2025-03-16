

import sys

def main():
    # Read the number of switches (N) and the number of lights (M)
    N, M = map(int, input().split())

    # Initialize a list of integers with N elements, all set to 0
    a = [0] * N

    # Read M groups of integers, where each group represents a switch and its corresponding states
    for _ in range(M):
        k = int(input())
        for s in map(int, input().split()):
            a[s - 1] |= 1 << _

    # Read the final state of each light
    p = sum(x << i for i, x in enumerate(map(int, input().split())))

    # Calculate the number of possible configurations of switch states that match the final state of the lights
    ans = 0
    for s in range(1 << N):
        t = 0
        for i in range(N):
            if (s >> i) & 1:
                t ^= a[i]
        if p == t:
            ans += 1

    # Print the result
    print(ans)

if __name__ == "__main__":
    main()

