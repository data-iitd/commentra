
# Python code to translate the given C code

# Define a class to represent a process
class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Define a function to enqueue a process
def enqueue(Q, x):
    # Check if the queue is full
    if len(Q) == MAX:
        Q.clear()
    # Store the process in the queue
    Q.append(x)

# Define a function to dequeue a process
def dequeue(Q):
    # Check if the queue is empty
    if len(Q) == 0:
        return None
    # Store the process to be removed
    temp = Q[0]
    # Remove the process from the queue
    Q.pop(0)
    return temp

# Main function to simulate the processes
def main():
    n, q = map(int, input().split()) # Read the number of processes and the time limit from the input
    Q = [] # Initialize an empty queue
    T = 0 # Initialize the total time to 0

    for i in range(n): # Loop to read the details of each process and enqueue it
        name, t = input().split()
        enqueue(Q, Process(name, int(t)))

    while len(Q)!= 0: # While there are still processes in the queue
        a = dequeue(Q) # Dequeue the current process
        if a.t > q: # If the process takes more time than the limit
            a.t -= q # Subtract the excess time from the process time
            T += q # Add the time limit to the total time
            enqueue(Q, a) # Re-enqueue the process
        else: # If the process takes less time than the limit
            T += a.t # Add the process time to the total time
            print(a.name, T) # Print the name and total time taken for the process

    return 0 # Return 0 to indicate successful execution of the program

# Call the main function to start the simulation
if __name__ == "__main__":
    main()

