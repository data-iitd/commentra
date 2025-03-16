
import sys

class Main:
    # Declare instance variables
    numberProcesses = 0
    numberMachines = 0
    run = []
    transfer = []
    cost = []

    # Constructor
    def __init__(self, numberProcesses, numberMachines, run, transfer):
        self.numberProcesses = numberProcesses
        self.numberMachines = numberMachines
        self.run = run
        self.transfer = transfer
        self.cost = [[0 for x in range(numberMachines)] for y in range(numberProcesses)]

    # Method to execute the scheduling algorithm
    def execute(self):
        self.calculateCost()
        self.showResults()

    # Method to calculate the cost of each process on each machine
    def calculateCost(self):
        for process in range(self.numberProcesses): # Iterate through all processes
            for machine in range(self.numberMachines): # Iterate through all machines
                self.cost[process][machine] = self.runningCost(process, machine)

    # Method to calculate the cost of a single process on a machine
    def runningCost(self, process, machine):
        if process == 0: # Base case: no previous process
            return self.run[process][machine]
        else: # Recursive case: there is a previous process
            runningCosts = [0 for x in range(self.numberMachines)] # Initialize an array to store the running costs of the next machine for each machine

            for nextMachine in range(self.numberMachines): # Iterate through all machines
                runningCosts[nextMachine] = self.cost[process - 1][nextMachine] + self.transfer[nextMachine][machine] + self.run[process][machine] # Calculate the running cost of the next machine

            return self.findMin(runningCosts) # Find the minimum running cost among all machines

    # Method to find the minimum value in an array
    def findMin(self, costArr):
        min = 0
        for i in range(1, len(costArr)):
            if costArr[i] < costArr[min]:
                min = i
        return costArr[min]

    # Method to show the results
    def showResults(self):
        for process in range(self.numberProcesses): # Iterate through all processes
            for machine in range(self.numberMachines): # Iterate through all machines
                print(self.cost[process][machine], end=" ") # Print the cost
            print() # Move to the next line after printing the costs of a process
        print() # Print an empty line after printing all costs

    # Method to get the cost of a specific process and machine
    def getCost(self, process, machine):
        return self.cost[process][machine]

if __name__ == "__main__":
    main = Main(0, 0, [], []) # Initialize a new instance of the Main class
    main.readInput() # Read input
    main.execute() # Execute the scheduling algorithm

