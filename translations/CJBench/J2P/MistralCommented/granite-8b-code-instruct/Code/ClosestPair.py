

import math

# Final class to avoid extending
class Main:
    numberPoints = 0 # Number of points in the array
    array = [] # Array to store the points
    point1 = None # First point of the closest pair
    point2 = None # Second point of the closest pair

    # Private static variables to be accessed by the static methods
    minNum = float('inf')
    secondCount = 0

    # Constructor to initialize the number of points and the array size
    def __init__(self, points):
        self.numberPoints = points
        self.array = [None] * points

    # Inner class to store the x and y coordinates of a point
    class Location:
        def __init__(self, xpar, ypar):
            self.x = xpar
            self.y = ypar

    # Method to build a Location object with given x and y coordinates
    def buildLocation(self, x, y):
        return Main.Location(x, y)

    # Method to partition the array using the last element as pivot
    def xPartition(self, a, first, last):
        pivot = a[last] # Set pivot as the last element
        i = first - 1 # Index of the last element in the left subarray

        for j in range(first, last):
            # Swap elements if the current element's x-coordinate is smaller than the pivot's x-coordinate
            if a[j].x <= pivot.x:
                i += 1
                a[i], a[j] = a[j], a[i] # Swap the elements

        i += 1 # Increment i to point to the correct position for the pivot

        a[i], a[last] = a[last], a[i] # Swap the pivot and the element at index i
        return i # Return the index of the pivot's new position

    # Method to perform quicksort on the array using the x-coordinate as the partition key
    def xQuickSort(self, a, first, last):
        if first < last: # If the array has more than one element
            q = self.xPartition(a, first, last) # Partition the array
            self.xQuickSort(a, first, q - 1) # Recursively sort the left subarray
            self.xQuickSort(a, q + 1, last) # Recursively sort the right subarray

    # Method to find the closest pair using brute force when the array size is less than or equal to 3
    def bruteForce(self, arrayParam):
        minValue = float('inf') # Initialize minimum distance with a large value
        length = 0 # Distance between two points

        # Iterate through the array and find the minimum distance
        for i in range(self.numberPoints - 1):
            for j in range(i + 1, self.numberPoints):
                xGap = abs(arrayParam[i].x - arrayParam[j].x) # Difference between x-coordinates
                yGap = abs(arrayParam[i].y - arrayParam[j].y) # Difference between y-coordinates
                length = math.sqrt(xGap * xGap + yGap * yGap) # Calculate the distance

                if length < minValue: # Update minimum distance if a smaller distance is found
                    minValue = length
                    if length < self.minNum: # Update the closest pair if the new minimum distance is the smallest found
                        self.point1 = arrayParam[i]
                        self.point2 = arrayParam[j]

        return minValue # Return the minimum distance

    # Method to find the closest pair using the divide-and-conquer approach
    def closestPair(self, a, indexNum):
        if indexNum <= 3: # If the array size is less than or equal to 3, use brute force
            return self.bruteForce(a)

        # Divide the array into two halves
        divideArray = a[:indexNum] # Copy the array to a new array for division

        divideX = indexNum // 2 # Calculate the middle index
        leftArray = divideArray[:divideX] # Initialize left subarray
        rightArray = divideArray[divideX:] # Initialize right subarray

        # Recursively find the minimum distances in the left and right subarrays
        minLeftArea = self.closestPair(leftArray, divideX)
        minRightArea = self.closestPair(rightArray, indexNum - divideX)

        # Find the minimum distance between points in the first window (the points within the epsilon distance from the middle point)
        minValue = min(minLeftArea, minRightArea)
        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x) # Difference between x-coordinates
            if xGap < minValue: # Update minimum distance if a smaller distance is found
                self.secondCount += 1 # Increment the secondCount variable

        # Find the minimum distance between points in the first window
        firstWindow = [None] * self.secondCount # Initialize an array to store the points in the first window
        k = 0 # Initialize an index to store the points in the firstWindow array
        for i in range(indexNum):
            xGap = abs(divideArray[divideX].x - divideArray[i].x) # Difference between x-coordinates
            if xGap < minValue: # Update the firstWindow array with the points in the first window
                firstWindow[k] = divideArray[i]
                k += 1

        # Find the minimum distance between any two points in the first window
        for i in range(self.secondCount - 1):
            for j in range(i + 1, self.secondCount):
                xGap = abs(firstWindow[i].x - firstWindow[j].x) # Difference between x-coordinates
                yGap = abs(firstWindow[i].y - firstWindow[j].y) # Difference between y-coordinates
                length = math.sqrt(xGap * xGap + yGap * yGap) # Calculate the distance

                if length < minValue: # Update minimum distance if a smaller distance is found
                    minValue = length
                    if length < self.minNum: # Update the closest pair if the new minimum distance is the smallest found
                        self.point1 = firstWindow[i]
                        self.point2 = firstWindow[j]

        # Reset the secondCount variable
        self.secondCount = 0

        return minValue # Return the minimum distance

    # Main method to read input and call the closestPair method
    @staticmethod
    def main():
        n = int(input()) # Read the number of points from the input
        cp = Main(n) # Create a Main object with the given number of points

        # Read the points and store them in the array
        for i in range(n):
            x = float(input())
            y = float(input())
            cp.array[i] = cp.buildLocation(x, y) # Build a Location object for each point and store it in the array

        # Sort the points using quicksort
        cp.xQuickSort(cp.array, 0, cp.numberPoints - 1)

        # Find the closest pair and print the result
        result = cp.closestPair(cp.array, cp.numberPoints)
        print("({}, {})".format(cp.point1.x, cp.point1.y))
        print("({}, {})".format(cp.point2.x, cp.point2.y))
        print("Minimum Distance : {}".format(result))

# Call the main method
Main.main()

