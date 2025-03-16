
import sys

# List to store points representing the skyline
points = []

# Class to represent a point in 2D space
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Method to check if this point dominates another point
    def dominates(self, p1):
        return ((self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y))

    # Override __str__ method for easy point representation
    def __str__(self):
        return str(self.x) + " " + str(self.y)

# Method to produce sub-skyline from a given list of points
def produceSubSkyLines(list):
    size = len(list)

    # Base case: if there's only one point, return it as the skyline
    if size == 1:
        return list

    # Base case: if there are two points, determine which one dominates the other
    if size == 2:
        if list[0].dominates(list[1]):
            list.remove(list[1]) # Remove dominated point
        elif list[1].dominates(list[0]):
            list.remove(list[0]) # Remove dominated point
        return list

    # Split the list into left and right halves
    leftHalf = list[:size // 2]
    rightHalf = list[size // 2:]

    # Recursively compute the skyline for both halves
    leftSkyline = produceSubSkyLines(leftHalf)
    rightSkyline = produceSubSkyLines(rightHalf)

    # Merge the two skylines into a final skyline
    return produceFinalSkyLine(leftSkyline, rightSkyline)

# Method to merge two skylines into a final skyline
def produceFinalSkyLine(left, right):
    finalSkyline = []
    i = 0
    j = 0

    # Merge points from left and right skylines based on x-coordinates
    while i < len(left) and j < len(right):
        if left[i].x < right[j].x:
            finalSkyline.append(left[i]) # Add point from left if it has a smaller x
            i += 1
        elif left[i].x > right[j].x:
            finalSkyline.append(right[j]) # Add point from right if it has a smaller x
            j += 1
        else: 
            # If x-coordinates are equal, add the point with the smaller y-coordinate
            finalSkyline.append(left[i] if left[i].y < right[j].y else right[j])
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

# Main method to execute the program
def main():
    # Read the number of points from input
    n = int(input())
    points = []

    # Read each point's coordinates and add to the list
    for i in range(n):
        x, y = map(int, input().split())
        points.append(Point(x, y))

    # Sort points based on x-coordinate
    points.sort(key=lambda p: p.x)

    # Create an instance of Main to compute the skyline
    skyline = Main()
    
    # Produce the final skyline from the list of points
    result = produceSubSkyLines(points)
    
    # Print the final skyline points
    print("Final Skyline:")
    for point in result:
        print(point)

if __name__ == "__main__":
    main()

