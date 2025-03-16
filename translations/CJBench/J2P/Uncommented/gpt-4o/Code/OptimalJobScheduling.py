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
        for i in range(self.number_processes):
            for j in range(self.number_machines):
                self.cost[i][j] = self.running_cost(i, j)

    def running_cost(self, process, machine):
        if process == 0:
            return self.run[process][machine]
        else:
            running_costs = [0] * self.number_machines
            for k in range(self.number_machines):
                running_costs[k] = self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine]
            return self.find_min(running_costs)

    def find_min(self, cost_arr):
        min_index = 0
        for i in range(1, len(cost_arr)):
            if cost_arr[i] < cost_arr[min_index]:
                min_index = i
        return cost_arr[min_index]

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
    run = [list(map(int, input().split())) for _ in range(number_processes)]
    transfer = [list(map(int, input().split())) for _ in range(number_machines)]
    
    scheduler = Main(number_processes, number_machines, run, transfer)
    scheduler.execute()

# <END-OF-CODE>
