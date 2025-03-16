
import sys
from typing import List
class Process:
    def __init__(self, process_id: str, burst_time: int, deadline: int):
        self.process_id = process_id
        self.burst_time = burst_time
        self.deadline = deadline
        self.waiting_time = 0
        self.turn_around_time = 0
    def get_process_id(self) -> str:
        return self.process_id
    def get_burst_time(self) -> int:
        return self.burst_time
    def get_deadline(self) -> int:
        return self.deadline
    def get_waiting_time(self) -> int:
        return self.waiting_time
    def set_waiting_time(self, waiting_time: int):
        self.waiting_time = waiting_time
    def get_turn_around_time(self) -> int:
        return self.turn_around_time
    def set_turn_around_time(self, turn_around_time: int):
        self.turn_around_time = turn_around_time
def schedule_processes(processes: List[Process]) -> List[Process]:
    processes.sort(key=lambda process: process.get_deadline())
    current_time = 0
    executed_processes = []
    for process in processes:
        process.set_waiting_time(current_time)
        current_time += process.get_burst_time()
        process.set_turn_around_time(process.get_waiting_time() + process.get_burst_time())
        if current_time > process.get_deadline():
            print("Warning: Process " + process.get_process_id() + " missed its deadline.")
        executed_processes.append(process)
    return executed_processes
if __name__ == "__main__":
    num_processes = int(input())
    processes = []
    for i in range(num_processes):
        process_id, burst_time, deadline = input().split()
        processes.append(Process(process_id, int(burst_time), int(deadline)))
    executed_processes = schedule_processes(processes)
    for process in executed_processes:
        print(
            process.get_process_id() + " " +
            str(process.get_waiting_time()) + " " +
            str(process.get_turn_around_time())
        )
