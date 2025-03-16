MOD = 7007

# Define a class QUEUE to store the current state and the total number of steps taken
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
    for i in range(len(Hash[n % MOD])):
        if n == Hash[n % MOD][i]:
            return False
    Hash[n % MOD].append(n)
    return True

# Main function to find the solution
def main():
    # Initialize some variables and read input data
    Push = QUEUE(0, 0, 0, 0)
    Push.a, Push.b, Push.c = map(int, input().split())
    que = [Push]

    # Main loop to find the solution
    while que:
        Fro = que[0]  # Dequeue the front element from the queue
        que.pop(0)

        # Check if the current state is the goal state
        if Fro.a == Fro.b == Fro.c:
            print(Fro.tot)  # Print the total number of steps taken and exit the program
            return

        # Try all six possible moves and check if the resulting state is already in the hash table
        for i in range(6):
            Push = QUEUE(Fro.a, Fro.b, Fro.c, Fro.tot + 1)  # Copy the current state into a new variable Push
            # Apply the move to the new state
            if i == 0: Push.a += 1
            elif i == 1: Push.a -= 1
            elif i == 2: Push.b += 1
            elif i == 3: Push.b -= 1
            elif i == 4: Push.c += 1
            elif i == 5: Push.c -= 1
            n = Push.a * 10000 + Push.b * 100 + Push.c  # Calculate the hash code of the new state
            if not HASH(n): continue  # If the new state is already in the hash table, skip it
            que.append(Push)  # Otherwise, push it into the queue and continue the search

    # Return 0 to indicate that the program has finished running
    return 0

# Call the main function
main()
