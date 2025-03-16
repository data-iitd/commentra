from collections import deque

MOD = 7007

# Define a class to store the current state and the total number of steps taken
class QUEUE:
    def __init__(self, a, b, c, tot):
        self.a = a
        self.b = b
        self.c = c
        self.tot = tot

# Initialize an empty hash table to store visited states
Hash = [[] for _ in range(MOD)]

# Function to check if a state is already in the hash table
def HASH(n):
    for state in Hash[n % MOD]:
        if n == state:
            return False
    Hash[n % MOD].append(n)
    return True

# Define the possible moves
F = [
    (1, 0, 0), (0, 1, 0), (0, 0, 1),
    (-1, 0, 0), (0, -1, 0), (0, 0, -1)
]

def main():
    # Initialize some variables and read input data
    a, b, c = map(int, input().split())
    Push = QUEUE(a, b, c, 0)
    que = deque([Push])

    # Main loop to find the solution
    while que:
        Fro = que.popleft()  # Dequeue the front element from the queue

        # Check if the current state is the goal state
        if Fro.a == Fro.b == Fro.c:
            print(Fro.tot)  # Print the total number of steps taken and exit the program
            return

        # Try all six possible moves and check if the resulting state is already in the hash table
        for move in F:
            Push = QUEUE(Fro.a, Fro.b, Fro.c, Fro.tot + 1)  # Copy the current state into a new variable Push
            Push.a += move[0]
            Push.b += move[1]
            Push.c += move[2]
            n = Push.a * 10000 + Push.b * 100 + Push.c  # Calculate the hash code of the new state
            if not HASH(n):
                continue  # If the new state is already in the hash table, skip it
            que.append(Push)  # Otherwise, push it into the queue and continue the search

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
