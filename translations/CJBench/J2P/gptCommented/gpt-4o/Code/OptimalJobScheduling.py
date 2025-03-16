class Main:
    def __init__(self, number_processes, number_machines, run, transfer):
        self.number_processes = number_processes
        self.number_machines = number_machines
        self.run = run
        self.transfer = transfer
        self.cost = [[0] * number_machines for _ in range(number_processes)]  # Initialize cost matrix

    def execute(self):
        self.calculate_cost()  # Calculate the costs for each process and machine
        self.show_results()     # Display the calculated costs

    def calculate_cost(self):
        for i in range(self.number_processes):  # Iterate over each process
            for j in range(self.number_machines):  # Iterate over each machine
                self.cost[i][j] = self.running_cost(i, j)  # Calculate the running cost

    def running_cost(self, process, machine):
        if process == 0:  # If it's the first process
            return self.run[process][machine]
        else:
            running_costs = [0] * self.number_machines  # Array to hold running costs for the previous process
            for k in range(self.number_machines):  # Calculate the cost for the current process on each machine
                running_costs[k] = self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine]
            return self.find_min(running_costs)  # Return the minimum cost calculated

    def find_min(self, cost_arr):
        min_index = 0  # Initialize minimum index
        for i in range(1, len(cost_arr)):
            if cost_arr[i] < cost_arr[min_index]:
                min_index = i  # Update minimum index if a lower cost is found
        return cost_arr[min_index]  # Return the minimum cost

    def show_results(self):
        for i in range(self.number_processes):  # Iterate over each process
            for j in range(self.number_machines):  # Iterate over each machine
                print(self.cost[i][j], end=" ")  # Print the cost
            print()  # Move to the next line after each process
        print()  # Print an extra line for better readability

    def get_cost(self, process, machine):
        return self.cost[process][machine]  # Return the cost from the cost matrix

if __name__ == "__main__":
    number_processes, number_machines = map(int, input().split())  # Read the number of processes and machines
    
    run = [list(map(int, input().split())) for _ in range(number_processes)]  # Read the running costs
    transfer = [list(map(int, input().split())) for _ in range(number_machines)]  # Read the transfer costs
    
    scheduler = Main(number_processes, number_machines, run, transfer)  # Create an instance of Main
    scheduler.execute()  # Execute the cost calculation and display
