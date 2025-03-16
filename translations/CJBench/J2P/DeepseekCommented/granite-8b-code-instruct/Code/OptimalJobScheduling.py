
import sys

class Main:
    def __init__(self, number_processes, number_machines, run, transfer):
        self.number_processes = number_processes
        self.number_machines = number_machines
        self.run = run
        self.transfer = transfer
        self.cost = [[0 for _ in range(number_machines)] for _ in range(number_processes)]

    def execute(self):
        self.calculate_cost()
        self.show_results()

    def calculate_cost(self):
        for i in range(self.number_processes):
            for j in range(self.number_machines):
                self.cost[i][j] = self.running_cost(i, j)

    def running_cost(self, process, machine):
        if process == 0:
            return self.run[process][machine]
        else:
            running_costs = [self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine] for k in range(self.number_machines)]
            return min(running_costs)

    def show_results(self):
        for i in range(self.number_processes):
            for j in range(self.number_machines):
                print(self.cost[i][j], end=" ")
            print()
        print()

    def get_cost(self, process, machine):
        return self.cost[process][machine]

if __name__ == "__main__":
    number_processes = int(input())
    number_machines = int(input())
    run = [[int(x) for x in input().split()] for _ in range(number_processes)]
    transfer = [[int(x) for x in input().split()] for _ in range(number_machines)]
    scheduler = Main(number_processes, number_machines, run, transfer)
    scheduler.execute()

