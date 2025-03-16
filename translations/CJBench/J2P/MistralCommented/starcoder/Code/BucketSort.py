
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Main:
    # Constants
    BUCKET_DIVISOR = 10

    # Method to sort an array of comparable elements
    def sort(self, array):
        if len(array) == 0: # Base case: empty array is already sorted
            return array

        min = self.findMin(array) # Find the minimum element in the array
        max = self.findMax(array) # Find the maximum element in the array
        numberOfBuckets = self.calculateNumberOfBuckets(len(array)) # Calculate the number of buckets needed

        # Initialize the buckets list with the specified number of empty lists
        buckets = self.initializeBuckets(numberOfBuckets)

        # Distribute the elements into the buckets based on their hash values
        self.distributeElementsIntoBuckets(array, buckets, min, max, numberOfBuckets)

        # Concatenate the sorted buckets back into a single sorted array
        return self.concatenateBuckets(buckets, array)

    # Helper method to calculate the number of buckets needed based on the array length
    def calculateNumberOfBuckets(self, arrayLength):
        return max(arrayLength / BUCKET_DIVISOR, 1)

    # Helper method to initialize the buckets list with the specified number of empty lists
    def initializeBuckets(self, numberOfBuckets):
        buckets = ArrayList(numberOfBuckets) # Create an ArrayList of the specified size

        # Initialize each empty list in the ArrayList
        for i in range(numberOfBuckets):
            buckets.add(ArrayList())

        return buckets

    # Helper method to distribute the elements into the buckets based on their hash values
    def distributeElementsIntoBuckets(self, array, buckets, min, max, numberOfBuckets):
        for element in array: # Iterate through each element in the array
            bucketIndex = self.hash(element, min, max, numberOfBuckets) # Calculate the hash value for the element
            buckets.get(bucketIndex).add(element) # Add the element to the corresponding bucket

    # Helper method to concatenate the sorted buckets back into a single sorted array
    def concatenateBuckets(self, buckets, array):
        index = 0 # Initialize an index to keep track of the array position

        # Iterate through each sorted bucket and add its elements to the array
        for bucket in buckets:
            Collections.sort(bucket) # Sort the elements in the bucket
            for element in bucket:
                array[index++] = element # Add the element to the array

        return array

    # Helper method to calculate the hash value for an element based on the minimum, maximum, and number of buckets
    def hash(self, element, min, max, numberOfBuckets):
        range = max.compareTo(min) # Calculate the range between the minimum and maximum elements
        normalizedValue = element.compareTo(min) / range # Calculate the normalized value of the element
        return int(normalizedValue * (numberOfBuckets - 1)) # Calculate the hash value as an index

    # Helper methods to find the minimum and maximum elements in the array
    def findMin(self, array):
        min = array[0] # Initialize the minimum element as the first element in the array
        for element in array: # Iterate through the remaining elements in the array
            if element.compareTo(min) < 0: # If the current element is less than the minimum, update the minimum
                min = element
        return min

    def findMax(self, array):
        max = array[0] # Initialize the maximum element as the first element in the array
        for element in array: # Iterate through the remaining elements in the array
            if element.compareTo(max) > 0: # If the current element is greater than the maximum, update the maximum
                max = element
        return max

    # Main method to read input and call the sorting method
    def main(self):
        scanner = Scanner(System.in) # Create a Scanner object to read input from the console
        n = scanner.nextInt() # Read the number of elements in the array from the console
        array = [0] * n # Create a Double array of the specified size

        # Read the elements of the array from the console and store them in the array
        for i in range(n):
            array[i] = scanner.nextDouble()

        sorter = Main() # Create an instance of the Main class
        sortedArray = sorter.sort(array) # Call the sorting method to sort the array

        # Print the sorted elements to the console
        for num in sortedArray:
            print(num, end=" ")

        scanner.close() # Close the Scanner object

# 