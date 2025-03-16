class Main:
    def __init__(self, number_processes, number_machines, run, transfer):
        self.number_processes = number_processes
        self.number_machines = number_machines
        self.run = run
        self.transfer = transfer
        self.cost = [[0] * number_machines for _ in range(number_processes)]

    def execute(self):
        self.calculate_cost()
        self.show_results()

    def calculate_cost(self):
        for process in range(self.number_processes):
            for machine in range(self.number_machines):
                self.cost[process][machine] = self.running_cost(process, machine)

    def running_cost(self, process, machine):
        if process == 0:
            return self.run[process][machine]
        else:
            running_costs = [0] * self.number_machines
            for next_machine in range(self.number_machines):
                running_costs[next_machine] = (self.cost[process - 1][next_machine] +
                                                self.transfer[next_machine][machine] +
                                                self.run[process][machine])
            return self.find_min(running_costs)

    def find_min(self, cost_arr):
        min_index = 0
        for i in range(1, len(cost_arr)):
            if cost_arr[i] < cost_arr[min_index]:
                min_index = i
        return cost_arr[min_index]

    def show_results(self):
        for process in range(self.number_processes):
            for machine in range(self.number_machines):
                print(self.cost[process][machine], end=" ")
            print()
        print()

    def get_cost(self, process, machine):
        return self.cost[process][machine]

if __name__ == "__main__":
    import sys

    input_data = sys.stdin.read().splitlines()
    number_processes = int(input_data[0])
    number_machines = int(input_data[1])

    run = []
    for i in range(2, 2 + number_processes):
        run.append(list(map(int, input_data[i].split())))

    transfer = []
    for i in range(2 + number_processes, 2 + number_processes + number_machines):
        transfer.append(list(map(int, input_data[i].split())))

    scheduler = Main(number_processes, number_machines, run, transfer)
    scheduler.execute()

# <END-OF-CODE>
