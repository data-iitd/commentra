class Process:
    def __init__(self, name, arrival_time, burst_time):
        self.name = name
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.turn_around_time = 0
        self.finished = False

    def calculate_response_ratio(self, current_time):
        return (self.burst_time + current_time - self.arrival_time) / self.burst_time


def calculate_turn_around_time(process_names, arrival_times, burst_times):
    current_time = 0
    no_of_processes = len(process_names)
    turn_around_time = [0] * no_of_processes
    processes = [Process(process_names[i], arrival_times[i], burst_times[i]) for i in range(no_of_processes)]
    
    processes.sort(key=lambda p: p.arrival_time)
    finished_process_count = 0

    while finished_process_count < no_of_processes:
        next_process_index = find_next_process(processes, current_time)
        if next_process_index == -1:
            current_time += 1
            continue
        
        current_process = processes[next_process_index]
        current_time = max(current_time, current_process.arrival_time)
        current_process.turn_around_time = current_time + current_process.burst_time - current_process.arrival_time
        current_time += current_process.burst_time
        current_process.finished = True
        finished_process_count += 1

    for i in range(no_of_processes):
        turn_around_time[i] = processes[i].turn_around_time

    return turn_around_time


def calculate_waiting_time(turn_around_time, burst_times):
    return [turn_around_time[i] - burst_times[i] for i in range(len(turn_around_time))]


def find_next_process(processes, current_time):
    return find_highest_response_ratio(processes, current_time)


def find_highest_response_ratio(processes, current_time):
    max_response_ratio = -1.0
    max_index = -1
    for i, process in enumerate(processes):
        if not process.finished and process.arrival_time <= current_time:
            response_ratio = process.calculate_response_ratio(current_time)
            if response_ratio > max_response_ratio:
                max_response_ratio = response_ratio
                max_index = i
    return max_index


def main():
    no_of_processes = int(input())
    process_names = []
    arrival_times = []
    burst_times = []
    
    for _ in range(no_of_processes):
        process_names.append(input())
        arrival_times.append(int(input()))
        burst_times.append(int(input()))

    turn_around_times = calculate_turn_around_time(process_names, arrival_times, burst_times)
    waiting_times = calculate_waiting_time(turn_around_times, burst_times)

    print("Process WaitingTime TurnAroundTime")
    for i in range(no_of_processes):
        print(f"{process_names[i]} {waiting_times[i]} {turn_around_times[i]}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
