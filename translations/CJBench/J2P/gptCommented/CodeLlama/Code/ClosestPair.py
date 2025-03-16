
import math

# Inner class to represent a location with x and y coordinates
class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Class to find the closest pair of points using divide and conquer
class Main:
    # Number of points to be processed
    numberPoints = 0
    # Array to hold the locations of the points
    array = []
    # Variables to store the closest pair of points
    point1 = None
    point2 = None
    # Minimum distance initialized to maximum possible value
    minNum = float('inf')

    # Setter for minimum distance
    @staticmethod
    def setMinNum(minNum):
        Main.minNum = minNum

    # Setter for second count
    @staticmethod
    def setSecondCount(secondCount):
        Main.secondCount = secondCount

    # Counter for the number of points in the second window
    secondCount = 0

    # Constructor to initialize the number of points and the array
    def __init__(self, points):
        self.numberPoints = points
        self.array = [None] * self.numberPoints

    # Method to create a new Location object
    def buildLocation(self, x, y):
        return Location(x, y)

    # Partitioning method for quicksort based on x-coordinate
    def xPartition(self, a, first, last):
        pivot = a[last] # Choosing the last element as pivot
        i = first - 1 # Index of smaller element
        temp = None

        # Rearranging the array based on the pivot
        for j in range(first, last):
            if a[j].x <= pivot.x:
                i += 1
                # Swap elements
                temp = a[i]
                a[i] = a[j]
                a[j] = temp

        # Swap the pivot element to its correct position
        i += 1
        temp = a[i]
        a[i] = a[last]
        a[last] = temp
        return i # Return the partitioning index

    # Quicksort method for sorting the locations based on x-coordinate
    def xQuickSort(self, a, first, last):
        if first < last:
            q = self.xPartition(a, first, last) # Partition the array
            self.xQuickSort(a, first, q - 1) # Recursively sort the left subarray
            self.xQuickSort(a, q + 1, last) # Recursively sort the right subarray

    # Method to find the closest pair of points using divide and conquer
    def closestPair(self, a, indexNum):
        # Create a subarray to work with
        divideArray = a[:indexNum]
        divideX = indexNum // 2 # Find the midpoint
        leftArray = divideArray[:divideX]
        rightArray = divideArray[divideX:]

        # Base case for small arrays
        if indexNum <= 3:
            return self.bruteForce(divideArray) # Use brute force for small number of points

        # Split the array into left and right halves
        leftArray = divideArray[:divideX]
        rightArray = divideArray[divideX:]

        # Recursively find the minimum distances in both halves
        minLeftArea = self.closestPair(leftArray, divideX)
        minRightArea = self.closestPair(rightArray, indexNum - divideX)
        minValue = min(minLeftArea, minRightArea) # Minimum distance found so far

        # Check points in the strip around the dividing line
        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x)
            if xGap < minValue:
                Main.setSecondCount(Main.secondCount + 1) # Update second count

        # Create an array for points within the strip
        firstWindow = divideArray[:Main.secondCount]
        k = 0
        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x)
            if xGap < minValue:
                firstWindow[k] = divideArray[i] # Add point to the strip
                k += 1

        # Check for the closest pair within the strip
        length = 0
        for i in range(Main.secondCount - 1):
            for j in range(i + 1, Main.secondCount):
                xGap = abs(firstWindow[i].x - firstWindow[j].x)
                yGap = abs(firstWindow[i].y - firstWindow[j].y)
                if yGap < minValue:
                    length = math.sqrt(xGap * xGap + yGap * yGap) # Calculate distance
                    if length < minValue:
                        minValue = length # Update minimum distance
                        if length < Main.minNum:
                            Main.setMinNum(length) # Update global minimum distance
                            self.point1 = firstWindow[i] # Update closest points
                            self.point2 = firstWindow[j]

        Main.setSecondCount(0) # Reset second count for next call
        return minValue # Return the minimum distance found

    # Brute force method to find the closest pair of points for small arrays
    def bruteForce(self, arrayParam):
        minValue = float('inf') # Initialize minimum distance
        length = 0

        # Check all pairs of points
        for i in range(len(arrayParam) - 1):
            for j in range(i + 1, len(arrayParam)):
                xGap = arrayParam[i].x - arrayParam[j].x
                yGap = arrayParam[i].y - arrayParam[j].y
                length = math.sqrt(xGap * xGap + yGap * yGap) # Calculate distance
                if length < minValue:
                    minValue = length # Update minimum distance
                    if length < Main.minNum:
                        Main.setMinNum(length) # Update global minimum distance
                        self.point1 = arrayParam[i] # Update closest points
                        self.point2 = arrayParam[j]

        return minValue # Return the minimum distance found

    # Main method to execute the program
    def main(self):
        n = int(input()) # Read number of points
        cp = Main(n) # Create Main object with number of points

        # Read points from input
        for i in range(n):
            x = float(input())
            y = float(input())
            cp.array[i] = cp.buildLocation(x, y) # Build location objects

        # Sort the array of locations based on x-coordinate
        cp.xQuickSort(cp.array, 0, cp.array.length - 1)
        # Find the closest pair of points
        result = cp.closestPair(cp.array, cp.array.length)

        # Output the closest pair of points and the minimum distance
        print("(" + str(cp.point1.x) + ", " + str(cp.point1.y) + ")")
        print("(" + str(cp.point2.x) + ", " + str(cp.point2.y) + ")")
        print("Minimum Distance : " + str(result))

# Main method to execute the program
if __name__ == "__main__":
    Main().main()

