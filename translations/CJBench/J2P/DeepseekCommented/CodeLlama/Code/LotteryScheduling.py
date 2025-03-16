
import random

class Process:
    def __init__(self, process_id, burst_time, tickets):
        self.process_id = process_id
        self.burst_time = burst_time
        self.tickets = tickets
        self.waiting_time = 0
        self.turn_around_time = 0

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

def schedule_processes(processes):
    total_tickets = sum(process.get_tickets() for process in processes)
    current_time = 0
    executed_processes = []

    # Continue scheduling processes until there are no processes left
    while len(processes) > 0:
        winning_ticket = random.randint(1, total_tickets)
        selected_process = select_process_by_ticket(processes, winning_ticket)
        selected_process.set_waiting_time(current_time)
        current_time += selected_process.get_burst_time()
        selected_process.set_turn_around_time(selected_process.get_waiting_time() + selected_process.get_burst_time())
        executed_processes.append(selected_process)
        processes.remove(selected_process)
        total_tickets = sum(process.get_tickets() for process in processes)
    return executed_processes

def select_process_by_ticket(processes, winning_ticket):
    ticket_sum = 0
    for process in processes:
        ticket_sum += process.get_tickets()
        if ticket_sum >= winning_ticket:
            return process
    return None

def main():
    n = int(input())
    processes = []

    # Read process details from the user
    for i in range(n):
        process_id, burst_time, tickets = input().split()
        processes.append(Process(process_id, int(burst_time), int(tickets)))

    # Schedule the processes and print their details
    scheduled_processes = schedule_processes(processes)
    print("Process WaitingTime TurnAroundTime")
    for process in scheduled_processes:
        print(process.get_process_id(), process.get_waiting_time(), process.get_turn_around_time())

if __name__ == "__main__":
    main()

