import random

class Process:
    def __init__(self, process_id, burst_time, tickets):
        self.process_id = process_id
        self.burst_time = burst_time
        self.tickets = tickets
        self.waiting_time = 0
        self.turn_around_time = 0

    # Getters for process properties
    def get_process_id(self):
        return self.process_id

    def get_burst_time(self):
        return self.burst_time

    def get_tickets(self):
        return self.tickets

    def get_waiting_time(self):
        return self.waiting_time

    # Setters for process properties
    def set_waiting_time(self, waiting_time):
        self.waiting_time = waiting_time

    def set_turn_around_time(self, turn_around_time):
        self.turn_around_time = turn_around_time


def schedule_processes(processes):
    total_tickets = sum(process.get_tickets() for process in processes)  # Calculate total tickets
    current_time = 0  # Initialize current time
    executed_processes = []  # List to store executed processes

    while processes:  # While there are still processes to execute
        winning_ticket = random.randint(1, total_tickets)  # Generate a random ticket
        selected_process = select_process_by_ticket(processes, winning_ticket)  # Select process by ticket

        # Update process properties
        selected_process.set_waiting_time(current_time)
        current_time += selected_process.get_burst_time()
        selected_process.set_turn_around_time(selected_process.get_waiting_time() + selected_process.get_burst_time())
        executed_processes.append(selected_process)  # Add executed process to the list
        processes.remove(selected_process)  # Remove executed process from the list

        total_tickets = sum(process.get_tickets() for process in processes)  # Update total tickets

    return executed_processes  # Return the list of executed processes


def select_process_by_ticket(processes, winning_ticket):
    ticket_sum = 0  # Initialize ticket sum

    for process in processes:  # Iterate through processes
        ticket_sum += process.get_tickets()  # Add tickets of current process

        if ticket_sum >= winning_ticket:  # If ticket sum is greater than or equal to winning ticket
            return process  # Return the selected process

    return None  # Return None if no process is found


def main():
    n = int(input("Enter the number of processes: "))  # Read number of processes
    processes = []  # List to store processes

    for _ in range(n):  # Read properties of each process
        process_id = input("Enter process ID: ")
        burst_time = int(input("Enter burst time: "))
        tickets = int(input("Enter number of tickets: "))
        processes.append(Process(process_id, burst_time, tickets))

    scheduled_processes = schedule_processes(processes)  # Call scheduling algorithm

    print("Process WaitingTime TurnAroundTime")  # Print header

    for process in scheduled_processes:  # Print properties of executed processes
        print(f"{process.get_process_id()} {process.get_waiting_time()} {process.turn_around_time}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
