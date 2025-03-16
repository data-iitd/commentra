
import sys

class Main:

    def __init__(self, numberProcesses, numberMachines, run, transfer):
        self.numberProcesses = numberProcesses
        self.numberMachines = numberMachines
        self.run = run
        self.transfer = transfer
        self.cost = [[0 for x in range(numberMachines)] for y in range(numberProcesses)]

    def execute(self):
        self.calculateCost()
        self.showResults()

    def calculateCost(self):

        for i in range(self.numberProcesses): # for each Process

            for j in range(self.numberMachines): # for each Machine

                self.cost[i][j] = self.runningCost(i, j)

    def runningCost(self, process, machine):

        if process == 0: # refers to the first process,which does not require for a previous one
            # to have been executed
            return self.run[process][machine]
        else:

            runningCosts = [0 for x in range(self.numberMachines)] # stores the costs of executing our Process depending on
            # the Machine the previous one was executed

            for k in range(self.numberMachines): # computes the cost of executing the previous
                # process to each and every Machine
                runningCosts[k] = self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine] # transferring the result to our Machine and executing
                # the Process to our Machine
            return self.findMin(runningCosts) # returns the minimum running cost

    def findMin(self, costArr):

        min = 0

        for i in range(1, self.numberMachines):

            if costArr[i] < costArr[min]:
                min = i
        return costArr[min]

    def showResults(self):

        for i in range(self.numberProcesses):

            for j in range(self.numberMachines):
                print(self.cost[i][j], end=" ")
            print()
        print()

if __name__ == "__main__":
    numberProcesses = int(sys.stdin.readline())

    numberMachines = int(sys.stdin.readline())

    run = [[0 for x in range(numberMachines)] for y in range(numberProcesses)]
    for i in range(numberProcesses):
        for j in range(numberMachines):
            run[i][j] = int(sys.stdin.readline())

    transfer = [[0 for x in range(numberMachines)] for y in range(numberMachines)]
    for i in range(numberMachines):
        for j in range(numberMachines):
            transfer[i][j] = int(sys.stdin.readline())

    scheduler = Main(numberProcesses, numberMachines, run, transfer)
    scheduler.execute()

