class Process:
    def __init__(self, process_id, burst_time, deadline):
        self.process_id = process_id
        self.burst_time = burst_time
        self.deadline = deadline
        self.waiting_time = 0
        self.turn_around_time = 0

    def get_process_id(self):
        return self.process_id

    def get_burst_time(self):
        return self.burst_time

    def get_deadline(self):
        return self.deadline

    def get_waiting_time(self):
        return self.waiting_time

    def set_waiting_time(self, waiting_time):
        self.waiting_time = waiting_time

    def get_turn_around_time(self):
        return self.turn_around_time

    def set_turn_around_time(self, turn_around_time):
        self.turn_around_time = turn_around_time


def schedule_processes(processes):
    processes.sort(key=lambda process: process.get_deadline())
    current_time = 0
    executed_processes = []
    for process in processes:
        process.set_waiting_time(current_time)
        current_time += process.get_burst_time()
        process.set_turn_around_time(process.get_waiting_time() + process.get_burst_time())
        if current_time > process.get_deadline():
            print(f"Warning: Process {process.get_process_id()} missed its deadline.")
        executed_processes.append(process)
    return executed_processes


def main():
    num_processes = int(input())
    processes = []
    for _ in range(num_processes):
        process_id = input().split()[0]
        burst_time = int(input().split()[1])
        deadline = int(input().split()[2])
        processes.append(Process(process_id, burst_time, deadline))

    executed_processes = schedule_processes(processes)
    for process in executed_processes:
        print(f"{process.get_process_id()} {process.get_waiting_time()} {process.get_turn_around_time()}")


if __name__ == "__main__":
    main()
