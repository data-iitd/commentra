
import sys

class Main:
    def __init__(self, numberProcesses, numberMachines, run, transfer):
        self.numberProcesses = numberProcesses
        self.numberMachines = numberMachines
        self.run = run
        self.transfer = transfer
        self.cost = [[0 for i in range(numberMachines)] for j in range(numberProcesses)]

    def execute(self):
        self.calculateCost()
        self.showResults()

    def calculateCost(self):
        for i in range(self.numberProcesses):
            for j in range(self.numberMachines):
                self.cost[i][j] = self.runningCost(i, j)

    def runningCost(self, process, machine):
        if process == 0:
            return self.run[process][machine]
        else:
            runningCosts = [0 for i in range(self.numberMachines)]
            for k in range(self.numberMachines):
                runningCosts[k] = self.cost[process - 1][k] + self.transfer[k][machine] + self.run[process][machine]
            return self.findMin(runningCosts)

    def findMin(self, costArr):
        min = 0
        for i in range(1, len(costArr)):
            if costArr[i] < costArr[min]:
                min = i
        return costArr[min]

    def showResults(self):
        for i in range(self.numberProcesses):
            for j in range(self.numberMachines):
                print(self.cost[i][j], end=" ")
            print()
        print()

    def getCost(self, process, machine):
        return self.cost[process][machine]

if __name__ == "__main__":
    scanner = sys.stdin
    numberProcesses = int(scanner.readline().strip())
    numberMachines = int(scanner.readline().strip())
    run = [[0 for i in range(numberMachines)] for j in range(numberProcesses)]
    for i in range(numberProcesses):
        for j in range(numberMachines):
            run[i][j] = int(scanner.readline().strip())
    transfer = [[0 for i in range(numberMachines)] for j in range(numberMachines)]
    for i in range(numberMachines):
        for j in range(numberMachines):
            transfer[i][j] = int(scanner.readline().strip())
    scheduler = Main(numberProcesses, numberMachines, run, transfer)
    scheduler.execute()
    scanner.close()

