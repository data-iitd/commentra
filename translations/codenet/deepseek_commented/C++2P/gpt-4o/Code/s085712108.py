# Lucky_Glass
from collections import deque

MOD = 7007  # Define a constant MOD with the value 7007.

# Define a transformation matrix F with six possible transformations.
F = [[1, 1, 0], [1, 0, 1], [0, 1, 1], [2, 0, 0], [0, 2, 0], [0, 0, 2]]

# Define a hash table as a list of sets to store unique states.
Hash = [set() for _ in range(MOD)]

# Function to check if a state has been visited before.
def HASH(n):
    if n in Hash[n % MOD]:  # Check if the state is already present.
        return False  # Return false if the state is already visited.
    Hash[n % MOD].add(n)  # Add the state to the hash table.
    return True  # Return true if the state is new.

# Main function to execute the program.
def main():
    a, b, c = map(int, input().split())  # Read the initial values of a, b, and c.
    tot = 0  # Initialize the total number of operations to 0.
    que = deque()  # Create a queue of states.
    que.append((a, b, c, tot))  # Push the initial state into the queue.

    while que:  # Continue until the queue is empty.
        Fro = que.popleft()  # Retrieve and remove the front element of the queue.
        a, b, c, tot = Fro  # Unpack the current state.

        if a == b == c:  # Check if the current state is the goal state.
            print(tot)  # Print the total number of operations and exit.
            return

        for i in range(6):  # Apply each transformation to the current state.
            Push = (a + F[i][0], b + F[i][1], c + F[i][2], tot + 1)  # Apply the transformation.
            n = Push[0] * 10000 + Push[1] * 100 + Push[2]  # Create a unique identifier for the state.
            if not HASH(n):  # Check if the state has been visited before.
                continue
            que.append(Push)  # Push the new state into the queue.

if __name__ == "__main__":
    main()  # Execute the main function.

# <END-OF-CODE>
