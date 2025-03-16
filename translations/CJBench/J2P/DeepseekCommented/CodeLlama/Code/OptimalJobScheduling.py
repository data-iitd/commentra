import sys

# Main method to read input and execute the scheduling algorithm
def main():
    numberProcesses = int(sys.stdin.readline()) # Read number of processes
    numberMachines = int(sys.stdin.readline()) # Read number of machines
    run = []
    for i in range(numberProcesses):
        run.append([int(x) for x in sys.stdin.readline().split()])
    transfer = []
    for i in range(numberMachines):
        transfer.append([int(x) for x in sys.stdin.readline().split()])
    scheduler = Main(numberProcesses, numberMachines, run, transfer)
    scheduler.execute() # Execute the scheduling algorithm

# Class to implement the scheduling algorithm
class Main:
    # Constructor to initialize the class variables
    def __init__(self, numberProcesses, numberMachines, run, transfer):
        self.numberProcesses = numberProcesses
        self.numberMachines = numberMachines
        self.run = run
        self.transfer = transfer
        self.cost = [[0 for i in range(numberMachines)] for j in range(numberProcesses)] # Initialize cost matrix

    # Method to calculate the cost for each process and machine
    def calculateCost(self):
        for i in range(self.numberProcesses):
            for j in range(self.numberMachines):
                self.cost[i][j] = self.runningCost(i, j) # Calculate cost for each process and machine

    # Method to calculate the running cost of a process on a machine
    def runningCost(self, process, machine):
        if process == 0:
            return self.run[process][machine] # Base case: cost is the running cost of the first process
        else:
            runningCosts = [0 for i in range(self.numberMachines)]
            for k in range(self.numberMachines):
                runningCosts[k] = self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine]
            return min(runningCosts) # Find the minimum cost among all machines

    # Method to display the calculated costs
    def showResults(self):
        for i in range(self.numberProcesses):
            for j in range(self.numberMachines):
                print(self.cost[i][j], end=" ") # Print the cost
            print() # New line after each process's costs
        print() # New line after all costs

    # Method to get the cost of a specific process on a specific machine
    def getCost(self, process, machine):
        return self.cost[process][machine]

    # Method to execute the scheduling algorithm
    def execute(self):
        self.calculateCost() # Calculate the cost for each process and machine
        self.showResults() # Display the calculated costs

# Main method to execute the scheduling algorithm
if __name__ == "__main__":
    main()

# END-OF-CODE
