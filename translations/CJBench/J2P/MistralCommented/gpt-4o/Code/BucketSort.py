import sys
from typing import List, TypeVar, Generic

T = TypeVar('T', bound='Comparable')

class Comparable:
    def __lt__(self, other):
        return NotImplemented

class Main:
    # Constants
    BUCKET_DIVISOR = 10

    # Method to sort an array of comparable elements
    def sort(self, array: List[T]) -> List[T]:
        if len(array) == 0:  # Base case: empty array is already sorted
            return array

        min_elem = self.find_min(array)  # Find the minimum element in the array
        max_elem = self.find_max(array)  # Find the maximum element in the array
        number_of_buckets = self.calculate_number_of_buckets(len(array))  # Calculate the number of buckets needed

        # Initialize the buckets list with the specified number of empty lists
        buckets = self.initialize_buckets(number_of_buckets)

        # Distribute the elements into the buckets based on their hash values
        self.distribute_elements_into_buckets(array, buckets, min_elem, max_elem, number_of_buckets)

        # Concatenate the sorted buckets back into a single sorted array
        return self.concatenate_buckets(buckets, array)

    # Helper method to calculate the number of buckets needed based on the array length
    def calculate_number_of_buckets(self, array_length: int) -> int:
        return max(array_length // self.BUCKET_DIVISOR, 1)

    # Helper method to initialize the buckets list with the specified number of empty lists
    def initialize_buckets(self, number_of_buckets: int) -> List[List[T]]:
        return [[] for _ in range(number_of_buckets)]  # Create a list of empty lists

    # Helper method to distribute the elements into the buckets based on their hash values
    def distribute_elements_into_buckets(self, array: List[T], buckets: List[List[T]], min_elem: T, max_elem: T, number_of_buckets: int):
        for element in array:  # Iterate through each element in the array
            bucket_index = self.hash(element, min_elem, max_elem, number_of_buckets)  # Calculate the hash value for the element
            buckets[bucket_index].append(element)  # Add the element to the corresponding bucket

    # Helper method to concatenate the sorted buckets back into a single sorted array
    def concatenate_buckets(self, buckets: List[List[T]], array: List[T]) -> List[T]:
        index = 0  # Initialize an index to keep track of the array position

        # Iterate through each sorted bucket and add its elements to the array
        for bucket in buckets:
            bucket.sort()  # Sort the elements in the bucket
            for element in bucket:
                array[index] = element  # Add the element to the array
                index += 1

        return array

    # Helper method to calculate the hash value for an element based on the minimum, maximum, and number of buckets
    def hash(self, element: T, min_elem: T, max_elem: T, number_of_buckets: int) -> int:
        range_val = max_elem - min_elem  # Calculate the range between the minimum and maximum elements
        normalized_value = (element - min_elem) / range_val  # Calculate the normalized value of the element
        return int(normalized_value * (number_of_buckets - 1))  # Calculate the hash value as an index

    # Helper methods to find the minimum and maximum elements in the array
    def find_min(self, array: List[T]) -> T:
        return min(array)  # Use built-in min function

    def find_max(self, array: List[T]) -> T:
        return max(array)  # Use built-in max function

# Main method to read input and call the sorting method
if __name__ == "__main__":
    n = int(input())  # Read the number of elements in the array from the console
    array = [float(input()) for _ in range(n)]  # Create a list of floats from input

    sorter = Main()  # Create an instance of the Main class
    sorted_array = sorter.sort(array)  # Call the sorting method to sort the array

    # Print the sorted elements to the console
    print(" ".join(map(str, sorted_array)))

# <END-OF-CODE>
