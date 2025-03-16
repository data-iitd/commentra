
import sys

class Main:
    # Number of processes and machines
    numberProcesses = 0
    numberMachines = 0
    
    # Arrays to hold running costs, transfer costs, and total costs
    run = []
    transfer = []
    cost = []

    # Constructor to initialize the number of processes, machines, and cost matrices
    def __init__(self, numberProcesses, numberMachines, run, transfer):
        self.numberProcesses = numberProcesses
        self.numberMachines = numberMachines
        self.run = run
        self.transfer = transfer
        self.cost = [[0 for _ in range(numberMachines)] for _ in range(numberProcesses)] # Initialize cost matrix

    # Method to execute the cost calculation and display results
    def execute(self):
        self.calculateCost() # Calculate the costs for each process and machine
        self.showResults()    # Display the calculated costs

    # Method to calculate the total cost for each process on each machine
    def calculateCost(self):
        # Iterate over each process
        for i in range(self.numberProcesses): 
            # Iterate over each machine
            for j in range(self.numberMachines): 
                # Calculate the running cost for the current process and machine
                self.cost[i][j] = self.runningCost(i, j)

    # Method to calculate the running cost for a specific process on a specific machine
    def runningCost(self, process, machine):
        # If it's the first process, return the running cost directly
        if process == 0: 
            return self.run[process][machine]
        else:
            # Array to hold the running costs for the previous process on all machines
            runningCosts = [0 for _ in range(self.numberMachines)] 
            # Calculate the cost for the current process on each machine
            for k in range(self.numberMachines): 
                runningCosts[k] = self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine] 
            # Return the minimum cost calculated
            return min(runningCosts) 

    # Method to display the calculated costs for each process and machine
    def showResults(self):
        # Iterate over each process
        for i in range(self.numberProcesses):
            # Iterate over each machine
            for j in range(self.numberMachines):
                print(self.cost[i][j], end=" ") # Print the cost
            print() # Move to the next line after each process
        print() # Print an extra line for better readability

    # Method to get the cost for a specific process and machine
    def getCost(self, process, machine):
        return self.cost[process][machine] # Return the cost from the cost matrix

# Main method to run the program
if __name__ == "__main__":
    # Read the number of processes and machines
    numberProcesses = int(input())
    numberMachines = int(input())
    
    # Initialize the running cost matrix
    run = []
    # Read the running costs from input
    for i in range(numberProcesses):
        run.append([int(x) for x in input().split()])
    run = [x for x in zip(*run)] # Transpose the running cost matrix
    
    # Initialize the transfer cost matrix
    transfer = []
    # Read the transfer costs from input
    for i in range(numberMachines):
        transfer.append([int(x) for x in input().split()])
    transfer = [x for x in zip(*transfer)] # Transpose the transfer cost matrix
    
    # Create an instance of Main with the input data
    scheduler = Main(numberProcesses, numberMachines, run, transfer)
    scheduler.execute() # Execute the cost calculation and display
    sys.stdout.flush() # Flush the output buffer

