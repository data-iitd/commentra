class ProcessDetails:
    # Initialize instance variables and constructor
    def __init__(self, process_id, arrival_time, burst_time):
        self.process_id = process_id
        self.arrival_time = arrival_time
        self.burst_time = burst_time

    # Getter methods for the instance variables
    def get_process_id(self):
        return self.process_id

    def get_arrival_time(self):
        return self.arrival_time

    def get_burst_time(self):
        return self.burst_time


class Main:
    # Initialize instance variables
    def __init__(self, processes):
        self.processes = processes  # Assign input processes to the instance variable
        self.schedule = []  # Initialize an empty list to store the execution order
        self.sort_processes_by_arrival_time()  # Sort the processes based on their arrival time

    # Method to sort the processes based on their arrival time
    def sort_processes_by_arrival_time(self):
        self.processes.sort(key=lambda p: p.get_arrival_time())  # Sort using a lambda function

    # Method to schedule the processes based on Shortest Job First (SJF) algorithm
    def schedule_processes(self):
        ready = []  # Initialize an empty list to store the ready processes
        size = len(self.processes)  # Get the number of processes
        time = 0  # Initialize the current time to zero
        executed = 0  # Initialize the number of executed processes to zero
        k = 0  # Initialize an index variable to traverse the processes list

        if size == 0:  # Check if there are any processes to schedule
            return

        while executed < size:  # Iterate while all processes are not executed
            while k < size and self.processes[k].get_arrival_time() <= time:  # Check for ready processes
                ready.append(self.processes[k])  # Add the process to the ready list
                k += 1  # Increment the index
            running = self.find_shortest_job(ready)  # Find the process with the shortest burst time from the ready list
            if running is None:  # If the ready list is empty, increment the time and continue the loop
                time += 1
            else:  # Else, execute the shortest process and update the schedule and ready list
                time += running.get_burst_time()
                self.schedule.append(running.get_process_id())
                ready.remove(running)
                executed += 1

    # Method to find the process with the shortest burst time from the ready list
    def find_shortest_job(self, ready_processes):
        if not ready_processes:  # If the ready list is empty, return None
            return None
        return min(ready_processes, key=lambda p: p.get_burst_time())  # Find the process with the shortest burst time

    # Method to get the execution order of the processes
    def get_schedule(self):
        return self.schedule  # Return the execution order list


# Main method to read input and call the scheduling algorithm
if __name__ == "__main__":
    n = int(input())  # Read the number of processes
    processes = []  # Initialize an empty list to store the processes

    for _ in range(n):  # Iterate through each process and add it to the processes list
        process_id = input()
        arrival_time = int(input())
        burst_time = int(input())
        processes.append(ProcessDetails(process_id, arrival_time, burst_time))

    sjf_scheduling = Main(processes)  # Create an instance of the Main class
    sjf_scheduling.schedule_processes()  # Call the schedule_processes() method to schedule the processes

    print("Execution Order:")  # Print the execution order header
    for process_id in sjf_scheduling.get_schedule():  # Iterate through the execution order list and print each process ID
        print(process_id)

# <END-OF-CODE>
