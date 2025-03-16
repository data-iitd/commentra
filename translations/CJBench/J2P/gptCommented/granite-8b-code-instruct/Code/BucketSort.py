
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
        number_of_buckets = self.calculate_number_of_buckets(len(array))

        # Initialize the buckets as a list of lists
        buckets = self.initialize_buckets(number_of_buckets)

        # Distribute the elements of the array into the appropriate buckets
        self.distribute_elements_into_buckets(array, buckets, min_val, max_val, number_of_buckets)

        # Concatenate the sorted elements from the buckets back into the original array
        return self.concatenate_buckets(buckets, array)

    # Calculate the number of buckets based on the length of the array
    def calculate_number_of_buckets(self, array_length):
        return max(array_length // self.BUCKET_DIVISOR, 1)

    # Initialize the buckets as empty lists
    def initialize_buckets(self, number_of_buckets):
        return [[] for _ in range(number_of_buckets)]

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
                array[index] = element # Place the sorted elements back into the array
                index += 1
        return array

    # Calculate the bucket index for a given element
    def hash(self, element, min_val, max_val, number_of_buckets):
        range_ = max_val - min_val # Calculate the range of values
        normalized_value = (element - min_val) / range_ # Normalize the value to a range of 0 to 1
        return int(normalized_value * (number_of_buckets - 1)) # Scale to the number of buckets

    # Find the minimum element in the array
    def find_min(self, array):
        min_val = array[0] # Assume the first element is the minimum
        for element in array:
            if element < min_val:
                min_val = element # Update min if a smaller element is found
        return min_val

    # Find the maximum element in the array
    def find_max(self, array):
        max_val = array[0] # Assume the first element is the maximum
        for element in array:
            if element > max_val:
                max_val = element # Update max if a larger element is found
        return max_val

    # Main method to execute the sorting process
    def main(self):
        n = int(input()) # Read the number of elements
        array = [float(input()) for _ in range(n)] # Create an array to hold the elements
        sorted_array = self.sort(array) # Sort the array
        print(" ".join(map(str, sorted_array))) # Print the sorted array

if __name__ == "__main__":
    Main().main() # Call the main method to start the sorting process

