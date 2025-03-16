import sys

def main():
    N = int(sys.stdin.readline().strip())  # Read the integer N from standard input
    size = 1 << N  # Calculate the size of the array S, which is 2^N
    S = list(map(int, sys.stdin.readline().strip().split()))  # Read integers into the array S
    S.sort()  # Sort the array S
    spawned = [False] * size  # Initialize a boolean array to track spawned elements
    spawned[size - 1] = True  # Set the last element of spawned to true, indicating it's initially active

    active = [S[size - 1]]  # Initialize a list to keep track of active elements
    spawned[size - 1] = True

    # Iterate N times
    for _ in range(N):
        active.sort(reverse=True)  # Sort the active list in reverse order
        activated = []  # Initialize a list to find new activated elements
        next_index = size - 1  # Initialize next to find new activated elements

        # Find new activated elements
        for slime in active:
            while next_index >= 0 and (S[next_index] >= slime or spawned[next_index]):
                next_index -= 1
            if next_index < 0:
                print("No")  # If no new activated elements are found, print "No"
                return
            spawned[next_index] = True  # Mark the found element as spawned
            activated.append(S[next_index])  # Add the found element to the activated list

        active.extend(activated)  # Add the activated elements to the active list

    print("Yes")  # If N iterations are successful, print "Yes"

if __name__ == "__main__":
    main()

# <END-OF-CODE>
