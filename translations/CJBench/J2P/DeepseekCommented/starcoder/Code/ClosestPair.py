import sys
import math

class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Main:
    def __init__(self, n):
        self.numberPoints = n
        self.array = [None] * n
        self.point1 = None
        self.point2 = None
        self.minNum = sys.maxsize
        self.secondCount = 0

    def buildLocation(self, x, y):
        return Location(x, y)

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

    def xQuickSort(self, a, first, last):
        if first < last:
            q = self.xPartition(a, first, last)
            self.xQuickSort(a, first, q - 1)
            self.xQuickSort(a, q + 1, last)

    def closestPair(self, a, indexNum):
        divideArray = a[:indexNum]
        divideX = indexNum // 2
        leftArray = a[:divideX]
        rightArray = a[divideX:]
        if indexNum <= 3:
            return self.bruteForce(divideArray)
        minLeftArea = self.closestPair(leftArray, divideX)
        minRightArea = self.closestPair(rightArray, indexNum - divideX)
        minValue = min(minLeftArea, minRightArea)
        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x)
            if xGap < minValue:
                self.secondCount += 1
        firstWindow = [None] * self.secondCount
        k = 0
        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x)
            if xGap < minValue:
                firstWindow[k] = divideArray[i]
                k += 1
        for i in range(self.secondCount - 1):
            for j in range(i + 1, self.secondCount):
                xGap = abs(firstWindow[i].x - firstWindow[j].x)
                yGap = abs(firstWindow[i].y - firstWindow[j].y)
                if yGap < minValue:
                    length = math.sqrt(xGap * xGap + yGap * yGap)
                    if length < minValue:
                        minValue = length
                        if length < self.minNum:
                            self.setMinNum(length)
                            self.point1 = firstWindow[i]
                            self.point2 = firstWindow[j]
        self.secondCount = 0
        return minValue

    def bruteForce(self, arrayParam):
        minValue = sys.maxsize
        length = 0
        for i in range(len(arrayParam) - 1):
            for j in range(i + 1, len(arrayParam)):
                xGap = arrayParam[i].x - arrayParam[j].x
                yGap = arrayParam[i].y - arrayParam[j].y
                length = math.sqrt(xGap * xGap + yGap * yGap)
                if length < minValue:
                    minValue = length
                    if length < self.minNum:
                        self.setMinNum(length)
                        self.point1 = arrayParam[i]
                        self.point2 = arrayParam[j]
        return minValue

    def main(self):
        scanner = sys.stdin
        n = int(scanner.readline())
        cp = Main(n)
        for i in range(n):
            x = float(scanner.readline())
            y = float(scanner.readline())
            cp.array[i] = cp.buildLocation(x, y)
        cp.xQuickSort(cp.array, 0, cp.array.length - 1)
        result = cp.closestPair(cp.array, cp.array.length)
        print("(" + str(cp.point1.x) + ", " + str(cp.point1.y) + ")")
        print("(" + str(cp.point2.x) + ", " + str(cp.point2.y) + ")")
        print("Minimum Distance : " + str(result))
        scanner.close()

# 