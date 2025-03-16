
import sys

class Main:
    # Declare instance variables
    number_processes = 0
    number_machines = 0
    run = []
    transfer = []
    cost = []

    # Constructor
    def __init__(self, number_processes, number_machines, run, transfer):
        self.number_processes = number_processes
        self.number_machines = number_machines
        self.run = run
        self.transfer = transfer
        self.cost = [[0 for i in range(number_machines)] for j in range(number_processes)]

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
            running_costs = [0 for i in range(self.number_machines)] # Initialize an array to store the running costs of the next machine for each machine

            for next_machine in range(self.number_machines): # Iterate through all machines
                running_costs[next_machine] = self.cost[process - 1][next_machine] + self.transfer[next_machine][machine] + self.run[process][machine] # Calculate the running cost of the next machine

            return self.find_min(running_costs) # Find the minimum running cost among all machines

    # Method to find the minimum value in an array
    def find_min(self, cost_arr):
        min = 0
        for i in range(1, len(cost_arr)):
            if cost_arr[i] < cost_arr[min]:
                min = i
        return cost_arr[min]

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
    @staticmethod
    def main():
        scanner = sys.stdin # Initialize a Scanner to read input

        number_processes = int(scanner.readline().strip()) # Read the number of processes
        number_machines = int(scanner.readline().strip()) # Read the number of machines

        run = [[0 for i in range(number_machines)] for j in range(number_processes)] # Initialize a 2D array to store the run data
        for process in range(number_processes): # Iterate through all processes
            for machine in range(number_machines): # Iterate through all machines
                run[process][machine] = int(scanner.readline().strip()) # Read and store the run data

        transfer = [[0 for i in range(number_machines)] for j in range(number_machines)] # Initialize a 2D array to store the transfer data
        for machine1 in range(number_machines): # Iterate through all machines
            for machine2 in range(number_machines): # Iterate through all machines
                transfer[machine1][machine2] = int(scanner.readline().strip()) # Read and store the transfer data

        scheduler = Main(number_processes, number_machines, run, transfer) # Create a new instance of the Main class with the input data
        scheduler.execute() # Execute the scheduling algorithm

        scanner.close() # Close the Scanner

if __name__ == "__main__":
    Main.main()
    print("