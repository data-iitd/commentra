
import math

class Main:
    # Constants
    BUCKET_DIVISOR = 10

    # Method to sort an array of comparable elements
    def sort(self, array):
        if len(array) == 0: # Base case: empty array is already sorted
            return array

        min = self.find_min(array) # Find the minimum element in the array
        max = self.find_max(array) # Find the maximum element in the array
        number_of_buckets = self.calculate_number_of_buckets(len(array)) # Calculate the number of buckets needed

        # Initialize the buckets list with the specified number of empty lists
        buckets = self.initialize_buckets(number_of_buckets)

        # Distribute the elements into the buckets based on their hash values
        self.distribute_elements_into_buckets(array, buckets, min, max, number_of_buckets)

        # Concatenate the sorted buckets back into a single sorted array
        return self.concatenate_buckets(buckets, array)

    # Helper method to calculate the number of buckets needed based on the array length
    def calculate_number_of_buckets(self, array_length):
        return max(array_length // self.BUCKET_DIVISOR, 1)

    # Helper method to initialize the buckets list with the specified number of empty lists
    def initialize_buckets(self, number_of_buckets):
        buckets = [] # Create an empty list

        # Initialize each empty list in the list
        for i in range(number_of_buckets):
            buckets.append([])

        return buckets

    # Helper method to distribute the elements into the buckets based on their hash values
    def distribute_elements_into_buckets(self, array, buckets, min, max, number_of_buckets):
        for element in array: # Iterate through each element in the array
            bucket_index = self.hash(element, min, max, number_of_buckets) # Calculate the hash value for the element
            buckets[bucket_index].append(element) # Add the element to the corresponding bucket

    # Helper method to concatenate the sorted buckets back into a single sorted array
    def concatenate_buckets(self, buckets, array):
        index = 0 # Initialize an index to keep track of the array position

        # Iterate through each sorted bucket and add its elements to the array
        for bucket in buckets:
            bucket.sort() # Sort the elements in the bucket
            for element in bucket:
                array[index] = element # Add the element to the array
                index += 1

        return array

    # Helper method to calculate the hash value for an element based on the minimum, maximum, and number of buckets
    def hash(self, element, min, max, number_of_buckets):
        range = max - min # Calculate the range between the minimum and maximum elements
        normalized_value = (element - min) / range # Calculate the normalized value of the element
        return int(normalized_value * (number_of_buckets - 1)) # Calculate the hash value as an index

    # Helper methods to find the minimum and maximum elements in the array
    def find_min(self, array):
        min = array[0] # Initialize the minimum element as the first element in the array
        for element in array: # Iterate through the remaining elements in the array
            if element < min: # If the current element is less than the minimum, update the minimum
                min = element

        return min

    def find_max(self, array):
        max = array[0] # Initialize the maximum element as the first element in the array
        for element in array: # Iterate through the remaining elements in the array
            if element > max: # If the current element is greater than the maximum, update the maximum
                max = element

        return max

    # Main method to read input and call the sorting method
    def main(self):
        n = int(input()) # Read the number of elements in the array from the console
        array = [float(i) for i in input().split()] # Read the elements of the array from the console and store them in the array

        sorted_array = self.sort(array) # Call the sorting method to sort the array

        # Print the sorted elements to the console
        for num in sorted_array:
            print(num, end=" ")

        print()

if __name__ == "__main__":
    Main().main()

