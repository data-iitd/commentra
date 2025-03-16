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
        for i in range(self.number_processes):  # for each Process
            for j in range(self.number_machines):  # for each Machine
                self.cost[i][j] = self.running_cost(i, j)

    def running_cost(self, process, machine):
        if process == 0:  # refers to the first process, which does not require a previous one
            return self.run[process][machine]
        else:
            running_costs = [0] * self.number_machines  # stores the costs of executing our Process depending on the Machine the previous one was executed
            for k in range(self.number_machines):  # computes the cost of executing the previous process to each and every Machine
                running_costs[k] = self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine]  # transferring the result to our Machine and executing the Process to our Machine
            return self.find_min(running_costs)  # returns the minimum running cost

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
    import sys

    input_data = sys.stdin.read().splitlines()
    number_processes = int(input_data[0])
    number_machines = int(input_data[1])

    run = []
    for i in range(number_processes):
        run.append(list(map(int, input_data[2 + i].split())))

    transfer = []
    for i in range(number_machines):
        transfer.append(list(map(int, input_data[2 + number_processes + i].split())))

    scheduler = Main(number_processes, number_machines, run, transfer)
    scheduler.execute()

# <END-OF-CODE>
