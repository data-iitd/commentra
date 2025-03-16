import math

class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Main:
    def __init__(self, points):
        self.numberPoints = points
        self.array = [None] * points
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
                        self.point1 = arrayParam[i]
                        self.point2 = arrayParam[j]

        return minValue

    def closestPair(self, a, indexNum):
        if indexNum <= 3:
            return self.bruteForce(a)

        divideX = indexNum // 2
        leftArray = a[:divideX]
        rightArray = a[divideX:]

        minLeftArea = self.closestPair(leftArray, divideX)
        minRightArea = self.closestPair(rightArray, indexNum - divideX)

        minValue = min(minLeftArea, minRightArea)
        self.secondCount = 0

        firstWindow = []
        for i in range(indexNum):
            xGap = abs(a[divideX].x - a[i].x)
            if xGap < minValue:
                firstWindow.append(a[i])

        for i in range(len(firstWindow) - 1):
            for j in range(i + 1, len(firstWindow)):
                xGap = abs(firstWindow[i].x - firstWindow[j].x)
                yGap = abs(firstWindow[i].y - firstWindow[j].y)
                length = math.sqrt(xGap * xGap + yGap * yGap)

                if length < minValue:
                    minValue = length
                    if length < self.minNum:
                        self.point1 = firstWindow[i]
                        self.point2 = firstWindow[j]

        self.secondCount = 0
        return minValue

    def main(self):
        import sys
        input = sys.stdin.read
        data = input().split()

        n = int(data[0])
        points = []

        for i in range(1, len(data), 2):
            x = float(data[i])
            y = float(data[i + 1])
            points.append(self.buildLocation(x, y))

        self.xQuickSort(points, 0, len(points) - 1)

        result = self.closestPair(points, n)
        print(f"({self.point1.x}, {self.point1.y})")
        print(f"({self.point2.x}, {self.point2.y})")
        print("Minimum Distance :", result)

Main().main()
