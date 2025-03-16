from typing import List, TypeVar

T = TypeVar('T', bound='Comparable')

class Comparable:
    def __lt__(self, other):
        pass

    def __gt__(self, other):
        pass

class BucketSort:
    # Constant to determine the divisor for bucket calculation
    BUCKET_DIVISOR = 10

    # Main sorting method that sorts a list using bucket sort
    def sort(self, array: List[T]) -> List[T]:
        # Return the original array if it is empty
        if len(array) == 0:
            return array
        
        # Find the minimum and maximum elements in the array
        min_elem = self.find_min(array)
        max_elem = self.find_max(array)
        
        # Calculate the number of buckets needed for sorting
        number_of_buckets = self.calculate_number_of_buckets(len(array))
        
        # Initialize the buckets as a list of lists
        buckets = self.initialize_buckets(number_of_buckets)
        
        # Distribute the elements of the array into the appropriate buckets
        self.distribute_elements_into_buckets(array, buckets, min_elem, max_elem, number_of_buckets)
        
        # Concatenate the sorted elements from the buckets back into the original array
        return self.concatenate_buckets(buckets, array)

    # Calculate the number of buckets based on the length of the array
    def calculate_number_of_buckets(self, array_length: int) -> int:
        return max(array_length // self.BUCKET_DIVISOR, 1)

    # Initialize the buckets as empty lists
    def initialize_buckets(self, number_of_buckets: int) -> List[List[T]]:
        return [[] for _ in range(number_of_buckets)]

    # Distribute each element of the array into the corresponding bucket
    def distribute_elements_into_buckets(self, array: List[T], buckets: List[List[T]], min_elem: T, max_elem: T, number_of_buckets: int):
        for element in array:
            # Determine the bucket index for the current element
            bucket_index = self.hash(element, min_elem, max_elem, number_of_buckets)
            # Add the element to the appropriate bucket
            buckets[bucket_index].append(element)

    # Concatenate the sorted elements from all buckets back into the original array
    def concatenate_buckets(self, buckets: List[List[T]], array: List[T]) -> List[T]:
        index = 0
        for bucket in buckets:
            # Sort each bucket before concatenation
            bucket.sort()
            for element in bucket:
                array[index] = element  # Place the sorted elements back into the array
                index += 1
        return array

    # Calculate the bucket index for a given element
    def hash(self, element: T, min_elem: T, max_elem: T, number_of_buckets: int) -> int:
        range_val = max_elem - min_elem  # Calculate the range of values
        normalized_value = (element - min_elem) / range_val  # Normalize the value to a range of 0 to 1
        return int(normalized_value * (number_of_buckets - 1))  # Scale to the number of buckets

    # Find the minimum element in the array
    def find_min(self, array: List[T]) -> T:
        return min(array)  # Use built-in min function

    # Find the maximum element in the array
    def find_max(self, array: List[T]) -> T:
        return max(array)  # Use built-in max function

# Main method to execute the sorting process
if __name__ == "__main__":
    n = int(input())  # Read the number of elements
    array = [float(input()) for _ in range(n)]  # Create a list to hold the elements
    sorter = BucketSort()  # Create an instance of the BucketSort class
    sorted_array = sorter.sort(array)  # Sort the array
    print(" ".join(map(str, sorted_array)))  # Print the sorted array
