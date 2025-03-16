
import sys
from collections import deque

def main():
    n, q = map(int, sys.stdin.readline().split()) # Read number of tasks and queries from standard input
    elaps = 0 # Elapsed time
    Q = deque() # Queue to store tasks

    # Read tasks details and add them to the queue
    for i in range(n):
        name, time = sys.stdin.readline().split() # Read task name and time from standard input
        Q.append((name, int(time))) # Add the task to the queue

    # Process tasks in the queue until it is empty
    while Q:
        name, time = Q.popleft() # Get the task at the front of the queue

        # Check if the current task can be completed within the given query time
        if time <= q:
            elaps += time # Add the time taken by the task to the elapsed time
            print(name, elaps) # Print the name and elapsed time of the task
        else: # If the current task cannot be completed within the given query time
            # Subtract the query time from the time taken by the task
            Q.append((name, time - q))

    # Return 0 to indicate successful execution of the program
    return 0

if __name__ == "__main__":
    sys.exit(main())

