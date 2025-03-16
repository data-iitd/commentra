import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
class Main:
    BUCKET_DIVISOR = 10 # Constant divisor for calculating the number of buckets.
    def sort(self, array):
        if len(array) == 0:
            return array # Return the array as is if it's empty.
        min = self.findMin(array) # Find the minimum element in the array.
        max = self.findMax(array) # Find the maximum element in the array.
        numberOfBuckets = self.calculateNumberOfBuckets(len(array)) # Calculate the number of buckets.
        buckets = self.initializeBuckets(numberOfBuckets) # Initialize the buckets.
        self.distributeElementsIntoBuckets(array, buckets, min, max, numberOfBuckets) # Distribute elements into buckets.
        return self.concatenateBuckets(buckets, array) # Concatenate sorted buckets back into the array.
    def calculateNumberOfBuckets(self, arrayLength):
        return max(arrayLength / self.BUCKET_DIVISOR, 1) # Calculate the number of buckets based on the array length.
    def initializeBuckets(self, numberOfBuckets):
        buckets = [[] for i in range(numberOfBuckets)] # Create a list of empty lists for buckets.
        return buckets
    def distributeElementsIntoBuckets(self, array, buckets, min, max, numberOfBuckets):
        for element in array:
            bucketIndex = self.hash(element, min, max, numberOfBuckets) # Determine the bucket index for the element.
            buckets[bucketIndex].append(element) # Add the element to the appropriate bucket.
    def concatenateBuckets(self, buckets, array):
        index = 0
        for bucket in buckets:
            bucket.sort() # Sort each bucket.
            for element in bucket:
                array[index++] = element # Add sorted elements back into the original array.
        return array
    def hash(self, element, min, max, numberOfBuckets):
        range = max.compareTo(min) # Calculate the range between max and min.
        normalizedValue = element.compareTo(min) / range # Normalize the element's value.
        return int(normalizedValue * (numberOfBuckets - 1)) # Calculate the bucket index.
    def findMin(self, array):
        min = array[0] # Initialize min with the first element.
        for element in array:
            if element.compareTo(min) < 0: # Update min if a smaller element is found.
                min = element
        return min
    def findMax(self, array):
        max = array[0] # Initialize max with the first element.
        for element in array:
            if element.compareTo(max) > 0: # Update max if a larger element is found.
                max = element
        return max
if __name__ == "__main__":
    scanner = Scanner(System.in)
    n = scanner.nextInt() # Read the number of elements.
    array = [0.0 for i in range(n)]
    for i in range(n):
        array[i] = scanner.nextDouble() # Read the elements of the array.
    sorter = Main()
    sortedArray = sorter.sort(array) # Sort the array.
    for num in sortedArray:
        print(num, end=" ") # Print the sorted array.
    scanner.close() # Close the scanner.
