# Include the standard input/output library for input/output functions

MAX = 100005  # Define the maximum number of processes
N = 100  # Define the maximum length of the process name

class Process:  # Define a class for processes
    def __init__(self, name, t):  # Constructor to initialize process name and time
        self.name = name  # Store the process name
        self.t = t  # Store the time required for the process

Q = []  # Declare a queue of processes
head = 0  # Initialize head pointer for the queue
tail = 0  # Initialize tail pointer for the queue

def enqueue(x):  # Function to add a process to the queue
    global tail
    if tail == MAX:  # Wrap around if tail reaches the maximum size
        tail = 0
    if len(Q) < MAX:  # Ensure we do not exceed the maximum size
        Q.append(x)  # Assign the process to the queue
        tail += 1  # Increment the tail pointer

def dequeue():  # Function to remove and return the process at the front of the queue
    global head
    if head == MAX:  # Wrap around if head reaches the maximum size
        head = 0
    process = Q[head]  # Get the process at the head
    head += 1  # Increment the head pointer
    return process  # Return the process

def main():  # Main function to execute the process scheduling
    global head, tail
    n, q = map(int, input().split())  # Read the number of processes and the quantum
    total_time = 0  # Initialize total time

    for _ in range(n):  # Loop to read each process
        name, t = input().split()  # Read the process name and time
        t = int(t)  # Convert time to integer
        enqueue(Process(name, t))  # Enqueue the process

    while n != 0:  # Loop to process each process
        a = dequeue()  # Dequeue a process
        if a.t > q:  # If the process time is greater than the quantum
            a.t -= q  # Reduce the process time by the quantum
            total_time += q  # Increment the total time by the quantum
            enqueue(a)  # Enqueue the process again
        else:  # If the process time is less than or equal to the quantum
            total_time += a.t  # Increment the total time by the process time
            print(f"{a.name} {total_time}")  # Print the process name and total time
            n -= 1  # Decrement the number of processes

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
