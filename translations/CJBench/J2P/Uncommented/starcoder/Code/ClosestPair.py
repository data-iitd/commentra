
import math
class Main:
    def __init__(self, n):
        self.n = n
        self.array = []
        self.point1 = None
        self.point2 = None
        self.minNum = float('inf')
        self.secondCount = 0

    def buildLocation(self, x, y):
        return Location(x, y)

    def xPartition(self, a, first, last):
        pivot = a[last]
        i = first - 1
        for j in range(first, last):
            if a[j].x <= pivot.x:
                i += 1
                a[i], a[j] = a[j], a[i]
        i += 1
        a[i], a[last] = a[last], a[i]
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
        minLeftArea = self.closestPair(leftArray, divideX)
        minRightArea = self.closestPair(rightArray, indexNum - divideX)
        minValue = min(minLeftArea, minRightArea)
        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x)
            if xGap < minValue:
                self.secondCount += 1
        firstWindow = self.array[:self.secondCount]
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

class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y

if __name__ == '__main__':
    n = int(input())
    cp = Main(n)
    for i in range(n):
        x, y = map(float, input().split())
        cp.array.append(cp.buildLocation(x, y))
    cp.xQuickSort(cp.array, 0, cp.array.length - 1)
    result = cp.closestPair(cp.array, cp.array.length)
    print('(', cp.point1.x, ',', cp.point1.y, ')')
    print('(', cp.point2.x, ',', cp.point2.y, ')')
    print('Minimum Distance :', result)

