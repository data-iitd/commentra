class Process:
    def __init__(self, id, arrival_time, burst_time, priority):
        self.id = id
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.start_time = -1

    def __lt__(self, other):
        if self.priority == other.priority:
            return self.arrival_time < other.arrival_time
        return self.priority < other.priority

    def __repr__(self):
        return f"Process(id={self.id}, arrival_time={self.arrival_time}, burst_time={self.burst_time}, priority={self.priority}, start_time={self.start_time})"

