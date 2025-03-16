
import random

# Class representing a process with its attributes
class Process:
    def __init__(self, process_id, burst_time, tickets):
        self.process_id = process_id
        self.burst_time = burst_time
        self.tickets = tickets
        self.waiting_time = 0
        self.turn_around_time = 0

# Method to schedule processes based on a lottery system
def schedule_processes(processes):
    total_tickets = sum(process.tickets for process in processes)
    current_time = 0
    executed_processes = []

    while processes:
        winning_ticket = random.randint(1, total_tickets)
        selected_process = select_process_by_ticket(processes, winning_ticket)
        selected_process.waiting_time = current_time
        current_time += selected_process.burst_time
        selected_process.turn_around_time = selected_process.waiting_time + selected_process.burst_time
        executed_processes.append(selected_process)
        processes.remove(selected_process)
        total_tickets = sum(process.tickets for process in processes)

    return executed_processes

# Method to select a process based on the winning ticket
def select_process_by_ticket(processes, winning_ticket):
    ticket_sum = 0
    for process in processes:
        ticket_sum += process.tickets
        if ticket_sum >= winning_ticket:
            return process
    return None

# Main method to execute the program
def main():
    n = int(input())
    processes = []

    for i in range(n):
        process_id, burst_time, tickets = input().split()
        processes.append(Process(process_id, int(burst_time), int(tickets)))

    scheduled_processes = schedule_processes(processes)
    print("Process WaitingTime TurnAroundTime")
    for process in scheduled_processes:
        print(f"{process.process_id} {process.waiting_time} {process.turn_around_time}")

if __name__ == "__main__":
    main()

