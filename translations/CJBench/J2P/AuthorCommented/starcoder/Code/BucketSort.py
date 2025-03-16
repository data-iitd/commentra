import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Main:
    # Constant that defines the divisor for determining the number of buckets
    BUCKET_DIVISOR = 10

    def sort(self, array):
        if len(array) == 0:
            return array

        min = self.findMin(array)
        max = self.findMax(array)
        numberOfBuckets = self.calculateNumberOfBuckets(len(array))

        buckets = self.initializeBuckets(numberOfBuckets)
        self.distributeElementsIntoBuckets(array, buckets, min, max, numberOfBuckets)

        return self.concatenateBuckets(buckets, array)

    # Calculates the number of buckets to use based on the size of the array.
    def calculateNumberOfBuckets(self, arrayLength):
        return max(arrayLength / self.BUCKET_DIVISOR, 1)

    # Initializes a list of empty buckets.
    def initializeBuckets(self, numberOfBuckets):
        buckets = []
        for i in range(numberOfBuckets):
            buckets.append(ArrayList())
        return buckets

    # Distributes elements from the array into the appropriate buckets.
    def distributeElementsIntoBuckets(self, array, buckets, min, max, numberOfBuckets):
        for element in array:
            bucketIndex = self.hash(element, min, max, numberOfBuckets)
            buckets[bucketIndex].add(element)

    # Concatenates the sorted buckets back into the original array.
    def concatenateBuckets(self, buckets, array):
        index = 0
        for bucket in buckets:
            Collections.sort(bucket)
            for element in bucket:
                array[index] = element
                index += 1
        return array

    # The method computes the index of the bucket in which a given element should be placed.
    # This is done by "normalizing" the element within the range of the array's minimum (min) and maximum (max) values,
    # and then mapping this normalized value to a specific bucket index.
    def hash(self, element, min, max, numberOfBuckets):
        range = max.compareTo(min)
        normalizedValue = element.compareTo(min) / range
        return int(normalizedValue * (numberOfBuckets - 1))

    def findMin(self, array):
        min = array[0]
        for element in array:
            if element.compareTo(min) < 0:
                min = element
        return min

    def findMax(self, array):
        max = array[0]
        for element in array:
            if element.compareTo(max) > 0:
                max = element
        return max

if __name__ == '__main__':
    scanner = Scanner(System.in)

    # Input array size
    n = scanner.nextInt()
    array = []

    # Input array elements
    for i in range(n):
        array.append(scanner.nextDouble())

    sorter = Main()
    sortedArray = sorter.sort(array)

    # Print sorted array
    for num in sortedArray:
        System.out.print(num + " ")
    scanner.close()

