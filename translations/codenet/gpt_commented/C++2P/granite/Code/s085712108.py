
# Lucky_Glass
import sys
from collections import deque

# Define a constant for the modulus value
MOD = 7007

# Define a function to check if a state has already been visited
def HASH(n):
    # Check if the state is already in the hash table
    if n in Hash:
        return False # State already visited
    # If not visited, add the state to the hash table
    Hash.add(n)
    return True # State is new

def main():
    # Initialize the total operations count
    Push.tot = 0

    # Create a queue to perform BFS
    que = deque()

    # Read the initial amounts in the glasses
    Push.a, Push.b, Push.c = map(int, input().split())
    # Push the initial state into the queue
    que.append(Push)

    # Perform BFS until the queue is empty
    while que:
        # Get the front state from the queue
        Fro = que.popleft()

        # Check if all glasses have the same amount
        if Fro.a == Fro.b and Fro.b == Fro.c:
            # If they are equal, print the number of operations and exit
            print(Fro.tot)
            sys.exit(0)

        # Iterate through all possible operations
        for i in range(6):
            # Copy the current state to a new state
            Push = Fro
            Push.tot += 1 # Increment the operation count

            # Apply the operation to the glasses
            Push.a += F[i][0] 
            Push.b += F[i][1] 
            Push.c += F[i][2]

            # Create a unique identifier for the new state
            n = Push.a * 10000 + Push.b * 100 + Push.c

            # Check if the new state has been visited
            if not HASH(n): continue # If visited, skip to the next operation

            # Push the new state into the queue for further exploration
            que.append(Push)

    return 0 # Exit the program

if __name__ == "__main__":
    main()

