import sys

class Main:
    # Number of processes and machines
    def __init__(self, number_processes, number_machines, run, transfer):
        self.number_processes = number_processes
        self.number_machines = number_machines
        self.run = run
        self.transfer = transfer
        self.cost = [[0] * number_machines for _ in range(number_processes)]

    # Method to execute the cost calculation and display results
    def execute(self):
        self.calculate_cost()  # Calculate the costs for each process and machine
        self.show_results()    # Display the calculated costs

    # Method to calculate the total cost for each process on each machine
    def calculate_cost(self):
        # Iterate over each process
        for i in range(self.number_processes):
            # Iterate over each machine
            for j in range(self.number_machines):
                # Calculate the running cost for the current process and machine
                self.cost[i][j] = self.running_cost(i, j)

    # Method to calculate the running cost for a specific process on a specific machine
    def running_cost(self, process, machine):
        # If it's the first process, return the running cost directly
        if process == 0:
            return self.run[process][machine]
        else:
            # Array to hold the running costs for the previous process on all machines
            running_costs = [0] * self.number_machines
            # Calculate the cost for the current process on each machine
            for k in range(self.number_machines):
                running_costs[k] = self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine]
            # Return the minimum cost calculated
            return min(running_costs)

    # Method to display the calculated costs for each process and machine
    def show_results(self):
        # Iterate over each process
        for i in range(self.number_processes):
            # Iterate over each machine
            for j in range(self.number_machines):
                print(self.cost[i][j], end=" ")  # Print the cost
            print()  # Move to the next line after each process
        print()  # Print an extra line for better readability

    # Method to get the cost for a specific process and machine
    def get_cost(self, process, machine):
        return self.cost[process][machine]  # Return the cost from the cost matrix

# Main method to run the program
if __name__ == "__main__":
    # Read the number of processes and machines
    number_processes = int(sys.stdin.readline().strip())
    number_machines = int(sys.stdin.readline().strip())

    # Initialize the running cost matrix
    run = [[0] * number_machines for _ in range(number_processes)]
    # Read the running costs from input
    for i in range(number_processes):
        run[i] = list(map(int, sys.stdin.readline().strip().split()))

    # Initialize the transfer cost matrix
    transfer = [[0] * number_machines for _ in range(number_machines)]
    # Read the transfer costs from input
    for i in range(number_machines):
        transfer[i] = list(map(int, sys.stdin.readline().strip().split()))

    # Create an instance of Main with the input data
    scheduler = Main(number_processes, number_machines, run, transfer)
    scheduler.execute()  # Execute the cost calculation and display
