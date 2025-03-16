
import sys

class Building:
    def __init__(self, left, height, right):
        self.left = left
        self.height = height
        self.right = right

class Skyline:
    def __init__(self, x, height):
        self.x = x
        self.height = height

    def __str__(self):
        return str(self.x) + " " + str(self.height)

class Main:
    def __init__(self, numBuildings):
        self.buildings = [None] * numBuildings
        self.count = 0

    def add(self, left, height, right):
        self.buildings[self.count] = Building(left, height, right)
        self.count += 1

    def findSkyline(self, start, end):
        if start == end:
            list = []
            list.append(Skyline(self.buildings[start].left, self.buildings[start].height))
            list.append(Skyline(self.buildings[start].right, 0))
            return list

        mid = (start + end) // 2
        leftSkyline = self.findSkyline(start, mid)
        rightSkyline = self.findSkyline(mid + 1, end)
        return self.mergeSkyline(leftSkyline, rightSkyline)

    def mergeSkyline(self, sky1, sky2):
        mergedSkyline = []
        h1 = 0
        h2 = 0
        maxHeight = 0

        while len(sky1) > 0 and len(sky2) > 0:
            if sky1[0].x < sky2[0].x:
                x = sky1[0].x
                h1 = sky1[0].height
                sky1.remove(0)
                maxHeight = max(h1, h2)
                self.addSkylinePoint(mergedSkyline, x, maxHeight)
            else:
                x = sky2[0].x
                h2 = sky2[0].height
                sky2.remove(0)
                maxHeight = max(h1, h2)
                self.addSkylinePoint(mergedSkyline, x, maxHeight)

        while len(sky1) > 0:
            mergedSkyline.append(sky1.remove(0))
        while len(sky2) > 0:
            mergedSkyline.append(sky2.remove(0))

        return mergedSkyline

    def addSkylinePoint(self, skyline, x, height):
        if len(skyline) == 0 or skyline[len(skyline) - 1].height!= height:
            skyline.append(Skyline(x, height))

def main():
    numBuildings = int(input())
    skylineProblem = Main(numBuildings)

    for i in range(numBuildings):
        left = int(input())
        height = int(input())
        right = int(input())
        skylineProblem.add(left, height, right)

    result = skylineProblem.findSkyline(0, numBuildings - 1)
    for point in result:
        print(point)

if __name__ == "__main__":
    main()

