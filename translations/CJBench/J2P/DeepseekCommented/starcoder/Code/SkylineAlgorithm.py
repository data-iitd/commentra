import sys

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def dominates(self, p1):
        return ((self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y))

    def __str__(self):
        return str(self.x) + " " + str(self.y)

class Main:
    def __init__(self):
        self.points = []

    def produceSubSkyLines(self, list):
        size = len(list)
        if size == 1:
            return list
        elif size == 2:
            if list[0].dominates(list[1]):
                list.remove(1)
            elif list[1].dominates(list[0]):
                list.remove(0)
            return list
        leftHalf = list[:size // 2]
        rightHalf = list[size // 2:]
        leftSkyline = self.produceSubSkyLines(leftHalf)
        rightSkyline = self.produceSubSkyLines(rightHalf)
        return self.produceFinalSkyLine(leftSkyline, rightSkyline)

    def produceFinalSkyLine(self, left, right):
        finalSkyline = []
        i = 0
        j = 0
        while i < len(left) and j < len(right):
            if left[i].getX() < right[j].getX():
                finalSkyline.append(left[i])
                i += 1
            elif left[i].getX() > right[j].getX():
                finalSkyline.append(right[j])
                j += 1
            else:
                finalSkyline.append(left[i].getY() < right[j].getY() and left[i] or right[j])
                i += 1
                j += 1
        while i < len(left):
            finalSkyline.append(left[i])
            i += 1
        while j < len(right):
            finalSkyline.append(right[j])
            j += 1
        return finalSkyline

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    points = []
    for i in range(n):
        x, y = map(int, sys.stdin.readline().split())
        points.append(Point(x, y))
    points.sort(key=lambda p: p.getX())
    skyline = Main()
    result = skyline.produceSubSkyLines(points)
    print("Final Skyline:")
    for point in result:
        print(point)

