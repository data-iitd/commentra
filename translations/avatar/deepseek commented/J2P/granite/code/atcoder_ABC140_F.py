
import sys

def main():
    N = int(input()) # Read the integer N from standard input
    size = 1 << N # Calculate the size of the array S, which is 2^N
    S = [int(input()) for _ in range(size)] # Read integers into the array S
    S.sort(reverse=True) # Sort the array S in reverse order
    spawned = [False] * size # Initialize a boolean array to track spawned elements
    spawned[-1] = True # Set the last element of spawned to true, indicating it's initially active
    active = [S[-1]] # Initialize a list to keep track of active elements
    spawned[-1] = True # Mark the largest element from S as spawned

    # Iterate N times
    for _ in range(N):
        active.sort(reverse=True) # Sort the active list in reverse order
        activated = [] # Initialize a list to find new activated elements
        next = size - 1 # Initialize next to find new activated elements

        # Find new activated elements
        for slime in active:
            while next >= 0 and (S[next] >= slime or spawned[next]):
                next -= 1
            if next < 0:
                print("No") # If no new activated elements are found, print "No"
                return
            spawned[next] = True # Mark the found element as spawned
            activated.append(S[next]) # Add the found element to the activated list
        active.extend(activated) # Add the activated elements to the active list
    print("Yes") # If N iterations are successful, print "Yes"

if __name__ == "__main__":
    main()

