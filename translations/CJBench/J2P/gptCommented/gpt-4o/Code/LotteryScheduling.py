import random

# Class representing a process with its attributes
class Process:
    def __init__(self, process_id, burst_time, tickets):
        self.process_id = process_id  # Unique identifier for the process
        self.burst_time = burst_time  # Time required for the process to complete
        self.tickets = tickets  # Number of tickets assigned to the process for scheduling
        self.waiting_time = 0  # Time the process has been waiting in the queue
        self.turn_around_time = 0  # Total time taken from arrival to completion

    # Getter methods for process attributes
    def get_process_id(self):
        return self.process_id

    def get_burst_time(self):
        return self.burst_time

    def get_tickets(self):
        return self.tickets

    def get_waiting_time(self):
        return self.waiting_time

    def set_waiting_time(self, waiting_time):
        self.waiting_time = waiting_time

    def get_turn_around_time(self):
        return self.turn_around_time

    def set_turn_around_time(self, turn_around_time):
        self.turn_around_time = turn_around_time


# Method to schedule processes based on a lottery system
def schedule_processes(processes):
    total_tickets = sum(process.get_tickets() for process in processes)  # Calculate total tickets
    current_time = 0  # Initialize current time
    executed_processes = []  # List to store executed processes

    # Continue scheduling until all processes are executed
    while processes:
        # Select a winning ticket randomly
        winning_ticket = random.randint(1, total_tickets)
        # Select the process corresponding to the winning ticket
        selected_process = select_process_by_ticket(processes, winning_ticket)
        # Set the waiting time for the selected process
        selected_process.set_waiting_time(current_time)
        # Update current time by adding the burst time of the selected process
        current_time += selected_process.get_burst_time()
        # Calculate turn around time for the selected process
        selected_process.set_turn_around_time(selected_process.get_waiting_time() + selected_process.get_burst_time())
        # Add the executed process to the list
        executed_processes.append(selected_process)
        # Remove the executed process from the original list
        processes.remove(selected_process)
        # Recalculate total tickets after removing the executed process
        total_tickets = sum(process.get_tickets() for process in processes)

    return executed_processes  # Return the list of executed processes


# Method to select a process based on the winning ticket
def select_process_by_ticket(processes, winning_ticket):
    ticket_sum = 0  # Initialize sum of tickets
    # Iterate through the processes to find the one corresponding to the winning ticket
    for process in processes:
        ticket_sum += process.get_tickets()  # Accumulate ticket sum
        if ticket_sum >= winning_ticket:  # Check if the winning ticket falls within the current sum
            return process  # Return the selected process
    return None  # Return None if no process is found (should not happen)


# Main method to execute the program
def main():
    n = int(input("Enter the number of processes: "))  # Read the number of processes
    processes = []  # List to store all processes

    # Loop to read process details from user input
    for _ in range(n):
        process_id = input("Enter process ID: ")  # Read process ID
        burst_time = int(input("Enter burst time: "))  # Read burst time
        tickets = int(input("Enter number of tickets: "))  # Read number of tickets
        # Create a new process and add it to the list
        processes.append(Process(process_id, burst_time, tickets))

    # Schedule the processes and get the executed order
    scheduled_processes = schedule_processes(processes)
    # Print the results: Process ID, Waiting Time, and Turn Around Time
    print("Process WaitingTime TurnAroundTime")
    for process in scheduled_processes:
        print(f"{process.get_process_id()} {process.get_waiting_time()} {process.get_turn_around_time()}")
        

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
