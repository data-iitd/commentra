

import sys

class Main:
    def __init__(self):
        pass

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        pass

class BestFitCPU(Main):
    def findBestFit(self, blockSizes, processSize):
        minDiff = sys.maxsize
        index = -1
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] - processSize < minDiff:
                minDiff = blockSizes[i] - processSize
                index = i
        return index

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findBestFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= -1:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

class WorstFitCPU(Main):
    def findWorstFit(self, blockSizes, processSize):
        max = -1
        index = -1
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize and blockSizes[i] > max:
                max = blockSizes[i]
                index = i
        return index

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findWorstFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= -1:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

class FirstFitCPU(Main):
    def findFirstFit(self, blockSizes, processSize):
        for i in range(len(blockSizes)):
            if blockSizes[i] >= processSize:
                return i
        return -1

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findFirstFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= -1:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

class NextFit(Main):
    def __init__(self):
        self.counter = 0

    def findNextFit(self, blockSizes, processSize):
        for i in range(len(blockSizes)):
            idx = (self.counter + i) % len(blockSizes)
            if blockSizes[idx] >= processSize:
                self.counter = idx
                return idx
        return -1

    def fitProcess(self, sizeOfBlocks, sizeOfProcesses):
        memAlloc = []
        for processSize in sizeOfProcesses:
            chosenBlockIdx = self.findNextFit(sizeOfBlocks, processSize)
            memAlloc.append(chosenBlockIdx)
            if chosenBlockIdx!= -1:
                sizeOfBlocks[chosenBlockIdx] -= processSize
        return memAlloc

# 