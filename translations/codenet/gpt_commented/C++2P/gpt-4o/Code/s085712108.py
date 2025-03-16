from collections import deque

# Define a constant for the modulus value
MOD = 7007

# Class to represent the state of the glass
class QUEUE:
    def __init__(self, a, b, c, tot):
        self.a = a
        self.b = b
        self.c = c
        self.tot = tot

# Array to define the possible operations on the glasses
F = [[1, 1, 0], [1, 0, 1], [0, 1, 1], [2, 0, 0], [0, 2, 0], [0, 0, 2]]

# Hash table to keep track of visited states
Hash = [[] for _ in range(MOD)]

# Function to check if a state has already been visited
def HASH(n):
    # Check if the state is already in the hash table
    for state in Hash[n % MOD]:
        if n == state:
            return False  # State already visited
    # If not visited, add the state to the hash table
    Hash[n % MOD].append(n)
    return True  # State is new

def main():
    # Read the initial amounts in the glasses
    a, b, c = map(int, input().split())
    
    # Initialize the total operations count
    Push = QUEUE(a, b, c, 0)

    # Create a queue to perform BFS
    que = deque()
    que.append(Push)

    # Perform BFS until the queue is empty
    while que:
        # Get the front state from the queue
        Fro = que.popleft()

        # Check if all glasses have the same amount
        if Fro.a == Fro.b and Fro.b == Fro.c:
            # If they are equal, print the number of operations and exit
            print(Fro.tot)
            return

        # Iterate through all possible operations
        for i in range(6):
            # Copy the current state to a new state
            Push = QUEUE(Fro.a, Fro.b, Fro.c, Fro.tot + 1)

            # Apply the operation to the glasses
            Push.a += F[i][0]
            Push.b += F[i][1]
            Push.c += F[i][2]

            # Create a unique identifier for the new state
            n = Push.a * 10000 + Push.b * 100 + Push.c

            # Check if the new state has been visited
            if not HASH(n):
                continue  # If visited, skip to the next operation

            # Push the new state into the queue for further exploration
            que.append(Push)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
