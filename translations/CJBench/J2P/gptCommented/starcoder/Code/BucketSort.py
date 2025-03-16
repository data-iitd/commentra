import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Main:
    # Constant to determine the divisor for bucket calculation
    BUCKET_DIVISOR = 10

    # Main sorting method that sorts an array using bucket sort
    def sort(self, array):
        # Return the original array if it is empty
        if len(array) == 0:
            return array

        # Find the minimum and maximum elements in the array
        min = self.findMin(array)
        max = self.findMax(array)

        # Calculate the number of buckets needed for sorting
        numberOfBuckets = self.calculateNumberOfBuckets(len(array))

        # Initialize the buckets as a list of lists
        buckets = self.initializeBuckets(numberOfBuckets)

        # Distribute the elements of the array into the appropriate buckets
        self.distributeElementsIntoBuckets(array, buckets, min, max, numberOfBuckets)

        # Concatenate the sorted elements from the buckets back into the original array
        return self.concatenateBuckets(buckets, array)

    # Calculate the number of buckets based on the length of the array
    def calculateNumberOfBuckets(self, arrayLength):
        return max(arrayLength / self.BUCKET_DIVISOR, 1)

    # Initialize the buckets as empty lists
    def initializeBuckets(self, numberOfBuckets):
        buckets = []
        for i in range(numberOfBuckets):
            buckets.append([])
        return buckets

    # Distribute each element of the array into the corresponding bucket
    def distributeElementsIntoBuckets(self, array, buckets, min, max, numberOfBuckets):
        for element in array:
            # Determine the bucket index for the current element
            bucketIndex = self.hash(element, min, max, numberOfBuckets)
            # Add the element to the appropriate bucket
            buckets[bucketIndex].append(element)

    # Concatenate the sorted elements from all buckets back into the original array
    def concatenateBuckets(self, buckets, array):
        index = 0
        for bucket in buckets:
            # Sort each bucket before concatenation
            Collections.sort(bucket)
            for element in bucket:
                array[index] = element # Place the sorted elements back into the array
                index += 1
        return array

    # Calculate the bucket index for a given element
    def hash(self, element, min, max, numberOfBuckets):
        range = max.compareTo(min) # Calculate the range of values
        normalizedValue = element.compareTo(min) / range # Normalize the value to a range of 0 to 1
        return int(normalizedValue * (numberOfBuckets - 1)) # Scale to the number of buckets

    # Find the minimum element in the array
    def findMin(self, array):
        min = array[0] # Assume the first element is the minimum
        for element in array:
            if element.compareTo(min) < 0:
                min = element # Update min if a smaller element is found
        return min

    # Find the maximum element in the array
    def findMax(self, array):
        max = array[0] # Assume the first element is the maximum
        for element in array:
            if element.compareTo(max) > 0:
                max = element # Update max if a larger element is found
        return max

# Main method to execute the sorting process
if __name__ == "__main__":
    scanner = Scanner(System.in)
    n = scanner.nextInt() # Read the number of elements
    array = [] # Create an array to hold the elements
    for i in range(n):
        array.append(scanner.nextDouble()) # Read each element into the array
    sorter = Main() # Create an instance of the Main class
    sortedArray = sorter.sort(array) # Sort the array
    for num in sortedArray:
        print(num, end=" ") # Print the sorted array
    scanner.close() # Close the scanner to prevent resource leaks

