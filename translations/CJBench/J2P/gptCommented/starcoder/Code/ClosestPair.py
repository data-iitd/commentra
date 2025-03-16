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
        self.minNum = sys.float_info.max

    def setMinNum(self, minNum):
        self.minNum = minNum

    def setSecondCount(self, secondCount):
        self.secondCount = secondCount

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

        temp = a[i + 1]
        a[i + 1] = a[last]
        a[last] = temp
        return i + 1

    def xQuickSort(self, a, first, last):
        if first < last:
            q = self.xPartition(a, first, last)
            self.xQuickSort(a, first, q - 1)
            self.xQuickSort(a, q + 1, last)

    def closestPair(self, a, indexNum):
        divideArray = [None] * indexNum
        divideArray = a[0:indexNum]
        divideX = indexNum // 2
        leftArray = [None] * divideX
        rightArray = [None] * (indexNum - divideX)

        if indexNum <= 3:
            return self.bruteForce(divideArray)

        leftArray = divideArray[0:divideX]
        rightArray = divideArray[divideX:indexNum]

        minLeftArea = self.closestPair(leftArray, divideX)
        minRightArea = self.closestPair(rightArray, indexNum - divideX)
        minValue = min(minLeftArea, minRightArea)

        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x)
            if xGap < minValue:
                self.setSecondCount(self.secondCount + 1)

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

        self.setSecondCount(0)
        return minValue

    def bruteForce(self, arrayParam):
        minValue = sys.float_info.max
        length = 0

        for i in range(arrayParam.length - 1):
            for j in range(i + 1, arrayParam.length):
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

if __name__ == "__main__":
    n = int(input())
    cp = Main(n)

    for i in range(n):
        x = float(input())
        y = float(input())
        cp.array[i] = Location(x, y)

    cp.xQuickSort(cp.array, 0, cp.array.length - 1)
    result = cp.closestPair(cp.array, cp.array.length)

    print("(" + str(cp.point1.x) + ", " + str(cp.point1.y) + ")")
    print("(" + str(cp.point2.x) + ", " + str(cp.point2.y) + ")")
    print("Minimum Distance : " + str(result))

