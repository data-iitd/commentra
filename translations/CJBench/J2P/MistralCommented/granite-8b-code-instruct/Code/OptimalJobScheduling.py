

import sys

class Main:
    # Constructor
    def __init__(self, number_processes, number_machines, run, transfer):
        self.number_processes = number_processes
        self.number_machines = number_machines
        self.run = run
        self.transfer = transfer
        self.cost = [[0 for _ in range(number_machines)] for _ in range(number_processes)]

    # Method to execute the scheduling algorithm
    def execute(self):
        self.calculate_cost()
        self.show_results()

    # Method to calculate the cost of each process on each machine
    def calculate_cost(self):
        for process in range(self.number_processes): # Iterate through all processes
            for machine in range(self.number_machines): # Iterate through all machines
                self.cost[process][machine] = self.running_cost(process, machine)

    # Method to calculate the cost of a single process on a machine
    def running_cost(self, process, machine):
        if process == 0: # Base case: no previous process
            return self.run[process][machine]
        else: # Recursive case: there is a previous process
            running_costs = [self.cost[process - 1][next_machine] + self.transfer[next_machine][machine] + self.run[process][machine] for next_machine in range(self.number_machines)] # Calculate the running cost of the next machine for each machine
            return min(running_costs) # Find the minimum running cost among all machines

    # Method to show the results
    def show_results(self):
        for process in range(self.number_processes): # Iterate through all processes
            for machine in range(self.number_machines): # Iterate through all machines
                print(self.cost[process][machine], end=" ") # Print the cost
            print() # Move to the next line after printing the costs of a process
        print() # Print an empty line after printing all costs

    # Method to get the cost of a specific process and machine
    def get_cost(self, process, machine):
        return self.cost[process][machine]

# Main method to read input and start the scheduling algorithm
if __name__ == "__main__":
    number_processes = int(input()) # Read the number of processes
    number_machines = int(input()) # Read the number of machines

    run = [[int(x) for x in input().split()] for _ in range(number_processes)] # Read and store the run data
    transfer = [[int(x) for x in input().split()] for _ in range(number_machines)] # Read and store the transfer data

    scheduler = Main(number_processes, number_machines, run, transfer) # Create a new instance of the Main class with the input data
    scheduler.execute() # Execute the scheduling algorithm

