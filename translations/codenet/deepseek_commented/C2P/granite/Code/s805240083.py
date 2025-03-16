
# Python code to implement the process scheduling algorithm

# Define the maximum number of processes and the maximum length of the process name
MAX = 100005
N = 100

# Define a structure for processes
class Process:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Initialize the queue and pointers
Q = [None] * (MAX + 1)
head = 0
tail = 0

# Function to add a process to the queue
def Enqueue(x):
    global tail
    if tail == MAX:
        tail = 0
    Q[tail] = x
    tail += 1

# Function to remove and return the process at the front of the queue
def Dequeue():
    global head
    if head == MAX:
        head = 0
    x = Q[head]
    head += 1
    return x

# Main function to execute the process scheduling
def main():
    n, q = map(int, input().split()) # Read the number of processes and the quantum
    for i in range(n): # Loop to read each process
        name, t = input().split()
        Enqueue(Process(name, int(t))) # Enqueue the process
    T = 0 # Initialize the total time
    while n!= 0: # Loop to process each process
        a = Dequeue() # Dequeue a process
        if a.t > q: # If the process time is greater than the quantum
            a.t -= q # Reduce the process time by the quantum
            T += q # Increment the total time by the quantum
            Enqueue(a) # Enqueue the process again
        else: # If the process time is less than or equal to the quantum
            T += a.t # Increment the total time by the process time
            print(a.name, T) # Print the process name and total time
            n -= 1 # Decrement the number of processes
    return 0 # Return 0 to indicate successful execution

# Call the main function
if __name__ == "__main__":
    main()

# End of code

