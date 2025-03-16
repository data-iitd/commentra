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

        # Base case: if there's only one point, return it as the skyline
        if size == 1:
            return list
        # Base case: if there are two points, determine which one dominates the other
        elif size == 2:
            if list[0].dominates(list[1]):
                list.remove(1) # Remove dominated point
            elif list[1].dominates(list[0]):
                list.remove(0) # Remove dominated point
            return list

        # Split the list into left and right halves
        leftHalf = list[:size // 2]
        rightHalf = list[size // 2:]

        # Recursively compute the skyline for both halves
        leftSkyline = self.produceSubSkyLines(leftHalf)
        rightSkyline = self.produceSubSkyLines(rightHalf)

        # Merge the two skylines into a final skyline
        return self.produceFinalSkyLine(leftSkyline, rightSkyline)

    def produceFinalSkyLine(self, left, right):
        finalSkyline = []
        i = 0
        j = 0

        # Merge points from left and right skylines based on x-coordinates
        while i < len(left) and j < len(right):
            if left[i].getX() < right[j].getX():
                finalSkyline.append(left[i]) # Add point from left if it has a smaller x
                i += 1
            elif left[i].getX() > right[j].getX():
                finalSkyline.append(right[j]) # Add point from right if it has a smaller x
                j += 1
            else: 
                # If x-coordinates are equal, add the point with the smaller y-coordinate
                finalSkyline.append(left[i].getY() < right[j].getY() and left[i] or right[j])
                i += 1
                j += 1

        # Add remaining points from the left skyline
        while i < len(left):
            finalSkyline.append(left[i])
            i += 1

        # Add remaining points from the right skyline
        while j < len(right):
            finalSkyline.append(right[j])
            j += 1

        return finalSkyline # Return the merged final skyline

if __name__ == "__main__":
    # Read the number of points from input
    n = int(input())
    points = []
    
    # Read each point's coordinates and add to the list
    for i in range(n):
        x = int(input())
        y = int(input())
        points.append(Point(x, y))

    # Sort points based on x-coordinate
    points.sort(key=lambda p: p.getX())

    # Create an instance of Main to compute the skyline
    skyline = Main()
    
    # Produce the final skyline from the list of points
    result = skyline.produceSubSkyLines(points)
    
    # Print the final skyline points
    print("Final Skyline:")
    for point in result:
        print(point)

# 