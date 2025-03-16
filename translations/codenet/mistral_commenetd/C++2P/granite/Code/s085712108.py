
# Python code to solve the problem

# Define a function to check if a state is already in the hash table
def HASH(n):
    if n in Hash:
        return False
    Hash.add(n)
    return True

# Main loop to find the solution
def main():
    # Initialize some variables and read input data
    tot = 0
    que = []
    a, b, c = map(int, input().split())
    que.append((a, b, c, tot))

    # Main loop to find the solution
    while que:
        a, b, c, tot = que.pop(0)

        # Check if the current state is the goal state
        if a == b and b == c:
            print(tot) # Print the total number of steps taken and exit the program
            return

        # Try all six possible moves and check if the resulting state is already in the hash table
        for i in range(6):
            na, nb, nc = a + F[i][0], b + F[i][1], c + F[i][2]
            n = na * 10000 + nb * 100 + nc
            if not HASH(n): continue # If the new state is already in the hash table, skip it
            que.append((na, nb, nc, tot + 1)) # Otherwise, push it into the queue and continue the search

# Read input data and call the main function
Hash = set()
F = [[0, 1, 0], [1, -1, 0], [1, 0, -1], [1, 0, 1], [0, 1, 1], [-1, 1, 0]]
main()

