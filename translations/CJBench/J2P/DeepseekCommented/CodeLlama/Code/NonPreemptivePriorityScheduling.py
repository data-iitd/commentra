# Define the Process class
# This class represents a process with an ID, arrival time, burst time, priority, and start time.
# The compareTo method is overridden to sort processes based on priority and arrival time.
class Process:
    def __init__(self, id, arrivalTime, burstTime, priority):
        self.id = id
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.priority = priority
        self.startTime = -1
    def compareTo(self, other):
        if self.priority == other.priority:
            return self.arrivalTime - other.arrivalTime
        return self.priority - other.priority
# 