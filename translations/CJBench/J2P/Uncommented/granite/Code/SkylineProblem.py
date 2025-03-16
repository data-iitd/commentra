
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
def mergeSkyline(sky1, sky2):
    mergedSkyline = []
    h1 = 0
    h2 = 0
    maxHeight = 0
    while len(sky1) > 0 and len(sky2) > 0:
        if sky1[0].x < sky2[0].x:
            x = sky1[0].x
            h1 = sky1[0].height
            sky1.pop(0)
            maxHeight = max(h1, h2)
            addSkylinePoint(mergedSkyline, x, maxHeight)
        else:
            x = sky2[0].x
            h2 = sky2[0].height
            sky2.pop(0)
            maxHeight = max(h1, h2)
            addSkylinePoint(mergedSkyline, x, maxHeight)
    while len(sky1) > 0:
        mergedSkyline.append(sky1.pop(0))
    while len(sky2) > 0:
        mergedSkyline.append(sky2.pop(0))
    return mergedSkyline
def addSkylinePoint(skyline, x, height):
    if len(skyline) == 0 or skyline[-1].height!= height:
        skyline.append(Skyline(x, height))
def findSkyline(start, end):
    if start == end:
        skyline = []
        skyline.append(Skyline(buildings[start].left, buildings[start].height))
        skyline.append(Skyline(buildings[start].right, 0))
        return skyline
    mid = (start + end) // 2
    leftSkyline = findSkyline(start, mid)
    rightSkyline = findSkyline(mid + 1, end)
    return mergeSkyline(leftSkyline, rightSkyline)
if __name__ == "__main__":
    numBuildings = int(input())
    buildings = []
    for i in range(numBuildings):
        left, height, right = map(int, input().split())
        buildings.append(Building(left, height, right))
    result = findSkyline(0, numBuildings - 1)
    for point in result:
        print(point)
