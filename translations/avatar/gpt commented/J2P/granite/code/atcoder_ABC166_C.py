
import sys

def main():
    # Read the number of elements (N) and the number of comparisons (M)
    N, M = map(int, input().split())

    # Initialize an array to hold the heights and a boolean array to track valid heights
    H = list(map(int, input().split()))
    ans = [True] * N

    # Process M comparisons between pairs of heights
    for _ in range(M):
        temp1, temp2 = map(int, input().split())

        # Compare the heights and update the ans array based on the comparison results
        if H[temp1 - 1] < H[temp2 - 1]:
            ans[temp1 - 1] = False  # temp1 is shorter, mark it as invalid
        elif H[temp1 - 1] > H[temp2 - 1]:
            ans[temp2 - 1] = False  # temp2 is shorter, mark it as invalid
        else:
            # If heights are equal, mark both as invalid
            ans[temp1 - 1] = False
            ans[temp2 - 1] = False

    # Count the number of valid heights
    ans2 = sum(ans)

    # Output the count of valid heights
    print(ans2)

if __name__ == "__main__":
    main()

