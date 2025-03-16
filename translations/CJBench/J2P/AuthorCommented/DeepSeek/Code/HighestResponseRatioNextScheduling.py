import heapq

class Process:
    def __init__(self, name, arrival_time, burst_time):
        self.name = name
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.turn_around_time = 0
        self.finished = False

    def calculate_response_ratio(self, current_time):
        return (current_time - self.arrival_time + self.burst_time) / self.burst_time

def calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes):
    current_time = 0
    turn_around_time = [0] * no_of_processes
    processes = [Process(process_names[i], arrival_times[i], burst_times[i]) for i in range(no_of_processes)]

    while any(not p.finished for p in processes):
        ready_processes = [p for p in processes if not p.finished and p.arrival_time <= current_time]
        if not ready_processes:
            current_time += 1
            continue

        max_response_ratio = -1
        next_process_index = -1
        for i, process in enumerate(ready_processes):
            response_ratio = process.calculate_response_ratio(current_time)
            if response_ratio > max_response_ratio:
                max_response_ratio = response_ratio
                next_process_index = i

        current_process = ready_processes[next_process_index]
        current_time = max(current_time, current_process.arrival_time)
        current_process.turn_around_time = current_time + current_process.burst_time - current_process.arrival_time
        current_time += current_process.burst_time
        current_process.finished = True

    for i in range(no_of_processes):
        turn_around_time[i] = processes[i].turn_around_time

    return turn_around_time

def calculate_waiting_time(turn_around_time, burst_times):
    return [turn_around_time[i] - burst_times[i] for i in range(len(turn_around_time))]

def find_next_process(processes, current_time):
    max_response_ratio = -1
    next_process_index = -1

    for i, process in enumerate(processes):
        if not process.finished and process.arrival_time <= current_time:
            response_ratio = process.calculate_response_ratio(current_time)
            if response_ratio > max_response_ratio:
                max_response_ratio = response_ratio
                next_process_index = i

    return next_process_index

def main():
    no_of_processes = int(input())
    process_names = []
    arrival_times = []
    burst_times = []

    for _ in range(no_of_processes):
        process_names.append(input().strip())
        arrival_times.append(int(input().strip()))
        burst_times.append(int(input().strip()))

    turn_around_times = calculate_turn_around_time(process_names, arrival_times, burst_times, no_of_processes)
    waiting_times = calculate_waiting_time(turn_around_times, burst_times)

    print("Process WaitingTime TurnAroundTime")
    for i in range(no_of_processes):
        print(f"{process_names[i]} {waiting_times[i]} {turn_around_times[i]}")

if __name__ == "__main__":
    main()
