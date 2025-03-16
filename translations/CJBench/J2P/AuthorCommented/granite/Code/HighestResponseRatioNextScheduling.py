
import sys
import heapq

class Process:
    def __init__(self, name, arrival_time, burst_time):
        self.name = name
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.turn_around_time = 0
        self.waiting_time = 0
        self.finished = False

def calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes):
    current_time = 0
    turn_around_time = [0] * no_of_processes
    processes = [(arrival_time, i) for i, (arrival_time, burst_time) in enumerate(zip(arrival_times, burst_times))]
    heapq.heapify(processes)

    finished_process_count = 0
    while finished_process_count < no_of_processes:
        if not processes:
            current_time += 1
            continue

        arrival_time, process_index = heapq.heappop(processes)
        current_time = max(current_time, arrival_time)
        process = processes[process_index]
        process.turn_around_time = current_time + process.burst_time - process.arrival_time
        current_time += process.burst_time
        process.finished = True
        finished_process_count += 1

    for i, process in enumerate(processes):
        turn_around_time[i] = process.turn_around_time

    return turn_around_time

def calculate_waiting_time(turn_around_time, burst_times):
    waiting_time = [0] * len(turn_around_time)
    for i in range(len(turn_around_time)):
        waiting_time[i] = turn_around_time[i] - burst_times[i]
    return waiting_time

def find_next_process(processes, current_time):
    return find_highest_response_ratio(processes, current_time)

def find_highest_response_ratio(processes, current_time):
    max_response_ratio = -1.0
    max_index = -1

    for i, process in enumerate(processes):
        if not process.finished and process.arrival_time <= current_time:
            response_ratio = (process.burst_time + current_time - process.arrival_time) / process.burst_time
            if response_ratio > max_response_ratio:
                max_response_ratio = response_ratio
                max_index = i

    return max_index

if __name__ == "__main__":
    no_of_processes = int(input())
    process_names = [input() for _ in range(no_of_processes)]
    arrival_times = [int(input()) for _ in range(no_of_processes)]
    burst_times = [int(input()) for _ in range(no_of_processes)]

    turn_around_times = calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes)
    waiting_times = calculate_waiting_time(turn_around_times, burst_times)

    print("Process WaitingTime TurnAroundTime")
    for i in range(no_of_processes):
        print(f"{process_names[i]} {waiting_times[i]} {turn_around_times[i]}")

