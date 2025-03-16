

import sys

class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def setMinNum(minNum):
    global minNum
    minNum = minNum

def setSecondCount(secondCount):
    global secondCount
    secondCount = secondCount

class Main:
    def __init__(self, points):
        self.numberPoints = points
        self.array = [Location(0, 0) for _ in range(self.numberPoints)]

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
        leftArray = divideArray[:divideX]
        rightArray = divideArray[divideX:]

        if indexNum <= 3:
            return self.bruteForce(divideArray)

        self.xQuickSort(leftArray, 0, divideX - 1)
        self.xQuickSort(rightArray, 0, indexNum - divideX - 1)

        minLeftArea = self.closestPair(leftArray, divideX)
        minRightArea = self.closestPair(rightArray, indexNum - divideX)

        minValue = min(minLeftArea, minRightArea)

        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x)
            if xGap < minValue:
                setSecondCount(secondCount + 1)

        firstWindow = [divideArray[i] for i in range(indexNum) if abs(divideArray[divideX].x - divideArray[i].x) < minValue]

        length = 0
        for i in range(secondCount - 1):
            for j in range(i + 1, secondCount):
                xGap = abs(firstWindow[i].x - firstWindow[j].x)
                yGap = abs(firstWindow[i].y - firstWindow[j].y)
                if yGap < minValue:
                    length = (xGap ** 2 + yGap ** 2) ** 0.5
                    if length < minValue:
                        setMinNum(length)
                        self.point1 = firstWindow[i]
                        self.point2 = firstWindow[j]

        setSecondCount(0)
        return minValue

    def bruteForce(self, arrayParam):
        minValue = float('inf')
        length = 0
        for i in range(len(arrayParam) - 1):
            for j in range(i + 1, len(arrayParam)):
                xGap = arrayParam[i].x - arrayParam[j].x
                yGap = arrayParam[i].y - arrayParam[j].y
                length = (xGap ** 2 + yGap ** 2) ** 0.5
                if length < minValue:
                    minValue = length
                    if length < minNum:
                        setMinNum(length)
                        self.point1 = arrayParam[i]
                        self.point2 = arrayParam[j]
        return minValue

if __name__ == "__main__":
    n = int(input())
    main = Main(n)
    for i in range(n):
        x, y = map(float, input().split())
        main.array[i] = main.buildLocation(x, y)

    main.xQuickSort(main.array, 0, n - 1)
    result = main.closestPair(main.array, n)

    print("({}, {})".format(main.point1.x, main.point1.y))
    print("({}, {})".format(main.point2.x, main.point2.y))
    print("Minimum Distance : {}".format(result))

