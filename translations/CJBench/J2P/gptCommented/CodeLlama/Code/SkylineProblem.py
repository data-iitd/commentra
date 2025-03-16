import sys

# Class representing a point in the skyline with x-coordinate and height
class Skyline:
    def __init__(self, x, height):
        self.x = x
        self.height = height

    # Override toString for easy printing of skyline points
    def __str__(self):
        return str(self.x) + " " + str(self.height)

# Class representing a building with left, height, and right coordinates
class Building:
    def __init__(self, left, height, right):
        self.left = left
        self.height = height
        self.right = right

# Class to store buildings and a counter for the number of buildings
class Main:
    # Constructor to initialize the buildings array and count
    def __init__(self, numBuildings):
        self.buildings = [None] * numBuildings
        self.count = 0

    # Method to add a new building with its left, height, and right coordinates
    def add(self, left, height, right):
        self.buildings[self.count] = Building(left, height, right)
        self.count += 1

    # Method to find the skyline between two indices using divide and conquer
    def findSkyline(self, start, end):
        # Base case: if there's only one building, return its skyline points
        if start == end:
            list = []
            list.append(Skyline(self.buildings[start].left, self.buildings[start].height))
            list.append(Skyline(self.buildings[start].right, 0))
            return list

        # Recursive case: split the buildings into two halves
        mid = (start + end) // 2
        leftSkyline = self.findSkyline(start, mid)
        rightSkyline = self.findSkyline(mid + 1, end)

        # Merge the two skylines and return the result
        return self.mergeSkyline(leftSkyline, rightSkyline)

    # Method to merge two skylines into one
    def mergeSkyline(self, sky1, sky2):
        mergedSkyline = []
        h1 = 0
        h2 = 0
        maxHeight = 0

        # Merge the two skylines by comparing their x-coordinates
        while len(sky1) > 0 and len(sky2) > 0:
            if sky1[0].x < sky2[0].x:
                x = sky1[0].x
                h1 = sky1[0].height
                sky1.pop(0)
                maxHeight = max(h1, h2)
                self.addSkylinePoint(mergedSkyline, x, maxHeight)
            else:
                x = sky2[0].x
                h2 = sky2[0].height
                sky2.pop(0)
                maxHeight = max(h1, h2)
                self.addSkylinePoint(mergedSkyline, x, maxHeight)

        # Add any remaining points from the first skyline
        while len(sky1) > 0:
            mergedSkyline.append(sky1.pop(0))

        # Add any remaining points from the second skyline
        while len(sky2) > 0:
            mergedSkyline.append(sky2.pop(0))

        return mergedSkyline

    # Helper method to add a skyline point if it is not a duplicate height
    def addSkylinePoint(self, skyline, x, height):
        if len(skyline) == 0 or skyline[-1].height != height:
            skyline.append(Skyline(x, height))

    # Main method to execute the skyline problem
    def main(self):
        # Read the number of buildings from input
        numBuildings = int(sys.stdin.readline())
        skylineProblem = Main(numBuildings)

        # Read each building's left, height, and right coordinates
        for i in range(numBuildings):
            left, height, right = map(int, sys.stdin.readline().split())
            skylineProblem.add(left, height, right)

        # Find the skyline and print the result
        result = skylineProblem.findSkyline(0, numBuildings - 1)
        for point in result:
            print(point)

# Main method to execute the skyline problem
if __name__ == "__main__":
    skylineProblem = Main(int(sys.stdin.readline()))
    skylineProblem.main()

# END-OF-CODE
