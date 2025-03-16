
import math

class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def xPartition(a, first, last):
    pivot = a[last]
    i = first - 1
    temp = 0
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

def xQuickSort(a, first, last):
    if first < last:
        q = xPartition(a, first, last)
        xQuickSort(a, first, q - 1)
        xQuickSort(a, q + 1, last)

def closestPair(a, indexNum):
    if indexNum <= 3:
        return bruteForce(a)
    divideX = indexNum // 2
    divideArray = a[:divideX]
    leftArray = a[divideX:divideX + indexNum // 2]
    rightArray = a[divideX + indexNum // 2:]
    minLeftArea = closestPair(leftArray, divideX)
    minRightArea = closestPair(rightArray, indexNum - divideX)
    minValue = min(minLeftArea, minRightArea)
    for i in range(indexNum):
        xGap = abs(divideArray[divideX].x - a[i].x)
        if xGap < minValue:
            secondCount += 1
    firstWindow = [a[i] for i in range(indexNum) if abs(divideArray[divideX].x - a[i].x) < minValue]
    for i in range(secondCount - 1):
        for j in range(i + 1, secondCount):
            xGap = abs(firstWindow[i].x - firstWindow[j].x)
            yGap = abs(firstWindow[i].y - firstWindow[j].y)
            if yGap < minValue:
                length = math.sqrt(xGap * xGap + yGap * yGap)
                if length < minValue:
                    minValue = length
                    if length < minNum:
                        minNum = length
                        point1 = firstWindow[i]
                        point2 = firstWindow[j]
    secondCount = 0
    return minValue

def bruteForce(arrayParam):
    minValue = float('inf')
    for i in range(len(arrayParam) - 1):
        for j in range(i + 1, len(arrayParam)):
            xGap = arrayParam[i].x - arrayParam[j].x
            yGap = arrayParam[i].y - arrayParam[j].y
            length = math.sqrt(xGap * xGap + yGap * yGap)
            if length < minValue:
                minValue = length
                if length < minNum:
                    minNum = length
                    point1 = arrayParam[i]
                    point2 = arrayParam[j]
    return minValue

if __name__ == "__main__":
    n = int(input())
    array = []
    for _ in range(n):
        x, y = map(float, input().split())
        array.append(Location(x, y))
    xQuickSort(array, 0, n - 1)
    result = closestPair(array, n)
    print("({}, {})".format(point1.x, point1.y))
    print("({}, {})".format(point2.x, point2.y))
    print("Minimum Distance : {}".format(result))

