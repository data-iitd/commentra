import math

class Main:
    # Constant to determine the divisor for bucket calculation
    BUCKET_DIVISOR = 10

    # Main sorting method that sorts an array using bucket sort
    def sort(self, array):
        # Return the original array if it is empty
        if len(array) == 0:
            return array
        
        # Find the minimum and maximum elements in the array
        min_val = min(array)
        max_val = max(array)
        
        # Calculate the number of buckets needed for sorting
        number_of_buckets = max(len(array) // self.BUCKET_DIVISOR, 1)
        
        # Initialize the buckets as a list of lists
        buckets = [[] for _ in range(number_of_buckets)]
        
        # Distribute the elements of the array into the appropriate buckets
        self.distribute_elements_into_buckets(array, buckets, min_val, max_val, number_of_buckets)
        
        # Concatenate the sorted elements from the buckets back into the original array
        return self.concatenate_buckets(buckets, array)

    # Calculate the number of buckets based on the length of the array
    def calculate_number_of_buckets(self, array_length):
        return max(array_length // self.BUCKET_DIVISOR, 1)

    # Distribute each element of the array into the corresponding bucket
    def distribute_elements_into_buckets(self, array, buckets, min_val, max_val, number_of_buckets):
        for element in array:
            # Determine the bucket index for the current element
            bucket_index = self.hash(element, min_val, max_val, number_of_buckets)
            # Add the element to the appropriate bucket
            buckets[bucket_index].append(element)

    # Concatenate the sorted elements from all buckets back into the original array
    def concatenate_buckets(self, buckets, array):
        index = 0
        for bucket in buckets:
            # Sort each bucket before concatenation
            bucket.sort()
            for element in bucket:
                array[index] = element  # Place the sorted elements back into the array
                index += 1
        return array

    # Calculate the bucket index for a given element
    def hash(self, element, min_val, max_val, number_of_buckets):
        element_range = max_val - min_val
        normalized_value = (element - min_val) / element_range
        return int(normalized_value * (number_of_buckets - 1))

    # Main method to execute the sorting process
    @staticmethod
    def main():
        scanner = Scanner(System.in)
        n = scanner.nextInt()  # Read the number of elements
        array = [scanner.nextDouble() for _ in range(n)]  # Create a list to hold the elements
        sorter = Main()  # Create an instance of the Main class
        sorted_array = sorter.sort(array)  # Sort the array
        for num in sorted_array:
            print(num, end=" ")  # Print the sorted array
        scanner.close()  # Close the scanner to prevent resource leaks

