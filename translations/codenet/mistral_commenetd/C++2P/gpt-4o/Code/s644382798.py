class Process:
    def __init__(self, name, time):
        self.name = name
        self.time = time

class Queue:
    def __init__(self, max_size):
        self.queue = []
        self.max_size = max_size

    def enqueue(self, process):
        if len(self.queue) < self.max_size:
            self.queue.append(process)

    def dequeue(self):
        if self.queue:
            return self.queue.pop(0)
        return None

def min(a, b):
    return a if a < b else b

def main():
    elaps = 0  # elapsed time
    n, q = map(int, input().split())  # read the number of processes and the number of queries
    queue = Queue(max_size=n)

    for _ in range(n):  # initialize the queue with process information
        name = input().strip()
        time = int(input().strip())
        process = Process(name, time)
        queue.enqueue(process)  # enqueue each process

    while queue.queue:  # processing loop
        u = queue.dequeue()  # dequeue a process
        c = min(q, u.time)  # calculate the number of units to be processed in this iteration
        u.time -= c  # update the remaining time for the process
        elaps += c  # update the elapsed time
        if u.time > 0:  # if the process still has remaining time, enqueue it again
            queue.enqueue(u)
        else:  # if the process has been fully processed, print the result
            print(f"{u.name} {elaps}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
