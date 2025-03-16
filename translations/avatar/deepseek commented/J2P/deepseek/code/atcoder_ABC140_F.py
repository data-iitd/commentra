import sys

def main():
    # Read the integer N from standard input
    N = int(input().strip())
    # Calculate the size of the array S, which is 2^N
    size = 1 << N
    # Initialize an array S to store integers
    S = list(map(int, input().strip().split()))
    # Initialize a boolean array to track spawned elements
    spawned = [False] * size
    # Set the last element of spawned to true, indicating it's initially active
    spawned[size - 1] = True

    # Sort the array S
    S.sort()
    # Initialize a list to keep track of active elements
    active = [S[size - 1]]
    # Add the largest element from S to the active list and mark it as spawned
    spawned[size - 1] = True

    # Iterate N times
    for _ in range(N):
        # Sort the active list in reverse order
        active.sort(reverse=True)
        # Initialize a list to find new activated elements
        activated = []
        next = size - 1

        # Find new activated elements
        for slime in active:
            while next >= 0 and (S[next] >= slime or spawned[next]):
                next -= 1
            if next < 0:
                print("No")
                return
            spawned[next] = True
            activated.append(S[next])

        # Add the activated elements to the active list
        active.extend(activated)

    print("Yes")

if __name__ == "__main__":
    main()
