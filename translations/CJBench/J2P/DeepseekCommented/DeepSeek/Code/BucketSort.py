import math

class Sorter:
    BUCKET_DIVISOR = 10  # Constant divisor for calculating the number of buckets.

    def sort(self, array):
        if len(array) == 0:
            return array  # Return the array as is if it's empty.

        min_element = self.find_min(array)  # Find the minimum element in the array.
        max_element = self.find_max(array)  # Find the maximum element in the array.
        number_of_buckets = self.calculate_number_of_buckets(len(array))  # Calculate the number of buckets.
        buckets = self.initialize_buckets(number_of_buckets)  # Initialize the buckets.
        self.distribute_elements_into_buckets(array, buckets, min_element, max_element, number_of_buckets)  # Distribute elements into buckets.
        return self.concatenate_buckets(buckets, array)  # Concatenate sorted buckets back into the array.

    def calculate_number_of_buckets(self, array_length):
        return max(array_length // self.BUCKET_DIVISOR, 1)  # Calculate the number of buckets based on the array length.

    def initialize_buckets(self, number_of_buckets):
        return [[] for _ in range(number_of_buckets)]  # Create a list of empty lists for buckets.

    def distribute_elements_into_buckets(self, array, buckets, min_element, max_element, number_of_buckets):
        for element in array:
            bucket_index = self.hash(element, min_element, max_element, number_of_buckets)  # Determine the bucket index for the element.
            buckets[bucket_index].append(element)  # Add the element to the appropriate bucket.

    def concatenate_buckets(self, buckets, array):
        index = 0
        for bucket in buckets:
            bucket.sort()  # Sort each bucket.
            for element in bucket:
                array[index] = element  # Add sorted elements back into the original array.
                index += 1
        return array

    def hash(self, element, min_element, max_element, number_of_buckets):
        element_range = max_element - min_element  # Calculate the range between max and min.
        normalized_value = (element - min_element) / element_range  # Normalize the element's value.
        return math.floor(normalized_value * (number_of_buckets - 1))  # Calculate the bucket index.

    def find_min(self, array):
        min_element = array[0]  # Initialize min with the first element.
        for element in array:
            if element < min_element:  # Update min if a smaller element is found.
                min_element = element
        return min_element

    def find_max(self, array):
        max_element = array[0]  # Initialize max with the first element.
        for element in array:
            if element > max_element:  # Update max if a larger element is found.
                max_element = element
        return max_element

# Example usage:
if __name__ == "__main__":
    sorter = Sorter()
    n = int(input())  # Read the number of elements.
    array = [float(x) for x in input().split()]  # Read the elements of the array.
    sorted_array = sorter.sort(array)  # Sort the array.
    print(" ".join(map(str, sorted_array)))  # Print the sorted array.
