
import random
import math

class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Main:
    # Number of points
    numberPoints = 0
    # Array to store locations
    array = []
    # To store the closest pair of points
    point1 = None
    point2 = None
    # To store the minimum distance found so far
    minNum = float('inf')
    # To keep track of the number of comparisons made
    secondCount = 0

    # Constructor to initialize the number of points and array
    def __init__(self, points):
        self.numberPoints = points
        self.array = [Location(0, 0) for _ in range(self.numberPoints)]

    # Method to build a new Location object
    def buildLocation(self, x, y):
        return Location(x, y)

    # Method to partition the array based on x-coordinates for QuickSort
    def xPartition(self, a, first, last):
        pivot = a[last]
        i = first - 1
        temp = None
        for j in range(first, last):
            if a[j].x <= pivot.x:
                i += 1
                temp = a[i]
                a[i] = a[j]
                a[j] = temp
        i += 1
        temp = a[i]
        a[i] = a[last]
        a[last] = temp
        return i

    # Method to implement QuickSort using xPartition
    def xQuickSort(self, a, first, last):
        if first < last:
            q = self.xPartition(a, first, last)
            self.xQuickSort(a, first, q - 1)
            self.xQuickSort(a, q + 1, last)

    # Method to find the closest pair of points recursively
    def closestPair(self, a, indexNum):
        divideArray = a[:indexNum]
        divideX = indexNum // 2
        leftArray = divideArray[:divideX]
        rightArray = divideArray[divideX:]
        if indexNum <= 3:
            return self.bruteForce(divideArray)
        self.closestPair(leftArray, divideX)
        self.closestPair(rightArray, indexNum - divideX)
        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x)
            if xGap < self.minNum:
                self.secondCount += 1
        firstWindow = [divideArray[i] for i in range(indexNum) if abs(divideArray[divideX].x - divideArray[i].x) < self.minNum]
        length = 0
        for i in range(self.secondCount - 1):
            for j in range(i + 1, self.secondCount):
                xGap = abs(firstWindow[i].x - firstWindow[j].x)
                yGap = abs(firstWindow[i].y - firstWindow[j].y)
                if yGap < self.minNum:
                    length = math.sqrt(xGap ** 2 + yGap ** 2)
                    if length < self.minNum:
                        self.minNum = length
                        if length < self.minNum:
                            self.point1 = firstWindow[i]
                            self.point2 = firstWindow[j]
        self.secondCount = 0  # Reset the counter for the next call
        return self.minNum

    # Method to find the closest pair of points using brute-force approach
    def bruteForce(self, arrayParam):
        minValue = float('inf')
        length = 0
        for i in range(len(arrayParam) - 1):
            for j in range(i + 1, len(arrayParam)):
                xGap = arrayParam[i].x - arrayParam[j].x
                yGap = arrayParam[i].y - arrayParam[j].y
                length = math.sqrt(xGap ** 2 + yGap ** 2)
                if length < minValue:
                    minValue = length
                    if length < self.minNum:
                        self.minNum = length
                        if length < self.minNum:
                            self.point1 = arrayParam[i]
                            self.point2 = arrayParam[j]
        return minValue

    # Main method to read input, sort points, find closest pair, and print results
    @staticmethod
    def main():
        n = int(input())
        cp = Main(n)
        for i in range(n):
            x, y = map(float, input().split())
            cp.array[i] = cp.buildLocation(x, y)
        cp.xQuickSort(cp.array, 0, cp.numberPoints - 1)
        result = cp.closestPair(cp.array, cp.numberPoints)
        print(f"({cp.point1.x}, {cp.point1.y})")
        print(f"({cp.point2.x}, {cp.point2.y})")
        print(f"Minimum Distance : {result}")

if __name__ == "__main__":
    Main.main()

