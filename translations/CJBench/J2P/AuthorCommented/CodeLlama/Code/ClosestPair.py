

import math


class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Main:
    def __init__(self, points):
        self.numberPoints = points
        self.array = [None] * self.numberPoints

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
        divideArray = [None] * indexNum
        for i in range(indexNum):
            divideArray[i] = a[i]
        divideX = indexNum // 2
        leftArray = [None] * divideX
        rightArray = [None] * (indexNum - divideX)

        if indexNum <= 3:
            return self.bruteForce(divideArray)

        for i in range(divideX):
            leftArray[i] = divideArray[i]
        for i in range(divideX, indexNum):
            rightArray[i - divideX] = divideArray[i]

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
                            self.minNum = length
                            self.point1 = firstWindow[i]
                            self.point2 = firstWindow[j]

        self.secondCount = 0
        return minValue

    def bruteForce(self, arrayParam):
        minValue = float('inf')
        for i in range(len(arrayParam) - 1):
            for j in range(i + 1, len(arrayParam)):
                xGap = arrayParam[i].x - arrayParam[j].x
                yGap = arrayParam[i].y - arrayParam[j].y
                length = math.sqrt(xGap * xGap + yGap * yGap)
                if length < minValue:
                    minValue = length
                    if length < self.minNum:
                        self.minNum = length
                        self.point1 = arrayParam[i]
                        self.point2 = arrayParam[j]
        return minValue

    def main(self):
        n = int(input())
        self.array = [None] * n
        for i in range(n):
            x = float(input())
            y = float(input())
            self.array[i] = self.buildLocation(x, y)

        self.xQuickSort(self.array, 0, len(self.array) - 1)
        result = self.closestPair(self.array, len(self.array))

        print("(" + str(self.point1.x) + ", " + str(self.point1.y) + ")")
        print("(" + str(self.point2.x) + ", " + str(self.point2.y) + ")")
        print("Minimum Distance : " + str(result))


if __name__ == '__main__':
    main = Main(10000)
    main.main()


