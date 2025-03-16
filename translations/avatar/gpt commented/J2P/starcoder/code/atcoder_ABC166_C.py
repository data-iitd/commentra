import sys

def main():
    # Read the number of elements (N) and the number of comparisons (M)
    N = int(input())
    M = int(input())

    # Initialize an array to hold the heights and a boolean array to track valid heights
    H = [0] * N
    ans = [True] * N

    # Read the heights and initialize the ans array to true
    for i in range(N):
        H[i] = int(input()) # Read the height for each element
        ans[i] = True # Assume all heights are valid initially

    # Process M comparisons between pairs of heights
    for i in range(M):
        temp1 = int(input()) # Read the first index for comparison
        temp2 = int(input()) # Read the second index for comparison

        # Compare the heights and update the ans array based on the comparison results
        if H[temp1 - 1] < H[temp2 - 1]:
            ans[temp1 - 1] = False # temp1 is shorter, mark it as invalid
        elif H[temp1 - 1] > H[temp2 - 1]:
            ans[temp2 - 1] = False # temp2 is shorter, mark it as invalid
        else:
            # If heights are equal, mark both as invalid
            ans[temp1 - 1] = False
            ans[temp2 - 1] = False

    # Count the number of valid heights
    ans2 = 0
    for i in range(N):
        if ans[i]:
            ans2 += 1 # Increment count for each valid height

    # Output the count of valid heights
    print(ans2)

if __name__ == "__main__":
    main()

