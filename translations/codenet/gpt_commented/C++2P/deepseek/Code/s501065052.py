def main():
    # Read the number of elements
    N = int(input())

    # Create a list to store the positions of elements
    mem = [0] * (N + 1)

    # Populate the 'mem' list with the positions of each element
    elements = list(map(int, input().split()))
    for i in range(1, N + 1):
        P = elements[i - 1]
        mem[P] = i

    # Initialize counters for the longest increasing subsequence
    maxcnt = 1
    cnt = 1

    # Iterate through the 'mem' list to find the longest increasing subsequence
    for i in range(1, N):
        # Check if the current position is less than the next position
        if mem[i] < mem[i + 1]:
            cnt += 1
        else:
            # Update the maximum count if the current count is greater
            maxcnt = max(maxcnt, cnt)
            cnt = 1
        # Check at the last element to update max count
        if i == N - 1:
            maxcnt = max(maxcnt, cnt)

    # Output the minimum number of elements to remove to get the longest increasing subsequence
    print(N - maxcnt)


if __name__ == "__main__":
    main()
